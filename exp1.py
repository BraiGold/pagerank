

import os
import matplotlib.pyplot as plt
import numpy as np

def LeerEntrantes(nombreArchivo):
    archivoEntrada = open(nombreArchivo,'r')
    cantPaginas = int(archivoEntrada.readline())

    listaCantEntrantes = [0] * cantPaginas
    cantLinks = archivoEntrada.readline()
    for line in archivoEntrada:
        valores = line.split(" ")
        listaCantEntrantes[int(valores[1])-1]+= 1
    return listaCantEntrantes,cantPaginas;


def leerSalidas (nombreArchivo, cantPaginas):
    archivo = open(nombreArchivo,'r')
    p = float(archivo.readline())
    listaRanking = [0] * cantPaginas
    for i in range(0,cantPaginas):
        listaRanking[i] = float(archivo.readline())
    return listaRanking

def promedioCosas(listaEntradas, listaRankings):
    listaCantidadEntradas = []
    listaPromedios = []
    listaErrores = []
    for i in range(0,len(listaEntradas)):
        elems = []
        cantElems = 0
        cantRanking = 0
        for j in range(0,len(listaEntradas)):
            if( listaEntradas[j] == i):
                elems.append(listaRankings[j])
                cantElems+=1
                cantRanking += listaRankings[j]

        arrElems = np.array(elems)
        if (len(elems) != 0):
            miNuevoPromedio = cantRanking / (float(cantElems))
            listaErrores.append(np.std(arrElems))
            listaCantidadEntradas.append(i)
            listaPromedios.append(miNuevoPromedio)

    return listaCantidadEntradas,listaPromedios,listaErrores
#def separarEnBuckets(listaCantEntrantes,buckets):
#    for pagina in listaCantEntrantes:
#        if()


#aca Empieza El Experimento

# Creo una lista que en la pos i tenga la cantidad de links que entran a la pagina i
#nombreArchivo = input('Ingrese nombre archivo: ')
nombreArchivo = '/home/brian/Desktop/TP1-MetNum-franco/tests_tp1/tests_tp1/test_30_segundos.txt'
#p = input('Ingrese p: ')
listaCantEntrantes,cantPaginas = LeerEntrantes(nombreArchivo)


nombreArchivoSalidas = '/home/brian/Desktop/TP1-MetNum-franco/salidas/test_30_segundos.txt.out'
listaRankings = leerSalidas(nombreArchivoSalidas,cantPaginas)

listaEntradasPromediadas, listaRankingsPromediados, listaErrores = promedioCosas(listaCantEntrantes,listaRankings)

#plt.plot(listaEntradasPromediadas,listaRankingsPromediados ,'ro')
#plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores)
plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores, label="ranking test_30_segundos", fmt="bs",  linewidth=3,  elinewidth=0.5, ecolor='k', capsize=5, capthick=0.5)
#plt.legend()
#plt.show()

nombreArchivo = '/home/brian/Desktop/TP1-MetNum-franco/tests_tp1/tests_tp1/test_15_segundos.txt'
#p = input('Ingrese p: ')
listaCantEntrantes,cantPaginas = LeerEntrantes(nombreArchivo)


nombreArchivoSalidas = '/home/brian/Desktop/TP1-MetNum-franco/salidas/test_15_segundos.txt.out'
listaRankings = leerSalidas(nombreArchivoSalidas,cantPaginas)

listaEntradasPromediadas, listaRankingsPromediados, listaErrores = promedioCosas(listaCantEntrantes,listaRankings)

#plt.plot(listaEntradasPromediadas,listaRankingsPromediados ,'ro')
#plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores)
plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores, label="ranking test_15_segundos", fmt="ro",  linewidth=3,  elinewidth=0.5, ecolor='k', capsize=5, capthick=0.5)
plt.legend()
plt.show()
nombreArchivo = '/home/brian/Desktop/TP1-MetNum-franco/tests_tp1/tests_tp1/grafo_denso.txt'
#p = input('Ingrese p: ')
listaCantEntrantes,cantPaginas = LeerEntrantes(nombreArchivo)


nombreArchivoSalidas = '/home/brian/Desktop/TP1-MetNum-franco/salidas/grafo_denso.txt.out'
listaRankings = leerSalidas(nombreArchivoSalidas,cantPaginas)

listaEntradasPromediadas, listaRankingsPromediados, listaErrores = promedioCosas(listaCantEntrantes,listaRankings)

#plt.plot(listaEntradasPromediadas,listaRankingsPromediados ,'ro')
#plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores)
plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores, label="ranking grafo_denso", fmt="rs--",  linewidth=3,  elinewidth=0.5, ecolor='k', capsize=5, capthick=0.5)
plt.legend()
plt.show()
nombreArchivo = '/home/brian/Desktop/TP1-MetNum-franco/tests_tp1/tests_tp1/grafo_patologico.txt'
#p = input('Ingrese p: ')
listaCantEntrantes,cantPaginas = LeerEntrantes(nombreArchivo)


nombreArchivoSalidas = '/home/brian/Desktop/TP1-MetNum-franco/salidas/grafo_patologico.txt.out'
listaRankings = leerSalidas(nombreArchivoSalidas,cantPaginas)

listaEntradasPromediadas, listaRankingsPromediados, listaErrores = promedioCosas(listaCantEntrantes,listaRankings)

#plt.plot(listaEntradasPromediadas,listaRankingsPromediados ,'ro')
#plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores)
plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores, label="ranking grafo_patologico", fmt="rs--",  linewidth=3,  elinewidth=0.5, ecolor='k', capsize=5, capthick=0.5)
plt.legend()
plt.show()


#cmd = './main ' + nombreArchivo + ' ' + p
#os.system(cmd)
