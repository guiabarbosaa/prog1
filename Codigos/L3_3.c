#include <stdio.h>

int Primo(int num) 
{
    int i;
    if (num <= 1) 
    {
        return 0;
    }
    for (i = 2; i <= num / 2; i++) 
    {
        if (num % i == 0) 
        {
            return 0; 
        }
    }
    return 1;
}

int main() 
{
    int num1, num2, i;
    scanf("%d %d", &num1, &num2);

    for (i = num1 + 1; i < num2; i++) 
    {
        if (Primo(i)) 
        {
            printf("%d ", i);
        }
    }
    
    return 0;
}

