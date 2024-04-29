#include <stdio.h>

int main (){
int n1, n2, menor = 32001, prim = -1, ult = -1, i = 0, leitura = 0, j;

    //Leitura das duas sequências
    while(scanf("%d", &n1) == 1){
        //i++;
        leitura = 1;
        if(n1 <= menor){
            menor = n1;
        }
    }
    //até aqui lendo corretamente o menor da sequencia
    //limpar buffer
    scanf("%*c");
    //segunda sequencia
    while(scanf("%d", &n2) == 1){
        if(n2 == menor && prim == -1){
            prim = i;
        }
        if (n2 == menor){
            ult = i;
        }
        i++;
    }
    if(prim == -1 && ult == -1){
        j = i - 1;
        printf("%d %d %d", menor, i, i);
    } else {
        printf("%d %d %d", menor, prim, ult);
    }
return 0;
}
