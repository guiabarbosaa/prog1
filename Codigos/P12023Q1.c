#include <stdio.h>

int main()
{
    int num;
    int countprimo = 0;

    while(scanf("%01d", &num) == 1)
    {
        if(num % 2 != 0)
        {
        countprimo +=1;
        }
    }
printf("%d\n", countprimo);
return 0;
}
