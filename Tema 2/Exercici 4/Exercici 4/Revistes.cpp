#include "Revistes.h"

Data Revistes::calcRetorn(Data data)
{
	data = data + 30;
	return data;
}

bool Revistes::consultaDisponibilitat(string codi, int nExemplar, int &numPrestecs)
{
	if (nExemplar == m_codiExemplar)
		return false;
	else
		return true;
}