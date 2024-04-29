#include <stdio.h>

int Primo(int num) {
    int i;
    if (num <= 1) {
        return 0; // Não é primo
    }
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Não é primo
        }
    }
    return 1;
}

void ImprimirMultiplos(int num1, int num2, int primo) {
    int i;
    int temMultiplos = 0; 

    for (i = num1 + 1; i <= num2; i++) {
        if (i % primo == 0) {
            printf("%d ", i);
            temMultiplos = 1;
        }
    }

    if (!temMultiplos) {
        printf("*");
    }
    printf("\n");
}

int main() {
    int num1, num2, i;
    scanf("%d %d", &num1, &num2);

    for (i = num1 + 1; i <= num2; i++) {
        if (Primo(i)) {
            printf("%d\n", i);
            ImprimirMultiplos(i + 1, num2, i);
        }
    }
    return 0;
}

