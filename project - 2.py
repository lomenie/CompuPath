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
import copy
import win32api,win32con

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

# use watershed to segment the cells
mask = cv2.watershed(img,markers)
# set the edge as red color
mask[mask == -1] = 0
img[mask == 0] = [255, 0, 0]
numCells = np.max(markers) - 1
# in labeled image, 0 as edge,1 as background, change to 0 as background, 1...end as cells
labelCells = copy.deepcopy(mask)
labelCells = labelCells - 1
labelCells[labelCells == -1] = 0
# calculate the area of cells
cells1 = copy.deepcopy(labelCells)
cells1[cells1 > 0] = 1
areaCells = np.sum(cells1 == 1)
#for i in range(numCells):
#    areaCells = areaCells + np.sum(labelCells == i+1)

# process the RNA molecules
brownish = (255 - brownish) * (1/255)
#brownish = (255 - brownish)
numRNA,areaRNA,labelRNA = im.countNum(brownish)


labelCellAndRNA = labelCells * brownish

stainedCells = np.unique(labelCellAndRNA)
numStain = len(stainedCells) - 1
# calculate the area of RNA in nuclei
cells2 = copy.deepcopy(labelCellAndRNA)
cells2[cells2 > 0] = 1
areaRNAInside = np.sum(cells2 == 1)

# number of RNA inside nuclei
RNAInside = cells1 * labelRNA
numRNAInside = len(np.unique(RNAInside)) - 1

# the area of RNA in cytoplasm
cells3 = brownish - cells2
areaOfRNAInCyto = areaRNA - areaRNAInside

# set RNA molecule inside nuclei as yellow
img[cells2 == 1] = [255, 255, 0]
img[cells3 == 1] = [0, 255, 0]

#for i in range(1,len(stainedCells)):
#    stainedCellsArea = stainedCellsArea + np.sum(labelCellAndRNA == stainedCells[i])
areaOfImg = row*col

plt.figure(5)
plt.imshow(img)

print('Total tumor cells number:',numCells)
print('Total tumor cells area:',areaCells)
print('Total RNA molecules number:',numRNA)
print('Total RNA molecules area:',areaRNA)
print('The number of tumor cells with RNA:',numStain)
print('The number of RNA inside nuclei:',numRNAInside)
print('The area of RNA inside nuclei:',areaRNAInside)
print('The area of RNA inside cytoplasm:',areaOfRNAInCyto)
print('')
print('The percentage of cells nuclei with RNA: %.4f %%' %(numStain/numCells*100))
print('The percentage of RNA in nuclei: %.4f %%' %(areaRNAInside/areaRNA*100))
print('Stained RNA area in the all the cells: %.4f %%' %(areaRNA/areaCells*100))
print('Stained RNA area in the image: %.4f %%' %(areaRNA/areaOfImg*100))
print('Stained area (cells and RNA) in the image: %.4f %%' %((areaCells+areaRNA)/areaOfImg*100))

# ask if you want to select a ROI?
result = win32api.MessageBox(None,'Do you want to select a ROI ?','Select ROI',win32con.MB_YESNO|win32con.MB_ICONWARNING|win32con.MB_DEFBUTTON2)

#if result == win32con.IDYES:
#    print(1)
#else:
#    print(0)
fromCenter = False
showCrosshair = False

while result == win32con.IDYES:
    r = cv2.selectROI('Image',img,fromCenter,showCrosshair)
    # construct a mask of ROI
    maskROI = np.zeros((row,col))
    maskROI[int(r[1]):int(r[1]+r[3]), int(r[0]):int(r[0]+r[2])] = 1
    
    # the area of ROI
    areaROI = r[2]*r[3]
    # labeled cells in ROI
    cellROI = maskROI * labelCells
    numCellsROI = len(np.unique(cellROI)) - 1
    # area of cells in ROI
    areaCellROI = np.sum(cellROI > 0)
    # RNA in ROI
    RNAROI = maskROI * labelRNA
    numRNAROI = len(np.unique(RNAROI)) - 1
    areaRNAROI = np.sum(RNAROI > 0)
    
    cellRNAROI = maskROI * labelCellAndRNA
    numCellRNAROI = len(np.unique(cellRNAROI)) - 1
    areaCellRNAROI = np.sum(cellRNAROI > 0)
    
    RNAinsideROI = maskROI * RNAInside
    numRNAinsideROI = len(np.unique(RNAinsideROI)) - 1
    
    plt.figure(5)
    imCrop = img[int(r[1]):int(r[1]+r[3]), int(r[0]):int(r[0]+r[2])]
    plt.imshow(imCrop)
    
    print('')
    print('Information of ROI:')
    print('Total tumor cells number in ROI:',numCellsROI)
    print('Total tumor cells area in ROI:',areaCellROI)
    print('Total RNA molecules number in ROI:',numRNAROI)
    print('Total RNA molecules area in ROI:',areaRNAROI)
    print('The number of tumor cells with RNA in ROI:',numCellRNAROI)
    print('The number of RNA inside nuclei in ROI:',numRNAinsideROI)
    print('The area of RNA inside nuclei in ROI:',areaCellRNAROI)
    print('The area of RNA inside cytoplasm in ROI:',areaRNAROI - areaCellRNAROI)
    print('')
    print('The percentage of cells nuclei with RNA in ROI: %.4f %%' %(numCellRNAROI/numCellsROI*100))
    print('The percentage of RNA inside nuclei in ROI: %.4f %%' %(areaCellRNAROI/areaRNAROI*100))
    print('Stained RNA area in the all the cells of ROI: %.4f %%' %(areaRNAROI/areaCellROI*100))
    print('Stained RNA area in the ROI: %.4f %%' %(areaRNAROI/areaROI*100))
    print('Stained area (cells and RNA) in the ROI: %.4f %%' %((areaCellROI+areaRNAROI)/areaOfImg*100))
    
    result = win32api.MessageBox(None,'Do you want to select a ROI ?','Select ROI',win32con.MB_YESNO|win32con.MB_ICONWARNING|win32con.MB_DEFBUTTON2)
    
            
if result == win32con.IDNO:
    import win32gui
    def handle_window(hwnd, extra):
        if win32gui.IsWindowVisible(hwnd):
            if 'Image' in win32gui.GetWindowText(hwnd):
                win32gui.PostMessage(hwnd, win32con.WM_CLOSE, 0, 0)
    
    win32gui.EnumWindows(handle_window, None)