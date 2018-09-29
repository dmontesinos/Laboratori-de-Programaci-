#include "Matriu.h"

Matriu::Matriu() 
{
	float **m_matriu = new float*[0];
	m_nFiles = 0;
	m_nColumnes = 0;
}

Matriu::~Matriu() 
{
	for (int i = 0; i < m_nFiles; i++) 
		delete[] m_matriu[i]; 
	delete[] m_matriu;
}

Matriu::Matriu(int nFiles, int nColumnes)
{
	float **m_matriu = new float*[nFiles];
	
	for (int i = 0; i < nFiles; i++)
	{
		m_matriu[i] = new float[nColumnes];
	}
}

Matriu::Matriu(const Matriu& c)
{
	m_nFiles = c.m_nFiles;
	m_nColumnes = c.m_nColumnes;
	float **matriu = new float*[c.m_nFiles];

	for (int i = 0; i < c.m_nFiles; i++)
	{
		m_matriu[i] = new float[c.m_nColumnes];
		m_matriu[i] = c.m_matriu[i];
	}
}

Matriu& Matriu::operator=(const Matriu& c)
{
	//Eliminación de la matriz original
	for (int i = 0; i < this->m_nFiles; i++)
		delete[] this->m_matriu[i];
	delete[] this->m_matriu;

	//Creación de la matriz con las propiedades de la que queremos copiar
	float **m_matriu = new float*[c.m_nFiles];

	for (int i = 0; i < c.m_nFiles; i++)
	{
		m_matriu[i] = new float[c.m_nColumnes];
	}

	this->m_nColumnes = c.m_nColumnes;
	this->m_nFiles = c.m_nFiles;
}