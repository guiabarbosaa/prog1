#include <stdio.h>
#include <math.h>

int main(){
	
	int n1, n2, n3;
	int media;

	scanf("%d %d %d", &n1, &n2, &n3);

        media = round((n1 + n2 + n3)/3.0);
	
	printf("Notas acima da media: ");
	if (n1 >= media && n2 >= media && n3 < media){ 
		printf("%d %d", n1, n2);
	}
	if (n1 >= media && n2 >= media && n3 >= media){ 
		printf("%d %d %d",n1 ,n2, n3);
	}
	if (n1 >= media && n3 >= media && n2 < media){ 
		printf("%d %d",n1 ,n3);
	}
	if (n2 >= media && n3 >= media && n1 < media){ 
		printf("%d %d",n2 ,n3);
	}
	
	printf("!");
	
	return 0;
}

