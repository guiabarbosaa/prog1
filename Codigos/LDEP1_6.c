#include <stdio.h>

int main(){
	
	int l, c, i, j;
	int somatotal = 0;
                
	scanf("%d %d", &l, &c);
        
        int matriz [l] [c];
	
	for (i = 0; i<l; i++){
	        int somalinha = 0;
		for(j = 0; j<c; j++){
		        int atual;
			scanf("%d", &atual);
			somalinha += atual;
			matriz[i][j] = atual;
		}
		printf("%d\n", somalinha);
		somatotal += somalinha;
	}

	printf("%d\n", somatotal);

	return 0;
}
