function [W,H]=NMF_EuclideanD(V,r)  
% V is n*m matrix and r is the rank of dimensionality reduction

[n,m]=size(V);   %get the size of matrix
 
  
W=abs(rand(n,r));   % produce random matrix
H=abs(rand(r,m));  
  
for iterate=1:500  
    WD=W'*V;  
     WWH=W'*W*H;  
     H = H.*WD./WWH; %update H
%     for a = 1:r  
%         for u=1:m  
%             H(a,u)=H(a,u)*WD(a,u)/WWH(a,u);  
%         end  
%     end  
    DH=V*H';  
    WHH=W*H*H';  
    W = W.*DH./WHH;  %update W
%     for i = 1:n  
%         for a=1:r  
%             W(i,a)=W(i,a)*DH(i,a)/WHH(i,a);  
%         end  
%     end  
  
end  

