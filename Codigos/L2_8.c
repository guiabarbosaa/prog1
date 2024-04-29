#include <stdio.h>

int main(){
  int i, qtd1, qtd2, den, cont, primo;
  scanf("%d %d", &qtd1, &qtd2);
  
  printf("RESP:");
  
  if (qtd2>qtd1) {
  for(i=qtd1+1; i<qtd2; i++){
  primo = 1;  
    for (den = 2; den <= i/2; den++){
      if(i%den==0){
      primo = 0;
        break;
      }
    }
    if(primo==1)
      printf("%d ", i);
  }
}
  if (qtd1>qtd2) { 
  for(i=qtd2+1; i<qtd1; i++){
  primo = 1;  
    for (den = 2; den <= i/2; den++){
      if(i%den==0){
      primo = 0;
        break;
      }
    }
    if(primo==1)
      printf("%d ", i);
  }
}  
  
  return 0;
 }
