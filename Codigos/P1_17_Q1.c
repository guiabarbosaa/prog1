#include <stdio.h>
int main ()
{
	int num1, num2;
	
	scanf("%d %d", &num1, &num2);
	 
	if (num1 <= 5 && num1 <= 10 && num2 <= 5 && num2 <= 10)
	{
	 	if (num1 == num2)
	 	{
	 		printf("Um homem");
	 	}
	 	else
	 	{
	 		printf("Par de homens");
	 	}
	}
	else if (num1 <= 5 && num1 <= 10 && num2 > 5 && num2 <= 10)
	{
			printf("Um casal");
	}
	else if (num1 > 5 && num1 <= 10 && num2 <= 5 && num2 <= 10)
	{
			printf("Um casal");
	}
	else if (num1 > 5 && num1 <= 10 && num2 > 5 && num2 <= 10)
	{
		if (num1 == num2)
	 	{
	 		printf("Uma mulher");
	 	}
	 	else
	 	{
	 		printf("Par de mulheres");
	 	}
	}
	else 
	{
	 		printf("Invalido");
	} 
	
return 0;
}	
