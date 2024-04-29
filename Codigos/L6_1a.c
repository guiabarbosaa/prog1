#include <stdio.h>

typedef struct {
    int mensagem;
    int pacote;
    int tamanho;
    char conteudo[9];
    int codigoErro;
} tPacote;

tPacote LePacote();

void ImprimePacote(tPacote pacote);

int main() {
    int n, i;
    scanf("%d", &n);
    
    tPacote pacotes[n];
    
    for (i = 0; i < n; i++) {
        pacotes[i] = LePacote();
    }
     for (i = 0; i < n; i++) {
        ImprimePacote(pacotes[i]);
    }
    
    return 0;
}

tPacote LePacote() 
{
    int i;	
    tPacote pacote;
    scanf("%d%d%1d", &pacote.mensagem, &pacote.pacote, &pacote.tamanho);
    for(i = 0; i < 9; i++)
    {
    	scanf("%c", &pacote.conteudo[i]);
    }
    scanf("%*c");
    scanf("%d", &pacote.codigoErro);
    	
    return pacote;
}

void ImprimePacote(tPacote pacote) 
{
    int i;
    
    printf("PCT: %d,%d,%d,", pacote.mensagem, pacote.pacote, pacote.tamanho);
    for(i = 0; i < pacote.tamanho; i++)
    {
    	printf("%c", pacote.conteudo[i]);
    }
    printf(",%d\n", pacote.codigoErro);
}    

