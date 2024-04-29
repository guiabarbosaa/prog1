#include <stdio.h>
#include <string.h>

// Funçao para verificar se uma palavra ja foi contada
int palavraJaContada(char palavra[], char palavras[1001][50], int contador) 
{
    int i;
    for (i = 0; i < contador; i++) 
    {
        if(strcmp(palavra, palavras[i]) == 0) 
        {
            return 1; // A palavra ja foi contada
        }
    }
    return 0; // A palavra ainda nao foi contada
}

int main() {
    char palavras[1001][50];
    int contador = 0, frequencia = 0;
    int i, j;

    // Ler as palavras do texto e armazena-las na matriz de palavras
    while (scanf("%[a-zA-Z]", palavras[contador]) == 1) 
    {
        scanf("%*[^a-zA-Z]");
        contador++;
    }
    // Verificar e imprimir a frequencia de cada palavra
    for (i = 0; i < contador; i++) 
    {
        if (!palavraJaContada(palavras[i], palavras, i)) 
        {
            // Contar a frequencia da palavra
            for (j = 0; j < contador; j++) 
            {
                if (strcmp(palavras[i], palavras[j]) == 0) 
                {
                    frequencia++;
                }
            }
            printf("%s: %d\n", palavras[i], frequencia);
        }
        frequencia = 0;
    }

    return 0;
}

