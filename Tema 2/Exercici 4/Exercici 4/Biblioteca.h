#pragma once
#include "Data.h"
#include <string>
#include <list>
#include "Publicacio.h"
#include "Prestec.h"

using namespace std;

class Biblioteca
{
public:
	Biblioteca() {};
	~Biblioteca() {};

	void llegirPublicacions(const string& nomFitxer);
	bool prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar);
	bool retornar(const string& idUsuari, const string& codi, const Data& data, bool &dataCorrecta, int nExmplar);

	Data calcRetorn(Data data) {};


private:
	std::list<Publicacio*> m_llistaPublicacions;
	std::list<Prestec*> m_llistaPrestecs;
};

