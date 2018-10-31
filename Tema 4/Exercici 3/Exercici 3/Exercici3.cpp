#include <list>
#include <iostream>

using namespace std;


int MaxElsRec(list<int> l, list<int>::iterator it)
{
	int max = 0;

	if (it != l.end())
	{
		if (*it > max)
		{
			max = *it;
			MaxElsRec(l, ++it);
		}
		return max;
	}
	else {
		return max;
	}
}

int MaxElementsLlista(list<int> &l)
{
	cout << "El maximo de la lista es: " << endl;
	int maximo = MaxElsRec(l, l.begin());
	return maximo;
	system("pause");
}
