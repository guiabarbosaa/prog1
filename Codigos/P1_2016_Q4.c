#include <stdio.h>
int main ()
{
 	int num1, num2, num3, n1, n2, n3;
 	
 	scanf("%d %d %d", &num1, &num2, &num3);
 	
 	if ((num1 >= 100 || num2 >= 100 || num3 >= 100) && (num1 <= 999999 || num2 <= 999999 || num3 <= 999999))
 	{
 	 num1 = num1/100;
 	 num1 = num1 % 10;
 	 
 	 num2 = num2/100;
 	 num2 = num2 % 10;
 	 
 	 num3 = num3/100;
 	 num3 = num3 % 10;
 	
 		if (num1 == 0)
 		{
 	 	 num1 += 9999999;
 		}
 		if (num2 == 0)
 		{
 	 	 num2 += 9999999;
 		}
 		if (num3 == 0)
 		{
 	 	 num3 += 9999999;
 		}
 	 
 	 	if (num1 <= num2 & num1 <= num3)
 	 	{
 	  	 printf("N1");
 	 	} 
 	 	else if (num2 < num1 & num2 <=num3)
 	 	{
 	  	 printf("N2");
 	 	} 
 	 	else if (num3 < num2 & num3 <num1)
 	 	{
 	 	 printf("N3");
 	 	}
 	}
 	else
 	{
 	 printf("Nenhum");
 	}  
} 	  
