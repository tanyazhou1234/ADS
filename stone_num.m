clc;clear;

m=51;
n=80;
a=2;

temp=n;
ii=0;%stone umber
while n>0
  while m>0
    m=m-a;
    ii++;
    stone_pos(ii,1)=m;
    stone_pos(ii,2)=n;
  endwhile
  n=n-a;
  m=temp;
endwhile
ii
