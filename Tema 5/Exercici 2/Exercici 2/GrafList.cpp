#include "GrafList.h"
#include <iomanip>

struct ComparaPair
{
	ComparaPair(int val) : m_valor(val) {}
	bool operator()(const std::pair<int, int>& elem) const 
	{
		return m_valor == elem.first;
	}
	bool operator==(const std::pair<int, int>& elem) const
	{
		return m_valor == elem.first;
	}
private:
	int m_valor;
};

Graf::Graf(bool dirigit)
{
	m_numNodes = 0;
	m_numArestes = 0;
	m_dirigit = dirigit;
}

Graf::Graf(vector<string>& nodes, vector<vector<int>>& parNodes, bool dirigit)
{
	m_numNodes = nodes.size();
	m_nodes.resize(m_numNodes);
	m_veins.resize(m_numNodes);
	m_dirigit = dirigit;
	m_numArestes = parNodes.size();

	for (int i = 0; i < m_numNodes; i++)
	{
		m_nodes[i] = nodes[i];		
	}
	for (int j = 0; j < parNodes.size(); j++)
	{
		if ((parNodes[j][0] < m_numNodes) && (parNodes[j][1] < m_numNodes) && 
			(parNodes[j][0] >= 0) && (parNodes[j][1]>= 0))
		{
			m_veins[parNodes[j][0]].emplace_back(pair<int,int>(parNodes[j][1],1));
			if (!dirigit)
			{
				m_veins[parNodes[j][1]].emplace_back(pair<int, int>(parNodes[j][0], 1));
			}
		}			
	}
}
Graf::Graf(vector<string>& nodes, vector<vector<int>>& parNodes, vector<int>& pesos,bool dirigit)
{
	m_numNodes = nodes.size();
	m_nodes.resize(m_numNodes);
	m_veins.resize(m_numNodes);
	m_dirigit = dirigit;
	m_numArestes = parNodes.size();

	for (int i = 0; i < m_numNodes; i++)
	{
		m_nodes[i] = nodes[i];
	}
	for (int j = 0; j < parNodes.size(); j++)
	{
		if ((parNodes[j][0] < m_numNodes) && (parNodes[j][1] < m_numNodes) &&
			(parNodes[j][0] >= 0) && (parNodes[j][1] >= 0))
		{
			m_veins[parNodes[j][0]].emplace_back(pair<int, int>(parNodes[j][1], pesos[j]));
			if (!dirigit)
			{
				m_veins[parNodes[j][1]].emplace_back(pair<int, int>(parNodes[j][0], pesos[j]));
			}
		}
	}
}
Graf::~Graf()
{
}

void Graf::inserirAresta(int posNode1, int posNode2)
{
	if ((posNode1 < m_numNodes) && (posNode2 < m_numNodes) && (posNode1 >= 0) && (posNode2 >= 0))
	{
		m_veins[posNode1].emplace_back(pair<int,int>(posNode2,1));
		if (!m_dirigit)
		{
			m_veins[posNode2].emplace_back(pair<int, int>(posNode1, 1));
		}
		m_numArestes++;
	}	
}

void Graf::inserirAresta(int posNode1, int posNode2, int pes)
{
	if ((posNode1 < m_numNodes) && (posNode2 < m_numNodes)&& (posNode1 >=0) && (posNode2 >= 0))
	{
		m_veins[posNode1].emplace_back(pair<int, int>(posNode2, pes));
		if (!m_dirigit)
		{
			m_veins[posNode2].emplace_back(pair<int, int>(posNode1, pes));
		}
		m_numArestes++;
	}
}


void Graf::eliminarAresta(int posNode1, int posNode2)
{
	list<pair<int, int>>::iterator itAre = find_if(m_veins[posNode1].begin(), m_veins[posNode1].end(),ComparaPair(posNode2));
	if (itAre != m_veins[posNode1].end())
	{
		m_veins[posNode1].erase(itAre);
		m_numArestes--;
	}
	if (!m_dirigit)
	{
		itAre = find_if(m_veins[posNode2].begin(), m_veins[posNode2].end(), ComparaPair(posNode1));
		if (itAre != m_veins[posNode2].end())
		{
			m_veins[posNode2].erase(itAre);
		}		
	}
}

void Graf::afegirNode(string node)
{
	m_nodes.push_back(node);
	m_numNodes++;	
	m_veins.resize(m_numNodes);
}


