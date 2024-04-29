#include <stdio.h>

typedef struct
{
	int pontoX;
	int pontoY;
} tPonto;

tPonto InversoPonto(tPonto p)
{
	tPonto inverso;
	
	inverso.pontoX = -(p.pontoX);
        inverso.pontoY = -(p.pontoY);
	
	return inverso;
}

int LocalQuadrante(tPonto p)
{
	if(p.pontoX > 0 && p.pontoY > 0)
	{
		return 1;
	}
	else if(p.pontoX > 0 && p.pontoY < 0)
	{
		return 4;
	}
	else if(p.pontoX < 0 && p.pontoY > 0)
	{
		return 2;
	}
	else if(p.pontoX < 0 && p.pontoY < 0)
	{
		return 3;
	}
	else if(p.pontoX == 0 && p.pontoY < 0)
	{
		return 0;
	}
	else if(p.pontoX > 0 && p.pontoY == 0)
	{
		return 0;
	}
	else
	{
		return 0;
	}
}

void ImprimePonto(tPonto p)
{
	printf("(%d,%d) ", p.pontoX, p.pontoY);
}

int main ()
{
	int QTDPontos,i;
	int quadrante = 0,quadranteINV = 0;
	
	tPonto coordenada,INVcoordenada;
	
	scanf("%d", &QTDPontos);
	
		for (i = 1; i <= QTDPontos; i++)
		{
			scanf("%d %d", &coordenada.pontoX, &coordenada.pontoY);
			
			quadrante = LocalQuadrante(coordenada);
			
			ImprimePonto(coordenada);
			
			printf("%d ", quadrante);
			
			INVcoordenada = InversoPonto(coordenada);
			
			quadranteINV = LocalQuadrante(INVcoordenada);
			
			ImprimePonto(INVcoordenada);
			
			printf("%d\n", quadranteINV);
			
		}
return 0;
}		
			
			
			
			
			
				
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
