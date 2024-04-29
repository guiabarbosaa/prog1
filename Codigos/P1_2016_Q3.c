#include <stdio.h>
int main () 
{
	char c1,c2,c3,c4;
	int placacont=0;
	
	scanf("%c%c%c%c", &c1, &c2, &c3, &c4);
	
	if (c1 >= 'A' && c1 <= 'Z')
	{
	 placacont+=1;
	} 
	if (c2 >= '1' && c2 <= '9')
	{
	 placacont+=1;
	}
	if (c3 == 'a' || c3 == 'e' || c3 == 'i' || c3 == 'o' || c3 == 'u') 
	{
	 placacont+=1;
	}
	if (c3 == 'A' || c3 == 'E' || c3 == 'I' || c3 == 'O' || c3 == 'U')
	{
	 placacont+= 1;
	} 
	if ((c4 >= 'a' && c4 <= 'z') && (c4 != 'a' && c4 != 'e' && c4 != 'i' && c4 != 'o' && c4 != 'u'))
	{
	 placacont+=1;
	}
	
	if (placacont != 4)
	{
	 printf("Invalido");
	}
	else
	{
	 if (c3 == 'a' || c3 == 'e' || c3 == 'i' || c3 == 'o' || c3 == 'u')
	 {
	  c3 -= 32;
	  printf("%c%c%c%c",c1,c2,c3,c4-32);
	 }
	 else 
	 {
	  printf("%c%c%c%c",c1,c2,c3,c4-32);
	 } 
	}      
return 0;
}	
