#include <stdio.h>

int verificapH(float pH) 
{
    if (pH < 7) 
    {
        return 1;
    } 
    else if (pH == 7) 
    {
        return 2;
    } 
    else 
    {
        return 3;
    }
}

float porcentagem(float total, float valor) 
{
    float porcent;
    porcent = (valor * 100) / total;
    return porcent;
}

int verificaGotaChuvaAcida(float pH) 
{
    if (pH < 5.7) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal) 
{
    if (porcentagemGotasChuvaAcida >= 75.00) 
    {
        printf("Chuva Acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    } 
    else if (porcentagemGotasChuvaAcida <= 25.00) 
    {
        printf("Chuva Normal %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    } 
    else 
    {
        printf("Chuva com indicios de chuva acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    }
}

int main() 
{
    int A, D, T, QTDgotas=0, i;
    int acido = 0, neutro = 0, basico = 0, gotatotal = 0, chuvaAcida = 0;
    float gota, result1=0.0, result2=0.0, acidocont = 100.0, neutrocont1 = 0.0, basicont = 0.0, neutrocont2 = 100.0, neutrocontf1 = 0.0, neutrocontf2 = 0.0, neutrocontf0 = 0.0;
    scanf("%d %d %d", &A, &D, &T);
    QTDgotas = A * D * T;

    for (i = 1; i <= QTDgotas; i++) 
    {
        scanf("%f", &gota);
        gotatotal++;
        if (verificapH(gota) == 1) 
        {
            acido++;           
        } 
        else if (verificapH(gota) == 2) 
        {
            neutro++;
        } 
        else if (verificapH(gota) == 3) 
        {
            basico++;
        }
        if (gota < acidocont) 
        {
                acidocont = gota;
        }
        if (gota > basicont) 
        {
                basicont = gota;
        }    
            
        if (gota <= 7)
        {
            if (gota > neutrocont1)
            {
        	neutrocont1 = gota;
            }
        }
        if (gota > 7)
        {
            if (gota < neutrocont2)
            {
        	neutrocont2 = gota;
            }
        } 
        if (verificaGotaChuvaAcida(gota)) 
        {
            chuvaAcida++;
        }
    }
    neutrocontf2 = neutrocont2 - 7;
    neutrocontf1 = 7 - neutrocont1;
    
    if (neutrocontf1 < neutrocontf2)
    {
     neutrocontf0 = 7 - neutrocontf1;  
    }
    else if (neutrocontf1 >= neutrocontf2)
    {
     neutrocontf0 = neutrocontf2 + 7;
    }
    
    result1 = porcentagem(gotatotal, chuvaAcida);
    result2 = 100.0 - result1;

    printf("%d %d %d %.2f %.2f %.2f\n", acido, basico, neutro, acidocont, basicont, neutrocontf0);
    imprimeResultadosAnalise(result1, result2);

    return 0;
}

