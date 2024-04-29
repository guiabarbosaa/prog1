#include <stdio.h>
int main () {
     int num,i = 0, maior = 0, media = 0, soma = 0, quantidade = 0;
     
     scanf ("%d", &num);
     
     while (num != 0) {
         if (num > maior) {
         maior = num;
     }
     quantidade++;
     soma += num ;
     float media = (float) soma/quantidade;
     
     printf ("%d %.6f\n", maior, media);
     scanf ("%d", &num);
  }
     
return 0;
}     
