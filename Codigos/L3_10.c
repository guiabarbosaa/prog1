#include <stdio.h>
#include <stdlib.h>

int main(){
	int mode = 0, num = 0, corrector = 26;
	char newChar = '0';
	scanf("%d %d", &mode, &num);
	if (num>25){
		num = num%26;
	}
	if (mode == 2){
		num = -num;
		corrector = -26;
	}else{
		if(mode != 1){
			printf("Operacao invalida.");
			exit(0);
		}
	}
    scanf(" ");
	while(1){
		scanf("%c", &newChar);
		if(newChar == '.'){
			break;
		}
		if (newChar >= 97 && newChar <= 122){
			if ((newChar + num)>122||(newChar + num)<97){
				printf("%c", (newChar - corrector + num));
			}else{
				printf("%c", (newChar + num));
			}
			
		}else{
			printf("%c", newChar);
		}
	}
	printf(".");
	return 0;
}
