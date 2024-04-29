#include <stdio.h>

int main()
{
	int tam1, tam2, k, z;
	scanf("%d", &tam1);
	
	int sequencia[tam1];
	
	for(k = 0; k < tam1; k++)
	{
		scanf("%d", &sequencia[k]);
	}
	
	scanf("%d", &tam2);
	
	int sequencia2[tam2];
	
	for(z = 0; z < tam2; z++)
	{
		scanf("%d", &sequencia2[z]);
	}
	printf("PARES:\n");
	z = 0;
	k = 0;
	while(k < tam1)
	{
		if(z == tam2)
		{
			z = 0;
		}
			
		printf("%d - %d\n", sequencia[k], sequencia2[z]);
		k++;
		z++;
	}
}			
		
