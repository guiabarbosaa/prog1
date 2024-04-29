#include <stdio.h>
#include <math.h>

void LeNotas (int notas[], int n);

int MaiorNota (int notas[], int n);

int MenorNota (int notas[], int n);

float calcularMedia(int notas[], int n);

float calcularDesvioPadrao(int notas[], int n, float media);

int Reprovados(int notas[], int n);

int AcimaDaMedia(int notas[], int n, int media);

int main() {
    int n, i;
    int menorNota = 0, maiorNota = 0; 
    float media = 0.0, desvioPadrao = 0.0;
    int acimaDaMedia = 0, reprovados = 0;

    scanf("%d", &n);
    
    int notas[n];
    
    LeNotas(notas, n);
    
    menorNota = MenorNota (notas, n);
    
    maiorNota = MaiorNota (notas, n);   

    media = calcularMedia(notas, n);

    desvioPadrao = calcularDesvioPadrao(notas, n, media);
    
    acimaDaMedia = AcimaDaMedia(notas, n, media);
    
    reprovados = Reprovados(notas, n);

    printf("MENOR:%d, ", menorNota);
    printf("MAIOR:%d, ", maiorNota);
    printf("MEDIA:%.2f, ", media);
    printf("STD:%.2f, ", desvioPadrao);
    printf("ACIMA_MEDIA_CONC:%d, ", acimaDaMedia);
    printf("REPROV:%d", reprovados);

    return 0;
}
void LeNotas (int notas[], int n) {
	int i;
	for (i = 0; i < n; i++) {
        scanf("%d", &notas[i]);
        }
}
int MaiorNota (int notas[], int n) {
	int maiorNota = -3200;
        int i;

    for (i = 0; i < n; i++) {
        if (notas[i] > maiorNota) {
            maiorNota = notas[i];
        }
    }
    return maiorNota;    
}
int MenorNota (int notas[], int n) {
	int menorNota = 3200;
        int i;

    for (i = 0; i < n; i++) {
        if (notas[i] < menorNota) {
            menorNota = notas[i];
        }
    }    
    return menorNota;
}
float calcularMedia(int notas[], int n) {
        float soma = 0.0;
    	int i;
    	for (i = 0; i < n; i++) {
        	soma += notas[i];
    	}
    return soma / n;
}

float calcularDesvioPadrao(int notas[], int n, float media) {
    	float somaQuadrados = 0.0;
    	int i;
   	 for (i = 0; i < n; i++) {
        	somaQuadrados += pow((notas[i] - media), 2);
    	}
    return sqrt(somaQuadrados / n);
}

int Reprovados(int notas[], int n) {
	int reprovados = 0;
	int i;
	for (i = 0; i < n; i++) {

            if (notas[i] < 70) {
            reprovados++;
            }
        }
     return reprovados;   
}

int AcimaDaMedia(int notas[], int n, int media) {
	int acimaDaMedia = 0;
	int i;
	for (i = 0; i < n; i++) {
        	if (notas[i] > media) {
            	   acimaDaMedia++;
        	}
    	}
      return acimaDaMedia;	
}

