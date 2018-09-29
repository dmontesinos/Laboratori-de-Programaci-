#include "Matriu.h"

Matriu::Matriu() {
	int **matriu;
}

Matriu::~Matriu() {

}

Matriu::Matriu(int nFiles, int nColumnes)
{
	int fila_dinamica;
	int columna_dinamica;

	int **matriu = new int*[nFiles];
	
	for (int i = 0; i < nColumnes; i++)
	{
		matriu[i] = new int[nColumnes];
	}
}