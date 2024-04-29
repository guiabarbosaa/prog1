#include <stdio.h>

int main() {
    int n, num, i, maior, menor, pares = 0, soma = 0, impares = 0;
    float media;

    scanf("%d", &n);
    scanf("%d", &num);
    maior = num;
    menor = num;
    soma = num;

    
    for (i = 2; i <= n; i++) {
        scanf("%d", &num);

        if (num % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        if (num > maior) {
            maior = num;
        }
        if (num < menor) {
            menor = num;
        }

        soma += num;
    }

    media = (float) soma / n;

    printf("%d ", maior);
    printf("%d ", menor);
    printf("%d ", pares);
    printf("%d ", impares);
    printf("%.6f", media);

    return 0;
}
