#include "MatriuSparse.h"
#include <fstream>


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
			fichero >> valor;

			m_fil.push_back(fila);
			m_col.push_back(columna);
			m_val.push_back(valor);
		}
		fichero.close();
	}
	else {
		throw "No se ha podido leer el fichero.";
	}
}