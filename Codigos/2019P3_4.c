#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int identificador;
	int qtdPassageiro;
	char Nomecarro[100];
	int tamNomeCarro;
	int KMrodados;
	int cliente;
}tCarro;

typedef struct{
	int qtdCarro;
	tCarro carros[100];
}tConcessionaria;	

tCarro LeCarro();

tConcessionaria LeCarrosConcessionaria();

int ObtemNumPassageirosCarro(tCarro carro);

int ObtemKmCarro(tCarro carro);

int ObtemClienteAlugouCarro(tCarro carro);

tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int cliente, int pass, int km);

int EstaDisponivelCarro(tCarro carro);

tCarro AlugaCarro(tCarro carro, int cliente);

tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int cliente);

tCarro DevolveCarro(tCarro carro); 

void ImprimeCarro(tCarro carro);

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km);	

int main()
{
    tConcessionaria concessionaria;

    concessionaria = LeCarrosConcessionaria(); //ler os carros
    int qtdPassageiros, km, cliente;
    char acao;//aluguel ou devolução
    while(scanf("\n%d,%c", &cliente, &acao) == 2){ //loop pra cada caso
        switch(acao){
            case 'A': //aluguel
            scanf("\n%d,%d", &qtdPassageiros, &km);
            concessionaria=AlugaCarroConcessionaria(concessionaria, cliente, qtdPassageiros, km);
            break;
            case 'D': //devolução
            concessionaria=DevolveCarroConcessionaria(concessionaria, cliente);
            break;
        }
    }
    return 0;
}

tCarro LeCarro()
{
    tCarro carro;
    int i = 0;

    scanf("%d %d", &carro.identificador, &carro.qtdPassageiro);
    scanf(" %s", carro.Nomecarro); 
    scanf("%d", &carro.KMrodados);
    carro.tamNomeCarro = strlen(carro.Nomecarro);
    carro.cliente = 0; 

    return carro;
}

tConcessionaria LeCarrosConcessionaria()
{
	tConcessionaria concessionaria;
	int i;
	
	scanf("%d", &concessionaria.qtdCarro);
	
	for(i = 0; i < concessionaria.qtdCarro; i++)
	{
		concessionaria.carros[i] = LeCarro();
	}
	
	return concessionaria;
}

int ObtemNumPassageirosCarro(tCarro carro)
{
	int passageiros = 0;
	
	passageiros = carro.qtdPassageiro;
	
	return passageiros;
}

int ObtemKmCarro(tCarro carro)
{
	int km = 0;
	
	km = carro.KMrodados;
	
	return km;
}

int ObtemClienteAlugouCarro(tCarro carro)
{
	int alugou = 0;
	
	alugou = carro.cliente;
	
	return alugou;
}	

tConcessionaria AlugaCarroConcessionaria(tConcessionaria concessionaria, int cliente, int pass, int km)
{
	int k, alugado = 0;
	
	for(k = 0; k < concessionaria.qtdCarro; k++)
	{
		if(concessionaria.carros[k].qtdPassageiro==pass || pass==-1)
		{
            		if(concessionaria.carros[k].KMrodados<=km || km==-1)
            		{ // checar os requisitos do cliente
                		if(EstaDisponivelCarro(concessionaria.carros[k]))
                		{// ver se já foi alugado
                    			concessionaria.carros[k]=AlugaCarro(concessionaria.carros[k], cliente);
                    			printf("Alugado (cliente %d) -> ", cliente);
                    			ImprimeCarro(concessionaria.carros[k]); //alugar e sinalizar o aluguel
                    			return concessionaria;
                    		}
                    	}
		}
	}
	
	printf("Carro Indisponivel\n");
	
	return concessionaria;	                    			
}
int EstaDisponivelCarro(tCarro carro)
{
	if(!ObtemClienteAlugouCarro(carro))
	{
		return 1;
	}
	return 0;
}		

tCarro AlugaCarro(tCarro carro, int cliente)
{
	carro.cliente = cliente;
	
	return carro;
}	


tConcessionaria DevolveCarroConcessionaria(tConcessionaria concessionaria, int cliente)
{
	int i;
	
	for(i=0; i< concessionaria.qtdCarro; i++)
	{
        	if(concessionaria.carros[i].cliente == cliente)
        	{ //achar o carro do cliente
            		concessionaria.carros[i]=DevolveCarro(concessionaria.carros[i]);
            		printf("Devolvido (cliente %d) -> ", cliente);
            		ImprimeCarro(concessionaria.carros[i]); //devolver e sinalizar a devolução
            		break;
            	}	
        }
        
    return concessionaria;
}

tCarro DevolveCarro(tCarro carro)
{
	carro.cliente = 0;
	
	return carro;
}	

void ImprimeCarro(tCarro carro)
{	
	int i;
	printf("CARRO (%d): ", carro.identificador);
	for(i = 0; i < carro.tamNomeCarro; i++)
	{
		printf("%c", carro.Nomecarro[i]);
	}	
	printf(" de %d passageiros e com %d km\n", carro.qtdPassageiro, carro.KMrodados);
}
	
