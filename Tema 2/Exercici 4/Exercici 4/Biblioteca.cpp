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

				m_llistaPublicacions.push_back(llibre);
			}
			else 
			{ //REVISTA
				int periodicitat;
				int numExemplars;

				string stringCodisExemplars;
				Revistes revista;


				fitxer >> periodicitat;
				fitxer >> numExemplars;
				
				/*if (numExemplars > 0) //Comprobamos que hayan ejemplares
				{ 
					fitxer >> stringCodisExemplars;
					//STRING TO VECTOR
					const char delimitador = ',';

					std::vector<std::string> salida;
					tokenize(stringCodisExemplars, delimitador, salida);

					for (auto &s : salida) {
						revista.afegirCodiExemplar(stoi(s));
					}
					//FIN STRING TO VECTOR
				}*/

				if (numExemplars > 0) //Comprobamos que hayan ejemplares
				{
					fitxer >> stringCodisExemplars;

					//STRING TO VECTOR
					const char delimitador = ',';

					std::vector<std::string> salida;
					tokenize(stringCodisExemplars, delimitador, salida);

					//FIN STRING TO VECTOR

					for (int i = 0; i < numExemplars; i++) {
						revista.setCodi(codi);
						revista.setTitol(titol);
						revista.setPeriodicitat(periodicitat);
						revista.setNumExemplars(numExemplars);
						revista.setCodiExemplar(stoi(salida[i]));

						m_llistaPublicacions.push_back(revista);
					}
				}
			}
		}
		fitxer.close();
	}
}

void Biblioteca::tokenize(std::string const &str, const char delim,
	std::vector<std::string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

bool Biblioteca::consultaPublicacio(string codi)
{
	bool trovat = false;
	Publicacio publicacio;

	for (auto it = m_llistaPublicacions.begin(); it != m_llistaPublicacions.end(); it++)
	{
		publicacio = *it;
		if (publicacio.getCodi() == codi)
			trovat = true;
	}

	return trovat;
}

bool Biblioteca::consultaDisponibilitat(string codi, int nExemplar, int &numPrestecs)
{
	Prestec prestec;

	for (auto it = m_llistaPrestecs.begin(); it != m_llistaPrestecs.end(); it++)
	{
		prestec = *it;
		if (prestec.getCodiPublicacio() == codi) {
			numPrestecs++;
		}
	}
	return true;
}


bool Biblioteca::prestar(const string& idUsuari, const string& codi, 
	const Data& dataPrestec, Data& dataRetorn, int nExemplar = 0) 
{
	int numPrestecs;
	if (consultaPublicacio(codi) && consultaDisponibilitat(codi, nExemplar, numPrestecs))
	{
		dataRetorn = calcRetorn(dataPrestec);

	}
	else {
		return false;
	}
}

bool Biblioteca::retornar(const string& idUsuari, const string& codi, 
	const Data& data, bool &dataCorrecta, int nExmplar = 0)
{

}