#pragma once
#include "Data.h"
#include <string>
#include <vector>
#include "Publicacio.h"
#include "Prestec.h"

using namespace std;

class Biblioteca
{
public:
	Biblioteca() {}
	~Biblioteca() {}

	void tokenize(std::string const &str, const char delim,
		std::vector<std::string> &out);

	void llegirPublicacions(const string& nomFitxer);
	bool prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar = 0);
	bool retornar(const string& idUsuari, const string& codi, const Data& data, bool &dataCorrecta, int nExmplar = 0);
	
	bool consultaPublicacio(string codi);
	bool consultaDisponibilitat(string codi, int nExemplar, int &numPrestecs);

	Data calcRetorn(Data data) {};


private:
	std::vector<Publicacio> m_llistaPublicacions;
	std::vector<Prestec> m_llistaPrestecs;
};

