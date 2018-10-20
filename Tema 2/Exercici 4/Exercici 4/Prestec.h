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
	
	string getIdUsuari() { return m_idUsuari; };
	string getCodiPublicacio() { return m_codiPublicacio; };
	Data getDataRetorn() { return m_dataRetorn; };



private:
	string m_idUsuari;
	string m_codiPublicacio;
	Data m_dataPrestec;
	Data m_dataRetorn;
};