#include <stdio.h>
int main() {
int num, soma, resp;

scanf("%d", &num);
printf("RESP:");
while (num >= 10) {
    soma = 0;
    
     while (num > 0) {
         soma += num %10;
         num /= 10;
         }
   num = soma;
         
 }
 printf("%d", num);
 return 0;
}
