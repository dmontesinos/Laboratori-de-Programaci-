#include "Data.h"


Data::Data()
{

}

Data::~Data()
{

}

Data::Data(int dia, int mes, int any)
{
	m_dia = dia;
	m_mes = mes;
	m_any = any;
}

Data::Data(const Data& c)
{
	m_dia = c.m_dia;
	m_mes = c.m_mes;
	m_any = c.m_any;
}

Data Data::string2date(string data) const
{
	Data convData;

	std::string dia = data.substr(0, 2);
	std::string mes = data.substr(2, 2);
	std::string any = data.substr(5, 4);

	convData.setDia(std::stoi(dia));
	convData.setMes(std::stoi(mes));
	convData.setAny(std::stoi(any));
	
	return convData;
}
	

void Data::setDia(int dia)
{
	m_dia = dia;
}
int Data::getDia() const
{
	return m_dia;
}
void Data::setMes(int mes)
{
	m_mes = mes;
}

int Data::getMes() const
{
	return m_mes;
}
void Data::setAny(int any)
{
	m_any = any;
}
int Data::getAny() const
{
	return m_any;
}
bool Data::dataValida()
{
	bool valida = false;
	if ((m_any > 1900) && (m_any < 2100))
	{
		if ((m_mes > 0) && (m_mes < 13))
		{
			if ((m_mes == 1) || (m_mes == 3) || (m_mes == 5) || (m_mes == 7) || (m_mes == 8) || (m_mes == 10) || (m_mes == 12))
			{
				if ((m_dia > 0) && (m_dia < 32))
					valida = true;
			}
			if ((m_mes == 4) || (m_mes == 6) || (m_mes == 9) || (m_mes == 11))
			{
				if ((m_dia > 0) && (m_dia < 31))
					valida = true;
			}
			if ((m_mes == 2))
			{
				if ((m_dia > 0) && (m_dia < 29))
					valida = true;
			}
		}
	}
	return valida;
}


Data Data::operator+(const int dias)
{

	for (int i = 0; i < dias; i++)
	{
		this->m_dia++;

		if ((this->m_mes == 1) || (this->m_mes == 3) || (this->m_mes == 5) || (this->m_mes == 7) || (this->m_mes == 8) || (this->m_mes == 10) || (this->m_mes == 12))
		{
			if (this->m_dia > 31)
			{
				this->m_dia -= 31;
				this->m_mes++;
			}
			if (this->m_mes > 12)
			{
				this->m_mes -= 12;
				this->m_any++;
			}
			
		}
		if ((this->m_mes == 4) || (this->m_mes == 6) || (this->m_mes == 9) || (this->m_mes == 11))
		{
			if (this->m_dia > 30)
			{
				this->m_dia -= 30;
				this->m_mes++;
			}
			if (this->m_mes > 12) 
			{
				this->m_mes -= 12;
				this->m_any++;
			}

		}
		if (this->m_mes == 2)
		{
			if (this->m_dia > 28)
			{
				this->m_dia -= 28;
				this->m_mes++;
			}
			if (this->m_mes > 12)
			{
				this->m_mes -= 12;
				this->m_any++;
			}
		}
	}
	return *this;
}

bool Data::operator<(const Data fecha)
{
	bool lower = false;

	if (this->m_any < fecha.m_any)
	{
		lower = true;
	}
	else {
		if ((this->m_mes < fecha.m_mes) && (this->m_any == fecha.m_any))
		{
			lower = true;
		}
		else
		{
			if ((this->m_dia < fecha.m_dia) && (this->m_mes == fecha.m_mes) && (this->m_any == fecha.m_any))
			{
				lower = true;
			}
			else
			{
				lower = false;
			}
		}
	}
	return lower;
}



bool Data::operator==(const Data fecha)
{
	if ((fecha.m_dia == m_dia) && (fecha.m_mes == m_mes) && (fecha.m_any == m_any))
		return true;
	else
		return false;
}