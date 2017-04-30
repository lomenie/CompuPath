%% realize color deconvolution approach according to FIJI plugin
% specific absorbtion value for red, green,blue on slides stained by
% hematoxylin and RNAscope
colorMap = [0.650,0.704,0.286; % hematoxylin
            0.268,0.570,0.776;%RNAscope
            0,0,0;];
% this matrix just for text
% colorMap = [0.18,0.20,0.08; % hematoxylin
%             0.01,0.13,0.01;
%             0.10,0.21,0.29;];%RNAscope
[row,col] = size(colorMap);
% translation matrix
colorMapNor = [];
for i=1:row-1
    len = sqrt(colorMap(i,1).^2+colorMap(i,2).^2+colorMap(i,3).^2);
    colorMapNor(i,:) = colorMap(i,:)/len;
end
if colorMapNor(1,1).^2 + colorMapNor(2,1).^2 > 1
    colorMapNor(3,1) = 0;
else 
    colorMapNor(3,1) = sqrt(1 - colorMapNor(1,1).^2 - colorMapNor(2,1).^2);
end

if colorMapNor(1,2).^2 + colorMapNor(2,2).^2 > 1
    colorMapNor(3,2) = 0;
else 
    colorMapNor(3,2) = sqrt(1 - colorMapNor(1,2).^2 - colorMapNor(2,2).^2);
end

if colorMapNor(1,3).^2 + colorMapNor(2,3).^2 > 1
    colorMapNor(3,3) = 0;
else 
    colorMapNor(3,3) = sqrt(1 - colorMapNor(1,3).^2 - colorMapNor(2,3).^2);
end
len = sqrt(colorMapNor(3,1).^2+colorMapNor(3,2).^2+colorMapNor(3,3).^2);
colorMapNor(3,:) = colorMapNor(3,:)/len;

% matrix inversion
A = colorMapNor(2,2) - colorMapNor(2,1) * colorMapNor(1,2) / colorMapNor(1,1);
V = colorMapNor(2,3) - colorMapNor(2,1) * colorMapNor(1,3) / colorMapNor(1,1);
C = colorMapNor(3,3) - colorMapNor(3,2) * V/A + colorMapNor(3,1) * ...
    (V/A * colorMapNor(1,2) / colorMapNor(1,1) - colorMapNor(1,3)/colorMapNor(1,1));
q = zeros(1,9);
q(3) = (-colorMapNor(3,1) / colorMapNor(1,1) - colorMapNor(3,1) / A * ...
    colorMapNor(2,1) / colorMapNor(1,1) * colorMapNor(1,2) / colorMapNor(1,1) + ...
    colorMapNor(2,2)/A*colorMapNor(2,1)/colorMapNor(1,1)) / C;
q(2) = -q(3) * V / A - colorMapNor(2,1) / (colorMapNor(1,1) * A);
q(1) = 1.0 / colorMapNor(1,1) - q(2) * colorMapNor(1,2) / colorMapNor(1,1) - q(3) * ...
    colorMapNor(1,3) / colorMapNor(1,1);
q(6) = (-colorMapNor(3,2) / A + colorMapNor(3,1) / A * colorMapNor(1,2) / colorMapNor(1,1)) / C;
q(5) = -q(6) * V / A + 1.0 / A;
q(4) = -q(5) * colorMapNor(1,2) / colorMapNor(1,1) - q(6) * colorMapNor(1,3) / colorMapNor(1,1);
q(9) = 1.0 / C;
q(8) = -q(9) * V / A;
q(7) = -q(8) * colorMapNor(1,2) / colorMapNor(1,1) - q(9) * colorMapNor(1,3) / colorMapNor(1,1);

% img9 = imread('RNAscope5.tif'); % the image is the third decomposed color of
% % original image in FIJI
% imshow(img,[])
imgOri = imread('RNAscope3.tif');
img = double(imgOri);
[rowImg,colImg,dimention] = size(img);
% extract and transform each channel
imgR = img(:,:,1);
imgG = img(:,:,2);
imgB = img(:,:,3);

imgR = imgR(:);
imgG = imgG(:);
imgB = imgB(:);

%optical density
Dr = -log(imgR/max(imgR));
Dg = -log(imgG/max(imgG));
Db = -log(imgB/max(imgB));
OD = [Dr,Dg,Db;];
[row,col] = size(OD);

% initialization of three translated images
% transR = -((255.0 * log((double(imgR+1))/255.0))/log(255.0));
% transG = -((255.0 * log((double(imgG+1))/255.0))/log(255.0));
% transB = -((255.0 * log((double(imgB+1))/255.0))/log(255.0));

newImg = zeros(row,3);

for i=1:row
    transR = -((255.0 * log((double(imgR(i)+1))/255.0))/log(255.0));
    transG = -((255.0 * log((double(imgG(i)+1))/255.0))/log(255.0));
    transB = -((255.0 * log((double(imgB(i)+1))/255.0))/log(255.0));
    for j = 1:3
        Rscaled = transR * q(j*3-2);
        Gscaled = transG * q(j*3-1);
        Bscaled = transB * q(j*3);
        output = exp(-((Rscaled + Gscaled + Bscaled) - 255.0) * log(255.0) / 255.0);
        if (output >255) 
            output = 255;
        end
        newImg(i,j) = output;
    end
end
newImg = uint8(newImg);
imgRR = reshape(newImg(:,1),rowImg,colImg);
imgGG = reshape(newImg(:,2),rowImg,colImg);
imgBB = reshape(newImg(:,3),rowImg,colImg);

figure(1)
imshow(imgOri,[])
figure(2)
imshow(imgRR,[])
imwrite(imgRR,'abc.bmp');
figure(3)
imshow(imgGG,[])
imwrite(imgGG,'abc2.bmp');
figure(4)
imshow(imgBB,[])
thG = graythresh(imgGG);
imgGGBW = im2bw(imgGG,thG);
figure(5)
imshow(imgGGBW,[])
imwrite(imgGGBW,'abc3.bmp');
thR = graythresh(imgRR);
imgRRBW = im2bw(imgRR,thR);
figure(6)
imshow(imgRRBW,[])
imgRR2 = 255.0 * ((double(imgRR)/255.0).^2);
grayMean = mean(mean(imgRR2));
imgRR2(find(imgRR >= grayMean)) = 255;
figure(7)
imshow(imgRR2,[])
figure(8)
imgRR3 = 255 - imgRR2;
se = strel('disk',2);
imgRR4 = imopen(imgRR3,se);
imgRR4 = uint8(255 - imgRR4);
imshow(imgRR4,[])
% imwrite(imgRR4,'abc.bmp');
% figure(1)
% img2 = convertImgCol(OD*c,rowImg,colImg);
% % img2 = uint8(img2);
% imshow(img2,[])
% figure(2)
% tran = OD(:,3)*c(1,:);
% img3 = convertImgCol(tran,rowImg,colImg);
% % img3 = uint8(img3);
% colormap('gray')
% imshow(img3,[])
% figure(3)
% cc = rgb2gray(img3);
% imshow(cc,[])

