#include "Comanda.h";

Comanda::Comanda()
{
	m_nomClient = "";
	m_impTotal = 0;
	m_nProd = 0;
	m_producteLlistat = 0;
	m_prodDades = new ProducteComanda[m_nProd];
}

Comanda::Comanda(const Comanda& c)
{
	m_nomClient = c.m_nomClient;

	m_data.setAny(c.m_data.getAny());
	m_data.setMes(c.m_data.getMes());
	m_data.setDia(c.m_data.getDia());

	m_impTotal = c.m_impTotal;
	m_nProd = c.m_nProd;
	m_producteLlistat = c.m_producteLlistat;

	m_prodDades = new ProducteComanda[m_nProd];

	for (int i = 0; i < m_producteLlistat; i++)
	{
		m_prodDades[i].setCodi(c.m_prodDades[i].getCodi());
		m_prodDades[i].setPreu(c.m_prodDades[i].getPreu());
		m_prodDades[i].setUnitats(c.m_prodDades[i].getUnitats());
	}
}


Comanda::Comanda(string client, Data data, int numProductes)
{
	m_nomClient = client;
	m_data = data;
	m_nProd = numProductes;
	m_producteLlistat = 0;
	m_prodDades = new ProducteComanda[m_nProd];
}

Comanda::~Comanda()
{
	if (m_producteLlistat > 0)
	{
		delete[] m_prodDades;
	}
	
}

Comanda& Comanda::operator=(const Comanda& c)
{

	this->m_nomClient = c.m_nomClient;

	this->m_data.setAny(c.m_data.getAny());
	this->m_data.setMes(c.m_data.getMes());
	this->m_data.setDia(c.m_data.getDia());

	this->m_impTotal = c.m_impTotal;
	this->m_nProd = c.m_nProd;
	this->m_producteLlistat = c.m_producteLlistat;

	this->m_prodDades = new ProducteComanda[m_nProd];

	for (int i = 0; i < m_producteLlistat; i++)
	{
		this->m_prodDades[i].setCodi(c.m_prodDades[i].getCodi());
		this->m_prodDades[i].setPreu(c.m_prodDades[i].getPreu());
		this->m_prodDades[i].setUnitats(c.m_prodDades[i].getUnitats());
	}
	return *this;
}

void Comanda::setClient(string client)
{
	m_nomClient = client;
}

void Comanda::setData(Data data)
{
	m_data.setAny(data.getAny());
	m_data.setMes(data.getMes());
	m_data.setDia(data.getDia());
}

void Comanda::setImport(int import)
{
	m_impTotal = import;
}

void Comanda::setNumProd(int numProd)
{
	m_nProd = numProd;
}


string Comanda::getClient() const
{
	return m_nomClient;
}

Data Comanda::getData() const
{
	return m_data;
}


float Comanda::getImport() const
{
	return m_impTotal;
}

bool Comanda::afegeixProducte(string codi, int unitats, int pUnitat)
{
	bool afegit = false;
	if (m_producteLlistat < m_nProd)
	{
		m_prodDades = new ProducteComanda[m_nProd];
		m_prodDades[m_producteLlistat].setCodi(codi);
		m_prodDades[m_producteLlistat].setUnitats(unitats);
		m_prodDades[m_producteLlistat].setPreu(pUnitat);
		m_impTotal += (unitats*pUnitat);
		m_producteLlistat++;
		
		afegit = true;
	}
	return afegit;
}


bool Comanda::consultaProducte(string codi, int &unitats, float &preu)
{
	bool trobat = false;
	int indice = 0;
	if (m_producteLlistat != indice)
	{
		while (indice < m_producteLlistat)
		{
			if (m_prodDades[indice].getCodi() == codi)
			{
				trobat = true;
				preu = m_prodDades[indice].getPreu();
				unitats = m_prodDades[indice].getUnitats();
				indice = m_producteLlistat;
			}
			indice++;
		}
	}
	return trobat;
}
