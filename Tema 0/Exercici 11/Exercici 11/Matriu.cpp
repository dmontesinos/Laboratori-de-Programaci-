#include "Matriu.h"
#include <assert.h>  

Matriu::Matriu() 
{
	m_matriu = new float*[0];
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
	m_nFiles = nFiles;
	m_nColumnes = nColumnes;

	m_matriu = new float*[nFiles];
	
	for (int i = 0; i < nFiles; i++)
	{
		m_matriu[i] = new float[nColumnes];
	}

	for (int i = 0; i < nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			m_matriu[i][j] = 0;
		}
	}
}

Matriu::Matriu(const Matriu& c)
{
	m_nFiles = c.m_nFiles;
	m_nColumnes = c.m_nColumnes;

	m_matriu = new float*[c.m_nFiles];

	for (int i = 0; i < c.m_nFiles; i++)
	{
		m_matriu[i] = new float[c.m_nColumnes];
	}

	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			m_matriu[i][j] = c.m_matriu[i][j];
		}
	}
}

Matriu& Matriu::operator=(const Matriu& c)
{
	Matriu matriu2(c.m_nFiles, c.m_nColumnes);
	//Eliminación de la matriz original
	for (int i = 0; i < this->m_nFiles; i++)
		delete[] this->m_matriu[i];
	delete[] this->m_matriu;

	//Creación de la matriz con las propiedades de la que queremos copiar
	m_matriu = new float*[c.m_nFiles];

	for (int i = 0; i < c.m_nFiles; i++)
	{
		m_matriu[i] = new float[c.m_nColumnes];
	}

	this->m_nColumnes = c.m_nColumnes;
	this->m_nFiles = c.m_nFiles;

	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			m_matriu[i][j] = c.m_matriu[i][j];
		}
	}
	return matriu2;
}

float& Matriu::operator()(int fila, int columna)
{
	assert(columna >= 0 && columna < m_nColumnes);
	assert(fila >= 0 && fila < m_nFiles);

	return m_matriu[fila][columna];
}

const double Matriu::operator()(int fila, int columna) const
{
	assert(columna >= 0 && columna < m_nColumnes);
	assert(fila >= 0 && fila < m_nFiles);

	return m_matriu[fila][columna];
}

int Matriu::getNFiles() const
{
	return m_nFiles;
}

int Matriu::getNColumnes() const
{
	return m_nColumnes;
}

void Matriu::init(int nFiles, int nColumnes)
{
	m_nFiles = nFiles;
	m_nColumnes = nColumnes;

	m_matriu = new float*[m_nFiles];

	for (int i = 0; i < m_nFiles; i++)
	{
		m_matriu[i] = new float[m_nColumnes];
	}
}

void Matriu::setValor(float valor)
{
	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
			m_matriu[i][j] = valor;
	}
}

Matriu Matriu::operator*(const Matriu& m)
{
	int files = m_nFiles;
	int columnes = m.m_nColumnes;
	Matriu matriu(files, columnes);

	if (m_nColumnes == m.m_nFiles)
	{
		for (int i = 0; i < m_nFiles; i++)
		{
			for (int j = 0; j < m.m_nColumnes; j++)
			{
				for (int x = 0; x < m_nColumnes; x++)
				{
					matriu.m_matriu[i][j] += m_matriu[i][x] * m.m_matriu[x][j];
				}
			}
		}
		return matriu;
	}
	else {
		Matriu matriu2(0, 0);
		return matriu2;
	}
}

Matriu Matriu::operator*(float com)
{
	Matriu matriu(m_nFiles, m_nColumnes);

	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			matriu.m_matriu[i][j] = m_matriu[i][j] * com;
		}
	}
	return matriu;
}

bool Matriu::esBuida() const
{
	bool vacia = false;

	if (m_nFiles == 0 && m_nColumnes == 0)
		vacia = true;

	return vacia;
}