#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int identificador;
    int tamanho;
    int numeros[10][10];
} tCartela;

typedef struct {
    int quantidade;
    tCartela cartelas[100];
} tPartida;     

tPartida LeCartelaPartida();

void ImprimeInvCartelasPartida(tPartida partida);

int main()
{

tPartida partida;

partida = LeCartelaPartida();

ImprimeInvCartelasPartida(partida);

return 0;
}

tPartida LeCartelaPartida() {
    tPartida partida;
    int i, j, k;
    
    scanf("%d", &partida.quantidade);
    
    for(k = 0; k < partida.quantidade; k++)
    {
   
    	scanf("%d", &partida.cartelas[k].identificador);
    
    	scanf("%d", &partida.cartelas[k].tamanho);

    	for (i = 0; i < partida.cartelas[k].tamanho; i++) {
        	for (j = 0; j < partida.cartelas[k].tamanho; j++) {
            		scanf("%d", &partida.cartelas[k].numeros[j][i]);
        	}
    	}
    }
    return partida;
}

void ImprimeInvCartelasPartida(tPartida partida)
{
	int i, j, k;
	tCartela cartela;
	
	for(k = partida.quantidade - 1; k >= 0; k--)
	{
	
		cartela = partida.cartelas[k];
		
		printf("ID:%d\n", cartela.identificador);
    
    		for (i = 0; i < cartela.tamanho; i++) {
        		for (j = 0; j < cartela.tamanho; j++) {
            			if (j == cartela.tamanho - 1)
            			{
            			printf("%03d", cartela.numeros[i][j]);
            			}
            			else
            			{
            			printf("%03d|", cartela.numeros[i][j]);
            			}
        		}
        		printf("\n");
        	}
        }		
}
