#include <stdio.h>
int main ()
{
	int num, resto=0, real=0, inverso = 0, palincount=0;
	
	while(scanf("%d", &num) == 1)
	{
	 real = num;
		while (num > 0)
		{
		 resto = num%10;
		 inverso = inverso*10 + resto;
		 num /= 10;
		}
		if (inverso == real)
		{
		 palincount++;
		}		 
	 inverso = 0;
	 resto = 0;
	}
	
	printf("COUNT:%d", palincount);
}	
