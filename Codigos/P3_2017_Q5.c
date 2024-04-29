#include <stdio.h>

void deslocarSequencia(int *sequencia, int tamanho, int deslocamento) 
{
    int novaSequencia[tamanho];
    int i;

    for (i = 0; i < tamanho; i++) 
    {
        int novaPosicao = (i + deslocamento) % tamanho;
        novaSequencia[novaPosicao] = sequencia[i];
    }

    for (i = 0; i < tamanho; i++) 
    {
        sequencia[i] = novaSequencia[i];
    }
}

int main() 
{
    int s, x, i, j;

    while (scanf("%d", &s) == 1) 
    {
        int sequencia[s];

        for (i = 0; i < s; i++) 
        {
            scanf("%d", &sequencia[i]);
        }

        while (scanf("%d", &x) == 1 && x != -1) 
        {
            deslocarSequencia(sequencia, s, x);

            for (i = 0; i < s; i++) 
            {
                printf("%d ", sequencia[i]);
            }

            printf("\n");
        }
    }
    return 0;
}

