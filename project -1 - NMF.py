# -*- coding: utf-8 -*-
"""
Created on Tue Mar 21 17:01:40 2017

@author: CAO
"""

import matplotlib.pyplot as plt
import numpy as np
from sklearn.decomposition import NMF
import imtools as im
import cv2
from PIL import Image

img = np.double(plt.imread('2.jpg'))
row,col,dim = img.shape
# get each channel of image
imgR = img[:,:,0]
imgG = img[:,:,1]
imgB = img[:,:,2]

imgR = imgR.T.flatten()
imgG = imgG.T.flatten()
imgB = imgB.T.flatten()
# optical density
Dr = -np.log(imgR/max(imgR))
Dg = -np.log(imgG/max(imgG))
Db = -np.log(imgB/max(imgB))

OD = np.transpose(np.array([Dr,Dg,Db]))

# apply NMF
nf = NMF(n_components = 2)
w = nf.fit_transform(OD)
H = nf.components_
print(w.shape)
print(H.shape)
V = np.mat(w)*np.mat(H)
V = im.convertImg(V,row,col)

Rcom = np.mat(w[:,0]).T * np.mat(H[0,:])
imgRcom = im.convertImg(Rcom,row,col)
Bcom = np.mat(w[:,1]).T * np.mat(H[1,:])
imgBcom = im.convertImg(Bcom,row,col)

img = np.uint8(img)
plt.figure(1)
plt.imshow(img)

plt.figure(2)
plt.imshow(V)

plt.figure(3)
imgRGray = im.rgb2gray(imgRcom)
imgRGray = np.uint8(imgRGray*253)
thres,imgRR = cv2.threshold(imgRGray,0,255,cv2.THRESH_BINARY + cv2.THRESH_OTSU)
imgRR = 255 - imgRR
plt.imshow(imgRcom)
#plt.gray()

plt.figure(4)
imgBGray = im.rgb2gray(imgBcom)
imgBGray = np.uint8(imgBGray*253)
thres,imgBB = cv2.threshold(imgBGray,0,255,cv2.THRESH_BINARY + cv2.THRESH_OTSU)
#imgBB = 255 - imgBB
imgBB = imgBB/255
plt.imshow(imgBcom)
#plt.imshow(imgBcom)
plt.figure(5)
imgCom = imgRGray*imgBB
plt.imshow(imgCom)

plt.figure(6)
imgBw = im.delNoise(imgBB,50)
imgBw = 1 - imgBw
forCount = imgBw[np.where(imgBw == 0)]
numOfarea = len(forCount)
plt.imshow(imgBw)