#pragma once
#include "Publicacio.h"
#include <string>
#include "Data.h"

using namespace std;

class Llibres : public Publicacio
{
public:
	Llibres() : m_autor(""), m_numCopies(0), m_diesPrestec(0) {};
	~Llibres() {};
	void setAutor(string autor) { m_autor = autor; };
	void setNumCopies(int copies) { m_numCopies = copies; };
	void setDiesPrestec(int prestec) { m_diesPrestec = prestec; };

	string getautor() { return m_autor; };
	int getNumCopies() { return m_numCopies; };
	int getDiesPrestec() { return m_diesPrestec; };

	Data calcRetorn(Data data);

	bool consultaDisponibilitat(string codi, int nExemplar, int &numPrestecs);


private:
	string m_autor;
	int m_numCopies;
	int m_diesPrestec;
};

