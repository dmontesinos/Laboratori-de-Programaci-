#pragma once
#include "Heap.hpp"

template <class T>
class CuaPrioritat
{
public:
	CuaPrioritat() {}
	~CuaPrioritat() {}
	CuaPrioritat(const CuaPrioritat<T>& cua);
	CuaPrioritat& operator=(const CuaPrioritat<T>& cua);

	bool esBuida() const;
	int getNElements() const;
	T& top();
	void push(const T& element);
	void pop();
	void remove(const T& element);
private:
	Heap<T> m_cuaPrioritat;
};

// IMPLEMENTACIO METODES PER COMPLETAR

template<class T>
CuaPrioritat<T>::CuaPrioritat(const CuaPrioritat<T>& cua)
{
}

template<class T>
CuaPrioritat<T>& CuaPrioritat<T>::operator=(const CuaPrioritat<T>& cua)
{
	m_cuaPrioritat = cua.m_cuaPrioritat;
	return *this;
}


template<class T>
bool CuaPrioritat<T>::esBuida() const
{
	if (m_cuaPrioritat.getMida() != -1)
		return false;
	else
		return true;
}

template<class T>
int CuaPrioritat<T>::getNElements() const
{
	return m_cuaPrioritat.getMida();
}

template<class T>
T& CuaPrioritat<T>::top()
{
	return m_cuaPrioritat.getMinim();
}

template<class T>
void CuaPrioritat<T>::push(const T& element)
{
	m_cuaPrioritat.insereix(element);
}

template<class T>
void CuaPrioritat<T>::pop()
{
	m_cuaPrioritat.esborraMinim();
}

template<class T>
void CuaPrioritat<T>::remove(const T& element)
{
	m_cuaPrioritat.esborra(element);
}