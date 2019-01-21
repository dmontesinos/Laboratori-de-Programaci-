# -*- coding: utf-8 -*-

class Graf:
    __slots__ = {'__nodes'}
        
    def __init__(self, nodes, arestes, pesos):
        """ Creamos etiquetas con lista vacia """
        self.__nodes = [[node, []] for node in nodes]
        
        """ Añadimos las arestas y pesos a las etiquetas anteriores """
        for aresta, pes in zip(arestes, pesos):
            self.__nodes[aresta[0]][1].append([aresta[1], pes])
            self.__nodes[aresta[1]][1].append([aresta[0], pes])
            
    def __str__(self):
        s = "";
        for node in self.__nodes:
            s = s + "Comment :=>> Etiqueta: " + str(node[0]) + "\n"
            s = s + "Comment :=>> Arestes: " + str(node[1]) + "\n"
        return s
    
    
    def nodeMaxArestes(self):
        max = 0
        for elemento in range(len(self.__nodes)):
            if len(self.__nodes[elemento][1]) > max:
                max = len(self.__nodes[elemento][1])
                etiqueta = self.__nodes[elemento][0]
        return etiqueta
    
            
    def nodesAillats(self):
        aislados = []
        for elemento in range(len(self.__nodes)):
            if not self.__nodes[elemento][1]:
                aislados.append(self.__nodes[elemento][0])
        return aislados
            
            
    def etiquetesAdjacents(self, node):
        adjacents = []
        temporal = []
        for elemento in range(len(self.__nodes)):
            if self.__nodes[elemento][0] == node:
                for arestas in range(len(self.__nodes[elemento][1])):
                    temporal.append(self.__nodes[elemento][1][arestas][0])
                for etiquetas in temporal:
                    adjacents.append(self.__nodes[etiquetas][0])
        return adjacents
    
    def cicles(self):
        ciclos = []

        for elemento1 in range(len(self.__nodes)):
            """print ("ELEMENTO "+str(elemento1))"""
            """print(elemento1)"""
            """print("VECINOS DE "+str(elemento1))"""
            for vecinos1 in self.__nodes[elemento1][1]:
                """print(vecinos1)"""
                """print(vecinos1[0])"""
                """print("VECINOS DE VECINO "+str(vecinos1[0]))"""
                for vecinos2 in self.__nodes[vecinos1[0]][1]:
                    """print(vecinos2)"""
                    """print(vecinos2[0])"""
                    for vecinos3 in self.__nodes[vecinos2[0]][1]:
                        if elemento1 != vecinos2[0] and vecinos2[0] != vecinos3[0] and vecinos3[0] == elemento1:
                            encontrado = False
                            temporal = []
                            temporal.append(self.__nodes[elemento1][0])
                            temporal.append(self.__nodes[vecinos1[0]][0])
                            temporal.append(self.__nodes[vecinos2[0]][0])
                            

                            
                            for ciclo in range(len(ciclos)):
                                contador = 0
                                for elemCiclo in range(len(temporal)):
                                    if temporal[elemCiclo] == ciclos[ciclo][0] or temporal[elemCiclo] == ciclos[ciclo][1] or temporal[elemCiclo] == ciclos[ciclo][2]:
                                        contador = contador + 1
                                if contador == 3:
                                    encontrado = True
                                    break
                                    
                            if not encontrado:
                                
                                ciclos.append(temporal)
                                
                               
                            
        return ciclos