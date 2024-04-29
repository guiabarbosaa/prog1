#include <stdio.h>

int QuebraDois (int num) 
{
     int inicio, fim, result1, result2;
     
     inicio = num/100;
     fim = num % 100;
     
     result1 = inicio + fim;
     result2 = result1 * result1;
     	if (result2 != num) 
     	{
     	return 0;
     	}
     return 1;
}

int main() {
	int num1,num2,i;
	scanf("%d %d", &num1, &num2);
	     for (i = num1 +1; i < num2; i++)
	     {
	          if (QuebraDois(i)) 
	          {
	           printf("%d\n", i);
	          }
	     }
return 0;
}
