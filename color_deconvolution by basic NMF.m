%% the realization for color deconvolution by basic NMF
img = double(imread('RNAscope1.tif'));
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
imgR = imgR(:)';
imgG = imgG(:)';
imgB = imgB(:)';

%optical density
Dr = -log(imgR/max(imgR));
Dg = -log(imgG/max(imgG));
Db = -log(imgB/max(imgB));
OD = [Dr;Dg;Db;];

col = length(imgR);
% % construct 
% img2 = [imgR;imgG;imgB;];
% [row,col] = size(img2);

k = 2; % how many components in this image?
W = rand(3,k);
H = rand(k,col);
maxiter = 100;
for iter=1:maxiter
    W = W.*((OD./(W*H))*H');
    W=W./(ones(3,1)*sum(W));
    H=H.*(W'*(OD./(W*H)));
end
img3 = W*H;
imgV = convertImg(img3,rowImg,colImg);

Rcom = W(:,1)*H(1,:);
imgRcom = convertImg(Rcom,rowImg,colImg);

Bcom = W(:,2)*H(2,:);
imgBcom = convertImg(Bcom,rowImg,colImg);

img = uint8(img);
% imgV = uint8(imgV);
figure(1)
imshow(img,[])
figure(2);
imshow(imgV,[])
figure(3)
imshow(imgRcom,[])
figure(4)
imshow(imgBcom,[])
