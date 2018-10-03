#include "Matriu.h"
#include <math.h>
#include <iostream>
using namespace std;

const int MAX_ELEMENTS = 3;

void escriuValors(float valors[][MAX_ELEMENTS], int nFiles, int nColumnes)
{
	cout << endl << "[" << endl;
	for (int i = 0; i < nFiles; i++)
	{
		cout << "[";
		for (int j = 0; j < nColumnes; j++)
			cout << valors[i][j] << " ";
		cout << "]" << endl;
	}
	cout << "]" << endl;
}

void escriuValorsMatriu(const Matriu& m)
{
	cout << endl << "[" << endl;
	for (int i = 0; i < m.getNFiles(); i++)
	{
		cout << "[";
		for (int j = 0; j < m.getNColumnes(); j++)
			cout << m(i,j) << " ";
		cout << "]" << endl;
	}
	cout << "]" << endl;
}

void initMatriu(Matriu& m, float valors[][MAX_ELEMENTS])
{
	for (int i = 0; i < m.getNFiles(); i++)
		for (int j = 0; j < m.getNColumnes(); j++)
			m(i, j) = valors[i][j];
}

bool comparaMatriu(Matriu& m, float valors[][MAX_ELEMENTS], int nFiles, int nColumnes)
{
	bool iguals = !m.esBuida() && (m.getNFiles() == nFiles) && (m.getNColumnes() == nColumnes);
	int i = 0;
	while (iguals && (i < m.getNFiles()))
	{
		int j = 0;
		while (iguals && (j < m.getNColumnes()))
		{
			if (fabs(m(i, j) - valors[i][j]) > 0.1)
				iguals = false;
			else
				j++;
		}
		i++;
	}
	return iguals;
}

float testMultiplicacioMatriu()
{
	const int N_PROVES = 4;
	const int MAX_ELEMENTS = 3;
	float reduccio = 0;

	float matriu1Test[N_PROVES][MAX_ELEMENTS][MAX_ELEMENTS] =
	{
		{
			{1, 1, 1},
			{2, 2, 2}
		},
		{
			{1, 1},
			{2, 2},
			{3, 3}
		},
		{
			{1, 1, 1},
			{2, 2, 2},
			{3, 3, 3}
		},
		{
			{ 1, 1, 1 },
			{ 2, 2, 2 }
		}
	};
	float matriu2Test[N_PROVES][MAX_ELEMENTS][MAX_ELEMENTS] =
	{
		{
			{ 1, 1 },
			{ 2, 2 },
			{ 3, 3 }
		},
		{
			{ 1, 1, 1 },
			{ 2, 2, 2 }
		},
		{
			{ 1, 1, 1 },
			{ 2, 2, 2 },
			{ 3, 3, 3 }
		},
		{
			{ 1, 1, 1 },
			{ 2, 2, 2 }
		}
	};
	int dimensionsMatriu1Test[N_PROVES][2] = { {2, 3}, {3, 2}, {3, 3}, {2, 3} };
	int dimensionsMatriu2Test[N_PROVES][2] = { { 3, 2 },{ 2, 3 },{ 3, 3 },{ 2, 3 } };
	float resultatTest[N_PROVES][MAX_ELEMENTS][MAX_ELEMENTS] =
	{
		{
			{ 6, 6 },
			{ 12, 12 },
		},
		{
			{ 3, 3, 3 },
			{ 6, 6, 6 },
			{ 9, 9, 9 }
		},
		{
			{ 6, 6, 6 },
			{ 12, 12, 12 },
			{ 18, 18, 18 }
		},
		{
			{ },
			{ }
		}
	};
	int dimensionsResultatTest[N_PROVES][2] = { { 2, 2 },{ 3, 3 },{ 3, 3 },{ 0, 0 } };

	cout << endl;
	cout << "Comment :=>> Iniciant test MULTIPLICACIO DUES MATRIUS" << endl;
	cout << "Comment :=>> (Assumeix funcionament correcte operador (), getNFiles i getNColumnes)" << endl;
	cout << "Comment :=>> ======================================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		Matriu m1(dimensionsMatriu1Test[i][0], dimensionsMatriu1Test[i][1]);
		Matriu m2(dimensionsMatriu2Test[i][0], dimensionsMatriu2Test[i][1]);

		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Inicialitzant Matrius................ " << endl;
		cout << "Comment :=>> Valors de la primera matriu: ";
		escriuValors(matriu1Test[i], dimensionsMatriu1Test[i][0], dimensionsMatriu1Test[i][1]);
		cout << "Comment :=>> Valors de la segona matriu: ";
		escriuValors(matriu2Test[i], dimensionsMatriu2Test[i][0], dimensionsMatriu2Test[i][1]);
		initMatriu(m1, matriu1Test[i]);
		initMatriu(m2, matriu2Test[i]);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Realitzant multiplicacio....................... " << endl;
		Matriu resultat = m1 * m2;
		cout << "Comment :=>> Resultat esperat: "; 
		escriuValors(resultatTest[i], dimensionsResultatTest[i][0], dimensionsResultatTest[i][1]);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat obtingut: "; 
		escriuValorsMatriu(resultat); 

		if (dimensionsResultatTest[i][0] != 0)
		{
			bool correcte = comparaMatriu(resultat, resultatTest[i], dimensionsResultatTest[i][0], dimensionsResultatTest[i][1]);
			if (correcte)
			{
				cout << "Comment :=>> CORRECTE" << endl;
			}
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}

		}
		else
		{
			if (resultat.esBuida())
				cout << "Comment :=>> CORRECTE" << endl;
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
			cout << "Comment :=>> -----------------------------------------------" << endl;
		}
	}
	return reduccio;
}

