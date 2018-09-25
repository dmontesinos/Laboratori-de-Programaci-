#pragma once
#include <string>
using namespace std;

class Producte
{
public:
	Producte();
	~Producte();

	void setNom(string nom);
	void setCodi(string codi);
	void setPreu(float preu);

	string getNom(string nom) const;
	string getCodi(string codi) const;
	float getPreu(float preu) const;

private:
	string m_nom;
	string m_codi;
	float m_preu;
};
