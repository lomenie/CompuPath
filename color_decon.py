# -*- coding: utf-8 -*-
"""
Created on Wed Apr 19 10:23:45 2017

@author: CAO
"""

import numpy as np
import os
import math

def color_deconvolution(img):
    """ this function is used for color_deconvolution
        input image is a rgb image
        output is three images of different channels
    """
    

    img = np.double(img)
    
    rowImg,colImg,di = img.shape
    # judge if the image is RGB image
    dim = img.ndim
    if dim != 3:
        os._exit(0)
        
    # define the vectors of color component in the image
    # the first row is hematoxylin, second: RNAScope
    colorMap = np.array([[0.650,0.704,0.286],[0.268,0.570,0.776],[0,0,0]]) # the hematoxylin and DAB
    
#    colorMap = np.array([[0.650,0.704,0.286],[0.072,0.990,0.105],[0,0,0]]) # the hematoxylin and eosin
    # test colors which are not vectors
#    colorMap = np.array([[0.481,0.555,0.744],[0.686,0.742,0.871],[0.882,0.903,0.941]])
    row,col = colorMap.shape
    
    # translation matrix
    colorMapNor = np.zeros((row,col))
    
    for i in range(row-1):
        div = np.sqrt(np.power(colorMap[i,0],2) + np.power(colorMap[i,1],2) + np.power(colorMap[i,2],2))
        colorMapNor[i,:] = colorMap[i,:] / div
    
    if np.power(colorMapNor[0,0],2) + np.power(colorMapNor[1,0],2) > 1:
        colorMapNor[2,0] = 0
    else:
        colorMapNor[2,0] = np.sqrt(1 - np.power(colorMapNor[0,0],2) - np.power(colorMapNor[1,0],2))
    
    if np.power(colorMapNor[0,1],2) + np.power(colorMapNor[1,1],2) > 1:
        colorMapNor[2,1] = 0
    else:
        colorMapNor[2,1] = np.sqrt(1 - np.power(colorMapNor[0,1],2) - np.power(colorMapNor[1,1],2))
        
    if np.power(colorMapNor[0,2],2) + np.power(colorMapNor[1,2],2) > 1:
        colorMapNor[2,2] = 0
    else:
        colorMapNor[2,2] = np.sqrt(1 - np.power(colorMapNor[0,2],2) - np.power(colorMapNor[1,2],2))
        
    div = np.sqrt(np.power(colorMapNor[2,0],2) + np.power(colorMapNor[2,1],2) + np.power(colorMapNor[2,2],2))
    colorMapNor[2,:] = colorMapNor[2,:] / div
    
    # matrix inversion
    A = colorMapNor[1,1] - colorMapNor[1,0] * colorMapNor[0,1] / colorMapNor[0,0];
    V = colorMapNor[1,2] - colorMapNor[1,0] * colorMapNor[0,2] / colorMapNor[0,0];
    C = colorMapNor[2,2] - colorMapNor[2,1] * V/A + colorMapNor[2,0] * \
        (V/A * colorMapNor[0,1] / colorMapNor[0,0] - colorMapNor[0,2]/colorMapNor[0,0])
    q = np.zeros((9,1))
    q[2] = (-colorMapNor[2,0] / colorMapNor[0,0] - colorMapNor[2,0] / A * \
        colorMapNor[1,0] / colorMapNor[0,0] * colorMapNor[0,1] / colorMapNor[0,0] + \
        colorMapNor[1,1] / A * colorMapNor[1,0]/colorMapNor[0,0]) / C
    q[1] = -q[2] * V / A - colorMapNor[1,0] / (colorMapNor[0,0] * A)
    q[0] = 1.0 / colorMapNor[0,0] - q[1] * colorMapNor[0,1] / colorMapNor[0,0] - q[2] * \
        colorMapNor[0,2] / colorMapNor[0,0]
    q[5] = (-colorMapNor[2,1] / A + colorMapNor[2,0] / A * colorMapNor[0,1] / colorMapNor[0,0]) / C
    q[4] = -q[5] * V / A + 1.0 / A
    q[3] = -q[4] * colorMapNor[0,1] / colorMapNor[0,0] - q[5] * colorMapNor[0,2] / colorMapNor[0,0]
    q[8] = 1.0 / C;
    q[7] = -q[8] * V / A;
    q[6] = -q[7] * colorMapNor[0,1] / colorMapNor[0,0] - q[8] * colorMapNor[0,2] / colorMapNor[0,0];
    
    # extract and transform each channel
    imgR = img[:,:,0].T.flatten()
    imgG = img[:,:,1].T.flatten()
    imgB = img[:,:,2].T.flatten()
    
    # calculate and construct new image
    length = len(imgR)
    newImg = np.zeros((length,3))
    
    for i in range(length):
        transR = -((255.0 * math.log((np.double(imgR[i]+1))/255.0))/math.log(255.0));
        transG = -((255.0 * math.log((np.double(imgG[i]+1))/255.0))/math.log(255.0));
        transB = -((255.0 * math.log((np.double(imgB[i]+1))/255.0))/math.log(255.0));
        
        for j in range(3):
            Rscaled = transR * q[j*3];
            Gscaled = transG * q[j*3+1];
            Bscaled = transB * q[j*3+2];
    
            output = math.exp(-((Rscaled + Gscaled + Bscaled) - 255.0) * math.log(255.0) / 255.0);
            
            if output > 255:
                output = 255
                
            newImg[i,j] = output
            
    imgVR = np.reshape(newImg[:,0],(rowImg,colImg),order = 'F')
    imgVG = np.reshape(newImg[:,1],(rowImg,colImg),order = 'F')
    imgVB = np.reshape(newImg[:,2],(rowImg,colImg),order = 'F')
    
    return imgVR,imgVG,imgVB