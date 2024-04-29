#include <stdio.h>
#include <math.h>

float calcularEquacao(float a, float b, float c, float d, float x) 
{
    return (a * pow(x, 3)) + (b * pow(x, 2)) + (c * x) + d;
}

int main() 
{
    float a, b, c, d, e, f;
    int x, xvale, xpico;
    float y, inicio; 
    float pico=0, vale=0;
    
    scanf("%f %f %f %f", &a, &b, &c, &d);
    scanf("%f %f", &e, &f);
    
    pico = calcularEquacao(a, b, c, d, e);
    vale = pico;
    
    for (x = e + 1; x < f; x++) 
    {
        y = calcularEquacao(a, b, c, d, x);
        
        if (y > pico) 
        {
            pico = y;
            xpico = x;
        }
        
        if (y < vale) 
        {
            vale = y;
            xvale = x;
        }
        
    }
     if (pico != calcularEquacao(a, b, c, d, e) && vale != calcularEquacao(a, b, c, d, e)) 
    {
        printf("Pico em x=%d\n", xpico);
        printf("Vale em x=%d\n", xvale);
    } 
    else if (pico == calcularEquacao(a, b, c, d, e) && vale != calcularEquacao(a, b, c, d, e)) 
    {
        printf("Nao ha pico\n");
        printf("Vale em x=%d\n", xvale);
    } else if (pico != calcularEquacao(a, b, c, d, e) && vale == calcularEquacao(a, b, c, d, e)) 
    {
        printf("Pico em x=%d\n", xpico);
        printf("Nao ha vale\n");
    } else 
    {
        printf("Nao ha pico\n");
        printf("Nao ha vale\n");
    }
    
    return 0;
}

