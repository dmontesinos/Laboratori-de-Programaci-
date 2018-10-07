#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <vector>
#include <forward_list>
#include <algorithm>

using namespace std;

template<class TClau, class TValor>
class Map
{
public:
	Map();
	~Map();
	int longitud() const;
	bool esBuit() const;

	TValor& operator[](const TClau& clau);
	const TValor& operator[](const TClau& clau) const;

	TClau& operator[](const int& posicio);
	const TClau& operator[](const int& posicio) const;

	void afegeix(const TClau& clau, const TValor& valor);

	Map(const Map& c);

	Map<TClau, TValor>& operator=(const Map< TClau, TValor>& m);

	//bool Map<TClau, TValor>& operator==(const Map<TClau,TValor>& m);

private:
	std::vector< std::pair<TClau,TValor> > m_vector;
};

template<class TClau, class TValor>
Map<TClau, TValor>::Map()
{
	//m_vector.push_back(make_pair(NULL, NULL));
}

template<class TClau, class TValor>
Map<TClau, TValor>::~Map()
{

}

template<class TClau, class TValor>
int Map<TClau, TValor>::longitud() const
{
	return m_vector.size();
}

template<class TClau, class TValor>
bool Map<TClau, TValor>::esBuit() const
{
	return m_vector.empty();
}


template<class TClau, class TValor>
TValor & Map<TClau, TValor>::operator[](const TClau & clau)
{
	for (auto it = m_vector.begin(); it != m_vector.end(); it++)
	{
		if (it->first == clau)
		{
			clau = it->second;
		}
		else {
			clau = NULL;
		}
	}
}


template<class TClau, class TValor>
const TValor& Map<TClau, TValor>::operator[](const TClau& clau) const 
{
	for (auto it = m_vector.begin(); it != m_vector.end(); it++)
	{
		if (it->first == clau)
		{
			clau = it->second;
		}
		else {
			clau = NULL;
		}
	}
}

template<class TClau, class TValor>
TClau& Map<TClau, TValor>::operator[](const int& posicio) 
{
	if ((posicio < longitud()) && (posicio >= 0))
	{
		posicio = m_vector[posicio].first;
	}
	else {
		posicio = NULL;
	}
}

template<class TClau, class TValor>
const TClau& Map<TClau, TValor>::operator[](const int& posicio) const 
{
	if ((posicio < longitud()) && (posicio >= 0))
	{
		posicio = m_vector[posicio].first;
	}
	else {
		posicio = NULL;
	}
}

template<class TClau, class TValor>
void Map<TClau, TValor>::afegeix(const TClau& clau, const TValor& valor)
{
	bool trobat = false;

	for (auto it = m_vector.begin(); it != m_vector.end(); it++)
	{
		if (it->first == clau)
		{
			trobat = true;
			it->first = clau;
			it->second = valor;
		}
	}

	if (trobat == false)
		m_vector.push_back(make_pair(clau, valor));

	sort(m_vector.begin(), m_vector.end());
}

template <class TClau, class TValor>
Map<TClau,TValor>::Map(const Map& c)
{
	this->m_vector = c.m_vector;
}

template<class TClau, class TValor>
Map<TClau, TValor>& Map<TClau, TValor>::operator=(const Map<TClau, TValor>& m)
{
	this->m_vector = m.m_vector;
}
