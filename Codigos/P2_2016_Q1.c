#include <stdio.h>

int main () 
{
 	int ordem, num1, num, i; 
 	int parcont=1, imparcont=1;
 	
 	scanf ("%d", &ordem);
 	scanf ("%d", &num1);
 	
 	if (num1 % 2 == 0)
 	{
 	    for (i=2; i<=ordem;i++)
 	    {
 	    	scanf("%d", &num);
 	    	      if (num % 2 == 0)
 	              {
 	               parcont++;
 	              }
 	    }
 	  printf("QTD PARES:%d",parcont);  
 	}
 	else if (num1 % 2 != 0)
 	{
 	    for (i=2; i<=ordem;i++)
 	    {
 	    	scanf("%d", &num);
 	    	      if (num % 2 != 0)
 	              {
 	               imparcont++;
 	              }
 	    }
 	  printf("QTD IMPARES:%d",imparcont);
 	}
  return 0;
}   	    
 	                   
