#include <stdio.h>
#include <math.h>

int main () {
    int x;
    double soma = 0.0;
    double j1, k2;
    
    scanf("%d", &x);
    
    switch (x) {
        case 1: 
            j1 = 1.0;
            for (double i1 = 1; i1 <= 99; i1 = i1 + 2) {
                soma += i1 / j1;
                j1++;
            }
            printf("%.6lf", soma);   
            break;
        
        case 2: 
            k2 = 50.0;
            for (double i2 = 1; i2 <= 50; i2++) {   
                soma += pow(2, i2) / k2;
                k2--; 
            }
            printf("%.6lf", soma);
            break;
        
        case 3:
            
            for (double i3 = 1; i3 <= 10; i3++) {
                
                soma += i3 / (i3*i3);
                
            }
            printf("%.6lf", soma);
            break;
        
        default:   
            printf("error");
            break;
    }
  
    return 0;
}
	
	
