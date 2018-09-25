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
		while (!fitxer.eof() && m_ultimProd != m_llistaProductes.end())
		{
			fitxer >> nom;
			fitxer >> codi;
			fitxer >> preu;

			producte.setNom(nom);
			producte.setCodi(codi);
			producte.setPreu(preu);
			m_llistaProductes.insert_after(m_ultimProd,producte);
			m_ultimProd++;
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
	string nomProducte;
	int nUnitats;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		fitxer >> nomClient;
		comanda.setClient(nomClient);

		fitxer >> dataString;
		data.string2date(dataString);
		comanda.setData(data);
		
		fitxer >> nUnitatsCom;
		comanda.setNumProd(nUnitatsCom);

		while (!fitxer.eof() && m_ultimCom != m_llistaComandes.end())
		{
			comanda.setClient(nomClient);
			comanda.setImport()

			m_llistaProductes.insert_after(m_ultimProd, producte);
			m_ultimProd++;
		}
		fitxer.close();
	}
}
