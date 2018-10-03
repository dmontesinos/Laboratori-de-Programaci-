#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <vector>
#include <forward_list>


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

private:
	std::vector< std::pair<TClau,TValor> > m_vector;
	TValor m_valor;
};

template<class TClau, class TValor>
Map<TClau, TValor>::Map()
{
}

template<class TClau, class TValor>
Map<TClau, TValor>::~Map()
{
	m_vector.~vector();
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

/* 5. L’operador [] per poder accedir a un element qualsevol del conjunt a 
partir de la seva clau. Si la clau no existeix s’ha de retornar el valor per 
defecte del tipus del valor que es guarda al conjunt (el valor per defecte és 
el valor que s’obté després de cridar al constructor per defecte). 
Tingueu en compte que com que s’ha de retornar per referència, aquest valor 
s’haurà de guardar en un atribut de la classe (no podrà ser una variable local 
del mètode). Feu dues versions del mètode per retornar un objecte modificable i 
un objecte constant (les dues versions retornen el mateix, l’única diferència 
està en la declaració).*/

template<class TClau, class TValor>
TValor & Map<TClau, TValor>::operator[](const TClau & clau)
{
	TClau index;

	for (auto it = m_vector.begin(); it != m_vector.end(); it++)
	{
		index = *it.first();
		if (index == clau)
		{
			m_valor = *it.second();
		}
		else {
			m_valor = *it.first();
		}
	}
}


template<class TClau, class TValor>
const TValor& Map<TClau, TValor>::operator[](const TClau& clau) const {
	
	TClau index;

	for (auto it = m_vector.begin(); it != m_vector.end(); it++)
	{
		index = *it.first();
		if (index == clau)
		{
			m_valor = *it.second();
		}
		else {
			m_valor = *it.first();
		}
	}
}