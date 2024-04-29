#include <stdio.h>

void LeNum(int num[], int n);

void DentroForaIntervalo(int num[], int n, int inicio, int fim);

int main ()
{
	int n,a,b;
	
	scanf("%d", &n);
	int num[n];
	
	LeNum(num, n);
	
	scanf("%d %d", &a, &b);
	
	DentroForaIntervalo(num, n, a, b);
	
return 0;
}

void LeNum(int num[], int n)
{
	int i;
	for (i = 0; i < n; i++) 
	{
        scanf("%d", &num[i]);
        }
}	

void DentroForaIntervalo(int num[], int n, int inicio, int fim)
{
	int dentro=0, fora=0;
	int i;
	
	for (i=0; i < n; i++)
	{
		if (num[i] >= inicio && num[i] <= fim)
		{
		   dentro++;
		}
		else
		{
		   fora++;
		}
	}
	printf("%d %d", dentro, fora);	
}	
