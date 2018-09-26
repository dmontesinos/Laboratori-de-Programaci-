#include "Empresa.h"
#include <fstream>
using namespace std;

Empresa::Empresa()
{

}

Empresa::~Empresa()
{

}

void Empresa::llegeixProductes(const string & nomFitxer)
{
	ifstream fitxer;

	Producte producte;
	string nom;
	string codi;
	float preu;

	fitxer.open(nomFitxer);
	
	if (fitxer.is_open())
	{
		while (!fitxer.eof())
		{
			fitxer >> nom;
			fitxer >> codi;
			fitxer >> preu;

			producte.setNom(nom);
			producte.setCodi(codi);
			producte.setPreu(preu);
			m_llistaProductes.push_front(producte);
		}
		fitxer.close();
	}
}

bool Empresa::afegeixComanda(const string & nomFitxer)
{
	ifstream fitxer;
	Comanda comanda;
	string nomClient;
	string dataString;
	Data data;
	int nUnitatsCom;

	string codi;
	float preu;

	bool valid = false;
	string nomProducte;
	int nUnitats;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		while (!fitxer.eof())
		{
			fitxer >> nomClient;
			comanda.setClient(nomClient);

			fitxer >> dataString;
			comanda.setData(data.string2date(dataString));

			fitxer >> nUnitatsCom;
			comanda.setNumProd(nUnitatsCom);

			while (!fitxer.eof())
			{
				fitxer >> nomProducte;
				fitxer >> nUnitats;

				if (buscarProducte(nomProducte, preu, codi))
				{
					comanda.afegeixProducte(codi, nUnitats, preu);
					m_llistaComandes.push_front(comanda);
					valid = true;
				}
			}
		}
		fitxer.close();
	}
	return valid;
}

bool Empresa::buscarProducte(const string producte, float &preu, string &codi)
{
	bool valid = false;
	Producte prod;
	for (auto it = m_llistaProductes.begin(); it != m_llistaProductes.end(); it++)
	{
		prod = *it;
		if (producte == prod.getNom())
		{
			valid = true;
			preu = prod.getPreu();
			codi = prod.getCodi();
		}
	}
	return valid;
}

bool Empresa::importComanda(const string& nomClient, const Data& data, float &import)
{
	return false;
}

bool Empresa::DetallProducteComanda(const string& nomClient, const Data& data, const string& codiProducte, int& nUnitats, float& preu)
{
	return false;
}