void Graf::eliminarNode(string node)
{
	//busquem la posici� del node a esborrar
	vector<string>::iterator it;

	it = find(m_nodes.begin(), m_nodes.end(), node);
	//mirem si node existeix
	if (it != m_nodes.end())
	{
		//Obtenim index del node
		int nodeIndex = it - m_nodes.begin();
		
		// eliminem el node del vector de nodes
		m_nodes.erase(it);
		//Eliminem arestes desde el node
		m_veins.erase(m_veins.begin()+ nodeIndex);
		//Eliminem arestes cap al node
	
		for (int i = 0; i < m_veins.size(); i++)
		{//eliminem cada aresta sense ponderar
			m_veins[i].remove_if(ComparaPair(nodeIndex));
		}
		m_numNodes--;
	}	
}
bool Graf::comparaSiExisteix(vector<string> temporal, vector<vector<string>>& parades_cicles)
{
	
	bool encontrado = false;

	for (int i = 0; !encontrado && i < parades_cicles.size(); i++)
	{
		int contador = 0;
		for (auto it = parades_cicles[i].begin(); !encontrado && it != parades_cicles[i].end(); it++)
		{
			if (temporal[0] == *it || temporal[1] == *it || temporal[2] == *it)
				contador++;

			if (contador == 3)
			{
				encontrado = true;
			}
		}
	}
	return encontrado;
}

vector<vector<string>> Graf::cicles()
{
	vector<vector<string>> parades_cicles;
	vector<string> temporal;

	list<pair<int, int>>::iterator it;
	list<pair<int, int>>::iterator it2;
	list<pair<int, int>>::iterator it3;


	for (int i = 0; i < m_veins.size(); i++)
	{
		for (it = m_veins[i].begin(); it != m_veins[i].end(); it++)
		{
			for (it2 = m_veins[(*it).first].begin(); it2 != m_veins[(*it).first].end(); it2++)
			{
				for (it3 = m_veins[(*it2).first].begin(); it3 != m_veins[(*it2).first].end(); it3++)
				{
					if (m_nodes[i] != m_nodes[(*it2).first] && m_nodes[(*it2).first] != m_nodes[(*it3).first] && m_nodes[(*it3).first] == m_nodes[i])
					{
						temporal.push_back(m_nodes[i]);
						temporal.push_back(m_nodes[(*it).first]);
						temporal.push_back(m_nodes[(*it2).first]);

						if (!(comparaSiExisteix(temporal, parades_cicles)))
						{
							parades_cicles.push_back(temporal);
						}

						temporal.resize(0);
					}
				}
			}
		}
	}
	return parades_cicles;
}

/*vector<vector<string>> Graf::cicles()
{
	/*vector<vector<int>>& parades_cicles;
	for (int fila = 0; fila < m_numNodes; fila++) {
		for (int col = fila; col < m_numNodes; col++) {
			if (m_matriuAdj[fila][col] == 1) {
				for (int vei = col; vei < m_numNodes; vei++) {
					if ((m_matriuAdj[fila][vei] == 1) && (m_matriuAdj[col][vei] == 1)) {
						parades_cicles.push_back({ fila,col,vei });
					}
				}
			}
		}
	}
	return parades_cicles;
	vector<vector<string>> prueba;
	return prueba;
}*/

int Graf::grauOutNode(string node)
{
	int posicion;
	bool encontrado = false;
	int contador = 0;

	for (int i = 0; !encontrado && i < m_nodes.size(); i++)
	{
		if (m_nodes[i] == node)
		{
			posicion = i;
			encontrado = true;
		}
	}

	for (auto it = m_veins[posicion].begin(); it != m_veins[posicion].end(); it++)
	{
		contador++;
	}

	return contador;
}

int Graf::grauInNode(string node)
{
	int posicion;
	bool encontrado = false;
	int contador = 0;

	for (int i = 0; !encontrado && i < m_nodes.size(); i++)
	{
		if (m_nodes[i] == node)
		{
			posicion = i;
			encontrado = true;
		}
	}

	for (int i = 0; i < m_nodes.size(); i++)
	{
		for (auto it = m_veins[i].begin(); it != m_veins[i].end(); it++)
		{
			if ((*it).first == posicion)
			{
				contador++;
			}
		}
	}
	return contador;
}


void Graf::camins(string node1, string node2, vector<list<string>>& camins)
{

}


void Graf::mostra()
{
	// imprimim el nom dels v�rtexs
	cout << "Graf: NUMNODES: " << m_numNodes << " ; NUMARESTES: " << m_numArestes << ":" << endl;
	cout << "=====NODES=====" << endl;
	for (int i = 0; i < m_numNodes; i++)
	{
		int espai = 20;
		if (i == 0) espai--;
		for (int dig = i; dig > 0; dig /= 10)
		{
			espai -= 1;
		}
		cout << i << ":" << setw(espai) << m_nodes[i] << " ";
		for (list<pair<int,int>>::iterator it = m_veins[i].begin(); it != m_veins[i].end(); it++)
		{
			cout << "-----> ( " << m_nodes[(*it).first] <<"," << (*it).second << " )  ";			
		}
		cout << endl;
	}	
}

