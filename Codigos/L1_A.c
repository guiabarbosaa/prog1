#include <stdio.h>
   int main(){
   int H,h,M,m;
   int so1,so2;
   int dif1,dif2,dif3;
   
  scanf("%d:",&H);
  scanf("%d",&M);
  scanf("%d:",&h);
  scanf("%d",&m);
     
  if (H == h) {
  so1 = M+m;
  printf ("24:%02d",so1);
  }
 
  if (H > h)      {
   
   if (M == m)   {
   dif1 = H-h;
   printf ("%02d:00",dif1);
                  } 
  if (m > M)   {
 
  dif1 = H-h;
  dif2 = 24-dif1;
  dif3 = m - M;  
  printf ("%02d:%02d", dif2, dif3);
               }
  if (M>m) {
  dif1 = 24 - H - 1 + h;
  dif2 = 60 - M + m;
  printf ("%02d:%02d",dif1, dif2);
           } 
                  }
  
  if (H < h) {
   if (M == m) {
   dif1 = h-H;
   printf ("%02d:00",dif1);
                }
  if (M>m) {
  dif1 = h-H-1;
  dif2 = 60-M;
  so2 = dif2+m;
  printf ("%02d:%02d", dif1, so2);
  }
  if (m>M) {
  dif1 = h-H;
  dif2 = m - M;
  printf ("%02d:%02d", dif1, dif2);
  }
  }
  
  return 0;
  }
  
  
  
  
  
  
  
  
  
        	    
	   
   
