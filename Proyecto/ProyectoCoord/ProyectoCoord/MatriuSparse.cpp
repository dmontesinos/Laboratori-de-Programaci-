#include "MatriuSparse.h"
#include <fstream>
#include <algorithm>



MatriuSparse::MatriuSparse(const string &nombreFichero)
{
	ifstream fichero;

	float fila;
	float columna;
	float valor;


	fichero.open(nombreFichero);

	if (fichero.is_open())
	{
		while (!fichero.eof())
		{
			fichero >> fila;
			fichero >> columna;

			m_coordenadas.push_back(make_pair(fila, columna));
			m_val.push_back(1);
		}
		fichero.close();
	}
	else {
		throw "No se ha podido leer el fichero.";
	}
}

MatriuSparse::MatriuSparse(int filas, int columnas)
{
	vector <vector<float>> m_matriz(filas, vector<float>(columnas));
}

MatriuSparse::MatriuSparse(const MatriuSparse &c)//FALTA REVISAR
{
	m_matriz = c.m_matriz;
}


void MatriuSparse::setVal(int fila, int columna, float valor)
{
	m_coordenadas.push_back(make_pair(fila, columna));
	m_val.push_back(valor);
}

bool MatriuSparse::getVal(int fila, int columna, float &valor)
{
	bool encontrado = false;
	bool encontradoBucle = false;

	for (auto it = m_coordenadas.begin(); it != m_coordenadas.end() && !encontradoBucle; it++)
	{
		if (it->first == fila && it->second == columna)
		{
			int posicion = distance(m_coordenadas.begin(), it);
			valor = m_val[posicion];
			encontradoBucle = true;
			encontrado = true;
		}
		else {
			encontrado = true;
			valor = 0;
		}
	}
	return encontrado;
}


ostream &operator<<(ostream &out, const MatriuSparse &matriu)
{
	int max = 0;
	for (auto it = matriu.m_coordenadas.begin(); it != matriu.m_coordenadas.end(); it++)
	{
		if (it->first > max)
			max = it->first;
		if (it->second > max)
			max = it->second;
	}

	vector <vector<float> > matriz(max +1, vector<float>(max +1, 0)); //Crea una matriz de (#fila) filas y (#columna) columnas.
	
	for (auto it = matriu.m_coordenadas.begin(); it != matriu.m_coordenadas.end(); it++)
	{
		int posicion = distance(matriu.m_coordenadas.begin(), it);
		matriz[it->first][it->second] = matriu.m_val[posicion];
	}

	for (auto vec : matriz)
	{
		for (auto x : vec)
			out << x << ",";

		out << endl;
	}

	return out;
}
