#include "Biblioteca.h"
#include "Llibres.h"
#include "Revistes.h"
#include <fstream>
#include <vector>

void Biblioteca::llegirPublicacions(const string& nomFitxer)
{
	ifstream fitxer;

	Publicacio publicacio;
	string tipus;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		while (!fitxer.eof())
		{
			string codi;
			string titol;

			fitxer >> tipus;
			fitxer >> codi;
			fitxer >> titol;

			if (tipus == "L") //LLIBRE
			{
				string autor;
				int numCopies;
				int diesPrestec;
				fitxer >> autor;
				fitxer >> numCopies;
				fitxer >> diesPrestec;

				Llibres llibre;
				llibre.setCodi(codi);
				llibre.setTitol(titol);
				llibre.setAutor(autor);
				llibre.setNumCopies(numCopies);
				llibre.setDiesPrestec(diesPrestec);

				m_llistaPublicacions.push_back(new Llibres(llibre));
			}
			else 
			{ //REVISTA
				string periodicitat;
				int numExemplars;
				int codiExemplar;
				Revistes revista;


				fitxer >> periodicitat;
				fitxer >> numExemplars;
				

				if (numExemplars > 0) //Comprobamos que hayan ejemplares
				{
					revista.setCodi(codi);
					revista.setTitol(titol);
					revista.setPeriodicitat(periodicitat);
					revista.setNumExemplars(numExemplars);

					for (int i = 0; i < numExemplars; i++)
					{
						fitxer >> codiExemplar;
						revista.setCodiExemplar(codiExemplar);
					}

					m_llistaPublicacions.push_back(new Revistes(revista));
				}
			}
		}
		fitxer.close();
	}
}



bool Biblioteca::prestar(const string& idUsuari, const string& codi, 
	const Data& dataPrestec, Data& dataRetorn, int nExemplar = 0) 
{
	bool trovat = false;

	for (auto it = m_llistaPublicacions.begin(); it != m_llistaPublicacions.end() && !trovat; it++)
	{
		if ((*it)->getCodi() == codi)
		{
			if ((*it)->consulDisponibilitat(nExemplar))
			{
				trovat = true;

				(*it)->prestar(nExemplar);
				Prestec prestec;

				prestec.setIdUsuari(idUsuari);
				prestec.setCodiPublicacio(codi);
				prestec.setDataPrestec(dataPrestec);
				dataRetorn = (*it)->calcRetorn(dataPrestec);
				prestec.setDataRetorn(dataRetorn);
				m_llistaPrestecs.push_back(new Prestec(prestec));
				
			}
		}

	}
	return trovat;
}

bool Biblioteca::retornar(const string& idUsuari, const string& codi,
	const Data& data, bool &dataCorrecta, int nExemplar = 0)
{
	bool trovat = false;

	auto it = m_llistaPrestecs.begin();

	while (!trovat && it != m_llistaPrestecs.end())
	{
		if ((*it)->getIdUsuari() == idUsuari
			&& (*it)->getCodiPublicacio() == codi)
		{
			if ((*it)->getDataRetorn() < data
				|| (*it)->getDataRetorn() == data)
			{
				dataCorrecta = false;
			}
				
			else {
				dataCorrecta = true;
			}
				

			
			trovat = true;

			Publicacio publicacio;
			bool trovat2 = false;
	
			auto it2 = m_llistaPublicacions.begin();
			while (it2 != m_llistaPublicacions.end() && !trovat2)
			{
				if ((*it2)->getCodi() == codi)
				{
					trovat2 = true;
					(*it2)->retornar(nExemplar);
				}
				else {
					it2++;
				}
			}
			m_llistaPrestecs.erase(it);
		}
		else
			it++;
	}
	return trovat;
}