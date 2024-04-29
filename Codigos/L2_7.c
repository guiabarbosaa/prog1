#include <stdio.h>

int main (){
int x ,i, primo=1;
	scanf ("%d",&x);
	
	if (x<2) {
	printf ("Nao primo");
	}
        else {
	for (i=2; i < x; i++) {
	    if (x % i == 0) {
	    primo = 0;
	    break;
	    }
	 }
	 
    if (primo) {
        printf("Primo");
    } 
    else {
        printf ("Nao primo");
       }
    }
    return 0;
 }       
      
	
