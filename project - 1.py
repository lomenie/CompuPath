# -*- coding: utf-8 -*-
"""
Created on Wed Apr 19 12:01:39 2017

@author: CAO
"""

import numpy as np
import matplotlib.pyplot as plt
import color_decon as colde
import cv2
import imtools as im

img = plt.imread('RNA1.tif')

#chann1,chann2,chann3 = colde.color_deconvolution(img)
row,col,dimen = img.shape

plt.figure(1)
plt.gray()
plt.imshow(chann1)
plt.figure(2)
plt.gray()
plt.imshow(chann2)

chann1 = np.uint8(chann1)
chann2 = np.uint8(chann2)
#chann3 = np.uint8(chann3)
# do not need to change the histogram, the result will have more noise region 
# clahe method changes the histogram of the image.
#clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
#c1 = clahe.apply(chann1)
#chann2 = clahe.apply(chann2)
#plt.figure(1)
#plt.gray()
#plt.imshow(chann1)
#plt.figure(2)
#plt.gray()
#plt.imshow(chann2)

thres,bluish = cv2.threshold(chann1,0,255,cv2.THRESH_BINARY + cv2.THRESH_OTSU)
thres2,brownish = cv2.threshold(chann2,0,255,cv2.THRESH_BINARY + cv2.THRESH_OTSU)

plt.figure(3)
plt.imshow(bluish)
plt.figure(4)
plt.imshow(brownish)

bluish = 255 - bluish
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(2, 2))
bluishOpen = cv2.morphologyEx(bluish, cv2.MORPH_OPEN, kernel, iterations = 2)
bluishOpen = im.delNoise(bluish,10)

#sure the background area
sure_bg = cv2.dilate(bluishOpen,kernel,iterations = 3)

#finding sure foreground area
dist_transform = cv2.distanceTransform(bluishOpen,cv2.DIST_L2,5)
thres3,sure_fg = cv2.threshold(dist_transform,0.25*dist_transform.max(),255, 0)

#finding unknownn area
sure_fg = np.uint8(sure_fg)
unknown = cv2.subtract(sure_bg,sure_fg)

# marker labelling
ret,markers = cv2.connectedComponents(sure_fg)

# label the background as 1, so that all markers should be added one
markers = markers + 1

# label the unknown region as 0, so that we can change its value to segment the cells in the next step
markers[unknown == 255] = 0

mask = cv2.watershed(img,markers)
mask[mask == 0] = -1
img[mask == -1] = [255, 0, 0]
#numCells = np.max(markers) - 1

markers[markers <= 1] = 0 
markers[markers > 1] = 255
numCells,areaCells,labelCells = im.labelCells(markers)
# process the RNA molecules
#brownish = (255 - brownish) * (1/255)
brownish = (255 - brownish)
numRNA,areaRNA = im.countNum(brownish)
img[brownish == 255] = [255, 255, 0]



#plt.figure(5)
#plt.imshow(dist_transform)
#plt.figure(6)
#plt.imshow(brownish)
#plt.figure(7)
#plt.imshow(sure_fg)
plt.figure(5)
plt.imshow(img)
print('Tumor cells number:',numCells)
print('Tumor cells area:',areaCells)
print('RNA molecules number:',numRNA)
print('RNA molecules area:',areaRNA)
