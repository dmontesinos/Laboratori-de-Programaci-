#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "Tree.hpp"
#include <vector>
#include <string>
#include <iostream>
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

	friend ostream& operator<<(ostream& out, const MatriuSparse& r);

	MatriuSparse& operator*(int valor);
	vector<float>& operator*(vector<float> &v1);

	MatriuSparse& operator/(const int valor);
	//Nuevo codigo
	//------------
	void clear();
	//int getNValues() const { return _Valors.size(); }// Mirar si matriz Bidireccional y si es asi /2
	int getNValues() const { return m_coordenadas.size(); };
	void calculaGrau(vector<int>& graus) const;
	void creaMaps(vector<map<pair<int, int>, double>>& vMaps, vector<pair<int,int>>&indexComs) const;
	void calculaDendrograms(vector<Tree<double>*>& vDendograms) const;
	

private:
	vector<tuple<int, int, float>> m_coordenadas;
	int m_dimension;
};

