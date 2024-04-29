#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int identificador;
    int tamanho;
    int numeros[10][10];
    int acertos;
} tCartela;

typedef struct {
    int quantidade;
    tCartela cartelas[100];
} tPartida;     

tPartida LeCartelasPartida();

void ImprimeCartela(tCartela cartela);

int MarcaCartela(tCartela cartela, int pedra);

tPartida ResetaPartida(tPartida partida);

void JogaPartida(tPartida partida);

int VenceuCartela(tCartela cartela);

int main()
{
	tPartida partida;
	int qtdPartidas, i;
	
	partida = LeCartelasPartida();
	
	scanf ("%d", &qtdPartidas);
	
	for (i = 0; i < qtdPartidas; i++)
	{
		if ( i!=0 ) printf("\n");
		printf("PARTIDA %d\n", i+1);
		partida = ResetaPartida(partida);
		JogaPartida(partida);
	}
return 0;
}

tPartida LeCartelasPartida() {
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

void ImprimeCartela(tCartela cartela) {
    printf("ID:%d\n", cartela.identificador);
    int i, j;
    
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

int MarcaCartela(tCartela cartela, int pedra)
{
	int i, j;
	
	for(i = 0; i < cartela.tamanho; i++)
	{
		for(j = 0; j < cartela.tamanho; j++)
		{
			if(pedra == cartela.numeros[i][j])
			{
				return 1;
			}
		}
	}
	
	return 0;			
}
tPartida ResetaPartida(tPartida partida)
{
	int k;
	
	for(k = 0; k < partida.quantidade; k++)
	{
		partida.cartelas[k].acertos = 0;
	}
	
	return partida;	
}
int VenceuCartela(tCartela cartela)
{
	if(cartela.acertos == (cartela.tamanho * cartela.tamanho))
	{
		return 1;
	}
	return 0;	 
}
void JogaPartida(tPartida partida)
{
	int pedra = 0;
	int k;
	int countvencedor = 0;
	
    while(1)
    {
		scanf("%d", &pedra);
		
		if(pedra == -1)
		{
			printf ("SEM VENCEDOR\n");
			return;
		}
		
		for(k = 0; k < partida.quantidade; k++)
		{
			partida.cartelas[k].acertos += MarcaCartela(partida.cartelas[k], pedra);
		}
	
	for(k = 0; k < partida.quantidade; k++)
	{	
		if(VenceuCartela(partida.cartelas[k]))
		{
			if(!countvencedor)
			{
			printf("COM VENCEDOR\n");
			}
			ImprimeCartela(partida.cartelas[k]);
			countvencedor = 1;
		}
		if(k == partida.quantidade-1 && countvencedor == 1)
		{
			while(pedra != -1)
			{
				scanf("%d", &pedra);
			}
			return;
		}		
	}	
    }				
}				



















