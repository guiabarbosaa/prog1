#include <stdio.h>

int main ()
{
	char L1,L2,L3,num1,num2,num3,num4;
	int Lcont = 0,Numcont = 0;
	
	scanf("%c%c%c-%c%c%c%c", &L1, &L2, &L3, &num1, &num2, &num3, &num4);
	
	if (L1 >= 'a' && L1 <= 'z' || L1 >= 'A' && L1 <= 'Z')
	{
	 Lcont+=1;
	}  
	
	if (L2 >= 'a' && L2 <= 'z' || L2 >= 'A' && L2 <= 'Z')
	{
	 Lcont+=1;
	}  
	
	if (L3 >= 'a' && L3 <= 'z' || L3 >= 'A' && L3 <= 'Z')
	{
	 Lcont+=1;
	}
	if (num1 >= '0' && num1 <= '9')
	{
	 Numcont+=1;
	}
	if (num2 >= '0' && num2 <= '9')
	{
	 Numcont+=1;
	}
	if (num3 >= '0' && num3 <= '9')
	{
	 Numcont+=1;
	}
	if (num4 >= '0' && num4 <= '9')
	{
	 Numcont+=1;
	}
	
	if (Lcont == 3 && Numcont == 4)
	{
	 printf("Codigo valido!");
	} 
	else if (Lcont != 3 && Numcont == 4)
	{
	 printf("Codigo invalido!Problema nas letras!");
	} 
	else if (Lcont == 3 && Numcont != 4)
	{
	 printf("Codigo invalido!Problema nos numeros!");
	} 
	else if (Lcont != 3 && Numcont != 4)
	{
	 printf("Codigo invalido!Problema nas letras e nos numeros!");
	}
return 0;
} 
	
	
	
	           
	
