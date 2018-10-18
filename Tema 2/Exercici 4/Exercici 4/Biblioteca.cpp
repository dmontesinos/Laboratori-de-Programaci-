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
				Prestec prestec;

				prestec.setIdUsuari(idUsuari);
				prestec.setCodiPublicacio(codi);
				prestec.setDataPrestec(dataPrestec);
				prestec.setDataRetorn((*it)->calcRetorn(dataPrestec));

				m_llistaPrestecs.push_back(new Prestec(prestec));
				
			}
		}

	}
	return trovat;
}

bool Biblioteca::retornar(const string& idUsuari, const string& codi, 
	const Data& data, bool &dataCorrecta, int nExmplar = 0)
{
	bool trovat = false;
	return trovat;
}