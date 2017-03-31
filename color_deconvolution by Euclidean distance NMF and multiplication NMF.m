%% this script tests the NMF based on Euclidean and multiplication NMF
tic
img = double(imread('RNAscope3.tif'));
[rowImg,colImg,dimention] = size(img);
imgR = img(:,:,1);
imgG = img(:,:,2);
imgB = img(:,:,3);

% figure(1)
% imshow(imgR,[])
% figure(2)
% imshow(imgG,[])
% figure(3)
% imshow(imgB,[])
imgR = imgR(:);
imgG = imgG(:);
imgB = imgB(:);

%optical density
Dr = -log(imgR/max(imgR));
Dg = -log(imgG/max(imgG));
Db = -log(imgB/max(imgB));
OD = [Dr,Dg,Db;];
[row,col] = size(OD);
% apply NMF
r = 2;
W = zeros(row,r);
H = zeros(r,col);
% [W,H] = NMF_EuclideanD(OD,r);
[W,H] = nnmf(OD,r);

% dA = reshape(W,rowImg,colImg,r);% density of A
% iA = exp(-dA);% intensity of A
% iS = exp(-H);% intensity of S

% reconsctruct the image by W and H
recon = W*H;
reconImg = convertImgCol(recon,rowImg,colImg);
% extract one component of the image
Rcom = W(:,1)*H(1,:);
imgRcom = convertImgCol(Rcom,rowImg,colImg);
Bcom = W(:,2)*H(2,:);
imgBcom = convertImgCol(Bcom,rowImg,colImg);

imgRcomGray = rgb2gray(imgRcom);
thR = graythresh(imgRcomGray);
imgRcomBw = im2bw(imgRcomGray,thR);

imgBcomGray = rgb2gray(imgBcom);
th = graythresh(imgBcomGray);
imgBcomBw = im2bw(imgBcomGray,th);

% Gcom = W(:,3)*H(3,:);
% imgGcom = convertImgCol(Gcom,rowImg,colImg);
runTime = toc
img = uint8(img);
figure(1)
imshow(img,[])
figure(2);
imshow(reconImg,[])
figure(3)
imshow(imgRcom,[])
figure(4)
imshow(imgBcom,[])
figure(5)
imshow(imgBcomGray,[])
figure(6)
imshow(imgBcomBw,[])
figure(7)
imshow(imgRcomBw,[])