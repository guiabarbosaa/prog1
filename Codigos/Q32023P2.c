#include <stdio.h>

void LeMatriz(int linhas, int colunas, int matriz[linhas][colunas]);

int EhHorizontal(int linhas, int colunas, int matriz[linhas][colunas]);

int EhVertical(int linhas, int colunas, int matriz[linhas][colunas]);

int EhTransposta(int linhas, int colunas, int matriz[linhas][colunas]);

int main ()
{
    int linhas, colunas;

    scanf("%d %d",&linhas, &colunas);

    int matriz[linhas][colunas];

    LeMatriz(linhas,colunas,matriz);

    if(EhHorizontal(linhas,colunas,matriz))
    {
        printf("HORIZONTAL\n");
    }

    if(EhVertical(linhas,colunas,matriz))
    {
        printf("VERTICAL\n");
    }

    if(EhTransposta(linhas,colunas,matriz))
    {
        printf("TRANSPOSTA\n");
    }

    if(!EhHorizontal(linhas,colunas,matriz) && !EhVertical(linhas,colunas,matriz) && !EhTransposta(linhas,colunas,matriz)) 
    {
        printf("NAO SIMETRICA\n");
    }

    return 0;
}
void LeMatriz(int linhas, int colunas, int matriz[linhas][colunas])
{
    int num, i, j;

    for(i = 0; i < linhas; i++)
    {
        for(j = 0;  j < colunas; j++)
        {
            scanf("%d", &num);
            matriz[i][j] = num;
        }
    }
}
int EhHorizontal(int linhas, int colunas, int matriz[linhas][colunas])
{
    int i, j;

    for(i = 0; i < linhas/2; i++)
    {
        for(j = 0;  j < colunas; j++)
        {
            if(matriz[i][j] != matriz[linhas-1-i][j])
            {
                return 0;
            }
        }
    }
    return 1; 
}
int EhVertical(int linhas, int colunas, int matriz[linhas][colunas])
{
    int i, j;

    for(i = 0; i < linhas; i++)
    {
        for(j = 0;  j < colunas/2; j++)
        {
            if(matriz[i][j] != matriz[i][colunas-1-j])
            {
                return 0;
            }
        }
    }
    return 1; 
}
int EhTransposta(int linhas, int colunas, int matriz[linhas][colunas])
{
    int i, j;
    int matrizauxiliar[linhas+50][colunas+50];
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            matrizauxiliar[j][i] = matriz[i][j];
        }
    }

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            if(matriz[i][j] != matrizauxiliar[i][j])
            {
                return 0;
            }
        }
    }
    return 1;    
}