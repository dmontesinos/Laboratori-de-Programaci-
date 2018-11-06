#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <tuple>
using namespace std;

class MatriuSparse {
public:
	MatriuSparse() {};
	~MatriuSparse() {};

	MatriuSparse(const string &fichero);
	MatriuSparse(int filas, int columnas);
	MatriuSparse(const MatriuSparse &c);

	void setVal(int fila, int columna, float valor);
	bool getVal(int fila, int columna, float &valor);
	int getNFiles() { return m_matriz.size(); };
	int getNColumnes() { return m_matriz[0].size(); };

	MatriuSparse& operator=(const MatriuSparse& c);
	friend ostream& operator<<(ostream& out, const MatriuSparse& r);

	//MatriuSparse& operator*(const MatriuSparse& m); //No necesario
	MatriuSparse& operator*(const int valor);

	MatriuSparse& operator/(const int valor);

	void init(int filas, int columnas);

private:
	//vector<tuple<int,int,float>> m_coordenadas;
	vector <vector<float>> m_matriz;
};