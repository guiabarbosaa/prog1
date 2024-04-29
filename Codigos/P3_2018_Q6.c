#include <stdio.h>

void LeMatriz(int linhas, int colunas,int matriz[linhas][colunas]);

int ValidoPonto(int linhas, int colunas, int linhas2, int colunas2, int i, int j);

int EstaContidoTemplate(int linhas, int colunas,int matriz[linhas][colunas], int linhas2, int colunas2,
int matriz2[linhas2][colunas2], int iy, int jx);

int main()
{
	int i, j;
	
	int countErros = 0;
	
	int linhas, linhas2, colunas, colunas2;
	
	scanf("%d %d", &linhas, &colunas);
	
	int matriz[linhas][colunas];
	
	LeMatriz(linhas,colunas,matriz);
	
	scanf("%d %d", &linhas2, &colunas2);
	
	int matriz2[linhas2][colunas2];
	
	LeMatriz(linhas2,colunas2,matriz2);

	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			if(ValidoPonto(linhas,colunas,colunas2,colunas2,i,j))
			{
				if(EstaContidoTemplate(linhas,colunas,matriz,linhas2,colunas2,matriz2,i,j))
				{
					countErros++;
				}
			}
		}
	}
	printf("RESP:%d", countErros);
	
return 0;
}

void LeMatriz(int linhas, int colunas,int matriz[linhas][colunas])
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

int ValidoPonto(int linhas, int colunas, int linhas2, int colunas2, int i, int j)
{
    if ((j + colunas2 <= colunas) && (i + linhas2 <= linhas)) {
        return 1;
    }

    return 0;
}


int EstaContidoTemplate(int linhas, int colunas, int matriz[linhas][colunas], int linhas2, int colunas2,
                        int matriz2[linhas2][colunas2], int iy, int jx)
{
    int i, j;
    int countIgual = 0;

    for(i = 0; i < linhas2; i++)
    {
        for(j = 0; j < colunas2; j++)
        {
            if(matriz[iy + i][jx + j] == matriz2[i][j])
            {
                countIgual++;
            }
        }
    }
    
    if(countIgual == linhas2 * colunas2)
    {
        return 1;
    }

    return 0;
}
