#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} tData;

int InformaQtdDiasNoMesMA(int a_mes, int a_ano); // Protótipo da função

tData InicializaDataParam(int a_dia, int a_mes, int a_ano)
{
    tData data;
    int qtdDiasNoMes;

    data.ano = a_ano;

    if (a_mes > 12) {
        a_mes = 12;
    }
    else if (a_mes < 1) {
        a_mes = 1;
    }
    data.mes = a_mes;

    qtdDiasNoMes = InformaQtdDiasNoMesMA(a_mes, a_ano);
    if (a_dia > qtdDiasNoMes) {
        a_dia = qtdDiasNoMes;
    }
    else if (a_dia < 1) {
        a_dia = 1;
    }
    data.dia = a_dia;

    return data;
}

tData LeData()
{
    tData dataRtn;
    int d, m, a;

    if (scanf("%d %d %d", &d, &m, &a) != 3) {
        printf("ERRO: Formato de entrada nao compativel!\n");
        exit(1);
    }

    dataRtn = InicializaDataParam(d, m, a);

    return dataRtn;
}

void ImprimeData(tData a_data)
{
    printf("'%02d/%02d/%04d'", a_data.dia, a_data.mes, a_data.ano);
}

int EhBissextoAno(int a_ano)
{
    if (!(a_ano % 400)) {
        return 1;
    }
    if (!(a_ano % 100)) {
        return 0;
    }
    if (!(a_ano % 4)) {
        return 1;
    }
    return 0;
}

int EhBissexto(tData a_data)
{
    int rtn;
    rtn = EhBissextoAno(a_data.ano);
    return rtn;
}

int InformaQtdDiasNoMesMA(int a_mes, int a_ano)
{
    if (a_mes == 4 || a_mes == 6 || a_mes == 9 || a_mes == 11) {
        return 30;
    }
    if (a_mes == 2) {
        if (EhBissextoAno(a_ano)) {
            return 29;
        }
        return 28;
    }
    return 31;
}

int InformaQtdDiasNoMes(tData a_data)
{
    int rtn;
    rtn = InformaQtdDiasNoMesMA(a_data.mes, a_data.ano);
    return rtn;
}

tData AvancaParaDiaSeguinte(tData a_data)
{
    if (a_data.dia < InformaQtdDiasNoMes(a_data)) {
        a_data.dia++;
    }
    else {
        a_data.dia = 1;
        if (a_data.mes < 12) {
            a_data.mes++;
        }
        else {
            a_data.mes = 1;
            a_data.ano++;
        }
    }
    return a_data;
}

int EhIgual(tData a_data1, tData a_data2)
{
    return a_data1.dia == a_data2.dia &&
        a_data1.mes == a_data2.mes &&
        a_data1.ano == a_data2.ano;
}

int EhMenorDataAqDataB(tData a, tData b)
{
    if (a.ano < b.ano)
        return 1;
    else if (a.ano == b.ano && a.mes < b.mes)
        return 1;
    else if (a.ano == b.ano && a.mes == b.mes && a.dia < b.dia)
        return 1;

    return 0;
}

void ImprimeIntervaloDatas(tData d1, tData d2)
{
    tData data = d1;

    while (!EhIgual(data, d2)) {
        ImprimeData(data);
        printf("\n");
        data = AvancaParaDiaSeguinte(data);
    }
}

int main()
{
    tData d1, d2;

    d1 = LeData();
    d2 = LeData();

    ImprimeIntervaloDatas(d1, d2);

    return 0;
}


