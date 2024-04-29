#include <stdio.h>
typedef struct{
    int identificadordemensagem;
    int identificadordepacote;
    int tamanhomensagem;
    char mensagem[10];
    int codigodeerro;
} tPacote;

//IMPRIME A MENSAGEM DO PACOTE SE ELA FOR VALIDA
void ImprimePacote(tPacote pacote)
{
    int i=0, j=0;
    for(j=0;j<pacote.tamanhomensagem;j++)
    {
        printf("%c", pacote.mensagem[j]);
    }
}

/*PRINTA \n SE O NUMERO DA MENSAGEM MUDAR*/
int PrintaBarraN(tPacote PacoteAntes, tPacote PacoteDepois)
{
    if(PacoteDepois.identificadordemensagem==PacoteAntes.identificadordemensagem)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//CHECA SE A MENSAGEM EH VALIDA
int CalculaSomaDosDigitos(tPacote pacote, int qntdpacote)
{
    int soma=0, i=0;
    for(i=0;i<pacote.tamanhomensagem;i++)
    {
        soma+=pacote.mensagem[i];
    }
    soma+=pacote.identificadordemensagem;
    soma+=pacote.identificadordepacote;
    soma+=pacote.tamanhomensagem;
    if(soma==pacote.codigodeerro)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//ORDENA OS PACOTES DE MODO CRESCENTE DE ACORDO COM A LOGICA PROPOSTA
void OrdenaCrescente(tPacote pacote[], int qntdpacote)
{
    int i=0, j=0;
    tPacote salvavalor;
    for(i=0;i<qntdpacote;i++)
    {
        for(j=0;j<qntdpacote;j++)
        {
            if(pacote[i].identificadordemensagem<pacote[j].identificadordemensagem)
            {
                salvavalor=pacote[j];
                pacote[j]=pacote[i];
                pacote[i]=salvavalor;
            }
            else if(pacote[i].identificadordemensagem==pacote[j].identificadordemensagem)
            {
                if(pacote[i].identificadordepacote<pacote[j].identificadordepacote)
                {
                    salvavalor=pacote[i];
                    pacote[i]=pacote[j];
                    pacote[j]=salvavalor;
                }
            }
        }
    }
}

//OBTEM OS DADOS DE CADA PACOTE
tPacote LePacote()
{
    tPacote pacote;
    int i=0;
    scanf("%d %d %1d", &pacote.identificadordemensagem, &pacote.identificadordepacote, &pacote.tamanhomensagem);
    for(i=0;i<9;i++)
    {
        scanf("%c", &pacote.mensagem[i]);
    }
    scanf(" %d", &pacote.codigodeerro);
    return pacote;
}

//MAIN
int main()
{
    int qntdpacote=0, i=0, j=0;
    scanf("%d", &qntdpacote);
    tPacote pacote[qntdpacote];

    for(i=0;i<qntdpacote;i++)
    {
        pacote[i]=LePacote();//PEGA DADOS DE CADA PACOTE
    }
    
    //ORDENA OS PACOTES EM ORDEM CRESCENTE DE MENSAGEM
    OrdenaCrescente(pacote, qntdpacote);

    for(i=0;i<qntdpacote;i++)
    {
        if(i!=0)/*NAO PRINTAR /n NA PRIMEIRA POSICAO
        SEM QUERER*/
        {
            if(PrintaBarraN(pacote[i-1], pacote[i]))
            {   //SE O NUMERO DA MENSAGEM MUDAR, PRINTA \n
                printf("\n");
            }
        }
        if(CalculaSomaDosDigitos(pacote[i], qntdpacote))
        {   //MENSAGEM EH VALIDA, ENTAO PRINTA ELA
            ImprimePacote(pacote[i]);
        }
        else//MENSAGEM N EH VALIDA PRINTA FALHA
        {
            printf("##FALHA##");
        }
    }    

    return 0;    
}
