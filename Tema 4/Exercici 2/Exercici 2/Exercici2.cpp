#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int posicioMinim(vector<int>& v, int indexInici, int indexFinal)
{
	int minimo = v[indexInici];
	int posicion = 0;

	for (int i = indexInici; i <= indexFinal; i++)
	{
		if (minimo >= v[i]) {
			minimo = v[i];
			posicion = i;
		}
	}
	return posicion;
}

void ordenaArray(vector<int>& v, int indexInici, int indexFinal)
{
	if (indexInici == indexFinal || v.empty())
		cout << "acabado";
	else {
		int posicion = posicioMinim(v, indexInici, indexFinal);
		swap(v[indexInici], v[posicion]);
		ordenaArray(v, indexInici + 1, indexFinal);
	}

	/*for (int i = 0; i < v.size(); ++i) {
		int min = i;
		for (int c = i ; c < v.size(); ++c) {
			if (v[min] > v[c]) min = c;
		}
		int aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}*/
}

