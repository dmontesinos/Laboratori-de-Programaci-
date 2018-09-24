#include "Data.h"
#include <iostream>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

float testDataValida()
{
	float reduccio = 0.0;
	const int NPROVES = 11;

	int dataTest[NPROVES][3] =
	{
		{ 1, 1, 2015 },
		{ 31, 3, 2016 },
		{ 30, 4, 2017 },
		{ 28, 2, 2018 },
		{ 31, 12, 2018},
		{ 0, 1, 2018},
		{ 32, 1, 2018},
		{ 29, 2, 2018},
		{ 31, 4, 2018},
		{ 1, 0, 2018},
		{ 1, 13, 2018} 
	};

	bool validTest[NPROVES] = { true, true, true, true, true, false, false, false, false, false, false };

	cout << endl;
	cout << "Comment :=>> Iniciant test metode DATA VALIDA" << endl;
	cout << "Comment :=>> ================================" << endl;

	for (int p = 0; p < NPROVES; p++)
	{
		Data data;
		data.setDia(dataTest[p][0]);
		data.setMes(dataTest[p][1]);
		data.setAny(dataTest[p][2]);
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p + 1 << endl;
		cout << "Comment :=>> Data: " << data.getDia() << "/" << data.getMes() << "/" << data.getAny() << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(validTest[p]); cout << endl;
		cout << "Comment :=>> ---" << endl;
		bool valid = data.dataValida();
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(valid); cout << endl;
		if (valid == validTest[p])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testSumaDies()
{
	float reduccio = 0.0;
	const int NPROVES = 8;

	Data dataTest[NPROVES] =
	{
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 20, 12, 2018},
		{ 10, 1, 2018 }
	};

	int nDiesTest[NPROVES] = { 0, 1, 21, 31, 59, 90, 31, 365 };

	Data resultatTest[NPROVES] =
	{
		{ 10, 1, 2018 },
		{ 11, 1, 2018 },
		{ 31, 1, 2018 },
		{ 10, 2, 2018 },
		{ 10, 3, 2018 },
		{ 10, 4, 2018 },
		{ 20, 1, 2019 },
		{ 10, 1, 2019 }
	};

	cout << endl;
	cout << "Comment :=>> Iniciant test OPERADOR SUMA +" << endl;
	cout << "Comment :=>> =============================" << endl;

	for (int p = 0; p < NPROVES; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p + 1 << endl;
		cout << "Comment :=>> Data: " << dataTest[p].getDia() << "/" << dataTest[p].getMes() << "/" << dataTest[p].getAny() << endl;
		cout << "Comment :=>> Numero de dies: " << nDiesTest[p] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: " << resultatTest[p].getDia() << "/" << resultatTest[p].getMes() << "/" << resultatTest[p].getAny() << endl;
		cout << "Comment :=>> ---" << endl;
		Data resultat = dataTest[p] + nDiesTest[p];
		cout << "Comment :=>> Valor retorn obtingut: " << resultat.getDia() << "/" << resultat.getMes() << "/" << resultat.getAny() << endl;
		cout << "Comment :=>> Comparant dates amb la implementacio de l'operador == ..........." <<  endl;
		if (resultat == resultatTest[p])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 4.0)
		reduccio = 4.0;
	return reduccio;
}

float testComparacioDatesMenor()
{
	float reduccio = 0.0;
	const int NPROVES = 8;

	Data dataTest1[NPROVES] =
	{
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 }
	};

	Data dataTest2[NPROVES] =
	{
		{ 10, 6, 2018 },
		{ 11, 6, 2018 },
		{ 9, 6, 2018 },
		{ 10, 7, 2018 },
		{ 9, 7, 2018 },
		{ 11, 5, 2018 },
		{ 1, 1, 2019 },
		{ 12, 7, 2017 },
	};


	int resultatTest[NPROVES] = { false, true, false, true, true, false, true, false};


	cout << endl;
	cout << "Comment :=>> Iniciant test OPERADOR COMPARACIO <" << endl;
	cout << "Comment :=>> ===================================" << endl;

	for (int p = 0; p < NPROVES; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p + 1 << endl;
		cout << "Comment :=>> Data 1: " << dataTest1[p].getDia() << "/" << dataTest1[p].getMes() << "/" << dataTest1[p].getAny() << endl;
		cout << "Comment :=>> Data 2: " << dataTest2[p].getDia() << "/" << dataTest2[p].getMes() << "/" << dataTest2[p].getAny() << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat: ";  mostraBool(resultatTest[p]); cout << endl;
		cout << "Comment :=>> ---" << endl;
		bool resultat = dataTest1[p] < dataTest2[p];
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat == resultatTest[p])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

int main()
{
	float grade = 10.0;

	grade -= testDataValida();
	grade -= testSumaDies();
	grade -= testComparacioDatesMenor();

	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	system("pause");
	return 0;
}