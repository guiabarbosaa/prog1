#include <stdio.h>

void VerificaTipoSenha();

int EhAlgarismo(char c);

int EhNumero(char c);

int EhLetraMas(char c);

int EhLetraMin(char c);

int main()
{
    int num, i;

    scanf("%d\n",&num);

    for(i = 0; i < num; i++)
    {
        VerificaTipoSenha(); 
    }

    return 0;
}

void VerificaTipoSenha()
{
    char c; 
    int countMas = 0,countMin = 0,countNum = 0,countEspecial = 0,countLetras = 0;
    while(scanf("%c", &c) == 1)
    {
        if(c == '\n')
        {
            break;
        }
        countLetras +=1;
        if(EhAlgarismo(c))
        {
            if(EhLetraMas(c))
            {
                countMas += 1;
            }
            else if(EhLetraMin(c))
            {
                countMin += 1;
            }
        }
        else if(EhNumero(c))
        {
            countNum +=1;
        }
        else
        {
            countEspecial += 1;
        }
    }

    if(countLetras >= 6 && countMas >= 1 && countMin >= 1 && countNum >= 1 && countEspecial >= 1)
    {
        printf("FORTE\n");
    }
    else if(countLetras >= 6 && countMas >= 1 && countMin >= 1 && countNum >= 1)
    {
        printf("MEDIA\n");
    }
    else if(countLetras < 6)
    {
        printf("INVALIDA\n");
    }
    else
    {
        printf("FRACA\n");
    }
}

int EhAlgarismo(char c)
{
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    return 0;
}

int EhNumero(char c)
{
    switch(c){
        case '1': case '2':
        case '3': case '4':
        case '5': case '6':
        case '7': case '8':
        case '9': case '0':
        return 1;
        default:
        return 0;
    }
}

int EhLetraMas(char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    return 0;
}

int EhLetraMin(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return 1;
    }
    return 0;
}
