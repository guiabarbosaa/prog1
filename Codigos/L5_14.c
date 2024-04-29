#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
int ComparaString(char *str1, char *str2);

int main(){
	int qtdCand, i, j, sobrenomeIgual=0, breaker=0;
	scanf("%d", &qtdCand);
	tCandidato candidatos[qtdCand];
	tCandidato candidatosIguais[qtdCand];
	
	for(i = 0; i < qtdCand; i++)
	{
	candidatos[i] = LeCandidato();
	}		
	
	for(i = 0; i < qtdCand; i++)
	{
		if(candidatos[i].codigo != -1)
		{
			for(j = i + 1; j < qtdCand; j++)
			{
				if( ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome) )
				{
					if (!breaker)
                        		{
                            		candidatosIguais[sobrenomeIgual] = candidatos[i];
                            		candidatos[i].codigo = -1;
                            		sobrenomeIgual++;
                            		breaker = 1;
                        		}
                        
                        	candidatosIguais[sobrenomeIgual] = candidatos[j];
                        	candidatos[j].codigo = -1;
                        	sobrenomeIgual++;
				}
			}
			breaker = 0;
	    	}	
	}
	
	for(i = 0; i < sobrenomeIgual; i++)
	{
		ImprimeCandidato(candidatosIguais[i]);
	}						
		
return 0;
}

tCandidato LeCandidato()
{
	tCandidato candidato;
	scanf("%*[^{]");
	scanf("%*[{ ]");
	scanf("%d", &candidato.codigo);
	scanf("%*[, ]");
	scanf("%[^,],", candidato.sobrenome);
	scanf("%*[ ]");
	scanf("%[^,],", candidato.nome);
	scanf("%d", &candidato.nota);
	scanf("%*[, ]");
	scanf("%d", &candidato.idade);
	scanf("%*[^\n]\n");
	
return candidato;
}

void ImprimeCandidato(tCandidato candidato)
{

	printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
	
}
int ComparaString(char * str1, char * str2)
{
	int i = 0;
	
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return 0;
		}
	i++;
	}
	
	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return 1;
	}
	
	return 0;
}				
