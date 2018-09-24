#pragma once

class Data
{
private:
	int m_dia;
	int m_mes;
	int m_any;

public:
	Data();
	~Data();
	Data(int dia, int mes, int any);
	Data(const Data& c);
	Data operator+(const int dias);
	bool operator==(const Data fecha);
	bool operator<(const Data fecha);



	int getDia() const;
	int getMes() const;
	int getAny() const;
	
	void setDia(int dia);
	void setMes(int mes);
	void setAny(int any);

	bool dataValida();
};
