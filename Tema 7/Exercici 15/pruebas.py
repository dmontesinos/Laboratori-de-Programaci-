# -*- coding: utf-8 -*-
"""
Created on Tue Jan  8 19:36:47 2019

@author: danib
"""

import copy as cp
import numpy as np

nodes = [ "T0", "T1","T2","T3","T4","T5","T6","T7","T8","T9","T10", "T11"]
arestes = [ [ 0,1 ],[ 3,0 ],[ 4,1 ],[ 1,5 ],[ 3,5 ],[ 6,3 ],[ 5,4 ],[ 5,6 ],[ 4,7 ],[ 4,8 ],[ 6,8 ],[ 6,9 ],[ 7,8 ],[ 8,9 ],[ 7,10 ],[ 8,10 ],[ 9,10 ] ]
pesos = [ 5,5,7,7,4,4,6,6,3,3,9,9,1,8,2,8,4 ]



nodes = cp.deepcopy(nodes)
arestes = np.zeros([len(nodes), len(nodes)])

for aresta, pes in zip(arestes, pesos):
    arestes[aresta[0],aresta[1]] = pes
    arestes[aresta[1],aresta[0]] = pes