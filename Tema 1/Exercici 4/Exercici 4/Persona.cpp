#include "Persona.h"

ostream& operator<<(ostream &out, const Persona& p)
{
	out << "(" << p.m_nom << ", " << p.m_edat << ")";
	return out;
}

bool Persona::operator>(Persona &p) {
	bool trobat = false;

	if (m_edat > p.m_edat)
		trobat = true;
	else if(m_edat == p.m_edat && m_nom > p.m_nom)
	{
		trobat = true;
	}
	return trobat;
}


bool Persona::operator==(const Persona &p) const {
	bool trobat = false;

	if (m_nom == p.m_nom && m_edat == p.m_edat)
		trobat = true;

	return trobat;
}

Persona Persona::operator=(Persona &p) {
	m_nom = p.m_nom;
	m_edat = p.m_edat;

	return *this;
}