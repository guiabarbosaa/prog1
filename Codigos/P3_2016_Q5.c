#include <stdio.h>
#include <string.h>

typedef struct{
	char palavra1[401];
	int tampalavra1;
	char palavra2[401];
	int tampalavra2;
}tCasos;

tCasos LeCasos();

tCasos LeTamanho();

int VerificaEhMaiscula(tCasos caso, int i);

int ContaIguais(tCasos caso);

int PalavrasIguais(tCasos caso);

int main()
{
	int numCasos, k;
	int somaiguais = 0;
	
	scanf("%d", &numCasos);
	
	tCasos casos[numCasos];
	
	for(k = 0; k < numCasos; k++)
	{
		casos[k] = LeCasos();
		casos[k] = LeTamanho();
	}
	for(k = 0; k < numCasos; k++)
	{
		somaiguais = ContaIguais(casos[k]);
		
		if(somaiguais >= casos[k].tampalavra1)
		{
			if(casos[k].tampalavra1 == casos[k].tampalavra2)
			{
				if(PalavrasIguais(casos[k]))
				{
					printf("PODE!\n");
				}
				else
				{
					printf("NAO PODE!\n");
				}
			}
			else
			{
				printf("PODE!\n");
			}						
		}
		else
		{
			printf("NAO PODE!\n");
		}
	}			 
return 0;
}

tCasos LeCasos()
{
	tCasos caso;
	
	scanf("*c");
	scanf("%s", caso.palavra1);
	scanf("*c");
	scanf("%s", caso.palavra2);
	
	return caso;
}

tCasos LeTamanho()
{
	tCasos caso;
	
	caso.tampalavra1 = strlen(caso.palavra1);
	caso.tampalavra2 = strlen(caso.palavra2);
	
	return caso;
}

int VerificaEhMaiscula(tCasos caso, int i)
{
	if(caso.palavra1[i] >= 'A' && 'Z' <= caso.palavra1[i])
	{
		return 1;
	}
	return 0;	
}

int ContaIguais(tCasos caso)
{
	int i, j;
	int soma = 0, achou = 0;
	
	for(i = 0; i < caso.tampalavra1; i++)
	{
		for(j = 0; j < caso.tampalavra2; j++)
		{
			if(VerificaEhMaiscula(caso, i))
			{
				if(caso.palavra1[i] == caso.palavra2[j] && achou == 0)
				{
					soma++;
					achou = 1;
				}
				else if(caso.palavra1[i] == caso.palavra2[j] + 32 && achou == 0)
				{
					soma++;
					achou = 1;
				}
			}	
			else
			{
				if(caso.palavra1[i] == caso.palavra2[j] && achou == 0)
				{
					soma++;
					achou = 1;
				}
				else if(caso.palavra1[i] == caso.palavra2[j] - 32 && achou == 0)
				{
					soma++;
					achou = 1;
				}
			}
		}
		achou = 0;
	}
	return soma;								
}

int PalavrasIguais(tCasos caso)
{
	int i, j;
	int soma = 0;
	
	for(i = 0; i < caso.tampalavra1; i++)
	{
		if(caso.palavra1[i] == caso.palavra2[i])
		{
			soma++;
		}
		else if(caso.palavra1[i] + 32 == caso.palavra2[i])
		{
			soma++;
		}
		else if(caso.palavra1[i] == caso.palavra2[i] + 32)
		{
			soma++;
		}
	}
	if(soma == caso.tampalavra1)
	{
		return 1;
	}
	return 0;
}					
				
	

