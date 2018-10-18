#include "Llibres.h"

Data Llibres::calcRetorn(Data data)
{
	data = data + m_diesPrestec;

	return data;
}


bool Llibres::consulDisponibilitat(int codiExemplar)
{
	if (m_prestat)
		return false;
	else
		return true;
}

void Llibres::canviarDisponibilitat(int codiExemplar)
{
	if (m_prestat)
		m_prestat = false;
	else
		m_prestat = true;
}