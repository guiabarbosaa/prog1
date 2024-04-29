#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int identificador;
	int qtdPassageiro;
	char Nomecarro[100];
	int tamNomeCarro;
	int KMrodados;
}tCarro;

typedef struct{
	int qtdCarro;
	tCarro carros[100];
}tConcessionaria;	

tCarro LeCarro();

tConcessionaria LeCarrosConcessionaria();

int ObtemNumPassageirosCarro(tCarro carro[], int i);

int ObtemKmCarro(tCarro carro[], int i);

void ImprimeCarro(tCarro carro[], int j);

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km);	

int main()
{
	tConcessionaria concessionaria;
	
	concessionaria = LeCarrosConcessionaria();
	
	int qtdPassageiros, km, cliente;
	char modo;
	
	while(scanf("%d,%d",&qtdPassageiros, &km) == 2)
	{
	printf("Caso %d:\n", ++i);
	
	ListaCarrosConcessionaria(concessionaria, qtdPassageiros, km);
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

int ObtemNumPassageirosCarro(tCarro carro[], int i)
{
	int passageiros = 0;
	
	passageiros = carro[i].qtdPassageiro;
	
	return passageiros;
}

int ObtemKmCarro(tCarro carro[], int i)
{
	int km = 0;
	
	km = carro[i].KMrodados;
	
	return km;
}

void ImprimeCarro(tCarro carro[], int j)
{	
	int i;
	printf("CARRO (%d): ", carro[j].identificador);
	for(i = 0; i < carro[j].tamNomeCarro; i++)
	{
		printf("%c", carro[j].Nomecarro[i]);
	}	
	printf(" de %d passageiros e com %d km\n", carro[j].qtdPassageiro, carro[j].KMrodados);
}

void ListaCarrosConcessionaria(tConcessionaria concessionaria, int pass, int km)
{
	int kmcarro = 0, passcarro = 0;
	int i, j;
	
	for(i = 0; i < concessionaria.qtdCarro; i++)
	{
		passcarro = ObtemNumPassageirosCarro(concessionaria.carros, i);
		
		kmcarro = ObtemKmCarro(concessionaria.carros, i);
		
		if(pass == -1 && km == -1)
		{
			ImprimeCarro(concessionaria.carros, i);
		}	
		else if (pass == -1) 
		{
            		if (km >= kmcarro) 
            		{
                	ImprimeCarro(concessionaria.carros, i);
            		}
        	} 
        	else if (km == -1) 
        	{
            		if (pass == passcarro) 
            		{
                	ImprimeCarro(concessionaria.carros, i);
            		}
            	}	
		else
		{						
			if(pass == passcarro && km >= kmcarro)
			{
			ImprimeCarro(concessionaria.carros, i);
			}
		}
	}
}					   
