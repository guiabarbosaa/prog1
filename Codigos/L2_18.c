#include <stdio.h> 
int main () { 
int L,C,i,j,linha=0,coluna=0,num,coluna1=0;
int V = -32767, Maior = -32767;

scanf ("%d%d", &L, &C);

int matriz [L] [C];

      for (i = 0; i < L; i++) {
           for (j = 0; j < C; j++) {
                 scanf("%d", &num);
                     if (V < num) {
                         V = num;
                         coluna1=j;
                     }
            }
                                 
            if (Maior < V) {
                Maior = V;
                coluna=coluna1;
                linha=i; 
            }
        V = -32767;                          
      }
      
      printf ("%d (%d, %d)", Maior, linha+1, coluna+1);
return 0;
}                               
                          
                 
