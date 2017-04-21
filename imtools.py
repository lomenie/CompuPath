# -*- coding: utf-8 -*-
"""
Created on Wed Feb 22 17:32:40 2017

@author: CAO
"""

#from PIL import Image
#from numpy import *
import numpy as np
import skimage.measure as skp
import matplotlib.pylab as plb

def histeq(im,nbr_bins = 256):
    """ equalization of histogram """
    imhist,bins = np.histogram(im.flatten(),nbr_bins,normed = True)
    cdf = imhist.cumsum()
    cdf = 255 * cdf / cdf[-1]
    im2 = np.interp(im.flatten(),bins[:-1],cdf)
    return im2.reshape(im.shape),cdf

def pca(X):
    """ Principal Component Analysis:
        input: Matrix X, each row represents an image which has been flatten
        output: reflected matrix, variance, mean value
        Note: This is used for 2D matrix
        Importan: after calculate, it should be reshaped,
                  like: imshow(V[i].reshape(m,n))"""
        
    num_data,dim = X.shape #dimention of matrix
    mean_X = X.mean(axis = 0)
    X = X - mean_X
    
    if dim > num_data: # This means that there are too many data in this stack
        M = np.dot(X,X.T) # covariance matrix = X * X(T)
        e,Ev = np.linalg.eigh(M) # eigenvalue and eigenvector
        tmp = np.dot(X.T,Ev).T # key step
        V = tmp[::-1] # reverse the sequence
        S = np.sqrt(e)[::-1] 
        
        for i in range(V.shape[1]):
            V[:,i] /= S
    else:
        # by SVD method
        U,S,V = np.linalg.svd(X)
        V = V[:,num_data]
        
    return V,S,mean_X
    
def OtsuPy(img):
    gray=[0 for i in range(pow(2,8))] 
    height,width = img.shape
    for h in range(height): 
        for w in range(width): 
            gray[int(img[h,w])]+=1 

    maxV=0 
    bestTh=0 
    w=[0 for i in range(len(gray))] 
    px=[0 for i in range(len(gray))] 
    w[0]=gray[0] 
    px[0]=0 
    for m in range(1,len(gray)): 
            w[m]=w[m-1]+gray[m] 
            px[m]=px[m-1]+gray[m]*m 
    for th in range(len(gray)): 
            w1=w[th] 
            w2=w[len(gray)-1]-w1 
            if(w1*w2==0): 
                    continue 
            u1=px[th]/w1 
            u2=(px[len(gray)-1]-px[th])/w2 
            v=w1*w2*(u1-u2)*(u1-u2) 
            if v>maxV: 
                    maxV=v 
                    bestTh=th 
    return bestTh

def delNoise(img,numOfNoise):
    
    img = plb.array(img)
#    im5 = im4
    label_img = skp.label(img,connectivity = 2)
    props = skp.regionprops(label_img)

    for i in range(len(props)):
        if props[i].area < numOfNoise:
            img[np.where(label_img == i+1)] = 0
            
    return img
def getCentroid(img):
    img = plb.array(img)
#    im5 = im4
    label_img = skp.label(img,connectivity = 2)
    props = skp.regionprops(label_img)
#    centroidList = ()

#    centroidList = [[] for i in range(len(props))]
    a = [[] for i in range(len(props))]
    b = [[] for i in range(len(props))]
    for i in range(len(props)):
#        centroidList[i].append(props[i].centroid)
        a[i].append(props[i].centroid[0])
        b[i].append(props[i].centroid[1])
    
#    centro = tuple(centroidList)
    return a,b

def convertImg(img,row,col):
    imgVR = np.reshape(img[:,0],(row,col),order = 'F')
    imgVG = np.reshape(img[:,1],(row,col),order = 'F')
    imgVB = np.reshape(img[:,2],(row,col),order = 'F')
    
    imgV = np.zeros((row,col,3))
    imgV[:,:,0] = imgVR
    imgV[:,:,1] = imgVG
    imgV[:,:,2] = imgVB
    
    return imgV

def rgb2gray(rgb):
    return np.dot(rgb[...,:3], [0.299, 0.587, 0.144])

def file2list(filename):
    # read matrix from a file and import it as a matrix (n rows and 3 columns)
    fr = open(filename,'r')
    
    array = fr.readlines()
    num = len(array)  
    returnMat = np.zeros((num,3))
    index = 0   
    
    for line in array:  
        line = line.strip('\n')
        linelist = line.split('\t')
        returnMat[index,:] = linelist[0:3]
        index +=1
    return returnMat

def countNum(img):
    img = plb.array(img)
#    im5 = im4
    label_img = skp.label(img,connectivity = 1)
    num = np.max(label_img)
    props = skp.regionprops(label_img)
    areaObj = 0

    for i in range(len(props)):
        areaObj = areaObj + props[i].area
    return num,areaObj

def labelCells(img):
    img = plb.array(img)
#    im5 = im4
    label_img = skp.label(img,connectivity = 1)
    num = np.max(label_img)
    props = skp.regionprops(label_img)
    areaObj = 0

    for i in range(len(props)):
        areaObj = areaObj + props[i].area
    return num,areaObj,label_img