#include "MatriuSparse.h"


int main()
{

	try
	{
		float grade = 0.0;
		bool valid = true;

		cout << "Comment :=>> ==========================================" << endl;
		cout << "Comment :=>> TEST SOBRE XARXA1 ....................... " << endl;

		string nomFitxer = "Xarxa1.txt";

		cout << "Comment :=>> LLEGINT I CREANT XARXA1 ....................... " << endl;
		MatriuSparse m1(nomFitxer);

		cout << "Comment :=>> ESCRIVINT XARXA1 ....................... " << endl;
		cout << m1;

		cout << "Comment :=>> AFEGINT 7 a posicio (0,2) ....................... " << endl;
		m1.setVal(0, 2, 7);
		cout << "Comment :=>> AFEGINT 8 a posicio (8,1) ....................... " << endl;
		m1.setVal(8, 1, 8);
		cout << "Comment :=>> AFEGINT 9 a posicio (5,9) ....................... " << endl;
		m1.setVal(5, 9, 9);

		cout << "Comment :=>> ESCRIVINT XARXA1 ....................... " << endl;
		cout << m1;

		float valor;
		bool trobat = m1.getVal(0, 0, valor);
		if (trobat)
			if (valor == 0)
			{
				cout << "Comment :=>> OK VAL(0,0): " << valor << endl;
				grade++;
			}
			else
			{
				cout << "Comment :=>> OK EXISTEIX VAL(0,0): Pero ERROR val " << valor << " Valor correcte 0" << endl;
				valid = false;
			}
		else
		{
			cout << "Comment :=>> ERROR VAL(0,0): NO EXISTEIX. HAURIA D'EXISTIR i VALOR=0" << endl;
			valid = false;
		}

		trobat = m1.getVal(3, 2, valor);
		if (trobat)
			if (valor == 1)
			{
				cout << "Comment :=>>OK VAL(3,2): " << valor << endl;
				grade++;
			}
			else
			{
				cout << "Comment :=>>OK EXISTEIX VAL(3,2): Pero ERROR val " << valor << " Valor correcte 1" << endl;
				valid = false;
			}
		else
		{
			cout << "Comment :=>>VAL(3,2): ERROR NO EXISTEIX. HAURIA D'EXISTIR i VALOR=1" << endl;
			valid = false;
		}

		trobat = m1.getVal(0, 2, valor);
		if (trobat)
			if (valor == 7)
			{
				cout << "Comment :=>> OK VAL(0,2): " << valor << endl;
				grade++;
			}
			else
			{
				cout << "Comment :=>>OK EXISTEIX VAL(0,2): Pero ERROR val " << valor << " Valor correcte 7" << endl;
				valid = false;
			}
		else
		{
			cout << "Comment :=>>VAL(0,2): ERROR NO EXISTEIX. HAURIA D'EXISTIR i VALOR=7" << endl;
			valid = false;
		}

		trobat = m1.getVal(8, 1, valor);
		if (trobat)
			if (valor == 8)
			{
				cout << "Comment :=>> OK VAL(8,1): " << valor << endl;
				grade++;
			}
			else
			{
				cout << "Comment :=>>OK EXISTEIX VAL(8,1): Pero ERROR val " << valor << " Valor correcte 8" << endl;
				valid = false;
			}
		else
		{
			cout << "Comment :=>>VAL(8,1): ERROR NO EXISTEIX. HAURIA D'EXISTIR i VALOR=8" << endl;
			valid = false;
		}

		trobat = m1.getVal(9, 2, valor);
		if (trobat)
		{
			cout << "Comment :=>>VAL(9,2): " << valor << " . ERROR NO HAURIA D'EXISTIR" << endl;
			valid = false;
		}
		else
		{
			cout << "Comment :=>>VAL(9,2): OK NO EXISTEIX" << endl;
			grade++;
		}

		trobat = m1.getVal(4, 10, valor);
		if (trobat)
		{
			cout << "Comment :=>>VAL(4,10): " << valor << " . ERROR NO HAURIA D'EXISTIR" << endl;
			valid = false;
		}
		else
		{
			cout << "Comment :=>>VAL(4,10): OK NO EXISTEIX" << endl;
			grade++;
		}

		if (valid)
			cout << "Comment :=>> Final del test XARXA1 sense errors" << endl;
		if (grade < 0)
			grade = 0;
		cout << endl << "Comment :=>> Grade : " << grade << endl;

		cout << "Comment :=>> ==========================================" << endl;
		cout << "Comment :=>> TEST SOBRE SubEpinions2 ....................... " << endl;

		string nomFitxerRels2 = "SubEpinions2.txt";

		cout << "Comment :=>> LLEGINT I CREANT SubEpinions2 ....................... " << endl;
		MatriuSparse m2(nomFitxerRels2);

		cout << "Comment :=>> ESCRIVINT SubEpinions2 ....................... " << endl;
		cout << m2;

		cout << "Comment :=>> AFEGINT 7 a posicio (0,2) ....................... " << endl;
		m2.setVal(0, 2, 7);
		cout << "Comment :=>> AFEGINT 8 a posicio (8,1) ....................... " << endl;
		m2.setVal(8, 1, 8);
		cout << "Comment :=>> AFEGINT 9 a posicio (5,9) ....................... " << endl;
		m2.setVal(5, 9, 9);

		cout << "Comment :=>> ESCRIVINT SubEpinions2 ....................... " << endl;
		cout << m2;


		trobat = m2.getVal(0, 0, valor);
		if (trobat)
			if (valor == 0)
			{
				cout << "Comment :=>> OK VAL(0,0): " << valor << endl;
				grade++;
			}
			else
			{
				cout << "Comment :=>> OK EXISTEIX VAL(0,0): Pero ERROR val " << valor << " Valor correcte 0" << endl;
				valid = false;
			}
		else
		{
			cout << "Comment :=>> ERROR VAL(0,0): NO EXISTEIX. HAURIA D'EXISTIR i VALOR=0" << endl;
			valid = false;
		}

		trobat = m2.getVal(3, 2, valor);
		if (trobat)
			if (valor == 0)
			{
				cout << "Comment :=>>OK VAL(3,2): " << valor << endl;
				grade++;
			}
			else
			{
				cout << "Comment :=>>OK EXISTEIX VAL(3,2): Pero ERROR val " << valor << " Valor correcte 1" << endl;
				valid = false;
			}
		else
		{
			cout << "Comment :=>>VAL(3,2): ERROR NO EXISTEIX. HAURIA D'EXISTIR i VALOR=1" << endl;
			valid = false;
		}

		trobat = m2.getVal(0, 2, valor);
		if (trobat)
			if (valor == 7)
			{
				cout << "Comment :=>> OK VAL(0,2): " << valor << endl;
				grade++;
			}
			else
			{
				cout << "Comment :=>>OK EXISTEIX VAL(0,2): Pero ERROR val " << valor << " Valor correcte 7" << endl;
				valid = false;
			}
		else
		{
			cout << "Comment :=>>VAL(0,2): ERROR NO EXISTEIX. HAURIA D'EXISTIR i VALOR=7" << endl;
			valid = false;
		}

		trobat = m2.getVal(8, 1, valor);
		if (trobat)
			if (valor == 8)
			{
				cout << "Comment :=>> OK VAL(8,1): " << valor << endl;
				grade++;
			}
			else
			{
				cout << "Comment :=>>OK EXISTEIX VAL(8,1): Pero ERROR val " << valor << " Valor correcte 8" << endl;
				valid = false;
			}
		else
		{
			cout << "Comment :=>>VAL(8,1): ERROR NO EXISTEIX. HAURIA D'EXISTIR i VALOR=8" << endl;
			valid = false;
		}

		trobat = m2.getVal(30, 60000, valor);
		if (trobat)
		{
			cout << "Comment :=>>VAL(30,60000): " << valor << " . ERROR NO HAURIA D'EXISTIR" << endl;
			valid = false;
		}
		else
		{
			cout << "Comment :=>>VAL(30,60000): OK NO EXISTEIX" << endl;
			grade++;
		}

		trobat = m2.getVal(60000, 30, valor);
		if (trobat)
		{
			cout << "Comment :=>>VAL(60000,30): " << valor << " . ERROR NO HAURIA D'EXISTIR" << endl;
			valid = false;
		}
		else
		{
			cout << "Comment :=>>VAL(60000,30): OK NO EXISTEIX" << endl;
			grade++;
		}

		if (valid)
			cout << "Comment :=>> Final del test SUBEPINIONS2 sense errors" << endl;
		if (grade < 0)
			grade = 0;
		cout << endl << "Comment :=>> Grade : " << grade << endl;


		/*	cout << "Comment :=>> ==========================================" << endl;
			cout << "Comment :=>> TEST SOBRE EPINIONS ....................... " << endl;

			string nomFitxerRels = "Epinions.txt";

			cout << "Comment :=>> LLEGINT I CREANT Epinions ....................... " << endl;
			MatriuSparse m3(nomFitxerRels);

			cout << "Comment :=>> ESCRIVINT Epinions ....................... " << endl;
			cout << m3;

			cout << "Comment :=>> AFEGINT 7 a posicio (0,2) ....................... " << endl;
			m3.setVal(0, 2, 7);
			cout << "Comment :=>> AFEGINT 8 a posicio (8,1) ....................... " << endl;
			m3.setVal(8, 1, 8);
			cout << "Comment :=>> AFEGINT 9 a posicio (5,9) ....................... " << endl;
			m3.setVal(5, 9, 9);

			cout << "Comment :=>> ESCRIVINT Epinions ....................... " << endl;
			cout << m3;

			valor;
			trobat = m3.getVal(0, 0, valor);
			trobat = m3.getVal(0, 2, valor);
			trobat = m3.getVal(8, 1, valor);

			*/

		if (valid)
			cout << "Comment :=>> Final del test sense errors" << endl;
		if (grade < 0)
			grade = 0;
		cout << endl << "Grade :=>> " << grade << endl;
		system("pause");
		return 0;
	}
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	system("pause");
}