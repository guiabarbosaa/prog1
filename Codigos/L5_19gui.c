#include <stdio.h>

void LeMatriz(int linhas, int colunas, int matriz[linhas][colunas]);

void PreencheMatriz(int linhas, int colunas, int matriz[linhas][colunas], int horas);

int CountTerra(int linhas, int colunas, int matriz[linhas][colunas]);

int main()
{
	int horas, linhas, colunas;
	int terra1 = 0, terra2 = 0;
	
	scanf("%d %d %d", &horas, &colunas, &linhas);
	
	int matriz[linhas][colunas];
	
	LeMatriz(linhas, colunas, matriz);
	
	terra1 = CountTerra(linhas, colunas, matriz);
	
	PreencheMatriz(linhas, colunas, matriz, horas);
	
	terra2 = CountTerra(linhas, colunas, matriz);
	
	printf("%d %d\n", terra1, terra2);
	
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

void PreencheMatriz(int linhas, int colunas, int matriz[linhas][colunas], int horas)
{
	int i, j, k;
	int matrizAuxiliar[linhas][colunas];
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			matrizAuxiliar[i][j] = matriz[i][j];
		}
	}		
	
	for(k = 0; k < horas; k++)
	{
		for(i = 0; i < linhas; i++)
		{
			for(j = 0; j < colunas; j++)
			{
				if(matriz[i][j] == 0)
				{
					if(matriz[i-1][j] == 1 || matriz[i+1][j] == 1 ||
					matriz[i][j-1] == 1 || matriz[i][j+1] == 1)
					{
						matrizAuxiliar[i][j] = 1;
					}
				}
			}
		}
		for(i = 0; i < linhas; i++)
		{
			for(j = 0; j < colunas; j++)
			{
			matriz[i][j] = matrizAuxiliar[i][j];
			}
		}	
	}						
}	
int CountTerra(int linhas, int colunas, int matriz[linhas][colunas])
{
	int i, j;
	int soma = 0;
	 
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
 			if(matriz[i][j] == 0)
 			{
 				soma++;
 			}
 		}
 	}
 return soma;
} 				
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
