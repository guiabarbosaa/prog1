#include <stdio.h> 
int main () {
      int num, soma1pos=0, soma2pos=0, soma1neg=0, soma2neg=0;
       
      
      while (scanf("%d", &num) == 1) {
            if (num < 0) {
               soma1neg += num;
               soma2neg++;
               } else if (num > 0) {
               soma1pos += num;
               soma2pos++;
               }
       }
                       
       printf("%d %d %d %d", soma2neg, soma2pos, soma1neg, soma1pos);
       
       return 0;
}             
       
       
               
            
