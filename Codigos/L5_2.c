#include <stdio.h>

void LeNotas (int notas[], int n);
void verificarOrdenacao(int notas[], int n);

int main() {
    int n, i;
    
    scanf("%d", &n);
    int notas[n];

    LeNotas(notas, n);
    verificarOrdenacao(notas, n);

return 0;
}

void verificarOrdenacao(int notas[], int n) {
    int i;
    int crescente = 1;
    int decrescente = 1;

    for (i = 1; i < n; i++) {
        if (notas[i] < notas[i - 1]) {
            crescente = 0;
        }
        if (notas[i] > notas[i - 1]) {
            decrescente = 0;
        }
    }

    if (crescente && decrescente) {
        printf("CRESCENTE&DECRESCENTE");
    } 
    else if (crescente) {
        printf("CRESCENTE");
    } 
    else if (decrescente) {
        printf("DECRESCENTE");
    } 
    else {
        printf("DESORDENADO");
    }
}

void LeNotas (int notas[], int n) {
	int i;
	for (i = 0; i < n; i++) {
        scanf("%d", &notas[i]);
        }
}

