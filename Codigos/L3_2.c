#include <stdio.h>

float Soma(float num1, float num2) {
    return num1 + num2;
}

float Subtracao(float num1, float num2) {
    return num1 - num2;
}

float Divisao(float num1, float num2) {
    return num1 / num2;
}

float Multiplicacao(float num1, float num2) {
    return num1 * num2;
}

int main() 
{
    float num1, num2;
    float result = 0;
    char sinal;
    scanf("%f", &num1);
    while (scanf("%f", &num2) == 1 && scanf(" %c", &sinal) == 1) 
    {
        if (result == 0) 
        {
            result = num1;
        } 
        if (sinal == '+') 
        {
            result = Soma(result, num2);
        } 
        else if (sinal == '-') 
        {
            result = Subtracao(result, num2);
        } 
        else if (sinal == '/') 
        {
            result = Divisao(result, num2);
        } 
        else if (sinal == '*') 
        {
            result = Multiplicacao(result, num2);
        } 
    }

    printf("%.2f", result);

    return 0;
}

