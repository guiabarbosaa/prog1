#include <stdio.h>
int main() {
	int li, lf, i, j;

	scanf ("%d %d",&li ,&lf);

	int matriz [lf - li + 1] [10];
	for (i=li; i<= lf; i++) {
		for(j=1; j<=10; j++){ 
		     int atual = i*j;
		     matriz [i - li] [j - 1] = atual;
		     atual = i*j;
		     printf("%d x %d = %d\n", i, j, atual);	     
	    }	     
	}
	return 0;
}		     
