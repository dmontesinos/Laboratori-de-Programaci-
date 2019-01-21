# -*- coding: utf-8 -*-
"""
Created on Sat Dec 29 20:57:47 2018

@author: danib
"""


nodes = [ "T0", "T1","T2","T3","T4","T5","T6","T7","T8","T9","T10", "T11"]
arestes = [ [ 0,1 ],[ 3,0 ],[ 4,1 ],[ 1,5 ],[ 3,5 ],[ 6,3 ],[ 5,4 ],[ 5,6 ],[ 4,7 ],[ 4,8 ],[ 6,8 ],[ 6,9 ],[ 7,8 ],[ 8,9 ],[ 7,10 ],[ 8,10 ],[ 9,10 ] ]
pesos = [ 5,5,7,7,4,4,6,6,3,3,9,9,1,8,2,8,4 ]


""" Creamos etiquetas con lista vacia """
nodes = [[node, []] for node in nodes]

""" Añadimos las arestas y pesos a las etiquetas anteriores """
for aresta, pes in zip(arestes, pesos):
    nodes[aresta[0]][1].append([aresta[1], pes])
    nodes[aresta[1]][1].append([aresta[0], pes])
    

""" Buscamos los elementos vacios y ponemos "HOLA", "ADIOS" para los no vacios """
for elemento in range(len(nodes)):
    if not nodes[elemento][1]:
        print("HOLA",nodes[elemento][1])
    else:
        print("ADIOS",nodes[elemento][1])
        
        
""" Recorremos los elementos de la lista compuestos por su etiqueta y lista de
arestas. Para cada combinación, contamos el número de elementos dentro de la
lista de arestas. Devolvemos la etiqueta de este nodo """
max = 0
for elemento in range(len(nodes)):
    if len(nodes[elemento][1]) > max:
        max = len(nodes[elemento][1])
        etiqueta = nodes[elemento][0]


"""etiquetesAdjacents """
node = "T5"
adjacents = []
temporal = []
for elemento in range(len(nodes)):
    if nodes[elemento][0] == node:
        for arestas in range(len(nodes[elemento][1])):
            temporal.append(nodes[elemento][1][arestas][0])
        for etiquetas in range(len(temporal)):
            adjacents.append(nodes[etiquetas][0])
            
               
        
""" cicles """
ciclos = []
ciclos2 = []
for elemento1 in range(len(nodes)):
    """print ("ELEMENTO "+str(elemento1))"""
    """print(elemento1)"""
    """print("VECINOS DE "+str(elemento1))"""
    for vecinos1 in nodes[elemento1][1]:
        """print(vecinos1)"""
        """print(vecinos1[0])"""
        """print("VECINOS DE VECINO "+str(vecinos1[0]))"""
        for vecinos2 in nodes[vecinos1[0]][1]:
            """print(vecinos2)"""
            """print(vecinos2[0])"""
            for vecinos3 in nodes[vecinos2[0]][1]:
                if elemento1 != vecinos2[0] and vecinos2[0] != vecinos3[0] and vecinos3[0] == elemento1:
                    encontrado = False
                    temporal = []
                    temporal.append(elemento1)
                    temporal.append(vecinos1[0])
                    temporal.append(vecinos2[0])
                    
                    temporal2 = []
                    temporal2.append(nodes[elemento1][0])
                    temporal2.append(nodes[vecinos1[0]][0])
                    temporal2.append(nodes[vecinos2[0]][0])
                    
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
                        ciclos2.append(temporal2)
       
""" PRUEBAS """
ciclos = []

for elemento1 in range(len(nodes)):
    """print ("ELEMENTO "+str(elemento1))"""
    """print(elemento1)"""
    """print("VECINOS DE "+str(elemento1))"""
    for vecinos1 in nodes[elemento1][1]:
        """print(vecinos1)"""
        """print(vecinos1[0])"""
        """print("VECINOS DE VECINO "+str(vecinos1[0]))"""
        for vecinos2 in nodes[vecinos1[0]][1]:
            """print(vecinos2)"""
            """print(vecinos2[0])"""
            for vecinos3 in nodes[vecinos2[0]][1]:
                if elemento1 != vecinos2[0] and vecinos2[0] != vecinos3[0] and vecinos3[0] == elemento1:
                    encontrado = False
                    temporal = []
                    temporal.append(nodes[elemento1][0])
                    temporal.append(nodes[vecinos1[0]][0])
                    temporal.append(nodes[vecinos2[0]][0])
                    

                    
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