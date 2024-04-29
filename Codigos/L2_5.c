#include <stdio.h>
#include <math.h>

int main() {
    int num, i;
    int mult1 = 1;
    float mult2, raiz, soma = 0;
     
    scanf("%d", &num);
    
     
    for (i = 1; i <= num; i++) {
        mult1 = i;
        mult2 = 6/pow(i,2);
    soma += mult2;   
    }
    
    raiz = sqrt(soma);
  
    printf ("%.6f", raiz);
  
    return 0;
}

