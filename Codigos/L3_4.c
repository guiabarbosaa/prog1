#include <stdio.h>

int Primo(int num) 
{
    int i;
    if (num <= 1) 
    {
        return 0;
    }
    for (i = 2; i <= num / 2; i++) 
    {
        if (num % i == 0) 
        {
            return 0; 
        }
    }
    return 1;
}

int Multiplo(int j, int i)
{ 
     if (j % i != 0) 
     {
	return 0;
     }
     else 
     {
        return 1;
     }
}
    	

int main() {
    int num1, num2, i, j;
    scanf("%d %d", &num1, &num2);
    
    for (i = num1 + 1; i < num2; i++) 
    {
        if (Primo(i)) 
        {
            printf("%d\n", i);
                   int temMultiplos = 0;
            	   for (j = i + 1; j < num2; j++) 
            	   {  
            	   	if (Multiplo(j,i))
                   	{ 
                   	printf("%d ", j);
                   	temMultiplos = 1;
                   	}
                   }
                   	if (!temMultiplos)
                   	{
                   	printf("*");
                   	}
                   printf("\n");
                   	
         }
    }
    return 0;
}

