#pragma once
#include <string>
#include "Data.h"
using namespace std;


class Publicacio
{
public:
	Publicacio() : m_codi(""), m_titol("") {};
	~Publicacio() {};

	void setCodi(string codi) { m_codi = codi; };
	void setTitol(string titol) { m_titol = titol; };

	string getCodi() { return m_codi; };
	string getTitol() { return m_titol; };

	virtual Data calcRetorn(Data data) { return data; }; //MIRAR
	virtual bool consulDisponibilitat(int codiExemplar) { return true; };//MIRAR
	virtual void canviarDisponibilitat(int codiExemplar) {};

private:
	string m_codi;
	string m_titol;
};