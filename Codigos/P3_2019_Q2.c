#include <stdio.h>

int validoPonto(int linhas, int colunas, char ordem, int padrao, int iy, int jx);

int EhVertical(char ordem);

int main ()
{
	int padrao, i, j, linhas, colunas, k, countpadrao = 0;
	char ordem,letra;
	int Numpadrao = 0;
	
	scanf("%01d%c", &padrao, &ordem);
	
	scanf("%d %d", &linhas, &colunas);
	scanf("%*c");
	char matriz[linhas][colunas];
	
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			scanf("%c", &letra);
			matriz[i][j] = letra;
		}
		scanf("%*c");
	}
	
	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			 if(validoPonto(linhas,colunas,ordem,padrao,i,j))
			 {
			  countpadrao = 0;
			  	if(linhas == 1)
			  	{
			  		if(EhVertical(ordem))
			 		{
			 			if(matriz[i][j] == 'X')
			 			{
			 				Numpadrao++;
			 			}
			 		}
			 		else
			 		{
			 			if(padrao == 1)
			 			{
			 				if(matriz[i][j] == 'X')
			 				{
			 				Numpadrao++;
			 				}
			 			}
			 			else
			 			{
			 				k = 0;
			 				while (k < padrao - 1)
                    					{
                        					if (matriz[i][j+k] != matriz[i][j+k+1])
                        					{
                            					break;
                        					}
                        					if (matriz[i][j+k] == 'X')
                        					{
                            					countpadrao++;
                        					}
                        					k++;
                    					}
			 				if(countpadrao == padrao - 1)
			 				{
			 				Numpadrao++;
			 				}
			 			}		
			 		}									
			  	}
			  	else
			  	{	
			 		if(EhVertical(ordem))
			 		{
			 			k = 0;
			 		
			 			while (k < padrao - 1)
                    				{
                        				if (matriz[i + k][j] != matriz[i + k + 1][j])
                        				{
                            				break;
                        				}
                        				if (matriz[i + k][j] == 'X')
                        				{
                            				countpadrao++;
                        				}
                        				k++;
                    				}
                    			
			 			if(countpadrao == padrao - 1)
			 			{
			 			Numpadrao++;
			 			}
			 		}
			 		else
			 		{
			 			k = 0;
			 			while (k < padrao - 1)
                    				{
                        				if (matriz[i][j+k] != matriz[i][j+k+1])
                        				{
                            				break;
                        				}
                        				if (matriz[i][j+k] == 'X')
                        				{
                            				countpadrao++;
                        				}
                        				k++;
                    				}
			 			if(countpadrao == padrao - 1)
			 			{
			 			Numpadrao++;
			 			}
			 		}
			 	}
			 }	
		}
	}
	
	printf("CONT: %c %d\n", ordem, Numpadrao);
return 0;
}

int validoPonto(int linhas, int colunas, char ordem, int padrao, int iy, int jx)
{
	if(ordem == 'V')
	{
		if(iy + padrao -1 < linhas)
		{
			return 1;
		}
	}
	else if(ordem == 'H')
	{
		if(jx + padrao -1 < colunas)
		{
			return 1;
		}
	}
	return 0;
}				

int EhVertical(char ordem)			 		
{
	if(ordem == 'V')
	{	
		return 1;	
	}
	
	return 0;
}				 				
			 			
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 		
			 					 
