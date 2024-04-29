#include <stdio.h>

void LeMatriz(int l1, int c1, int matriz1[l1][c1]);

void MultiplicaMatriz(int l1, int c1, int matriz1[l1][c1], int l2, int c2, int matriz2[l2][c2], int result[l1][c2]);

void ImprimeMatriz(int l1, int c1, int matriz1[l1][c1]);

int main()
{
	int l1, l2, c1, c2, i, j, n, k;
	
	scanf("%d", &n);
	
	for(k = 0; k < n; k++)
	{
		scanf("%d %d", &c1, &l1);
		
		int matriz1[l1][c1];
		
		LeMatriz(l1, c1, matriz1);

		scanf("%d %d", &c2, &l2);
		
		int matriz2[l2][c2];
		
		LeMatriz(l2, c2, matriz2);
		
		int result[l1][c2];
		
		MultiplicaMatriz(l1, c1, matriz1, l2, c2, matriz2, result);
		
		if(c1 == l2)
		{
			ImprimeMatriz(l1, c2, result);
		}
	}
return 0;	
}			
		
void LeMatriz(int l1, int c1, int matriz1[l1][c1])
{
	int i, j, num;
	
	for(i = 0; i < l1; i++)
	{
		for(j = 0; j < c1; j++)
		{
			scanf("%d", &num);
			matriz1[i][j] = num;
		}
	}
}
			
void ImprimeMatriz(int l1, int c1, int matriz1[l1][c1])
{
	int i, j;
	
	for(i = 0; i < l1; i++)
	{
		for(j = 0; j < c1; j++)
		{
			printf("%d ", matriz1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void MultiplicaMatriz(int l1, int c1, int matriz1[l1][c1], int l2, int c2, int matriz2[l2][c2], int result[l1][c2])
{
	int i, j, k;
	
	if(c1 != l2)
	{
		printf("IMPOSSIVEL\n\n");
	}
	else
	{
		for(i = 0; i < l1; i++)
		{
			for(j = 0; j < c2; j++)
			{
			result[i][j] = 0;
				for(k = 0; k < c1; k++)
				{
				result[i][j] += matriz1[i][k]*matriz2[k][j];
				}
			}
		}
	}	
}				
				

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
			
		
