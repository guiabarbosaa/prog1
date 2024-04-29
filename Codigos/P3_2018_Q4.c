#include <stdio.h>
#include <string.h>

int main()
{
    	char matriz[100][100];
    	char MaiorPalavra[100] = "--";
    	int i, j, result = 0, verificaTam = 0;
    	i = 0;

    	while (scanf("%99s", matriz[i]) == 1)
    	{
        i++;
    	}
  
    	for(j = 1; j <= i; j+=2)
    	{
    		if(strlen(matriz[j]) > strlen(matriz[j-1]))
    		{
    			printf("%s\n", matriz[j]);
    			if (strlen(matriz[j]) > strlen(MaiorPalavra))
        		{
            		strcpy(MaiorPalavra, matriz[j]);
        		}
    		}
    		else if(strlen(matriz[j]) < strlen(matriz[j-1]))
    		{
    			printf("%s\n", matriz[j-1]);
    			if (strlen(matriz[j-1]) > strlen(MaiorPalavra))
        		{
            		strcpy(MaiorPalavra, matriz[j-1]);
        		}
    		}
    	}
    			
    	printf("MAX:%s\n", MaiorPalavra);
    	return 0;
}
	
					
			 
		
		
