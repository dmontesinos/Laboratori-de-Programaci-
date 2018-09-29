#pragma once


class Matriu
{
public:
	Matriu();
	Matriu(int nFiles, int nColumnes);
	Matriu(const Matriu& m);
	~Matriu();

	Matriu& operator=(const Matriu& m);
	void init(int nFiles, int nColumnes);
	void setValor(float valor);
	Matriu operator*(const Matriu& m);
	Matriu operator*(float s);

	bool esBuida() const;
	int getNFiles() const;
	int getNColumnes() const;
	float& operator()(int fila, int columna);
private:
	int m_nFiles;
	int m_nColumnes;
};