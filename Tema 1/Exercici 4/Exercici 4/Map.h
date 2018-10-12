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

	Map<TClau, TValor>& operator=(const Map< TClau, TValor>& m);

private:
	std::vector< std::pair<TClau,TValor> > m_vector;
	std::vector< std::pair<TClau,TValor> > m_vector2;
};

template<class TClau, class TValor>
Map<TClau, TValor>::Map()
{
	TClau clau;
	TValor valor;
	m_vector2.push_back(make_pair(clau, valor));
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
	/*bool trobat = false;
	for (auto it = m_vector.begin(); it != m_vector.end() && !trobat; it++)
	{
		if (it->first == clau)
		{
			return it->second;
			trobat = true;
		}
	}*/

	bool bypass = false;
	int left = 0;
	int right = m_vector.size() - 1;

	int cont = 0;
	while (left <= right && !bypass)
	{
		cont = ((left + right) / 2);

		if (m_vector[cont].first < clau)
			left = cont + 1;

		else if (m_vector[cont].first > clau)
			right = cont - 1;

		else
			bypass = true;
	}
	if (bypass == false)
		return m_vector2[0].second;
	else
		return m_vector[cont].second;
}


template<class TClau, class TValor>
const TValor& Map<TClau, TValor>::operator[](const TClau& clau) const 
{
	/*bool trobat = false;
	for (auto it = m_vector.begin(); it != m_vector.end() && !trobat; it++)
	{
		if (it->first == clau)
		{
			return it->second;
			trobat = true;
		}
	}*/


	bool bypass = false;
	int left = 0;
	int right = m_vector.size() - 1;

	int cont = 0;
	while (left <= right && !bypass)
	{
		cont = ((left + right) / 2);

		if (m_vector[cont].first < clau)
			left = cont + 1;

		else if (m_vector[cont].first > clau)
			right = cont - 1;

		else
			bypass = true;
	}
	if (bypass == false)
		return m_vector2[0].second;
	else
		return m_vector[cont].second;
}

template<class TClau, class TValor>
TClau& Map<TClau, TValor>::operator[](const int& posicio) 
{
	if ((posicio < longitud()) && (posicio >= 0))
		return m_vector[posicio].first;
}

template<class TClau, class TValor>
const TClau& Map<TClau, TValor>::operator[](const int& posicio) const 
{
	if ((posicio < longitud()) && (posicio >= 0))
		return m_vector[posicio].first;
}

template<class TClau, class TValor>
void Map<TClau, TValor>::afegeix(const TClau& clau, const TValor& valor)
{
	vector<pair<TClau, TValor>> auxiliar;
	TClau clauAux;
	TValor valorAux;

	auxiliar.push_back(make_pair(clauAux, valorAux));
	m_vector.push_back(make_pair(clau, valor));

	if (m_vector.size() > 1) {
		for (int i = 0; i < m_vector.size() - 1; i++)
		{
			if (m_vector[i].first == m_vector[i + 1].first) {
				m_vector[i].second = m_vector[i + 1].second;
				m_vector.pop_back();
			}
			else if (m_vector[i].first > m_vector[i + 1].first)
			{
				auxiliar[0].first = m_vector[i].first;
				auxiliar[0].second = m_vector[i].second;
				m_vector[i].first = m_vector[i + 1].first;
				m_vector[i].second = m_vector[i + 1].second;
				m_vector[i + 1].first = auxiliar[0].first;
				m_vector[i + 1].second = auxiliar[0].second;
			}
		}
	}
	auxiliar.pop_back();
}


template<class TClau, class TValor>
Map<TClau, TValor>& Map<TClau, TValor>::operator=(const Map<TClau, TValor>& m)
{
	m_vector = m.m_vector;
	return *this;
}