#include <stdio.h>

void LeNum(int num[], int n);

void ImprimeOcorrencia(int num[], int n, int procurado);

int main()
{
	int n, procurado;
	scanf("%d", &procurado);
	scanf("%d", &n);
	
	int num[n];
	
	LeNum(num, n);
	
	ImprimeOcorrencia(num, n, procurado);

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

void ImprimeOcorrencia(int num[], int n, int procurado)
{
	int i;
	int posicao = -3200;
	for (i = 0; i < n; i++)
	{
		if(num[i] == procurado)
		{
			posicao = i;
			break;
		}
	}
	
	if (posicao == -3200)
	{
		printf("RESP:%d", n);
	}
	else
	{
		printf("RESP:%d", posicao);
	}		
}					
	
	
