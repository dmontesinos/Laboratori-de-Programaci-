#include "Producte.h"
#include <fstream>
using namespace std;

Producte::Producte()
{
	m_nom = "";
	m_codi = "";
	m_preu = 0;
}

Producte::~Producte()
{

}

void Producte::setNom(string nom)
{
	m_nom = nom;
}

void Producte::setCodi(string codi)
{
	m_codi = codi;
}

void Producte::setPreu(float preu)
{
	m_preu = preu;
}

string Producte::getNom() const
{
	return m_nom;
}

string Producte::getCodi() const
{
	return m_codi;
}

float Producte::getPreu() const
{
	return m_preu;
}

