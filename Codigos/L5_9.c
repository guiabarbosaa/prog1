#include <stdio.h>

void LeVetor(int vet[], int n);

void InverteSequencia(int vet[], int n);

void ImprimeDadosDoVetor(int vet[], int n);

int main()
{
	int n;
	
	scanf("%d", &n);
	
	int vetor[n];
	
	LeVetor(vetor, n);
	
	InverteSequencia(vetor, n);
	
	ImprimeDadosDoVetor(vetor, n);

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

void InverteSequencia(int vet[], int n)
{
	int i, temp;
	for(i = 0; i < n/2; i++)
	{
	temp = vet[i];
	vet[i] = vet[n-i-1];
	vet[n-i-1] = temp;
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
	
