
import os
import matplotlib.pyplot as plt
import numpy as np
import subprocess
import numpy as np; np.random.seed(0)
import seaborn as sns; sns.set()


archivo = open("grafo_denso.txt",'w')
G = np.random.randint(2, size=(100,100))
archivo.write(str(100)+ '\n')
archivo.write(str(G.sum()) + '\n')
for i in range(0,100):
    for j in range(0,100):
        if(G[i][j] == 1):
            archivo.write(str(i+1) + ' ' + str(j+1) + '\n')

archivo2 = open("grafo_triangular_superior.txt",'w')
H = np.zeros((100,100))
for i in range(0,100):
    for j in range(0,100):
        if( j > i):
            H[i][j] = 1
archivo2.write(str(100)+ '\n')
archivo2.write(str(H.sum()) + '\n')
for i in range(0,100):
    for j in range(0,100):
        if(H[i][j] == 1):
            archivo2.write(str(i+1) + ' ' + str(j+1) + '\n')

K = np.zeros((100,100))
for i in range(0,100):
    for j in range(0,100):
        if( j > i):
            K[i][j] = 1
K[99][0] = 1

archivo3 = open("grafo_patologico.txt", 'w')
archivo3.write(str(100)+ '\n')
archivo3.write(str(K.sum()) + '\n')
for i in range(0,100):
    for j in range(0,100):
        if(K[i][j] == 1):
            archivo3.write(str(i+1) + ' ' + str(j+1) + '\n')


#plt.plot(listai EntradasPromediadas,listaRankingsPromediados ,'ro')
#plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores)
#plt.errorbar(listaEntradasPromediadas, listaRankingsPromediados, listaErrores, label="ranking", fmt="rs--",  linewidth=3,  elinewidth=0.5, ecolor='k', capsize=5, capthick=0.5)
#plt.show()
#cmd = './main ' + nombreArchivo + ' ' + p
#os.system(cmd)
