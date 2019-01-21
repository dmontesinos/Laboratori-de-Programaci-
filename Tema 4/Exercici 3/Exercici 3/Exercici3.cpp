#include <list>
#include <iostream>

using namespace std;


int MaxElsRec(list<int>& l, list<int>::iterator it, int &max)
{
	if (it != l.end())
	{
		if (*it > max)
		{
			max = *it;
		}
		return MaxElsRec(l, ++it, max);
	}
	else {
		return max;
	}
}

int MaxElementsLlista(list<int>& l)
{
	cout << "El maximo de la lista es: " << endl;
	int max = 0;
	int maximo = MaxElsRec(l, l.begin(), max);
	return maximo;
	system("pause");
}
