  #include <stdio.h>

int main(){
  int i, qtd1, qtd2, den, primo, j, atual, multiplo;
  scanf("%d %d", &qtd1, &qtd2);
  
  if (qtd2>qtd1) {
    for(i=qtd1+1; i<qtd2; i++){
      primo = 1;  
      for (den = 2; den <= i/2; den++){
        if(i%den==0){
          primo = 0;
          break;
        }
      }
      if(primo==1) {
        printf("%d\n", i);
        atual = i;
        multiplo = 0;
        for (j=atual*2; j<qtd2;j++){
          if (j % atual == 0) {
            printf("%d ", j);
            multiplo = 1;
          }
        }
        if(!multiplo) {
          printf("*\n");
        } else {
          printf("\n");
        }  
      }
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
      if(primo==1) {
        printf("%d\n", i);
        atual = i;
        multiplo = 0;
        for (j=atual*2; j<qtd1;j++){
          if (j % atual == 0) {
            printf("%d ", j);
            multiplo = 1;
          }
        }
        if(!multiplo) {
          printf("*\n");
        } else {
          printf("\n");
        }  
      }
    } 
  }
  
  return 0;
}

