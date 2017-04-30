%% tried Maya's formulas for color decomposition
img = imread('RNAscope1.tif');
figure(1)
imshow(img,[])s
imgRed = img(:,:,1);
imgGreen = img(:,:,2);
imgBlue = img(:,:,3);
% the formula: blue - 0.3*(red + green) (less efficient)
Brown  = imgBlue - 0.3*(imgRed + imgGreen);
figure(2)
imshow(Brown,[])
th = graythresh(Brown);
BrownBw = im2bw(Brown,th);
BrownBw = 1 - BrownBw;
BrownBw = bwareaopen(BrownBw,50);
BrownBw = 1 - BrownBw;
numOfBrown = length(BrownBw(find(BrownBw == 0)))
figure(3)
imshow(BrownBw,[])
% remain the negative level-line
grayMean = mean(mean(Brown));
Brown(find(Brown >= grayMean)) = 255;
figure(4)
imshow(Brown,[])
% the formula: blue^2/red (this is more effective)
bb = double(imgBlue).*double(imgBlue);
DAB = bb./double(imgRed);
DAB = uint8(DAB);
figure(5)
imshow(DAB,[])
th2 = graythresh(DAB);
DABbw = im2bw(DAB,th2);
DABbw = 1 - DABbw;
DABbw = bwareaopen(DABbw,50);
DABbw = 1 - DABbw;
numOfDAB = length(DABbw(find(DABbw == 0)))
figure(6)
imshow(DABbw,[])