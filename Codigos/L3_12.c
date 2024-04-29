#include <stdio.h>

int somadosdigitos(int n)
{
    int soma = 0;
    
    while (n > 0)
    {
        int resto = n % 10;
        soma += resto;
        n /= 10;
    }
    
    return soma;
}

void parImpar(int n)
{
    if (n % 2 == 0)
    {
        printf("Par ");
    }
    else
    {
        printf("Impar ");
    }
}

void valorPrimo(int n)
{
    int i, cont = 0;
    
    if (n < 2)
    {
        cont += 1;
        printf("Nao e primo");
    }
    
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cont += 1;
            printf("Nao e primo");
            break;
        }
    }
    
    if (cont == 0)
    {
        printf("Primo");
    }
}

int main()
{
    int num, soma1 = 0, soma2 = 0;
    
    scanf("%d", &num);
    
    soma1 = somadosdigitos(num);
    
    printf("%d ", soma1);
    parImpar(soma1);
    valorPrimo(soma1);
    printf("\n");
    
    soma2 = soma1;
    
    while (soma2 >= 10)
    {
        soma2 = somadosdigitos(soma2);
        printf("%d ", soma2);
        parImpar(soma2);
        valorPrimo(soma2);
        printf("\n");
    }
    return 0;
}


	
	
	

