float testMultiplicacioEscalar()
{
	const int N_PROVES = 3;
	const int MAX_ELEMENTS = 3;
	float reduccio = 0;

	float matriuTest[N_PROVES][MAX_ELEMENTS][MAX_ELEMENTS] =
	{
		{
			{ 1, 1, 1 },
			{ 2, 2, 2 }
		},
		{
			{ 1, 1 },
			{ 2, 2 },
			{ 3, 3 }
		},
		{
			{ 1, 1, 1 },
			{ 2, 2, 2 },
			{ 3, 3, 3 }
		},
	};
	float valorTest[N_PROVES] = { 2, -1, 0 };
	int dimensionsMatriuTest[N_PROVES][2] = { { 2, 3 },{ 3, 2 },{ 3, 3 } };
	float resultatTest[N_PROVES][MAX_ELEMENTS][MAX_ELEMENTS] =
	{
		{
			{ 2, 2, 2 },
			{ 4, 4, 4 }
		},
		{
			{ -1, -1 },
			{ -2, -2 },
			{ -3, -3 }
		},
		{
			{ 0, 0, 0 },
			{ 0, 0, 0 },
			{ 0, 0, 0 }
		},
	};
	int dimensionsResultatTest[N_PROVES][2] = { { 2, 3 },{ 3, 2 },{ 3, 3 } };

	cout << endl;
	cout << "Comment :=>> Iniciant test MULTIPLICACIO PER UN VALOR ESCALAR" << endl;
	cout << "Comment :=>> (Assumeix funcionament correcte operador (), getNFiles i getNColumnes)" << endl;
	cout << "Comment :=>> ======================================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		Matriu m(dimensionsMatriuTest[i][0], dimensionsMatriuTest[i][1]);

		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Inicialitzant Matriu................ " << endl;
		cout << "Comment :=>> Valors de la matriu: ";
		escriuValors(matriuTest[i], dimensionsMatriuTest[i][0], dimensionsMatriuTest[i][1]);
		cout << "Comment :=>> Valors escalar a multiplicar: " << valorTest[i] << endl;;
		initMatriu(m, matriuTest[i]);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Realitzant multiplicacio....................... " << endl;
		Matriu resultat = m * valorTest[i];
		cout << "Comment :=>> Resultat esperat: ";
		escriuValors(resultatTest[i], dimensionsResultatTest[i][0], dimensionsResultatTest[i][1]);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat obtingut: ";
		escriuValorsMatriu(resultat);

		bool correcte = comparaMatriu(resultat, resultatTest[i], dimensionsResultatTest[i][0], dimensionsResultatTest[i][1]);
		if (correcte)
		{
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


float testOperadorAssignacio()
{
	float reduccio = 0;

	float matriuTest[MAX_ELEMENTS][MAX_ELEMENTS] =
	{
		{ 1, 1, 1 },
		{ 2, 2, 2 }
	};
	int dimensionsMatriuTest[2] = { 2, 3 };
	cout << endl;
	cout << "Comment :=>> Iniciant test operador ASSIGNACIO" << endl;
	cout << "Comment :=>> (Assumeix funcionament correcte operador (), getNFiles i getNColumnes)" << endl;
	cout << "Comment :=>> ======================================================================" << endl;

	Matriu *m1 = new Matriu;
	Matriu m2;
	cout << "Comment :=>> Creant i inicialitzant matriu inicial................ " << endl;
	cout << "Comment :=>> Valors de la matriu: ";
	escriuValors(matriuTest, dimensionsMatriuTest[0], dimensionsMatriuTest[1]); 
	m1->init(dimensionsMatriuTest[0], dimensionsMatriuTest[1]);
	initMatriu(*m1, matriuTest);
	cout << "Comment :=>> Fent copia de la matriu inicial amb operador assignacio................ " << endl;
	m2 = *m1;
	cout << "Comment :=>> Destruint matriu inicial................ " << endl;
	delete m1;
	cout << "Comment :=>> Valors la matriu obtinguda amb la copia: ";  
	escriuValorsMatriu(m2); cout << endl;

	bool correcte = comparaMatriu(m2, matriuTest, dimensionsMatriuTest[0], dimensionsMatriuTest[1]);
	if (correcte)
	{
		cout << "Comment :=>> CORRECTE" << endl;
	}
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;
	return reduccio;
}

float testConstructorCopia()
{
	float reduccio = 0;

	float matriuTest[MAX_ELEMENTS][MAX_ELEMENTS] =
	{
		{ 1, 1, 1 },
		{ 2, 2, 2 }
	};
	int dimensionsMatriuTest[2] = { 2, 3 };
	cout << endl;
	cout << "Comment :=>> Iniciant test CONSTRUCTOR COPIA" << endl;
	cout << "Comment :=>> (Assumeix funcionament correcte operador (), getNFiles i getNColumnes)" << endl;
	cout << "Comment :=>> ======================================================================" << endl;

	Matriu *m1 = new Matriu;
	cout << "Comment :=>> Creant i inicialitzant matriu inicial................ " << endl;
	cout << "Comment :=>> Valors de la matriu: ";
	escriuValors(matriuTest, dimensionsMatriuTest[0], dimensionsMatriuTest[1]);
	m1->init(dimensionsMatriuTest[0], dimensionsMatriuTest[1]);
	initMatriu(*m1, matriuTest);
	cout << "Comment :=>> Fent copia de la matriu inicial amb constructor copia................ " << endl;
	Matriu m2(*m1);
	cout << "Comment :=>> Destruint matriu inicial................ " << endl;
	delete m1;
	cout << "Comment :=>> Valors la matriu obtinguda amb la copia: ";
	escriuValorsMatriu(m2); cout << endl;

	bool correcte = comparaMatriu(m2, matriuTest, dimensionsMatriuTest[0], dimensionsMatriuTest[1]);
	if (correcte)
	{
		cout << "Comment :=>> CORRECTE" << endl;
	}
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;
	return reduccio;
}

int main()
{
	bool valid = true;
	float grade = 0;
	float reduccio;

	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testMultiplicacioMatriu();
	if (reduccio > 5.0)
		reduccio = 5.0;
	grade += (4.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testMultiplicacioEscalar();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testOperadorAssignacio();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testConstructorCopia();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;


	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	system("pause");

	return 0;
}

