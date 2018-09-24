#pragma once
#include <string>

using namespace std;

class ProducteComanda
{
public:
	ProducteComanda();
	~ProducteComanda();

	void setCodi(string m_codi);
	void setUnitats(int m_nUnitats);
	void setPreu(float m_preu);

	string getCodi() const; 
	int getUnitats() const;
	float getPreu() const;


private:
	string m_codi;
	int m_nUnitats;
	float m_preu;
};
