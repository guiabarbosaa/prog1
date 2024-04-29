#include <stdio.h>
int main ()
{
	int ordem, num, posicont=0, i, menor = 3000, posicao=0;
	
	scanf ("%d", &ordem);
	
		for(i = 1; i <= ordem; i++)
		{
			scanf("%d", &num);
			posicont++;
			
				if (num < menor)
				{
				    menor = num;
				    posicao = posicont;
				}
		}
		
		if (ordem == 0)
		{
		   printf("\n");;
		}
		else
		{    
		   printf("POS:%d", posicao);
		}
return 0;
}				    
