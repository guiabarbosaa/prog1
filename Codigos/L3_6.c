#include <stdio.h>

int EhPalindromo(int num) 
{
      int inverso = 0,resto,origem;
      origem = num; 
      while (num != 0)
      {
            resto = num % 10;
            inverso = inverso * 10 + resto;
            num /= 10;
      }
      
      if (origem == inverso)
      {
      return 1;
      }
      else
      {
      return 0;
      }      
}

int main ()
{
      int num;
      while (scanf("%d", &num) == 1) 
      {
             if (EhPalindromo(num)) 
             {
                 printf("S\n");
             }
             else
             {
                 printf("N\n");
             }
      }		
return 0;
}	
