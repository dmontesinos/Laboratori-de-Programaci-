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
		fichero >> fila;
		fichero >> columna;

		while (!fichero.eof())
		{	
			m_coordenadas.push_back(tuple<int, int, float>(fila, columna, 1));
			fichero >> fila;
			fichero >> columna;
		}
		fichero.close();

		for (auto it = m_coordenadas.begin(); it != m_coordenadas.end(); it++)
		{
			if (get<0>(*it) > max)
				max = get<0>(*it);
			if (get<1>(*it) > max)
				max = get<1>(*it);
		}

		m_dimension = max + 1;

		sort(m_coordenadas.begin(), m_coordenadas.end(), [](tuple<int, int, float> const& A, tuple<int, int, float> const& B)
		{
			if (get<0>(A) < get<0>(B)) return true;
			if (get<0>(B) < get<0>(A)) return false;

			if (get<1>(A) < get<1>(B)) return true;
			if (get<1>(B) < get<1>(A)) return false;

			if (get<2>(A) < get<2>(B)) return true;
			if (get<2>(B) < get<2>(A)) return false;

			return false;
		});
	}
		
	else {
		throw "No se ha podido leer el fichero.";
	}
}



MatriuSparse::MatriuSparse(int filas, int columnas)
{
	if (filas > columnas)
		m_dimension = filas + 1;
	else
		m_dimension = columnas + 1;
}

MatriuSparse::MatriuSparse(const MatriuSparse &c)
{
	m_coordenadas = c.m_coordenadas;
	m_dimension = c.m_dimension;
}


MatriuSparse& MatriuSparse::operator=(const MatriuSparse& c)
{
	m_coordenadas = c.m_coordenadas;
	m_dimension = c.m_dimension;

	return *this;
}

vector<float>& MatriuSparse::operator=(const vector<float>& v)
{
	vector<float> aux = v;
	return aux;
}


MatriuSparse& MatriuSparse::operator*(const int valor)
{
	for (auto it = m_coordenadas.begin(); it != m_coordenadas.end(); it++)
	{
		get<2>(*it) *= valor;
	}

	return *this;
}

vector<float>& MatriuSparse::operator*(const vector<float> v1)
{
	vector<float> aux(v1.size(),0);

	auto it = m_coordenadas.begin();
	int fila = get<0>(*it);
	float sumatorio = 0;

	while (it != m_coordenadas.end())
	{
		if (get<0>(*it) == fila)
		{
			sumatorio += v1[get<1>(*it)] * get<2>(*it);
		}
		else {
			aux[fila] = sumatorio;
			sumatorio = 0;
			fila = get<0>(*it);
			aux[fila] += v1[get<1>(*it)] * get<2>(*it);
		}
		it++;
	}
	return aux;
}

MatriuSparse & MatriuSparse::operator/(const int valor)
{
	for (auto it = m_coordenadas.begin(); it != m_coordenadas.end(); it++)
	{
		get<2>(*it) /= valor;
	}

	return *this;
}

void MatriuSparse::init(int filas, int columnas)
{
	if (filas > columnas)
		m_dimension = filas + 1;
	else
		m_dimension = columnas + 1;
}

void MatriuSparse::setVal(int fila, int columna, float valor)
{
	if (fila > m_dimension)
		m_dimension = fila + 1;
	if (columna > m_dimension)
		m_dimension = columna + 1;
		
	bool encontrado = false;
	bool incrementar = true;

	auto it = m_coordenadas.begin();
	auto it2 = m_coordenadas.begin() +1;
	
	while (!encontrado && it != m_coordenadas.end())
	{
		if (it2 != m_coordenadas.end()) {
			if (get<0>(*it) == fila) {
				if (columna == get<1>(*it)) {
					if (valor == get<2>(*it)) //Ya existe
					{
						encontrado = true;
						incrementar = false;
					}
					else if (valor > get<2>(*it) && valor < get<2>(*it2)) {
						m_coordenadas.insert(it2, tuple<int, int, float>(fila, columna, valor));
						encontrado = true;
						incrementar = false;
					}
				}
				else if (columna > get<1>(*it) && columna < get<1>(*it2))
				{
					m_coordenadas.insert(it2, tuple<int, int, float>(fila, columna, valor));
					incrementar = false;
					encontrado = true;
				}
				else if (columna > get<1>(*it2) && fila < get<0>(*it2))
				{
					m_coordenadas.insert(it2, tuple<int, int, float>(fila, columna, valor));
					incrementar = false;
					encontrado = true;
				}
			}
			else if (get<0>(*it) < fila && get<0>(*it2) > fila) {
				m_coordenadas.insert(it2, tuple<int, int, float>(fila, columna, valor));
				incrementar = false;
				encontrado = true;
			}
			else if (get<0>(*it) > fila)
			{
				m_coordenadas.insert(it, tuple<int, int, float>(fila, columna, valor));
				encontrado = true;
				incrementar = false;
			}

			if (incrementar)
			{
				it++;
				it2++;
			}
		}
		else {
			m_coordenadas.push_back(tuple<int, int, float>(fila, columna, valor));
			encontrado = true;
		}
	}
}

bool MatriuSparse::getVal(int fila, int columna, float &valor)
{	
	bool encontrado = false;
	for (auto it = m_coordenadas.begin(); it != m_coordenadas.end(); it++)
	{
		if (get<0>(*it) == fila && get<1>(*it) == columna)
		{
			valor = get<2>(*it);
			encontrado = true;
		}
		if (fila < m_dimension && columna < m_dimension)
			if (encontrado == false) {
				valor = 0;
				encontrado = true;
			}
	}
	return encontrado;
}

ostream &operator<<(ostream &out, const MatriuSparse &matriu)
{
	out << "MATRIU DE (FILES: " << matriu.m_dimension << "  COLUMNES: " << matriu.m_dimension << " )" << endl;
	out << "VALORS (FILA::COL::VALOR)" << endl;
	for (auto it = matriu.m_coordenadas.begin(); it != matriu.m_coordenadas.end(); it++)
	{
		out << "( " << get<0>(*it) << " :: " << get<1>(*it) << " :: " << get<2>(*it) << " ) " << endl;
	}
	return out;
}
