#include <stdio.h>

void LeMatriz(int linhas, int colunas, int matriz[linhas][colunas]);

void PreencheMatriz(int linhas, int colunas, int matriz[linhas][colunas], int iy1, int jx1, int iy2, int jx2);

void ImprimeMatriz(int linhas, int colunas, int matriz[linhas][colunas]);

int main()
{
	int posicao1l = 0, posicao1c = 0;
	int i, j, coordenadax, coordenaday, linhas, colunas;
	
	scanf("%d %d", &colunas, &linhas);
	
	int matriz[linhas][colunas];
	
	LeMatriz(linhas,colunas,matriz);
	
	while(scanf("%d %d", &coordenadax, &coordenaday) == 2)
	{
		PreencheMatriz(linhas,colunas,matriz,posicao1l,posicao1c,coordenaday,coordenadax);
		
		posicao1c = coordenadax;
		
		posicao1l = coordenaday;
	}
	
	ImprimeMatriz(linhas,colunas,matriz);
	
return 0;
}

void LeMatriz(int linhas, int colunas, int matriz[linhas][colunas])		
{
	int i, j;
	
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			matriz[i][j] = 0;
		}
	}
	matriz[0][0] = 1;
}					
	
void PreencheMatriz(int linhas, int colunas, int matriz[linhas][colunas], int iy1, int jx1, int iy2, int jx2)
{	
	int i, j;
	int distanciaX = 0, distanciaY = 0;
	
	distanciaX = jx1 - jx2;
	if(distanciaX < 0)
	{
		distanciaX = distanciaX*-1;
	}
	
	distanciaY = iy1 - iy2;
	if(distanciaY < 0)
	{
		distanciaY = distanciaY*-1;
	}	
	
	if(distanciaY < distanciaX)
	{
		if(iy1 - iy2 > 0)
		{
			for(i = iy1; i >= iy2; i--)
			{
				matriz[i][jx1] = 1;
			}
		}	
		else
		{
			for(i = iy1; i <= iy2; i++)
			{
				matriz[i][jx1] = 1;
			}
		}
		
		if(jx1 - jx2 > 0)
		{
			for(j = jx1; j >= jx2; j--)
			{
				matriz[iy2][j] = 1;
			}
		}
		else
		{
			for(j = jx1; j <= jx2; j++)
			{
				matriz[iy2][j] = 1;
			}
		}
	}
	else
	{
		if(jx1 - jx2 > 0)
		{
			for(j = jx1; j >= jx2; j--)
			{
				matriz[iy1][j] = 1;
			}
		}
		else
		{
			for(j = jx1; j <= jx2; j++)
			{
				matriz[iy1][j] = 1;
			}
		}
		
		if(iy1 - iy2 > 0)
		{
			for(i = iy1; i >= iy2; i--)
			{
				matriz[i][jx2] = 1;
			}
		}	
		else
		{
			for(i = iy1; i <= iy2; i++)
			{
				matriz[i][jx2] = 1;
			}
		}
	}
}

void ImprimeMatriz(int linhas, int colunas, int matriz[linhas][colunas])
{
	int i, j;		
						
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}				
					 	
	
	
	
	
	
	
	
	
