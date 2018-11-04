#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	/*
	std::vector< std::pair<int, string> > m_vector;


	m_vector.push_back(make_pair(500, "hola"));
	m_vector.push_back(make_pair(600, "hola2"));
	m_vector.push_back(make_pair(700, "hola3"));
	m_vector.push_back(make_pair(200, "hola4"));
	m_vector.push_back(make_pair(300, "hola5"));
	m_vector.push_back(make_pair(500, "hola6"));

	int primero;
	string segundo;


	primero = m_vector[2].first;
	segundo = m_vector[2].second;

	cout << primero << endl << segundo << endl;

	std::sort(m_vector.begin(), m_vector.end());

	for (int i = 0; i != m_vector.size(); ++i)
		cout << m_vector[i].first << " " << m_vector[i].second << endl;

	/*for (auto it = m_vector.begin(); it != m_vector.end(); it++)
	{
		primero = it->first;
		segundo = it->second;

		cout << primero << endl;
		cout << segundo << endl;
	
	}*/
	

	/*std::vector<int> pruebas;

	for (int i = 0; i < 30; i++)
	{
		pruebas.push_back(i);
	}

	cout << endl;

	for (auto it = pruebas.begin(); it != pruebas.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	for (int i = 0; i < 30; i++)
	{
		cout << pruebas[i] << " ";
	}

	cout << endl;


	bool trovat = false;
	auto it = pruebas.begin();

	while (!trovat && it != pruebas.end()) {
		if (*it == 2)
		{
			pruebas.erase(it);
			trovat = true;
		}
		else
		{
			it++;
		}
	}
	
	for (auto it = pruebas.begin(); it != pruebas.end(); it++)
	{
		cout << *it << " ";
	}*/

	///////////////////
	/*std::unordered_map<std::string, std::string> diccionari;

	diccionari.insert(make_pair("hola", "prueba"));
	
	for (auto it = diccionari.begin(); it != diccionari.end(); it++)
	{
		cout << (*it).first << endl;
		cout << (*it).second;
	}

	auto it = diccionari.find("hola");
	cout << (*it).first << " " << (*it).second << endl;
	*/

	vector<tuple<int, int, float>> m_vector;
	m_vector.push_back(tuple<int,int,float>(25, 30, 35));
	m_vector.push_back(tuple<int, int, float>(50, 60, 70));
	m_vector.push_back(tuple<int, int, float>(51, 61, 71.5));

	for (auto it = m_vector.begin(); it != m_vector.end(); it++)
	{
		cout << get<0>(*it) << " " << get<1>(*it) << " " << get<2>(*it) << endl;
	}
	


	/*	vector<list<int>> m_vector = { 
		{},
		{ 4 },
		{ 1, 2, 3, 4, 5 },
		{ 5, 4, 3, 2, 1 },
		{ 1, 3, 5, 2, 4 },
		{ 3, 1, 4, 2, 5 },
		{ 5, 1, 3, 4, 2 },
		{ 3, 5, 4, 2, 1 } };


	for (auto it1 = m_vector.begin(); it1 != m_vector.end(); it1++)
	{
		int tamaño = it1->size();
		int max = 0;
		for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			if (*it2 > max)
				max = *it2;
			cout << *it2;
 		}
		cout << " - El mas grande es: " << max << endl;
	}
	*/

	return 0;
}
