#pragma once
#include <iostream>
using namespace std;

template <class T>
class SmartPointer
{
public:
	SmartPointer();
	~SmartPointer();

	SmartPointer(SmartPointer<T>& c);

	SmartPointer<T>& operator=(T* p);
	SmartPointer<T> &operator = (SmartPointer &p);
	T& operator* ();
	T* operator-> ();

	bool isNull();
private:
	T* m_apuntador;
};

template<class T>
SmartPointer<T>::SmartPointer()
{
	m_apuntador = new T;
	m_apuntador = NULL;
}

template<class T>
SmartPointer<T>::~SmartPointer()
{
}

template<class T>
SmartPointer<T>::SmartPointer(SmartPointer<T>& c)
{
	m_apuntador = new T;
	*m_apuntador = *c.m_apuntador;
	
	c.m_apuntador = NULL;
}

template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(T* p)
{

	cout << "ESTE ES EL DE ARRIBA";
	if (m_apuntador != NULL)
	{
		delete m_apuntador;
		m_apuntador = new T;
	}

	m_apuntador = p;

	return *this;
}

template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer & p)
{
	/* SP2 = SP1  //  THIS = p */
	cout << "ESTE ES EL DE ABAJO ";
	if (m_apuntador != NULL)
	{
		delete m_apuntador;
		m_apuntador = new T;
	}

	m_apuntador = p.m_apuntador;

	p.m_apuntador = NULL;

	return *this;
}

template<class T>
T& SmartPointer<T>::operator*()
{
	//FALTA PONER MENSAJE POR PANTALLA EN CASO DE NULL
	return *m_apuntador;
}

template<class T>
T* SmartPointer<T>::operator->()
{
	return m_apuntador;
}

template<class T>
bool SmartPointer<T>::isNull()
{
	if (m_apuntador == NULL)
		return true;
	else
		return false;
}