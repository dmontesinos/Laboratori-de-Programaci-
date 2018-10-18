#include "Revistes.h"
#include "Prestec.h"

Data Revistes::calcRetorn(Data data)
{
	data = data + 30;
	return data;
}

bool Revistes::consulDisponibilitat(int codiExemplar)
{
	bool disponible = true;
	for (auto it = m_codiExemplarPrestat.begin(); it != m_codiExemplarPrestat.end() && disponible == false; it++) {
		if (*it == codiExemplar)
			disponible = false;
	}
	return disponible;
}

void Revistes::canviarDisponibilitat(int codiExemplar)
{
	/*for (auto it = m_codiExemplarPrestat.begin(); it != m_codiExemplarPrestat.end(); it++)
	{
		if (*it = codiExemplar)

	}*/
}