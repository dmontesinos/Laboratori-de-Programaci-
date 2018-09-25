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

private:
	std::forward_list<Comanda> m_llistaComandes;
	std::forward_list<Comanda>::iterator m_ultimCom = m_llistaComandes.begin();
	std::forward_list<Producte> m_llistaProductes;
	std::forward_list<Producte>::iterator m_ultimProd = m_llistaProductes.begin();
};