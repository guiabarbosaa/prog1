#include <stdio.h>
int main () {
int num1,num2; 
int menor = 32000, pcont = 0, pi = 32000, posiçao1 = 0;
char c = 0; 

//leitura da primeira sequencia
while (scanf("%d", &num1)==1) {
     
     if (num1 < menor) {
        menor = num1;}
}        
scanf("%*c");

//limpa de buffer

while (scanf("%d", &num2)==1) {
pcont++;

if (num2 == menor) {
    posiçao1 = pcont;
    
    if(pi > posiçao1) {
       pi = posiçao1;
                       }  
   }
}
if (posiçao1 == 0) {
printf("%d %d %d", menor, pcont, pcont);
}
else {
printf("%d %d %d", menor, pi-1, posiçao1-1);
}

return 0;
}
