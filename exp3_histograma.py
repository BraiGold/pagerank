import os
import matplotlib.pyplot as plt
import numpy as np
import subprocess
import numpy as np; np.random.seed(0)
import seaborn as sns; sns.set()




def leerSalidas (nombreArchivo, cantPaginas):
    archivo = open(nombreArchivo,'r')
    p = float(archivo.readline())
    listaRanking = [0] * cantPaginas
    for i in range(0,cantPaginas):
        listaRanking[i] = float(archivo.readline())
    return listaRanking

def LeerEntrantes(nombreArchivo):
    archivoEntrada = open(nombreArchivo,'r')
    cantPaginas = int(archivoEntrada.readline())

    listaCantEntrantes = [0] * cantPaginas
    cantLinks = archivoEntrada.readline()
    for line in archivoEntrada:
        valores = line.split(" ")
        listaCantEntrantes[int(valores[1])-1]+= 1
    return listaCantEntrantes,cantPaginas;



nombreArchivo = '/home/brian/Desktop/TP1-MetNum-franco/tests_tp1/tests_tp1/grafo_3_formas_distintas.txt'
p = input('Ingrese p: ')
listaCantEntrantes,cantPaginas = LeerEntrantes(nombreArchivo)
nombreArchivoSalidas = '/home/brian/Desktop/TP1-MetNum-franco/salidas/grafo_3_formas_distintas.txt.out'
listaRanking = leerSalidas(nombreArchivoSalidas, cantPaginas)
listaPrimerForma = listaRanking[0:31]
listaSegundaForma = listaRanking[31:62]
listaTercerForma = listaRanking[62:93]

primerPromedio = np.average(listaPrimerForma)
segundoPromedio = np.average(listaSegundaForma)
tercerPromedio = np.average(listaTercerForma)
print (primerPromedio,segundoPromedio,tercerPromedio,len(listaRanking))











#
