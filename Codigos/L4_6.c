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

int main ()
{
	tPonto ponto, inicio, fim;
	int QTDPontos, i;
	float distanciainicio=0.0,distanciafim=0.0;
	
	scanf("%d", &QTDPontos);
	
		for(i = 1; i <= QTDPontos; i++)
		{
		 scanf("%d %d", &ponto.pontoX, &ponto.pontoY);
		 scanf("%d %d", &inicio.pontoX, &inicio.pontoY);
		 scanf("%d %d", &fim.pontoX, &fim.pontoY);
    		 
    		 distanciainicio = DistanciaPontos(ponto,inicio);
    		 distanciafim = DistanciaPontos(ponto,fim);
    		 
    		 	if (distanciainicio < distanciafim)
    		 	{
    		            printf("INICIO\n");
    		        }
    		        else if (distanciainicio > distanciafim)
    		 	{
    		            printf("FIM\n");
    		        }
    		        else
    		        {
    		            printf("EQUIDISTANTE\n");
    		        }
    		 distanciainicio = 0;                
		 distanciafim = 0;
		}
return 0;
}		 
		
		
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
