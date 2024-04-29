#include <stdio.h>

int main()
{
    int a, b, c, d, e, f;
    double result, menor = 30000000;
    int ix, fx, iy, fy;
    int i, j, intervalox, intervaloy;

    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    scanf("%d %d %d %d", &ix, &fx, &iy, &fy);

    for (i = ix; i <= fx; i++)
    {
        for (j = iy; j <= fy; j++) // Corrigido o erro aqui, substituí "i" por "j"
        {
            result = a * (i * i) + b * (j * j) + c * i * j + d * i + e * j + f;

            if (result < menor)
            {
                menor = result;
                intervalox = i;
                intervaloy = j;
            }
        }
    }

    printf("%d %d\n", intervalox, intervaloy);

    return 0;
}
