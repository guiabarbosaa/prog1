#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int codigo;
char sobrenome[21];
char nome[21];
int nota;
int idade;
} tCandidato;

tCandidato LeCandidato();

void ImprimeCandidato(tCandidato candidato);

void OrdenaCrescente(tCandidato * vet, int qtd);

int main(){
	int qtdCand, i = 0, j;
	scanf("%d", &qtdCand);
	tCandidato candidatos[qtdCand];
	tCandidato candidatosCrescente[qtdCand];
	
	for(i = 0; i < qtdCand; i++)
	{
	candidatos[i] = LeCandidato();
	}
	
	OrdenaCrescente(candidatos, qtdCand);
	
	for(i = 0; i < qtdCand; i++)
	{
	ImprimeCandidato(candidatos[i]);
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
printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
candidato.codigo, candidato.nome,
candidato.sobrenome, candidato.nota, candidato.idade);
}

void OrdenaCrescente(tCandidato* vet, int qtd) 
{
	int i, j;
	tCandidato temp;
	
	for(i = 0; i < qtd-1; i++)
	{
		for(j = i+1; j < qtd; j++)
		{
			if(vet[j].nota > vet[i].nota)
			{
				temp = vet[i];
                		vet[i] = vet[j];
                		vet[j] = temp;
			}
			else if(vet[j].nota == vet[i].nota)
			{
				if(vet[j].idade < vet[i].idade)
				{
					temp = vet[i];
                			vet[i] = vet[j];
                			vet[j] = temp;
                		}
                		else if (vet[j].idade == vet[i].idade)
                		{
                			if(vet[j].codigo < vet[i].codigo)
                			{
                				temp = vet[i];
                				vet[i] = vet[j];
                				vet[j] = temp;
                			}
                		}
                	}
                }
         }
}                					
                			

















