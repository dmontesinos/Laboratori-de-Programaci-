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
		/*if (fila > max)
				max = fila;
			if (columna > max)
				max = columna;*/
			
			m_coordenadas.push_back(tuple<int,int,float>(fila, columna,1));

		}
		fichero.close();

		for (auto it = m_coordenadas.begin(); it != m_coordenadas.end(); it++)
		{
			if (get<0>(*it) > max)
				max = get<0>(*it);
			if (get<1>(*it) > max)
				max = get<1>(*it);
		}
		
		m_matriz.resize(max+1);
		for (int i = 0; i < m_matriz.size(); i++)
		{
			m_matriz[i].resize(max + 1);
		}
		
		for (auto it = m_coordenadas.begin(); it != m_coordenadas.end(); it++)
		{
			//cout << it->first << " " << it->second << endl;
			m_matriz[get<0>(*it)][get<1>(*it)] = 1;
		}


		/*m_matriz.resize(max+1);
		for (int i = 0; i < m_matriz.size(); i++)
		{
			m_matriz[i].resize(max+1);
		}
		
		for (auto it = m_coordenadas.begin(); it != m_coordenadas.end(); it++)
		{
			m_matriz[it->first][it->second] = 1;
		}*/
	}
	else {
		throw "No se ha podido leer el fichero.";
	}
}

MatriuSparse::MatriuSparse(int filas, int columnas)
{
	vector<vector<float>> m_matriz(filas, vector<float>(columnas,0));
}

MatriuSparse::MatriuSparse(const MatriuSparse &c)
{
	
	//vector<vector<float>> newMatriz(c.m_matriz.size(), vector<float>(c.m_matriz.size()));
}

MatriuSparse& MatriuSparse::operator=(const MatriuSparse& c)
{
	cout << this->getNColumnes();
	m_coordenadas = c.m_coordenadas;
	m_matriz = c.m_matriz;

	return *this;
}

/*MatriuSparse & MatriuSparse::operator*(const MatriuSparse & m)
{
	int files = this->getNFiles();
	int columnes = m.getNColumnes;
	MatriuSparse matriu(files, columnes);

	if (this->getNColumnes() == m.getNFiles)
	{
		for (int i = 0; i < this->getNFiles(); i++)
		{
			for (int j = 0; j < m.getNColumnes; j++)
			{
				for (int x = 0; x < this->getNColumnes(); x++)
				{
					matriu.m_matriz[i][j] += m_matriz[i][x] * m.m_matriz[x][j];
				}
			}
		}
		return matriu;
	}
	else {
		MatriuSparse matriu2(0, 0);
		return matriu2;
	}
}*/

MatriuSparse& MatriuSparse::operator*(const int valor)
{
	MatriuSparse aux(this->m_matriz.size(), this->m_matriz.size());
	aux.m_matriz = this->m_matriz;
	aux.m_coordenadas = this->m_coordenadas;

	cout << aux.m_matriz.size() << endl;
	cout << aux.getNFiles() << endl;
	cout << aux.getNColumnes() << endl;

	for(int i = 0; i < aux.m_matriz.size(); i++)
		for (int j = 0; j < aux.m_matriz[i].size(); j++)
		{
			aux.m_matriz[i][j] = this->m_matriz[i][j];
			aux.m_matriz[i][j] *= valor;
		}
	*this = aux;
	return aux;
}

MatriuSparse & MatriuSparse::operator/(const int valor)
{
	MatriuSparse matriz(this->getNFiles(), this->getNColumnes());

	for (int i = 0; i < matriz.m_matriz.size(); i++)
		for (int j = 0; j < matriz.m_matriz[i].size(); j++)
		{
			matriz.m_matriz[i][j] = this->m_matriz[i][j];
			matriz.m_matriz[i][j] /= valor;
		}
	return matriz;
}

void MatriuSparse::init(int filas, int columnas)
{
	vector<vector<float>> m_matriz(filas, vector<float>(columnas));
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
	
	m_coordenadas.push_back(tuple<int,int,float>(fila, columna,valor));
	m_matriz[fila][columna] = valor;
}

bool MatriuSparse::getVal(int fila, int columna, float &valor)
{
	/*bool encontrado = false;

	for (auto it = m_coordenadas.begin(); it != m_coordenadas.end(); it++)
		if (it->first == fila && it->second == columna)
		{
			encontrado = true;
			int posicion = distance(m_coordenadas.begin(), it);
			valor = m_val[posicion];
		}

	return encontrado;*/

	
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

	out << "MATRIU DE (FILES: " << m_auxiliar.size() << "  COLUMNES: " << m_auxiliar[0].size() << " )" << endl;
	out << "VALORS (FILA::COL::VALOR)" << endl;
	for (int fila = 0; fila < matriu.m_matriz.size(); fila++)
	{
		for (int columna = 0; columna < matriu.m_matriz.size(); columna++)
		{
			if (m_auxiliar[fila][columna] != 0) {
				out << "( " << fila << " :: " << columna << " :: " << m_auxiliar[fila][columna] << " ) " << endl;
			}
		}
	}
	return out;
}
/*ostream &operator<<(ostream &out, const MatriuSparse &matriu)
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
}*/
