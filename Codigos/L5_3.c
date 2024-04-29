#include <stdio.h>

void LeNotas(int notas[], int n);

int MaiorDiferenca(int notas[], int n);

void PontosDifIguais(int notas[], int n, int diferenca);

int main ()
{
	int n, i;
	int maiordif = 0;
	
	scanf ("%d", &n);
	
	int notas[n];
	
	LeNotas(notas, n);
	
	maiordif = MaiorDiferenca(notas, n);
	
	PontosDifIguais(notas, n, maiordif);
	
return 0;
}

void LeNotas (int notas[], int n) 
{
	int i;
	for (i = 0; i < n; i++) 
	{
        scanf("%d", &notas[i]);
        }
}

int MaiorDiferenca(int notas[], int n) 
{
    int i;
    int diferenca = 0, maiordif = -3200;

    for (i = 1; i < n; i++) 
    {
            diferenca = notas[i] - notas[i - 1];
            if (diferenca < 0)
            {
            	diferenca = diferenca * -1;
            }
            
            if (diferenca > maiordif) 
            {
                maiordif = diferenca;
            }
            
            diferenca = 0;    
    }      

    return maiordif;
}

void PontosDifIguais(int notas[], int n, int diferenca)
{
	int i;
	
	for(i = 1; i < n; i++)
	{ 
	    if (notas[i] - notas[i-1] == diferenca || notas[i-1] - notas[i] == diferenca)
	    {
	    	printf(" (%d %d)", i-1, i);
	    }
	}
	if (n == 1)
	{
	    printf("IMPOSSIVEL");
	}        	
}	
























	
