#include "Llibres.h"

Data Llibres::calcRetorn(Data data)
{
	data = data + m_diesPrestec;

	return data;
}

bool Llibres::consultaDisponibilitat(string codi, int nExemplar, int &numPrestecs)
{
	if (numPrestecs < m_numCopies)
		return true;
	else
		return false;
}