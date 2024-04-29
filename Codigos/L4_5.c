#include <stdio.h>
#include <math.h>

typedef struct
{
    int pontoX;
    int pontoY;
} tPonto;

float DistanciaPontos(tPonto pi, tPonto pf)
{
    float result, diferenca1 = 0, diferenca2 = 0, diferenca3 = 0, diferenca4 = 0, soma = 0;
    diferenca1 = pi.pontoX - pf.pontoX;
    diferenca2 = pi.pontoY - pf.pontoY;
    diferenca3 = diferenca1 * diferenca1;
    diferenca4 = diferenca2 * diferenca2;
    soma = diferenca3 + diferenca4;

    result = sqrtf(soma);

    return result;
}

int main()
{
    float result = 0;
    tPonto predecessor, sucessor, inicial;
    int countsuce = 0, QTDPontos, i;

    scanf("%d", &QTDPontos);
    scanf("%d %d", &inicial.pontoX, &inicial.pontoY);
    predecessor = inicial;

    for (i = 2; i <= QTDPontos; i++)
    {
        if (countsuce == 0)
        {
            printf("-\n");
        }
        countsuce++;

        if (countsuce != 0)
        {
            scanf("%d %d", &sucessor.pontoX, &sucessor.pontoY);
            result = DistanciaPontos(predecessor, sucessor);
            printf("%.2f\n", result);
        }

        predecessor = sucessor;
    }

    return 0;
}
	 	
