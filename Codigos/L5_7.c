#include <stdio.h>

void LeNum(int num[], int n);

void ImprimeProgressao(int num[], int n, int diferenca);

int main()
{
	int n;
	int diferenca = 0;
	
	scanf ("%d", &n);
	
	int num[n];
	
	LeNum(num, n);
	
	diferenca = num[1] - num[0];
	
	ImprimeProgressao(num, n, diferenca);
	
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

void ImprimeProgressao(int num[], int n, int diferenca)
{
	int i;
	int progresscont = 0;
	
	for(i = 1; i < n; i++)
	{
		if(num[i] - num[i-1] == diferenca)
		{
		   progresscont++;
		}
	}
	
	if(progresscont == n - 1 && n > 1)
	{
		printf("RESP:%d", diferenca);
	}
	else if(n == 1)
	{
		printf("NAO");
	}		
	else
	{
		printf("NAO");	
	}
}				   
		
		
