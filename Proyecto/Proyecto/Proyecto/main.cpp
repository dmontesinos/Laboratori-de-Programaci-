//PRUEBA 1
/*#include <string>
#include <iostream>
using namespace std;
#include "Matriu.h"
int main()
{
	try
	{
		string nomFitxer = "Xarxa1.txt";
		Matriu m(nomFitxer, 8, 8);
	}
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
	}
	return 0;
}*/



//PRUEBA 2
#include <string>
#include <iostream>
using namespace std;
#include "Matriu.h"
int main()
{
	try
	{
		string nomFitxerRels = "Epinions.txt";//mida 75877
		Matriu m(nomFitxerRels, 75877, 75877);
	}
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
	}
	return 0;
}