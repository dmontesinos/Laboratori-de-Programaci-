# -*- coding: utf-8 -*-
"""
Created on Sat Jan  5 16:56:10 2019

@author: danib
"""

def llegirFitxer(nomFitxer):
    fitxer = open(nomFitxer, "rt")
    comandes = {}
    for linia in fitxer:
        paraules = linia.split()
        comandes[paraules[0]] = paraules[1:]
    return comandes

def modificaClient(comandes, nomClient, novesComandes):
    if nomClient in comandes:
        comandes[nomClient]= comandes[nomClient] + novesComandes
    else:
        comandes[nomClient] = novesComandes
        
def eliminaComanda(comandes, nomClient, codiComanda):
    if nomClient in comandes:
        if codiComanda in comandes[nomClient]:
            comandes[nomClient].remove(codiComanda)
        

def nComandes(comandes):
    nComandesClient = 