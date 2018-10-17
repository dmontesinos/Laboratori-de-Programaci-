#pragma once
#include "Publicacio.h"
#include <string>
#include <vector>
#include "Data.h"
using namespace std;

class Revistes : public Publicacio
{
public:
	Revistes() : m_periodicitat(0), m_codiExemplar(0) {};
	~Revistes() {};

	void setPeriodicitat(int periodicitat) { m_periodicitat = periodicitat; };
	void setNumExemplars(int exemplars) { m_numExemplars = exemplars; };
	//void afegirCodiExemplar(int codiExemplar) { m_codiExemplar.push_back(codiExemplar); };
	void setCodiExemplar(int codiExemplar) { m_codiExemplar=codiExemplar; };
	
	int getPeriodicitat() { return m_periodicitat; };

	Data calcRetorn(Data data);

	bool consultaDisponibilitat(string codi, int nExemplar, int &numPrestecs);

private:
	int m_periodicitat;
	int m_numExemplars;
	int m_codiExemplar;
	//std::vector<int> m_codiExemplar;

	static const int MENSUAL = 0;
	static const int TRIMESTRAL = 1;
	static const int ANUAL = 2;
};

