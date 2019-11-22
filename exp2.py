
import os
import matplotlib.pyplot as plt
import numpy as np
import subprocess
import numpy as np; np.random.seed(0)
import seaborn as sns; sns.set()


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
nombreArchivo = '/home/brian/Desktop/TP1-MetNum-franco/tests_tp1/tests_tp1/test_15_segundos.txt'

listaCantEntrantes,cantPaginas = LeerEntrantes(nombreArchivo)



nombreArchivoSalidas = '/home/brian/Desktop/TP1-MetNum-franco/salidas/test_15_segundos.txt.out'
listaP =  []



p = 0.00


subprocess.call(["./main", "tests_tp1/tests_tp1/test_15_segundos.txt", str(p)])
listaRankings = leerSalidas(nombreArchivoSalidas,cantPaginas)
listaEntradasPromediadas, listaRankingsPromediados, listaErrores = promedioCosas(listaCantEntrantes,listaRankings)
matriz = np.zeros(shape=(11,len(listaEntradasPromediadas)))
for i in range(0,11):
    listaP.append(round(p,2))
    p += 0.1

    subprocess.call(["./main", "tests_tp1/tests_tp1/test_15_segundos.txt", str(p)])
    listaRankings = leerSalidas(nombreArchivoSalidas,cantPaginas)
    listaEntradasPromediadas, listaRankingsPromediados, listaErrores = promedioCosas(listaCantEntrantes,listaRankings)
    for j in range(0,len(listaEntradasPromediadas)):
        matriz[i][j] = listaRankingsPromediados[j]

    # hay que hacer matriz M e (len(listaEntradasPromediadas),20) donde en M[i][j] = rankingPromedioDe(lasPaginasCOn(listaEntradasPromediadas[i]),p[j])

#uniform_data = np.matrix([[2,10,4,5,6],[7,9,5,6,6],[2,10,4,7,8],[7,9,3,4,5],[2,10,3,2,1],[7,9,2,3,4],[2,30,1,2,3]])

ax = sns.heatmap(matriz, xticklabels=listaEntradasPromediadas, yticklabels=listaP)
ax.invert_yaxis()
#a = np.matrix([[1,2,3,4],[19,4900,39,49],[1,2,3,4]])
#plt.imshow(a, cmap='hot', interpolation='nearest')
plt.show()


#plt.plot(listaEntradasPromediadas,listaRankingsPromediados ,'ro')
#plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores)
#plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores, label="ranking", fmt="rs--",  linewidth=3,  elinewidth=0.5, ecolor='k', capsize=5, capthick=0.5)
#plt.show()
#cmd = './main ' + nombreArchivo + ' ' + p
#os.system(cmd)
