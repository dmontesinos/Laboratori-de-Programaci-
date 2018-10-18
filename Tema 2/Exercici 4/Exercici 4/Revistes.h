#pragma once
#include "Publicacio.h"
#include <string>
#include <list>
#include "Data.h"
using namespace std;

class Revistes : public Publicacio
{
public:
	Revistes() : m_periodicitat(""), m_codiExemplar(0) {};
	~Revistes() {};

	void setPeriodicitat(string periodicitat) { m_periodicitat = periodicitat; };
	void setNumExemplars(int exemplars) { m_numExemplars = exemplars; };
	//void afegirCodiExemplar(int codiExemplar) { m_codiExemplar.push_back(codiExemplar); };
	void setCodiExemplar(int codiExemplar) { m_codiExemplar.push_back(codiExemplar); };
	
	string getPeriodicitat() { return m_periodicitat; };

	Data calcRetorn(Data data);

	bool consultaDisponibilitat(string codi, int nExemplar, int &numPrestecs);

private:
	string m_periodicitat;
	int m_numExemplars;
	std::list<int> m_codiExemplar;
};

