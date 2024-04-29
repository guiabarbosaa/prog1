#include <stdio.h>

int EhPar(int x)
{
    if (x % 2 == 0)
    {
        return 1;
    }
    return 0; // Adicionado retorno 0 para números não pares
}

void PrintaPares(int N)
{
    if (EhPar(N))
    {
        printf("%d ", N); // Adicionada quebra de linha no final
    }
}

void PrintaImpares(int N)
{
    if (!EhPar(N))
    {
        printf("%d ", N); // Adicionada quebra de linha no final
    }
}

int main()
{
    int ordem, num1, i = 0, multiplos;

    scanf("%d %d", &ordem, &num1);

    if (ordem == 0)
    {
        multiplos = num1;
        while (multiplos > 0)
        {
            i++;
            if (EhPar(i))
            {
                PrintaPares(i);
                multiplos--;
            }
        }
    }

    if (ordem == 1)
    {
        multiplos = num1;
        while (multiplos > 0)
        {
            i++;
            if (!EhPar(i))
            {
                PrintaImpares(i);
                multiplos--;
            }
        }
    }
    return 0;
}

