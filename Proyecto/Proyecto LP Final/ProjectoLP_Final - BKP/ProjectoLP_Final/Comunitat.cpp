#include "Comunitat.h"

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
	/* ALTERNATIVO
	vector<int>::iterator it_k;
	for (it_k = m_k.begin(); it_k != m_k.end(); it_k++)
	{
		int posicio = distance(m_k.begin(), it_k);
		m_A[posicio] = *it_k / m_M2;
	}
	*/
	for (int j = 0; j < m_k.size(); j++)
	{
		m_A[j] = m_k[j] / m_M2;
	}

}
void Comunitat::creaIndexComs()
{
	for (int i = 0; i < m_indexComs.size(); i++)
	{
		m_indexComs[i].first = i - 1;
		m_indexComs[i].second = i + 1;
	}
}
void Comunitat::creaDeltaQHeap()
{
	double max_dQ;
	int pos;
	for (int x = 0; x < m_deltaQ.size(); x++)
	{
		for (auto it = m_deltaQ[x].begin(); it != m_deltaQ[x].end(); it++)
		{
			int i = (*it).first.first;
			int j = (*it).first.second;
			double dQ = (1/m_M2) - ((m_k[i]* m_k[j]) / (m_M2 *m_M2));
			(*it).second = dQ;
			
			if (it == m_deltaQ[x].begin())
			{
				max_dQ = dQ;
				pos = distance(m_deltaQ[x].begin(), it);
			}
			else
			{
				if (max_dQ < dQ)
				{
					max_dQ = dQ;
					pos = distance(m_deltaQ[x].begin(), it);
				}
			}
		}
		m_maxDeltaQFil[x].first = pos;
		m_maxDeltaQFil[x].second = max_dQ;
	}
}

void Comunitat::modificaVei(int com1, int com2, int vei, int cas)
{

}

void Comunitat::fusiona(int com1, int com2)
{

}

void Comunitat::generaDendrogram(int pos1, int pos2, double deltaQp1p2)
{

}

void Comunitat::calculaComunitats(list<Tree<double>*>& listDendrogram)
{

}
