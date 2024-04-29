#include <stdio.h>
#include <string.h>

typedef struct {
    int tamPalavra;
    char conteudo[5000];
} tPalavra;

int CountVogal(tPalavra palavra);

int CountConsoante(tPalavra palavra);

void ImprimePalavra(tPalavra palavra);

int main() {
    tPalavra palavras[100];
    int i = 0, k = 0;
    char c;
     while (scanf("%[^\n]", palavras[i].conteudo) == 1) {
        scanf("%*[\n]");
        
        i++;
    }
    while(k < i)
    {
    	ImprimePalavra(palavras[k]);
    	
    	k++;
    }	
}

int CountVogal(tPalavra palavra) {
    int Vogal = 0;
    int k;

    for (k = 0; palavra.conteudo[k] != '\0'; k++) {
          switch(palavra.conteudo[k]){
              case 'A': case 'a':
              case 'E': case 'e':
              case 'I': case 'i':
              case 'O': case 'o':
              case 'U': case 'u':
              Vogal++;
              break; 
          }
    }
    return Vogal;
}

int CountConsoante(tPalavra palavra) {
    int Consoante = 0;
    int k;

    for (k = 0; palavra.conteudo[k] != '\0'; k++) {
        if ((palavra.conteudo[k] >= 'A' && palavra.conteudo[k] <= 'Z') ||
            (palavra.conteudo[k] >= 'a' && palavra.conteudo[k] <= 'z')) {
                switch(palavra.conteudo[k]){
                     	case 'A': case 'a':
                	case 'E': case 'e':
                	case 'I': case 'i':
               	 	case 'O': case 'o':
                	case 'U': case 'u':
                    	break;
                	default:
                	Consoante++;
            }
        }
    }
    return Consoante;
}

void ImprimePalavra(tPalavra palavra) {
    int NumVogal = 0, NumConsoante = 0, i = 0;
    int k;
    char c[100];
    
    NumVogal = CountVogal(palavra);

    NumConsoante = CountConsoante(palavra);

    if (NumVogal == NumConsoante) 
    {
        printf("%s\n", palavra.conteudo);
    } 
    else if (NumVogal > NumConsoante) 
    {
        for (k = 0; palavra.conteudo[k] != '\0'; k++) 
        {
            switch(palavra.conteudo[k])
            {
              case 'A': case 'a':
              case 'E': case 'e':
              case 'I': case 'i':
              case 'O': case 'o':
              case 'U': case 'u':
              printf("%c", palavra.conteudo[k]);
              break; 
            }
        }
        printf("\n");
    } 
    else if (NumVogal < NumConsoante)
    {
        for (k = 0; palavra.conteudo[k] != '\0'; k++) 
        {
             if((palavra.conteudo[k] >= 'A' && palavra.conteudo[k] <= 'Z') ||
                 (palavra.conteudo[k] >= 'a' && palavra.conteudo[k] <= 'z')) 
                 {
                        switch(palavra.conteudo[k])
                        {
                     	case 'A': case 'a':
                	case 'E': case 'e':
                	case 'I': case 'i':
               	 	case 'O': case 'o':
                	case 'U': case 'u':
                    	break;
                	default:
                	printf("%c", palavra.conteudo[k]);
                	}
            	}
        }
        printf("\n");
    }
}

		
		
		
		
		
		
		
		
		
		
		
		
		
		
				
				
	
		
	
