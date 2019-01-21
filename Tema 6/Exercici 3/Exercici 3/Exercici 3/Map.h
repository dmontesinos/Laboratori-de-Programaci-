#pragma once
#include <stdlib.h>
#include <iostream>
#include <utility>
#include "TreeRB.hpp"
using namespace std;



template<class TClau, class TValor>
class PairMap
{
public:
	TClau first;
	TValor second;
	PairMap() { first = TClau(); second = TValor(); }
	PairMap(TClau primer, TValor segon) { first = primer; second = segon; }
	bool operator<(PairMap<TClau, TValor> valor) const { return (first < valor.first); }
	bool operator==(PairMap<TClau, TValor> valor) const {	return (first == valor.first); }
	friend ostream& operator<<(ostream& out, PairMap<TClau, TValor> valor)
	{
		out << "<" << valor.first << ", " << valor.second << ">";
		return out;
	}
};



template<class TClau, class TValor>
class Map
{
public:
	Map() {};
	Map(const Map<TClau, TValor>& m) { m_valor = m.m_valor; m_treePMap = m.m_treePMap; }; //HAY QUE MIRAR SI HACE FALTA
	~Map() {};
	bool esBuit() const;
	TValor& operator[](const TClau& clau);
	void afegeix(const TClau& clau, const TValor& valor);
	friend std::ostream& operator<<(std::ostream& out, const Map<TClau, TValor>& m) 
	{
		out << m;
	};
private:
	TreeRB<PairMap<TClau,TValor>> m_treePMap;
	TValor m_valor;
};

// IMPLEMENTACIÓ MÉTODES PER COMPLETAR

template<class TClau, class TValor>
bool Map<TClau, TValor>::esBuit() const
{
	return m_treePMap.isEmpty();
}

template<class TClau, class TValor>
TValor& Map<TClau, TValor>::operator[](const TClau& clau)
{
	m_valor = TValor();

	PairMap<TClau, TValor> elemento;
	TreeRB<PairMap<TClau, TValor>> *resultado;

	if (m_treePMap.cerca(elemento, resultado))
	{
		m_valor = resultado->getData().second;
		return m_valor;
	}
	else {
		TValor vDefecto;
		return vDefecto;
	}
}

template<class TClau, class TValor>
void Map<TClau, TValor>::afegeix(const TClau & clau, const TValor & valor)
{
	PairMap<TClau, TValor> elemento;

	TreeRB<PairMap<TClau, TValor>> *tmp;

	if (m_treePMap.cerca(elemento, tmp))
	{
		tmp->getData().second = valor;
	}
	else
	{
		m_treePMap.insert(elemento);
	}
}