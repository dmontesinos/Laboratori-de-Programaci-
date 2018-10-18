#pragma once
#include <string>
#include "Data.h"
using namespace std;

class Prestec
{
public:
	void setIdUsuari(string idUsuari) { m_idUsuari = idUsuari; };
	void setCodiPublicacio(string codiPublicacio) { m_codiPublicacio = codiPublicacio; };
	void setDataPrestec(Data data) { m_dataPrestec = data; };
	void setDataRetorn(Data data) { m_dataRetorn = data; };

	string getCodiPublicacio() { return m_codiPublicacio; };


private:
	string m_idUsuari;
	string m_codiPublicacio;
	Data m_dataPrestec;
	Data m_dataRetorn;
};