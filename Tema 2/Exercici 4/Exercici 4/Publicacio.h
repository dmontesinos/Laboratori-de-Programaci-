#pragma once
#include <string>
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

	

private:
	string m_codi;
	string m_titol;
};