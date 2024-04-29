#include <stdio.h>

int VerificaPrimo(int n)
{
    int i;
    if (n <= 1) 
    {
        return 0; // Não é primo
    }
    for (i = 2; i < n; i++) 
    {
        if (n % i == 0) 
        {
            return 0; // Não é primo
        }
    }
    return 1;
}

int TransformaPrimo(int n)
{
    return ++n;
}

int VerificaNegativo(int n)
{
    
    return -n;
    
}

int main() 
{
    int linha, coluna, num, i, j, normal;

    scanf("%d %d", &linha, &coluna);
    printf("	");
    for (i = 1; i <= linha; i++) 
    {
        for (j = 1; j <= coluna; j++)
        {
            scanf("%d", &num);
            if (num >= 0)
            {
            normal = num;
                if (VerificaPrimo(num))
                {
                    printf("%d ", num);
                }
                else
                {
                    while (1)
                    {
                        num = TransformaPrimo(num);
                        if (VerificaPrimo(num))
                        {
                            if (num <= 32000)
                            {                       
                            printf("%d ", num);
                            break;
                            }
                            else
                            {
                            printf("%d ", normal);
                            break;
                            } 
                        }
                    }
                }
            }
            else
            {
             normal = num;
             num = VerificaNegativo(num);
                 if (VerificaPrimo(num))
                {
                    printf("-%d ", num);
                }
                else
                {
                    while (1)
                    {
                        num = TransformaPrimo(num);
                        if (VerificaPrimo(num))
                        {
                            if (num <= 32000)
                            {                       
                            printf("-%d ", num);
                            break;
                            }
                            else
                            {
                            printf("%d ", normal);
                            break;
                            }
                        }
                    }
                }
            } 
        }
        printf("\n");
        printf("	");
    }
    printf("\n");
    return 0;
}

