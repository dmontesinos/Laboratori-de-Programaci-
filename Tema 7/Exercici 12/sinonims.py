# -*- coding: utf-8 -*-
"""
Created on Wed Jan 24 10:43:25 2018

@author: ernest
"""
import random

def afegeixSinonim(diccionari, paraula, sinonim):
    if paraula not in diccionari:
        diccionari[paraula] = [sinonim]
    else:
        if sinonim not in diccionari[paraula]:
            diccionari[paraula] = diccionari[paraula] + [sinonim]


def conversioSinonims(frase, diccionari):
    novaFrase = []
    for palabra in frase:
        novaFrase.append(palabra)

    for index, paraula in enumerate(frase):
        if paraula in diccionari.keys():
            novaFrase[index] = diccionari[paraula][random.randrange(len(diccionari[paraula]))]
        else:
            if paraula not in novaFrase:
                novaFrase.append(paraula)
    
    return novaFrase