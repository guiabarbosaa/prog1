#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int identificador;
    int tamanho;
    int numeros[10][10];
} tCartela;

tCartela LeCartela() {
    tCartela cartela;
    int i, j;
   
    scanf("%d", &cartela.identificador);
    
    scanf("%d", &cartela.tamanho);

    
    for (i = 0; i < cartela.tamanho; i++) {
        for (j = 0; j < cartela.tamanho; j++) {
            scanf("%d", &cartela.numeros[j][i]);
        }
    }

    return cartela;
}

void ImprimeCartela(tCartela cartela) {
    printf("ID:%d\n", cartela.identificador);
    int i, j;
    
    for (i = 0; i < cartela.tamanho; i++) {
        for (j = 0; j < cartela.tamanho; j++) {
            if (j == cartela.tamanho - 1)
            {
            printf("%03d", cartela.numeros[i][j]);
            }
            else
            {
            printf("%03d|", cartela.numeros[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    tCartela cartela = LeCartela();
    ImprimeCartela(cartela);

    return 0;
}

