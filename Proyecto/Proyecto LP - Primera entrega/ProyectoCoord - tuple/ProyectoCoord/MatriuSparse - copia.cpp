#include "MatriuSparse.h"
#include <fstream>
#include <algorithm>


MatriuSparse::MatriuSparse(const string &nombreFichero)
{
	ifstream fichero;

	float fila;
	float columna;
	float valor;
	float max = 0;

	fichero.open(nombreFichero);

	if (fichero.is_open())
	{
		while (!fichero.eof())
		{
			fichero >> fila;
			fichero >> columna;
			if (fila > max)
				max = fila;
			if (columna > max)
				max = columna;

			m_coordenadas.push_back(make_pair(fila, columna));
			m_val.push_back(1);
		}
		fichero.close();

		m_matriz.resize(max+1);
		for (int i = 0; i < m_matriz.size(); i++)
		{
			m_matriz[i].resize(max+1);
		}
		
		for (auto it = m_coordenadas.begin(); it != m_coordenadas.end(); it++)
		{
			m_matriz[it->first][it->second] = 1;
		}
	}
	else {
		throw "No se ha podido leer el fichero.";
	}
}

MatriuSparse::MatriuSparse(int filas, int columnas)
{
	vector<vector<float>> m_matriz(filas, vector<float>(columnas));
}

MatriuSparse::MatriuSparse(const MatriuSparse &c)
{
	vector<vector<float>> m_matriz(c.m_matriz.size(), vector<float>(c.m_matriz.size(), 0));
	m_matriz = c.m_matriz;
}

MatriuSparse& MatriuSparse::operator=(const MatriuSparse& c)
{
	m_coordenadas = c.m_coordenadas;
	m_matriz = c.m_matriz;
	m_val = c.m_val;

	return *this;
}

void MatriuSparse::setVal(int fila, int columna, float valor)
{
	if (fila >= m_matriz.size() || columna >= m_matriz.size())
	{
		int max = fila;
		if (columna > max)
			max = columna;

		m_matriz.resize(max+1);
		for (int i = 0; i < m_matriz.size(); i++)
		{
			m_matriz[i].resize(max+1);
		}
	}
	
	m_coordenadas.push_back(make_pair(fila, columna));
	m_val.push_back(valor);
	m_matriz[fila][columna] = valor;
}

bool MatriuSparse::getVal(int fila, int columna, float &valor)
{
	bool encontrado = false;

	if (fila < m_matriz.size() && columna < m_matriz.size())
	{
		encontrado = true;
		valor = m_matriz[fila][columna];
	}
	return encontrado;
}


ostream &operator<<(ostream &out, const MatriuSparse &matriu)
{	
	vector<vector<float>> m_auxiliar;
	m_auxiliar = matriu.m_matriz;

	for (int fila = 0; fila < matriu.m_matriz.size(); fila++)
	{
		for (int columna = 0; columna < matriu.m_matriz.size(); columna++)
		{
			out << m_auxiliar[fila][columna] << ",";
		}
		out << endl;
	}
	return out;
}
