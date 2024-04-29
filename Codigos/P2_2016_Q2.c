#include <stdio.h>

int EhPrimo(int num)
{
	int i;
	
 	if (num < 2)
 	{
 	 return 0;
 	}
 	for (i = 2; i < num; i++)
 	     if (num % i == 0)
 	     {
 	      return 0;
 	     }
 	return 1;       
 
}

int MaiorDigitoPrimo(int num)
{
	int resto=0, Maior = 0;
	while (num > 0)
	{
	resto = num % 10;
		 if (EhPrimo(resto) && resto >= Maior)
		 {
		  Maior = resto;
		 }  
	num = num/10;
	}
	return Maior;
}

int main ()
{
	int num, Maior=0, soma=0;
	char c;
	
	while (scanf("%d%c", &num, &c)==2)
	{
	       if (c != ' ')
	       {
	        break;
	       } 
	 Maior = MaiorDigitoPrimo(num);
         soma += Maior;
	}
	printf("SOMA:%d", soma);
return 0;
}	 	 
