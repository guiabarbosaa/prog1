#include <stdio.h>

#define numeros 51

void PreencheMatriz(int linhas, int numeros, int matriz[linhas][numeros]);

int VerificaTamMatriz(int linhas, int numeros, int matriz[linhas][numeros], int ix);

void ImprimeSomaNum(int linhas, int numeros, int matriz[linhas][numeros], int ix, int TamMatriz[]);

int main()
{
	int QtdPares, k, num, Qtd;
	int i = 0, j = 0;
	
	scanf("%d" , &Qtd);
	
	QtdPares = Qtd * 2;
	
	int Pares[QtdPares][numeros];
	
	int TamMatriz[QtdPares];
	
	PreencheMatriz(QtdPares,numeros,Pares);
	
	for(k = 1; k <= pares; k++)
	{
		while(scanf("%d", &num) == 1 && num != -1)
		{
			Pares[i][j] = num;
			j++;
		}
		i++;
		j = 0;
		while(scanf("%d", &num) == 1 && num != -1)
		{
			Pares[i][j] = num;
			j++;
		}
	}
	
	for(k = 0; k < pares; k++)
	{
		TamMatriz[k] = VerificaTamMatriz(QtdPares,numeros,Pares,k);
	}
	
	for(k = 1; k < pares; k+2)
	{
		ImprimeSomaNum(QtdPares,numeros,Pares,k,TamMatriz[]);
	}
	
return 0;
}

void PreencheMatriz(int linhas, int numeros, int matriz[linhas][numeros])
{
	int i, j;
	
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < numeros; j++)
		{
			matriz[i][j] = -2;
		}
	}
}
			
int VerificaTamMatriz(int linhas, int numeros, int matriz[linhas][numeros], int ix)
{
	int j;
	int TamMatriz = 0;
	
	for(j = numeros - 1; j >= 0; j--)
	{
		if(matriz[ix][j] == -2)
		{
			TamMatriz = j + 1;
			break;
		}
	}		 
void ImprimeSomaNum(int linhas, int numeros, int matriz[linhas][numeros], int ix, int TamMatriz[])
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
			
