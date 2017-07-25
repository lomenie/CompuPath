%% read a deconvolution image
% this function will give you the results of:
% contrast improvement
% remove the background by keeping level-lines(Maya's method)
% filter the noise (by open operator or by area pixel threshold)
% k-means for two clusters and construc a mask
% segment the connectted components by Watershed transform
% construct colormap to indicate the staining degree
% fuse the result with the original image
%
% Dengfeng CAO - comprehensive code for the first try
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

img = imread('RNAscope.tif'); % this is a deconvolution image
% immm = im2bw(img);
img2 = 255.0 * ((double(img)/255.0).^2);
% img2 = img;
figure(1)
% gray;
imshow(img,[])
figure(2)
imshow(img2,[])
grayMean = mean(mean(img2));
img2(find(img >= grayMean)) = 255;
figure(3)
imshow(img2,[])
img3 = 255 - img2;
figure(4)
imshow(img3,[])

% filter the noise by open operator
% se = strel('disk',3);
% img4 = imopen(img3,se);

% another way to filter noise by object area less than a threshold
transImg = img3;
transImg(find(transImg > 0)) == 1;
transImg = bwareaopen(transImg,30);
img4 = img3.*transImg;

img5 = 255 - img4;
figure(5)
imshow(img5,[])


L = bwlabel(img4,8); % label the different connected area
maxL = max(max(L));

indexImg = [];
map = [1,0,0];
% use k-means to get two clusters for each object
for i=1:maxL
    [row,col] = find(L == i);
    crop = img4(sub2ind(size(img4),row,col));
    indexImg(:,1:3) = [row,col,crop];
    idxK = kmeans(crop,2);
    idxC1 = find(idxK == 1);
    idxC2 = find(idxK == 2);
    cluster1 = indexImg(idxC1,:);
    cluster2 = indexImg(idxC2,:);
    if isempty(cluster1)
        nucleus = cluster2;
    elseif isempty(cluster2)
        nucleus = cluster1;
    else
        if cluster1(1,3) < cluster2(1,3)
            nucleus = cluster2;
        else
            nucleus = cluster1;
        end
    end
    testImg = zeros(390,456);
    testImg(sub2ind(size(testImg),nucleus(:,1),nucleus(:,2))) = nucleus(:,3);
    testImg = int16(testImg); 
    % because the maximum of int8 is 127
    
    maskImg(:,:,i) = testImg;
    indexImg = [];
    testImg = [];
end
    maskNuclei = int16(zeros(390,456)); 
    % because '+' can only be used for integer 
    % and label2rgb function needs integer number
    
    % merge all the obtained objects
    for i=1:maxL
        buf = maskImg(:,:,i);
        maskNuclei = maskNuclei + buf;
    end
    % use Watershed transform to segment connected components and 
    % construct a binary mask
    maskNuclei = double(maskNuclei);
    maskNucleiBW = im2bw(maskNuclei);
    maskNucleiDis= -bwdist(~maskNucleiBW); 
    maskNuclei2 = imextendedmin(maskNucleiDis,2);
    maskNucleiDis2 = imimposemin(maskNucleiDis,maskNuclei2); 
    maskNucleiWatershed = watershed(maskNucleiDis2);
    finalNuclei = maskNucleiBW;
    finalNuclei(maskNucleiWatershed == 0) = 0; % have the boundary of each cell
    figure(6)
    maskNucleiBW2 = 1 - maskNucleiBW;
    imshow(maskNucleiBW2,[])
    figure(7)
    finalNuclei2 = 1 - finalNuclei;
    length(finalNuclei2(find(finalNuclei2 == 0)))
    imshow(finalNuclei2,[])
    % apply the segmented mask for previous result
    SegNuclei = maskNuclei.*finalNuclei;
    figure(8)
    % construct colormap to represent staining degree
    map = flipdim(colormap('jet'),1);
    SegNuclei2 = SegNuclei;
    SegNuclei2(find(SegNuclei2>0)) = 255 - SegNuclei2(find(SegNuclei2>0));
    SegNuclei2 = round(SegNuclei2*(64/255)); % because there are 64
%     different colors in 'jet' colormap, so if when the value more than
%     64, there is no color to assign. So it is importan to normalize the
%     image value
    maskNucleiWithColor= label2rgb(SegNuclei2,map,'w');
%     maskNucleiWithColor= label2rgb(maskNuclei,'jet','k');
    imshow(maskNucleiWithColor,[])
    colormap(map)
    colorbar;
%     set(h,'YTick',255:-1:0)
% fuse results
    figure(9)
    fuse = imfuse(img5,maskNucleiWithColor,'blend');
%     fuse = imfuse(img4,maskNucleus,'blend','scaling','joint');
    imshow(fuse,[])
    colormap(map)
    colorbar;
    figure(10)
    fuse2 = imfuse(img,maskNucleiWithColor,'blend');
    imshow(fuse2,[])
    colormap(map)
    colorbar;
    countDAB = cellNum(finalNuclei);
    
%     colorOut = [1,0,0];
%     h = patch(nucleus(:,1),456 - nucleus(:,2),rand(1,3),'visible','on');
%     
%     set(h,'FaceColor',colorOut);
%% trying the Hierarchical Clustering tree
% imgDis = pdist(img2);
% imgDis2 = squareform(imgDis);
% treeS = linkage(imgDis2,'average');
% figure(4)
% dendrogram(treeS)

%%
% img2 = uint8(img2);
% th = graythresh(img2);
% img3 = im2bw(img2,th);
% figure(4)
% imshow(img3,[])
% img3 = uint8(img3);
% img3(find(img3 == 0)) = 2;
% img3(find(img3 == 1)) = 0;
% img3(find(img3 == 2)) = 1;
% img4 = bwareaopen(img3,100);
% figure(5)
% imshow(img3,[])
% figure(6)
% imshow(img4,[])



% img4 = delNoise(img3);
% figure(5)
% imshow(immm,[])
% im = delNoise(immm);
% figure(6)
% imshow(im,[])
% tConnectArea = bwconncomp(img3);
% tCenter = regionprops(tConnectArea,'Centroid');
% tArea = regionprops(tConnectArea,'Area');
% tn = length(tCenter);
% L = bwlabel(img3,8);