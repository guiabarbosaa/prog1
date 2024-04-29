#include <stdio.h>
int main () {
int ini, fim, i, atual, primeiro, segundo, soma, resultado;

	scanf ("%d %d", &ini, &fim);
	      for (i = ini+1; i < fim; i++) {
	           atual = i;
	           primeiro = atual / 100;
	           segundo = atual % 100;
	           soma = primeiro + segundo; 
	           resultado = soma * soma;
	                 if (resultado == atual) {
	                     printf ("%d\n", resultado);
     }	           	
    }
return 0;
}    
