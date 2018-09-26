#pragma once
#include "Comanda.h"
#include "Producte.h"
#include <forward_list>

class Empresa
{
public:
	Empresa();
	~Empresa();

	void llegeixProductes(const string& nomFitxer);
	bool afegeixComanda(const string& nomFitxer);
	bool buscarProducte(const string producte, float &preu, string &codi);
	bool importComanda(const string& nomClient,const Data& data, float &import);
	bool DetallProducteComanda(const string& nomClient, const Data& data, const string& codiProducte, int& nUnitats, float& preu);

private:
	std::forward_list<Comanda> m_llistaComandes;
	std::forward_list<Producte> m_llistaProductes;
};