#pragma once
#include <iostream>
//#include "Persona.h"
using namespace std;

template <class T>
class SmartPointer
{
public:
	SmartPointer();
	SmartPointer(SmartPointer&s);
	SmartPointer<T> &operator= (T* p);
	SmartPointer<T> &operator= (SmartPointer& p);
	T &operator *();
	T *operator ->();
	bool isNull();
private:
	T *m_apuntador;

};

template <class T>
SmartPointer<T>::SmartPointer() {

	m_apuntador = nullptr;

}

template <class T>
SmartPointer<T>::SmartPointer(SmartPointer &s) {//o T

	m_apuntador = s.m_apuntador;
	s.m_apuntador = nullptr;

}
/*template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(T * p)
{
	// TODO: insertar una instrucción return aquí
}*/
template<class T>
SmartPointer<T>& SmartPointer<T>:: operator= (T* p) {

	if (m_apuntador != nullptr) {
		delete m_apuntador;
	}

	//p = new T(10);
	m_apuntador = p;

	return *this;
}

template<class T>
SmartPointer<T>& SmartPointer<T>:: operator= (SmartPointer& p) {

	if (m_apuntador != nullptr) {
		//delete m_apuntador;
		m_apuntador == nullptr;
	}

	//p = new T(10);
	m_apuntador = new T;
	m_apuntador = p.m_apuntador;
	p.m_apuntador = nullptr;

	//p = nullptr;

	return *this;
}

template<class T>
T& SmartPointer<T>:: operator *() {



	return *m_apuntador;
}

template <class T>
T* SmartPointer<T>::operator->() {

	return m_apuntador;
}

template <class T>
bool SmartPointer<T>::isNull() {

	bool retorn = false;
	if (m_apuntador == nullptr) {
		retorn = true;
	}
	return retorn;
}