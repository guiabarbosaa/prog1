#include <stdio.h>

void LeMatriz(int linhas, int colunas, int matriz[linhas][colunas]);

int CountCusto(int linhas, int colunas, int matriz[linhas][colunas], int i, int j);

int main()
{
	int linhas, colunas, i, j;
	int soma = 0;
	
	scanf("%d %d", &colunas, &linhas);
	
	int matriz[linhas][colunas];
	
	LeMatriz(linhas, colunas, matriz);
	
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			if(matriz[i][j] == 0)
			{
				if(CountCusto(linhas,colunas,matriz,i,j))
				{
					soma++;
				}
			}	
		}
	}
	printf("%d\n", soma);

return 0;
}

void LeMatriz(int linhas, int colunas, int matriz[linhas][colunas])
{
	int i, j;
	int num = 0;
	
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			scanf("%01d", &num);
			
			matriz[i][j] = num;
		}
	}
}

int CountCusto(int linhas, int colunas, int matriz[linhas][colunas], int i, int j)
{
	int l, c;
	int somaAgua = 0;
	for(l = i - 1; l <= i + 1; l++)
	{
		for(c = j - 1; c <= j + 1; c++)
		{
			if(matriz[l][c] == 1)
			{
				somaAgua++;
			}
		}	
	}
	if(somaAgua > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}						




















						

