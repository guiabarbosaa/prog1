#include <stdio.h>

typedef struct
{
	int pontoX;
	int pontoY;
} tPonto;

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

int main ()
{
	tPonto ponto1, ponto2;
	int quadrante1=0, quadrante2=0;
	int QTDPontos, i;
	
	scanf("%d", &QTDPontos);
	
		for(i = 1; i <= QTDPontos; i++)
		{
		    scanf("%d %d", &ponto1.pontoX, &ponto1.pontoY);
		    scanf("%d %d", &ponto2.pontoX, &ponto2.pontoY);
		
		    quadrante1 = LocalQuadrante(ponto1);
		    quadrante2 = LocalQuadrante(ponto2);
		    
		          if(quadrante1 == quadrante2 && quadrante1 != 0 && quadrante2 != 0)
		          {
                             printf("MESMO\n");
                          }
                          else
                          {
                             printf("DIFERENTE\n");
                          }
                    quadrante1 = 0;
                    quadrante2 = 0;
                }
return 0;
}                              		          
		         
 	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
