#include <stdio.h>

typedef struct
{
	int codigo;
	float preco;
	int QTDEstoque;
} tProduto;

int EhProduto1MaiorQ2(float p1, float p2)
{
	if (p1 > p2)
	{
	 return 1;
	}
  return 0;
}  	
	 

int EhProduto1MenorQ2(float p1, float p2)
{
	if (p1 < p2)
	{
	 return 1;
	}
  return 0;
}  	

int TemProdutoEmEstoque(tProduto p)
{
	if(p.QTDEstoque > 0)
	{
	 return 1;
	}
  return 0;
}	 
void ImprimeProduto(tProduto p)
{
	
 	printf("COD %d, PRE %.2f, QTD %d\n", p.codigo, p.preco, p.QTDEstoque);
 	
}	

int main ()
{
	int numQTD, i;
	tProduto material, maiorproduto, menorproduto;
	maiorproduto.preco = -3000; 
	menorproduto.preco = 3000;
	
	scanf("%d", &numQTD);
	
	for(i = 1; i <= numQTD; i++)
	{
	    scanf("%d;%f;%d", &material.codigo, &material.preco, &material.QTDEstoque);
	    
	    	  if (EhProduto1MaiorQ2(material.preco, maiorproduto.preco))
	    	  {
	    	   	maiorproduto = material;
	          }
	            
	          if (EhProduto1MenorQ2(material.preco, menorproduto.preco))
	          {
	           	menorproduto = material;
	          }
	          
	          if (!TemProdutoEmEstoque(material))
		  {
			printf("FALTA:");
			ImprimeProduto(material);
		  }
	}
	 
	printf("MAIOR:");
	ImprimeProduto(maiorproduto);

	printf("MENOR:");
	ImprimeProduto(menorproduto);

	return 0;
}          
	          
	          
	            
	    
	  
