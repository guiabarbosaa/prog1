#include <stdio.h>

typedef struct{
	int matriz[100];
	int qtdNumeros;
}tSequencia;

int EhMaior(tSequencia sequencia, int j);	

int main ()
{
	int numSequencia, i, j;
	int soma = 0;
	
	scanf("%d", &numSequencia);
	
	tSequencia sequencia[numSequencia];
	
	for(i = 0; i < numSequencia; i++)
	{
		scanf("%d", &sequencia[i].qtdNumeros);
		
		for(j = 0; j < sequencia[i].qtdNumeros; j++)
		{
			scanf("%d", &sequencia[i].matriz[j]);
		}
	}
	
	for(i = 0; i < numSequencia; i++)
	{
		for(j = 0; j < sequencia[i].qtdNumeros; j++)
		{
			soma = EhMaior(sequencia[i], j);
			
			printf("%d ", soma);
		}
		printf("\n");
	}		
return 0;
}

int EhMaior(tSequencia sequencia, int j)
{
	int i, num;
	int soma = 0;
	
	num = sequencia.matriz[j];
	
	for(i = 0; i < sequencia.qtdNumeros; i++)
	{
		if(sequencia.matriz[i] > num)
		{
			soma++;
		}
	}
	return soma;
}			
			
