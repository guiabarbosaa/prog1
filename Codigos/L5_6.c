#include <stdio.h>

void LeNum(int num[], int n);

void ImprimePresente(int num1[],int num2[], int n1, int n2);

int main()
{
	int n1, n2;
	
	scanf("%d", &n1);
	
	int num1[n1];
	
	LeNum(num1, n1);
	
	scanf("%d", &n2);
	
	int num2[n2];
	
	LeNum(num2, n2);
	
	ImprimePresente(num1, num2, n1, n2);

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

void ImprimePresente(int num1[],int num2[], int n1, int n2)
{
	int i, j;
	int dentrocont = 0;
	for (i = 0; i < n1; i++)
	{
		for(j = 0; j < n2; j++)
		{
			if (num1[i] == num2[j])
			{
			    dentrocont++;
			    break;
			}
		}
	}
	if(dentrocont == n1)
	{
		printf("TODOS");
	}
	else if(dentrocont == 0)
	{
		printf("NENHUM");
	}
	else
	{
		printf("PARCIAL");
	}
}						    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	
	
	
