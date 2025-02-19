#include "Comanda.h"
#include <signal.h>
#include <iostream>
#include <math.h>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

float testAfegeixProducte(Comanda& comanda)
{
	float reduccio = 0.0;
	const int NPROVES = 4;

	string codiTest[NPROVES] = { "prod_1", "prod_2", "prod_3", "prod_4" };
	int nUnitatsTest[NPROVES] = { 1, 10, 20, 1 };
	float preuTest[NPROVES] = { 100.0, 5.0, 10.0, 20.0 };
	bool validTest[NPROVES] = { true, true, true, false};

	cout << endl;
	cout << "Comment :=>> Iniciant test metode AFEGEIX_PRODUCTE" << endl;
	cout << "Comment :=>> =====================================" << endl;

	for (int p = 0; p < NPROVES; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p + 1 << endl;
		cout << "Comment :=>> Codi Producte: " << codiTest[p] << endl;
		cout << "Comment :=>> Num. unitats: " << nUnitatsTest[p] << endl;
		cout << "Comment :=>> Preu unitat: " << preuTest[p] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(validTest[p]); cout << endl;
		cout << "Comment :=>> ---" << endl;
		bool valid = comanda.afegeixProducte(codiTest[p], nUnitatsTest[p], preuTest[p]);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(valid); cout << endl;
		if (valid == validTest[p])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	return reduccio;
}

float testConsultaProducte(Comanda& comanda)
{
	float reduccio = 0.0;
	const int NPROVES = 5;

	string codiTest[NPROVES] = { "prod_1", "prod_2", "prod_3", "prod_4", "prod_5" };
	int nUnitatsTest[NPROVES] = { 1, 10, 20, 0, 0 };
	float preuTest[NPROVES] = { 100.0, 5.0, 10.0, 0.0, 0.0 };
	bool validTest[NPROVES] = { true, true, true, false, false };

	cout << endl;
	cout << "Comment :=>> Iniciant test metode CONSULTA_PRODUCTE" << endl;
	cout << "Comment :=>> (Assumeix funcionament correcte de afegir producte)" << endl;
	cout << "Comment :=>> ====================================================" << endl;

	for (int p = 0; p < NPROVES; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p + 1 << endl;
		cout << "Comment :=>> Codi Producte: " << codiTest[p] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(validTest[p]); cout << endl;
		if (validTest[p])
		{
			cout << "Comment :=>> Num. unitats esperat: " << nUnitatsTest[p] << endl;
			cout << "Comment :=>> Preu unitat esperat: " << preuTest[p] << endl;
		}
		cout << "Comment :=>> ---" << endl;
		int nUnitats;
		float preu;
		bool valid = comanda.consultaProducte(codiTest[p], nUnitats, preu);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(valid); cout << endl;
		if (valid)
		{
			cout << "Comment :=>> Num. habitacions obtingut: " << nUnitats << endl;
			cout << "Comment :=>> Preu obtingut: " << preu << endl;
		}
		if (valid == validTest[p])
		{
			if (valid)
				if ((nUnitats == nUnitatsTest[p]) &&
					(fabs(preu - preuTest[p]) < 0.1))
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
			else
				cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	return reduccio;
}


float testConsulta(Comanda& comanda)
{
	float reduccio = 0.0;

	cout << endl;
	cout << "Comment :=>> Iniciant test metodes de CONSULTA COMANDA" << endl;
	cout << "Comment :=>> =========================================" << endl;

	cout << "Comment :=>> Nom del client esperat: client_1" << endl;
	cout << "Comment :=>> Data de la comanda esperada: 01/01/2018" << endl;
	cout << "Comment :=>> Import esperat: 350.0" << endl;

	cout << "Comment :=>> ---" << endl;

	cout << "Comment :=>> Nom del client obtingut: " << comanda.getClient() << endl;
	Data data = comanda.getData();
	cout << "Comment :=>> Data de la comanda obtinguda: " << data.getDia() << "/" << data.getMes() << "/" << data.getAny() << endl;
	cout << "Comment :=>> Import obtingut: " << comanda.getImport() << endl;

	if ((comanda.getClient() == "client_1") && (data.getDia() == 1) && (data.getMes() == 1) && (data.getAny() == 2018) &&
		(fabs(comanda.getImport() - 350.0) < 0.1))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 2.0;
	}
	return reduccio;
}


float testConstructorCopia(Comanda& comanda)
{
	float reduccio = 0.0;

	cout << endl;
	cout << "Comment :=>> Iniciant test constructor COPIA" << endl;
	cout << "Comment :=>> ===============================" << endl;

	cout << endl << "Comment :=>> Inicialitzant nou objecte Comanda amb constructor de copia....." << endl;

	Comanda copia(comanda);

	cout << endl << "Comment :=>> Iniciant test metodes de CONSULTA COMANDA a l'objecte inicialitzat amb la copia....." << endl;
	reduccio += testConsulta(copia);

	cout << endl << "Comment :=>> Iniciant test metode CONSULTA PRODUCTE a l'objecte inicialitzat amb la copia....." << endl;
	reduccio += testConsultaProducte(copia);

	return reduccio;
}

float testOperadorAssignacio(Comanda& comanda)
{
	float reduccio = 0.0;

	cout << endl;
	cout << "Comment :=>> Iniciant test operador ASSIGNACIO" << endl;
	cout << "Comment :=>> =================================" << endl;

	cout << endl << "Comment :=>> Inicialitzant nou objecte Comanda amb operador assignacio....." << endl;

	Comanda assignacio("", Data(1, 1, 2018), 0);

	assignacio = comanda;

	cout << endl << "Comment :=>> Iniciant test metodes de CONSULTA COMANDA a l'objecte inicialitzat amb l'assignacio....." << endl;
	reduccio += testConsulta(assignacio);

	cout << endl << "Comment :=>> Iniciant test metode CONSULTA PRODUCTE a l'objecte inicialitzat amb l'assignacio....." << endl;
	reduccio += testConsultaProducte(assignacio);

	return reduccio;
}

int main()
{
	float grade = 0.0;
	float reduccio;

	Data data(1, 1, 2018);
	Comanda comanda("client_1", data, 3);

	cout << endl;
	cout << "Comment :=>> Cridant al constructor de Comandes per inicialitzar dades de la comanda....." << endl;
	cout << "Comment :=>> ============================================================================" << endl;
	cout << "Comment :=>> Nom del client: client_1" << endl;
	cout << "Comment :=>> Data de la comanda: 01/01/2018" << endl;
	cout << "Comment :=>> Num. productes: 3" << endl;

	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testAfegeixProducte(comanda);

	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	if (reduccio > 2.0)
		reduccio = 2.0;
	reduccio = testConsulta(comanda);
	grade += (1.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;  

	reduccio = testConsultaProducte(comanda);
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testConstructorCopia(comanda);
	if (reduccio > 4.0)
		reduccio = 4.0;
	grade += (2.5 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testOperadorAssignacio(comanda);
	if (reduccio > 4.0)
		reduccio = 4.0;
	grade += (2.5 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;


	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}