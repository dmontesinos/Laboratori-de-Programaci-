#include "Revistes.h"
#include "Prestec.h"

Data Revistes::calcRetorn(Data data)
{
	data = data + 30;
	return data;
}

bool Revistes::consulDisponibilitat(int codiExemplar)
{
	/*bool disponible = true;
	for (auto it = m_codiExemplarPrestat.begin(); it != m_codiExemplarPrestat.end() && disponible == false; it++) {
		if (*it == codiExemplar)
			disponible = false;
	}
	return disponible;*/

	bool trovat = false;
	bool disponible = true;
	auto it = m_codiExemplar.begin();

	while (!trovat && it != m_codiExemplar.end())
	{
		if (*it == codiExemplar) 
		{
			trovat = true;
		}
		else
		{
			disponible = false;
			it++;
		}
		
	}


	it = m_codiExemplarPrestat.begin();

	while (trovat && disponible && it != m_codiExemplarPrestat.end()) {
		if (*it == codiExemplar)
		{
			disponible = false;
		}
		else
		{
			it++;
		}
	}
	return disponible;
}

void Revistes::prestar(int codiExemplar)
{
	m_codiExemplarPrestat.push_back(codiExemplar);
}

void Revistes::retornar(int codiExemplar)
{
	bool trovat = false;
	auto it = m_codiExemplarPrestat.begin();

	while (!trovat && it != m_codiExemplarPrestat.end()) {
		if (*it == codiExemplar)
		{
			m_codiExemplarPrestat.erase(it);
			trovat = true;
		}
		else
		{
			it++;
		}
	}
}