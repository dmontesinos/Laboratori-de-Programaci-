# -*- coding: utf-8 -*-


import copy as cp
import numpy as np
class Graf:
    __slots__ = {'__nodes', '__arestes'}
        
    def __init__(self, nodes, arestes, pesos):
        self.__nodes = cp.deepcopy(nodes)
        self.__arestes = np.zeros([len(nodes), len(nodes)])
        for aresta, pes in zip(arestes, pesos):
            self.__arestes[aresta[0],aresta[1]] = pes
            self.__arestes[aresta[1],aresta[0]] = pes
            
    def __str__(self):
        s = "";
        for posNode, node in enumerate(self.__nodes):
            s = s + "Etiqueta: " + str(node) + "\n"
            s = s + "Arestes: " + str([[vei[0], pes] for vei, pes in np.ndenumerate(self.__arestes[posNode,:]) if pes != 0]) + "\n"
        return s
    
    
    def etiquetesAdjacents(self, node):
        adyacentes = []
        
        indice = self.__nodes.index(node)
        for i,y in enumerate(self.__arestes[indice]):
            if int(y) != 0:
                adyacentes.append(self.__nodes[i])
        
        return adyacentes
    
    def cicles(self):
        ciclos = []

        for i0,x in enumerate(self.__arestes):
            for i1,y in enumerate(x):
                if int(y) != 0:
                    for i2,z in enumerate(self.__arestes[i1]):
                        if int(z) != 0:
                            for i3,j in enumerate(self.__arestes[i2]):
                                if int(j) != 0:
                                    if self.__nodes[i0] == self.__nodes[i3]:
                                        ciclo = []
                                        ciclo.append(self.__nodes[i1])
                                        ciclo.append(self.__nodes[i2])
                                        ciclo.append(self.__nodes[i3])
                                        
                                        if self.comprobarCiclo(ciclo,ciclos) != True:
                                            ciclos.append(ciclo)
        return ciclos
          
    def comprobarCiclo(self,ciclo,ciclos):
        contador = 0
        for x in ciclos:
            if len(ciclo) == len(x):
                orden1 = sorted(ciclo)
                orden2 = sorted(x)
                for i in range(3):
                    if orden1[i] == orden2[i]:
                        contador = contador + 1
                    if contador == 3: 
                         return True
                contador = 0
        return False
    
    
    def nodesAillats(self):
        nodosAislados = []
        contador = 0
        size = len(self.__nodes)
        for i,x in enumerate(self.__arestes):
            for y in x:
                if int(y) == 0:
                    contador = contador + 1       
            if size == contador:
                nodosAislados.append(self.__nodes[i])
            contador = 0
        return nodosAislados
    
    
    def nodeMaxArestes(self):
        maximo = self.__nodes[0]
        nTotal = 0
        
        contador = 0
        for i,x in enumerate(self.__arestes):
            for y in x:
                if int(y) != 0:
                    contador = contador + 1
            if contador > nTotal:
                nTotal = contador
                maximo = self.__nodes[i]
            contador = 0
        return maximo
    
       
    
    
        
                
 