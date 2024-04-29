#include <stdio.h>
int main ()
{
	int num1, num2, result;
	char operador;
	
	scanf("%d %d %c", &num1, &num2, &operador);
	
		if (operador == '+')
		{
			result = num1 + num2;
			printf("RESP:%d", result);
		}
		else if (operador == '-')
		{
			result = num1 - num2;
			printf("RESP:%d", result);
		}
		else if (operador == '*')
		{
			result = num1 * num2;
			printf("RESP:%d", result);
		}
		else if (operador == '/')
		{
			result = num1 / num2;
			printf("RESP:%d", result);
		}
		else
		{
			printf("Invalido");
		}
return 0;
}		
