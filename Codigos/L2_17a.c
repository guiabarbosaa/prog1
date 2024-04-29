#include <stdio.h>

int main() {
    int modo, chave, atual = 0, soma = 0;
    char c, somac, corrigido;
    scanf("%d %d ", &modo, &chave);
    if (modo == 2) 
    {
      chave = -chave;
    }
    while (1) 
    {
        scanf("%c", &c);

        if (c == '.') 
        {
            printf(".");
            break;
        }
        if (chave > ('z' - 'a')) 
        {
            chave = chave % 26;
        }
        if (modo == 1 || modo == 2) 
        {
            
            if (c >= 'a' && c <= 'z' || c >= 'A' && c < 'Z' && c != 'J') 
            {
                somac = chave + c;
                if (somac > 'z' || (somac > 'Z' && c <= 'Z')) 
                {
                    corrigido = somac - ('z' - 'a' + 1);
                    printf("%c", corrigido);
                } 
                else 
                {
                    printf("%c", somac);
                }
            } 
            else 
            {
                printf("%c", c);
            }

        } 
        else 
        {
            printf("Operacao invalida.");
            break;
        }
    }
    return 0;
}





