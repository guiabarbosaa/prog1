#include <stdio.h>

void LeVetor(int vet[], int n);

void InverteSequenciaCrescente(int vet[], int n);

void intercalarSequencias(int vetA[], int nA, int vetB[], int nB);

int main ()
{
	int n1, n2;
	
	scanf("%d", &n1);
	
	int vetorA[n1];
	
	LeVetor(vetorA, n1);
	
	scanf("%d", &n2);
	
	int vetorB[n2];
	
	LeVetor(vetorB, n2);
	
	InverteSequenciaCrescente(vetorA, n1);
	
	InverteSequenciaCrescente(vetorB, n2);
	
	intercalarSequencias(vetorA, n1, vetorB, n2);
	
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

void InverteSequenciaCrescente(int vet[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(vet[j] > vet[j+1])
			{
			   temp = vet[j];
			   vet[j] = vet[j + 1];
			   vet[j + 1] = temp;
			}       
		}
	}
}

void intercalarSequencias(int vetA[], int nA, int vetB[], int nB)
{
	int i = 0, j = 0;
    
    	while (i < nA && j < nB) 
    	{
        	if (vetA[i] <= vetB[j]) 
        	{
            	    printf("A");
            	    i++;
        	}
        	else 
        	{
            	    printf("B");
            	    j++;
        	}
        }
    
    	while (i < nA) 
    	{
        	printf("A");
        	i++;
        }
    
    	while (j < nB) 
    	{
        	printf("B");
        	j++;
        }
}

















	
	
