#include <stdio.h>

int main ()
{
	int count = 0, countInicio = 0;
	char c;
	
	while (1)
	{
		scanf("%c", &c);
		countInicio++;
		if(c == '.' && count == 0)
		{
		 break;
		}
		
		if (countInicio == 1)
		{
		 printf("RESP:");
		}
		 
		if (c == ')')
		{
		 count--;
		}
		
		if (count != 0)
		{
		 printf("%c", c);
		} 
		
		if (c == '(')
		{
		 count++;
		}
	}
return 0;
}		
		
		
