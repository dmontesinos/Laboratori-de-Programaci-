#pragma once
#include "Data.h"
#include "ProducteComanda.h"
#include <string>


using namespace std;



class Comanda
{
public:
	Comanda();
	~Comanda();

	Comanda(const Comanda& c);
	Comanda(string client,Data data,int numProductes);
	
	Comanda& operator=(const Comanda& c);


	void setClient(string client);
	void setData(Data data);
	void setImport(int import);
	void setNumProd(int numProd);
	

	string getClient() const;
	Data getData() const;
	float getImport() const;

	bool afegeixProducte(string codi,int unitats,int pUnitat);
	bool consultaProducte(const string codi, int &unitats,float &preu);

private:
	string m_nomClient;
	Data m_data;
	int m_impTotal;
	int m_nProd;
	int m_producteLlistat;
	ProducteComanda *m_prodDades;
};
