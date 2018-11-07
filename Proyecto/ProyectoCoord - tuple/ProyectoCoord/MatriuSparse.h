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
	int getNFiles() { return m_dimension; };
	int getNColumnes() { return m_dimension; };
	void init(int filas, int columnas);

	MatriuSparse& operator=(const MatriuSparse& c);
	vector<float>& operator=(const vector<float>& v);
	friend ostream& operator<<(ostream& out, const MatriuSparse& r);

	MatriuSparse& operator*(const int valor);
	vector<float>& operator*(const vector<float> v1);

	MatriuSparse& operator/(const int valor);


private:
	vector<tuple<int,int,float>> m_coordenadas;
	int m_dimension;
};