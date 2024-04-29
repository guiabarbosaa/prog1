#include <stdio.h>

void LeVetor(int num[], int n);

void TrocaParEImpar(int vet[], int n);

void ImprimeDadosDoVetor(int vet[], int n);

int main() 
{
    int qtd;
    
    scanf("%d", &qtd);
    
    int vetor[qtd];
    
    LeVetor(vetor, qtd);
    
    TrocaParEImpar(vetor, qtd);
    
    ImprimeDadosDoVetor(vetor, qtd);
    
return 0;
}

void LeVetor(int vet[], int n)
{
	int i;
	for (i = 0; i < n; i++) 
	{
        scanf("%d", &vet[i]);
        }
}

void TrocaParEImpar(int vet[], int n) 
{
    	int temp, i;
    	for (i = 0; i < n - 1; i += 2) 
    	{
        temp = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = temp;
    	}
}

void ImprimeDadosDoVetor(int vet[], int n) 
{
	int i;
    		
    	if (n > 0)
    	{
    	printf("{");
    		for (i = 0; i < n-1; i++) 
    		{
        	printf("%d, ", vet[i]);
    		}
    	printf("%d", vet[n-1]);
    	
    	printf("}");
    	}
    	else if(n == 0)
    	{
    	printf("{}");
    	}
}



