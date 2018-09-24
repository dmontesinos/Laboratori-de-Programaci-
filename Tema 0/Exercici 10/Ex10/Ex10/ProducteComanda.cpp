#include "ProducteComanda.h";

ProducteComanda::ProducteComanda() 
{

}

ProducteComanda::~ProducteComanda() 
{

}

void ProducteComanda::setCodi(string codi)
{
	m_codi = codi;
}

void ProducteComanda::setPreu(float preu)
{
	m_preu = preu;
}

void ProducteComanda::setUnitats(int unitats)
{
	m_nUnitats = unitats;
}

string ProducteComanda::getCodi() const
{
	return m_codi;
}

float ProducteComanda::getPreu() const
{
	return m_preu;
}

int ProducteComanda::getUnitats() const
{
	return m_nUnitats;
}
