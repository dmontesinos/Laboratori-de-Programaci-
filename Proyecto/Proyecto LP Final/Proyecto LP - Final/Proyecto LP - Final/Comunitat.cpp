#include "Comunitat.h"
#include <math.h>

Comunitat::Comunitat(MatriuSparse* pMAdj)
{
	m_primComdeltaQ = -1;
	m_Q = 0;
	m_pMAdj = pMAdj;
}

Comunitat::~Comunitat()
{
	m_pMAdj = nullptr;	
}
void Comunitat::clear()
{
	m_pMAdj = nullptr;
	m_deltaQ.clear();
	m_indexComs.clear();
	m_maxDeltaQFil.clear();
	m_primComdeltaQ=-1;
	m_vDendrograms.clear();
	m_k.clear();
	m_A.clear();
	m_hTotal.clear();
	m_Q=0;
	m_M2=0;	
}

void Comunitat::calculaA()
{
	m_A.resize(m_k.size(),0);

	for (int pos = 0; pos < m_k.size(); pos++)
	{
		double a, b;
		a = m_k[pos];
		b = m_M2;

		m_A[pos] = a/b;
	}
}
void Comunitat::creaIndexComs()
{
	for (int i = 0; i < m_indexComs.size(); i++)
	{
		m_indexComs[i].first = i + 1;
		m_indexComs[i].second = i - 1;
	}
}
void Comunitat::creaDeltaQHeap()
{
	m_pMAdj->creaMaps(m_deltaQ);
	m_maxDeltaQFil.resize(m_pMAdj->getNFiles(), make_pair(-1, -2));
	m_indexComs.resize(m_pMAdj->getNFiles());

	auto itinit = m_deltaQ[0].begin();
	int fila = (*itinit).first.first;

	pair<int, int> coordMax;
	double valorMax;

	m_hTotal.resize(m_pMAdj->getNFiles());

	for (int x = 0; x < m_deltaQ.size(); x++)
	{
		for (auto it = m_deltaQ[x].begin(); it != m_deltaQ[x].end(); it++)
		{
			int i = (*it).first.first;
			int j = (*it).first.second;

			double a, b, c, d, dQ;
			a = 1.0 / m_M2;
			b = (m_k[i] * m_k[j]);
			c = pow(m_M2, 2);
			dQ = a - (b / c);

			(*it).second = dQ;


			if ((*it).first.first == fila && dQ > m_maxDeltaQFil[fila].second)
			{
				m_maxDeltaQFil[fila].first = j;
				m_maxDeltaQFil[fila].second = dQ;
			}
			else {
				if ((*it).first.first != fila)
				{
					m_maxDeltaQFil[(*it).first.first].first = j;
					m_maxDeltaQFil[(*it).first.first].second = dQ;

					fila = (*it).first.first;
				}
			}

		}
	}
	for (int i = 0; i < m_maxDeltaQFil.size(); i++)
	{
		ElemHeap elemento(m_maxDeltaQFil[i].second, make_pair(i, m_maxDeltaQFil[i].first));
		m_hTotal.insert(elemento);
	}
}

void Comunitat::modificaVei(int com1, int com2, int vei, int cas)
{

}

void Comunitat::fusiona(int com1, int com2)
{

}

/*void Comunitat::generaDendrogram(int pos1, int pos2, double deltaQp1p2)
{

}*/

void Comunitat::calculaComunitats(list<Tree<double>*>& listDendrogram)
{

}
