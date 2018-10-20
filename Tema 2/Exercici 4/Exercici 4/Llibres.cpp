#include "Llibres.h"

Data Llibres::calcRetorn(Data data)
{
	data = data + m_diesPrestec;

	return data;
}


bool Llibres::consulDisponibilitat(int codiExemplar)
{
	if (m_numCopies > 0)
		return true;
	else
		return false;
}

void Llibres::prestar(int codiExemplar)
{
	m_numCopies--;
}

void Llibres::retornar(int codiExemplar)
{
	m_numCopies++;
}