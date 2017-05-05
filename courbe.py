# -*- coding: utf-8 -*-
"""
Created on Fri Apr 28 14:05:21 2017

@author: djiro
"""


from pylab import *
#from numpy import *
import numpy as np
import matplotlib.pyplot as ax

def lissage(Lx,Ly,p):
    '''Fonction qui débruite une courbe par une moyenne glissante
        sur 2P+1 points'''
    Lxout=[]
    Lyout=[]
    Lxout = Lx[p: -p]
    for index in range(p, len(Ly)-p):
        average = np.mean(Ly[index-p : index+p+1])
        Lyout.append(average)
    return Lxout,Lyout




#figure(figsize=(8,5), dpi=80)
#subplot(111)

dataG  = fromfile('/home/djiro/annotations/fichierCourbeX.txt', 'float32', sep='\n')
dataC  = fromfile('/home/djiro/annotations/fichierCourbeY.txt', 'float32', sep='\n')
x_orig    = dataG[::1]
y_orig     = dataC[::1]
#tu changes le pas de lissage (la tailel de la fenêtre glissante moyenneuse ici j'ai mis 20 par défaut
x,y = lissage(x_orig,y_orig,9)
#plt.grid(True)
plot(x, y, color="blue", linewidth=2.5, linestyle="-")
#legend('courbe lissée')

plot(x_orig, y_orig, color="red", linewidth=2.5, linestyle="-")
#legend("courbe lissée")

ax =gca()
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.spines['bottom'].set_position(('data',0))
ax.yaxis.set_ticks_position('left')
ax.spines['left'].set_position(('data',0))
ax.grid(True)

#ax.xlabel("Distance du Front: unité = 5µm")
#ax.ylabel("Nombres pixels objets Bio: unité = 1pixel")

savefig("/home/djiro/annotations/Courbe.png",dpi=72)
show()
