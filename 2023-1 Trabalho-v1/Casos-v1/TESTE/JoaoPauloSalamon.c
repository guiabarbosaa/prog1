#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COLMAPA 100
#define LINMAPA 40
#define FANTASMAS 4
#define FANTASMA_B 0
#define FANTASMA_C 1
#define FANTASMA_I 2
#define FANTASMA_P 3
#define MOVIMENTOS 4
#define MOV_W 0
#define MOV_S 1
#define MOV_A 2
#define MOV_D 3
#define TUNEIS 2
#define TUNEL_1 0
#define TUNEL_2 1

/////////////////STRUCTS///////////////////
typedef struct{
    int hasF; //flagpra se existe o fantasma
    int flagDir; //flag para indicar se o movimento do fantasma deve mudar de direcao
    int fant_X;
    int fant_Y; //posicoes de cada fantasma
    int fSombra_X;
    int fSombra_Y; //posicoes anteriores dos fantasmas
    char color; //saber a "cor"(letra) do fantasma
} tFantasmas; //tipo para tratar dos fantasmas

typedef struct{
    int pontos; //contar quantas frutas foram comidas
    int pac_X;
    int pac_Y; //posicao do pacman
    int pacSombra_X;
    int pacSombra_Y; //posicao anterior do pacman
} tPacMan; //tipo para tratar do jogadores

typedef struct{
    char mapaJogo[LINMAPA][COLMAPA]; //mapa normal
    int localFrutas[LINMAPA][COLMAPA]; //mapa auxiliar para guardar as posicoes das frutas
    int trilha[LINMAPA][COLMAPA]; //trilha a ser exibida no fim do jogo
    int lin;
    int col; //linhas e colunas que serao utilizadas no jogo
} tMapa; //tipo para tratar dos mapas

typedef struct{
    int movimentos; //nm de vezes que uma direcao foi usada
    int movPontuou; //nm de vezes que uma direcao usada resultou em um ponto
    int bateuParede; //nm de vezes que uma direcao usada bateu na parede
    char letra; //char para diferenciar cada direcao. i.e.:w, a, s, d.
} tStats; //tipo para tratar as estatisticas/ranking

typedef struct{
    int tun_X;
    int tun_Y; //posicoes dos tuneis
} tTunel; //tipo para tratar os casos bonus (tunel)

typedef struct{
    tMapa mapa;
    tPacMan pac;
    tFantasmas fantasma[FANTASMAS];
    tStats estatisticas[MOVIMENTOS];
    tTunel tuneis[TUNEIS];
    int limJogadas; //limite de jogadas por partida
    int nJogada; //numero da jogada atual
    int fContinue; //flag para saber se o jogo continua
} tJogo; //tipo para tratar do jogo em geral

////////////////////////////////////DECLARACAO//////////////////////////////////////////
/////////////INICIALIZACAO////////////////
tJogo LeJogo(char **argv); //preparar o jogo
tMapa FazMapa(FILE * pJogo, tMapa mapa); //preparar o mapa e imprimir a inicializacao
tMapa FazTrilha(tMapa mapa, int n, int x, int y); //preparar a trilha inicial (pos. 0)
tPacMan EncontraPacMan(tMapa mapa, tPacMan pac, FILE * pOutput); //achar a pos. inicial do pacman e imprimir
tJogo EncontraFantasmas(tJogo jogo); //achar quantos e quais fantasmas tem
int EhFantasmaB(char x);
int EhFantasmaC(char x);
int EhFantasmaI(char x);
int EhFantasmaP(char x); //func. auxiliares para saber a "cor" do fantasma
void InicializaFantasma(tFantasmas *fantasma, int n, char cor, int a, int b); //funcao para inic. a flag, letra e pos. do fantasma no mapa
tJogo EncontraTuneis(tJogo jogo); //achar os tuneis caso tenha
void FazStats(tStats * stats); //inicialixar as estatisticas. i.e.:nm de movimentos, etc.

///////////////////JOGADAS//////////////////////
tJogo FazMovimento(tJogo jogo, char movimento, FILE * pSaida, FILE * pResumo);//funcao para fazer cada jogada
tMapa MudaCharDoMapa(tMapa mapa, int x, int y, char c);//funcao que muda o char de uma posicao x,y do mapa
////FANTASMAS////
tJogo Movefantasmas(tJogo jogo); //funcao geral para mov os fantasmas
tMapa FazMovFantasma(tFantasmas * fantasmas, tMapa mapa, int i, int a, int b); //funcao que mexe cada fant. especificamente
tFantasmas MovimentaUmFantasma(tFantasmas fantasma, int a, int b, int f, char parede);//funcao para fazer o movimento de cada fantasma especifico
tFantasmas AndaFantasma(tFantasmas fantasma, int a, int b);//funcao que muda o x e y de um fantasma
////PACMAN////
tJogo MovePac(tJogo jogo, char mov, int i, int j, FILE * pResumo); //funcao que movimenta o pacman
tJogo DecideTeclaMov(tJogo jogo, char mov);
tJogo DecideTeclaParede(tJogo jogo, char mov);//funcoes para saber qual tecla foi usada
tStats AumentaMov(tStats acao);//funcao para aumentar o nm de vezes que uma tecla foi usada
tStats BateuParede(tStats acao);//funcao para aumentar o nm de vezes que o jogador bateu na parede com uma tecla especifica
int TemParede(char p);//funcao para checar se o proximo espaco e uma parede
int TemFruta(int n);//funcao para checar se o proximo espaco e uma fruta
tJogo GanhaPonto(tJogo jogo, char m); //funcao para aumentar os pontos do jogador
tMapa ComeFruta(tMapa mapa, int x, int y); //funcao para tirar o ponto do mapa auxiliar
int ExisteFant(tFantasmas fantasma);//funcao para checar a existencia de um fantasma
int TemFantasma(tFantasmas * fantasma, int x, int y);//saber se tem um fantasma no ponto atual
int TemFantNaSombra(int x, int y, tFantasmas * fantasmas);//saber se o fantasma esta na "sombra" de algo
int TemPacNaSombra(int x, int y, tFantasmas * fantasmas);//saber se o pacman etsa na "sombra de um fantasma"
int CoincidePonto(int xa, int ya, int xf, int yf);//funcao para saber se xa coincide com xf e ya com yf
////TUNEL////
int EstaNoTunel(tTunel * tunel, int x, int y);//funcao para saber se o pacman esta em um tunel
tJogo Teletransporta(tJogo jogo); //funcao para checar qual dos tuneis ele esta
tJogo PassaNoTunel(tJogo jogo, int i, int j);//funcao para mandar o pacman de um tunel ao outro
////POS-JOGADA////
tMapa IncrementaTrilha(tMapa mapa, int n, int x, int y); //funcao para adicionar cada mov ao mapa de trilha
void ImprimeSaida(tMapa mapa, char m, int p, FILE * pSaida); //funcao para imprimir a situacao do jogo apos cada rodada
void ImprimeBateuNaParede(int n, char m, FILE * pResumo);//funcao para imprimir no resumo quando o pacman se choca contra a parede
void ImprimeComeu(int n, char m, FILE * pResumo);//funcao para imprimir no resumo quando o pacman ganhar um ponto
void ImprimeMorreu(int n, char m, FILE * pResumo);//funcao para imprimir no resumo quando o pacman morrer ao tocar em um fantasma 
int TerminouJogo(tJogo jogo); //funcao para terminar o jogo por algum motivo 
int Venceu(tMapa mapa);//funcao que ve se ainda ha pontos no mapa

/////////////POS-JOGO/////////////////
void ImprimeTrilha(FILE * pTrilha, tMapa mapa); //funcao que imprime a trilha
void ImprimeEstats(FILE * pStats, tJogo jogo); //funcao que imprime as estatisticas
int FazSomatoriaColisoes(tStats * vet, int lim); //funcao que calcula o nm total de vezes que o pacman bate na parede
void ImprimeRanking(FILE * pRank, tJogo jogo); //funcao que imprime o ranking
void FazRank(tStats * stats, int q); //funcao que monta o ranking
void TrocaPosicao(tStats * stats, int a, int b); //funcao que troca a pos de dois elementos de um vetor
void PrintaColoc(tStats stat, FILE * pRank); //funcao que printa cada colocado especifico em um ranking

///////////////////////////////////MAIN/////////////////////////////////////////////////
int main(int argc, char **argv){
    tJogo jogo;
    char jogada /*movimentacao*/, diretorio[1001]; //diretorio dos arquivos do jogo
    FILE * pSaida=NULL, * pResumo=NULL;

    if(argc<=1){
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
        exit(0);
    }
    jogo=LeJogo(argv); //iniciar o jogo
    sprintf(diretorio, "%s/saida/saida.txt", argv[1]);
    pSaida=fopen(diretorio, "w");
    sprintf(diretorio, "%s/saida/resumo.txt", argv[1]);
    pResumo=fopen(diretorio, "w");
    while(scanf("%c\n", &jogada)==1 && jogo.fContinue){ //loop das jogadas
        jogo=FazMovimento(jogo, jogada, pSaida, pResumo);//aqui seram feitas todas as mudancas no mapa
        if(!jogo.fContinue){ //checa a flag que indica a situacao do jogo (falso==jogo acabou)
            fprintf(pSaida, "Pontuacao final: %d\n", jogo.pac.pontos);//printa a pontuacao final
            break;
        }
    }
    fclose(pSaida);
    fclose(pResumo);
    sprintf(diretorio, "%s/saida/trilha.txt", argv[1]);
    pSaida=fopen(diretorio, "w");
    ImprimeTrilha(pSaida, jogo.mapa); //imprimir a trilha
    sprintf(diretorio, "%s/saida/estatisticas.txt", argv[1]);
    pSaida=fopen(diretorio, "w");
    ImprimeEstats(pSaida, jogo); //imprimir as estatisticas
    sprintf(diretorio, "%s/saida/ranking.txt", argv[1]);
    pSaida=fopen(diretorio, "w");
    ImprimeRanking(pSaida, jogo); //imprimir o ranking
    return 0;
}


/////////////////FUNCOES///////////////////
tJogo LeJogo(char **argv){
    int i, j;
    tJogo jogo;
    char dir[1001];
    FILE * pJogo=NULL, *pOutput=NULL;

    sprintf(dir, "%s/mapa.txt", argv[1]); //puxar o arqv de texto do mapa
    pJogo=fopen(dir, "r");
    fscanf(pJogo, "%d %d %d", &jogo.mapa.lin, &jogo.mapa.col, &jogo.limJogadas); //ler tudo antes do mapa
    jogo.nJogada=0;
    jogo.mapa=FazMapa(pJogo, jogo.mapa); //ler o mapa
    sprintf(dir, "%s/saida/inicializacao.txt", argv[1]);//abrir o arqv onde sera impressa a inicializacao
    pOutput=fopen(dir, "w");
    for(i=0; i<jogo.mapa.lin; i++){
        for(j=0; j<jogo.mapa.col; j++){
            fprintf(pOutput, "%c", jogo.mapa.mapaJogo[i][j]); //imprimir o mapa no inicializacao.txt
        }
        fprintf(pOutput, "\n");
    }
    jogo.pac=EncontraPacMan(jogo.mapa, jogo.pac, pOutput); //encontrar o pacman e imprimir sua pos. inicial
    jogo.mapa=FazTrilha(jogo.mapa, jogo.nJogada, jogo.pac.pac_X, jogo.pac.pac_Y);//fazer a trilha inicial
    jogo=EncontraFantasmas(jogo); //encontrar as posicoes iniciais dos fantasmas
    jogo=EncontraTuneis(jogo);//encontrar as pos iniciais dos tuneis
    FazStats(jogo.estatisticas);//inicializar as estatisticas
    fclose(pOutput);
    jogo.fContinue=1;//tornar verdadeira a flag de continuidade do jogo
    return jogo;
}

tMapa FazMapa(FILE * pJogo, tMapa mapa){
    int i=0, j=0;
    while(!feof(pJogo)){
    fscanf(pJogo, "%*[^\n]");
    fscanf(pJogo, "%*[\n]");
    fscanf(pJogo, "%[ #*>@A-Z]", mapa.mapaJogo[i]); //ler apenas os simbolos usados
    i++;
    }
    fclose(pJogo);
    for(i=0; i<mapa.lin; i++){ //montar mapa auxiliar, indicando verdadeiro quando ha fruta
        for(j=0; j<mapa.col; j++){
            if(mapa.mapaJogo[i][j]=='*'){ //tem fruta
                mapa.localFrutas[i][j]=1;
            }
            else{
                mapa.localFrutas[i][j]=0; //nao tem fruta
            }
        }
    }
    return mapa;
}

tPacMan EncontraPacMan(tMapa mapa, tPacMan pac, FILE * pOutput){
    int i, j;
    for(i=0; i<mapa.lin; i++){
        for(j=0; j<mapa.col; j++){
            if(mapa.mapaJogo[i][j]=='>'){ //simbolo do pacman
                fprintf(pOutput
                , "Pac-Man comecara o jogo na linha %d e coluna %d\n",
                i+1, j+1); //imprimir no inicializacao.txt a pos. inicial do pacman
                pac.pac_X=j;
                pac.pac_Y=i;
                pac.pontos=0; //achar a loc. inicial de pacman e zerar seus pontos
                return pac;
            }
        }
    }
}

tJogo EncontraFantasmas(tJogo jogo){
    int i, j;
    for(i=0; i<FANTASMAS; i++){
        jogo.fantasma[i].hasF=0;
    }
    for(i=0; i<jogo.mapa.lin; i++){
        for(j=0; j<jogo.mapa.col; j++){
            if(EhFantasmaB(jogo.mapa.mapaJogo[i][j])){ //checar qual dos fantasmas eh
                InicializaFantasma(jogo.fantasma, FANTASMA_B, jogo.mapa.mapaJogo[i][j], i, j);
            }//inicializar o char, as flags, as posicoes...
            if(EhFantasmaC(jogo.mapa.mapaJogo[i][j])){ 
                InicializaFantasma(jogo.fantasma, FANTASMA_C, jogo.mapa.mapaJogo[i][j], i, j);
            }
            if(EhFantasmaI(jogo.mapa.mapaJogo[i][j])){ 
                InicializaFantasma(jogo.fantasma, FANTASMA_I, jogo.mapa.mapaJogo[i][j], i, j);
            }
            if(EhFantasmaP(jogo.mapa.mapaJogo[i][j])){ 
                InicializaFantasma(jogo.fantasma, FANTASMA_P, jogo.mapa.mapaJogo[i][j], i, j);
            }
        }
    }
    return jogo;
}

int EhFantasmaB(char x){
    return x=='B';
}

int EhFantasmaC(char x){
    return x=='C';
}

int EhFantasmaI(char x){
    return x=='I';
}

int EhFantasmaP(char x){
    return x=='P';
}

void InicializaFantasma(tFantasmas *fantasma, int n, char cor, int a, int b){
    fantasma[n].hasF=1;
    fantasma[n].color=cor; //atribuir a cada fantasma a letra dele
    fantasma[n].fant_X=b;
    fantasma[n].fant_Y=a; //posicoes iniciais dos fantasmas
    fantasma[n].flagDir=0; //setar a flag de direcao como falsa, para que ele inicie fazendo o movimento normal
}

tJogo EncontraTuneis(tJogo jogo){
    int i, j, k=0;
    for(i=0; i<jogo.mapa.lin; i++){
        for(j=0; j<jogo.mapa.col; j++){
            if(jogo.mapa.mapaJogo[i][j]=='@'){ //char do tunel
                jogo.tuneis[k].tun_X=j;
                jogo.tuneis[k].tun_Y=i;//posicoes iniciais
                k++;
            }
        }
    }
    return jogo;
}

tMapa FazTrilha(tMapa mapa, int n, int x, int y){
    int i, j;
    for(i=0; i<mapa.lin; i++){
        for(j=0; j<mapa.col; j++){
            mapa.trilha[i][j]=-1; //colocar todos os espacos do mapa como -1
        }
    }
    mapa.trilha[y][x]=n; //colocar a posicao inicial do pacman como "0" na trilha
    return mapa;
}

void FazStats(tStats * stats){
    int i;
    for(i=0; i<MOVIMENTOS; i++){
        stats[i].bateuParede=0;
        stats[i].movimentos=0;
        stats[i].movPontuou=0; //zerar os contadores 
    }
    stats[MOV_A].letra='a';
    stats[MOV_S].letra='s';
    stats[MOV_D].letra='d';
    stats[MOV_W].letra='w'; //atribuir cada movimento a sua letra
}

tJogo FazMovimento(tJogo jogo, char movimento, FILE * pSaida, FILE * pResumo){
    jogo=Movefantasmas(jogo); //movimentar os fantasmas primeiro
    jogo.pac.pacSombra_X=jogo.pac.pac_X;
    jogo.pac.pacSombra_Y=jogo.pac.pac_Y;//salvar a posicao anterior do pacman
    switch(movimento){
        case 'w':
        jogo=MovePac(jogo, movimento, -1, 0, pResumo);
        break;
        case 's':
        jogo=MovePac(jogo, movimento, +1, 0, pResumo);
        break;
        case 'a':
        jogo=MovePac(jogo, movimento, 0, -1, pResumo);
        break;
        case 'd':
        jogo=MovePac(jogo, movimento, 0, +1, pResumo);//movimentar o pacman, diferenciando a direcao usada
        break;
    }
    ImprimeSaida(jogo.mapa, movimento, jogo.pac.pontos, pSaida);//impeimir a saida apos a jogada
    jogo.nJogada++;//avancar uma jogada
    if(TemFantasma(jogo.fantasma, jogo.pac.pac_X, jogo.pac.pac_Y) || (TemPacNaSombra(jogo.pac.pac_X, jogo.pac.pac_Y, jogo.fantasma) && 
    TemFantNaSombra(jogo.pac.pacSombra_X, jogo.pac.pacSombra_Y, jogo.fantasma))){//checar se o pacman morreu enquanto se movimentou
        jogo.fContinue=TerminouJogo(jogo);
        fprintf(pSaida, "Game over!\n");
    }
    else{
        jogo.mapa=IncrementaTrilha(jogo.mapa, jogo.nJogada, jogo.pac.pac_X, jogo.pac.pac_Y);//incrementar a trilha caso ele tenha se movido
    }
    if(jogo.nJogada>=jogo.limJogadas){//checar se o jogo ja atingiu o limite de jogadas
        jogo.fContinue=TerminouJogo(jogo);
        fprintf(pSaida, "Game over!\n");
    }
    if(Venceu(jogo.mapa)){//checar se ainda ha pontos no mapa
        jogo.fContinue=TerminouJogo(jogo);
        fprintf(pSaida, "Voce venceu!\n"); 
    }
    return jogo;
}

tMapa MudaCharDoMapa(tMapa mapa, int x, int y, char c){
    mapa.mapaJogo[y][x]=c;
    return mapa;
}

tJogo MovePac(tJogo jogo, char mov, int i, int j, FILE * pResumo){
    if(!TemParede(jogo.mapa.mapaJogo[jogo.pac.pac_Y+i][jogo.pac.pac_X+j])){ //acoes quando nao ha uma parede na direcao que o jogador se moveu
        if(!TemFantasma(jogo.fantasma, jogo.pac.pac_X, jogo.pac.pac_Y)){
            jogo.mapa.mapaJogo[jogo.pac.pac_Y][jogo.pac.pac_X]=' '; //imprimir um espaco em branco se nao ha ja um fantasma ali
        }
        if(EstaNoTunel(jogo.tuneis, jogo.pac.pac_X, jogo.pac.pac_Y)>-1){
            jogo.mapa.mapaJogo[jogo.pac.pac_Y][jogo.pac.pac_X]='@'; //retornar o portal a posicao, caso ele tenha sido sobrescrito
        }
        jogo.pac.pac_X=jogo.pac.pac_X+j;
        jogo.pac.pac_Y=jogo.pac.pac_Y+i;//movimentacao baseada na tecla (wasd) usada
        jogo=DecideTeclaMov(jogo, mov);//aumentar o nm de vezes que a tecla foi usada
        if((EstaNoTunel(jogo.tuneis, jogo.pac.pac_X, jogo.pac.pac_Y))>-1){ //verificar se o pac esta em algum dos tuneis
            jogo.mapa=IncrementaTrilha(jogo.mapa, jogo.nJogada+1, jogo.pac.pac_X, jogo.pac.pac_Y);//funcao "prematura" para incrementar a trilha ao passar no portal
            jogo=Teletransporta(jogo);//mandar para o outro portal
            return jogo;
        }
        if(TemFantasma(jogo.fantasma, jogo.pac.pac_X, jogo.pac.pac_Y) || (TemPacNaSombra(jogo.pac.pac_X, jogo.pac.pac_Y, jogo.fantasma)
        && TemFantNaSombra(jogo.pac.pacSombra_X, jogo.pac.pacSombra_Y, jogo.fantasma))){//verificar se o pacman se chocou com um fantasma
            ImprimeMorreu(jogo.nJogada+1, mov, pResumo);//imprimir que morreu
            jogo.fContinue=TerminouJogo(jogo);
            return jogo;
        }
        jogo.mapa.mapaJogo[jogo.pac.pac_Y][jogo.pac.pac_X]='>';
        if(TemFruta(jogo.mapa.localFrutas[jogo.pac.pac_Y][jogo.pac.pac_X])){//verificar se tem ponto na pos atual
            ImprimeComeu(jogo.nJogada+1, mov, pResumo);//imprimir no resumo o ganho de ponto
            jogo=GanhaPonto(jogo, mov);//comer o ponto
        }
    }
    else{
        jogo=DecideTeclaMov(jogo, mov);//aumentar o nm de vezes que a tecla foi usada
        if((EstaNoTunel(jogo.tuneis, jogo.pac.pac_X, jogo.pac.pac_Y))>-1){//se o pac ja estava em um portal e ele avanca para uma parede, tem que se telportar sem registrar o choque
            jogo.mapa=IncrementaTrilha(jogo.mapa, jogo.nJogada+1, jogo.pac.pac_X, jogo.pac.pac_Y);//funcao "prematura" para incrementar a trilha ao passar no portal
            jogo=Teletransporta(jogo);//mandar para o outro portal
            return jogo;
        }
        jogo=DecideTeclaParede(jogo, mov);//aumentar o nm de vezes que a tecla bateu na parede
        if(TemFantasma(jogo.fantasma, jogo.pac.pac_X, jogo.pac.pac_Y)){
            ImprimeMorreu(jogo.nJogada+1, mov, pResumo);
            jogo.fContinue=TerminouJogo(jogo);
        }
        ImprimeBateuNaParede(jogo.nJogada+1, mov, pResumo);//imprimir no resumo que bateu na parede
    }
    return jogo;
}

tJogo DecideTeclaMov(tJogo jogo, char mov){
    switch(mov){//checar qual tecla foi usada
        case 'w':
        jogo.estatisticas[MOV_W]=AumentaMov(jogo.estatisticas[MOV_W]);
        break;
        case 's':
        jogo.estatisticas[MOV_S]=AumentaMov(jogo.estatisticas[MOV_S]);
        break;
        case 'd':
        jogo.estatisticas[MOV_D]=AumentaMov(jogo.estatisticas[MOV_D]);
        break;
        case 'a':
        jogo.estatisticas[MOV_A]=AumentaMov(jogo.estatisticas[MOV_A]);
        break;
    }
    return jogo;
}

tJogo DecideTeclaParede(tJogo jogo, char mov){
    switch(mov){//checar qual tecla foi usada
        case 'w':
        jogo.estatisticas[MOV_W]=BateuParede(jogo.estatisticas[MOV_W]);
        break;
        case 's':
        jogo.estatisticas[MOV_S]=BateuParede(jogo.estatisticas[MOV_S]);
        break;
        case 'd':
        jogo.estatisticas[MOV_D]=BateuParede(jogo.estatisticas[MOV_D]);
        break;
        case 'a':
        jogo.estatisticas[MOV_A]=BateuParede(jogo.estatisticas[MOV_A]);
        break;
    }
    return jogo;
}

int EstaNoTunel(tTunel * tunel, int x, int y){
    int i=0;
    for(i=0; i<TUNEIS; i++){//checar se a pos do pacman bate com a pos do portal
        if(tunel[i].tun_X==x && tunel[i].tun_Y==y){
            return i; //retornar qual portal especifico ele esta(0 e 1 aqui)
        }
    }
    return -1;//retornar que nao esta no mapa
}

tJogo Teletransporta(tJogo jogo){
    int i;
    i=EstaNoTunel(jogo.tuneis, jogo.pac.pac_X, jogo.pac.pac_Y);//receber qual portal esta
    if(i==TUNEL_1){
        jogo=PassaNoTunel(jogo, TUNEL_1, TUNEL_2);
    }
    else{
        jogo=PassaNoTunel(jogo, TUNEL_2, TUNEL_1);//saber qual tunel esta e mandar para o outro
    }
    return jogo;
}

tJogo PassaNoTunel(tJogo jogo, int i, int j){
    jogo.mapa.mapaJogo[jogo.tuneis[i].tun_Y][jogo.tuneis[i].tun_X]='@';//retornar o portal ao mapa
    jogo.mapa.mapaJogo[jogo.tuneis[j].tun_Y][jogo.tuneis[j].tun_X]='>';//colocar o pacman onde esta o outro portal
    jogo.pac.pac_X=jogo.tuneis[j].tun_X;
    jogo.pac.pac_Y=jogo.tuneis[j].tun_Y;//atualizar a pos do pacman
    return jogo;
}

void ImprimeBateuNaParede(int n, char m, FILE * pResumo){
    fprintf(pResumo, "Movimento %d (%c) colidiu na parede\n", n, m);//imprimir no resumo
}

void ImprimeComeu(int n, char m, FILE * pResumo){
    fprintf(pResumo, "Movimento %d (%c) pegou comida\n", n, m);//imprimir no resumo
}

void ImprimeMorreu(int n, char m, FILE * pResumo){
    fprintf(pResumo, "Movimento %d (%c) fim de jogo por encostar em um fantasma\n", n, m);//imprimir no resumo
}

tJogo GanhaPonto(tJogo jogo, char m){
    jogo.mapa=ComeFruta(jogo.mapa, jogo.pac.pac_X, jogo.pac.pac_Y);
    jogo.pac.pontos++;//ganhar ponto
    switch(m){
        case 'w'://aumentar o nm de vezes que uma tecla pontuou
        jogo.estatisticas[MOV_W].movPontuou++;
        break;
        case 's':
        jogo.estatisticas[MOV_S].movPontuou++;
        break;
        case 'd':
        jogo.estatisticas[MOV_D].movPontuou++;
        break;
        case 'a':
        jogo.estatisticas[MOV_A].movPontuou++;
        break;
    }
    return jogo;
}

tMapa IncrementaTrilha(tMapa mapa, int n, int x, int y){
    mapa.trilha[y][x]=n;//colocar a jogada na trilha
    return mapa;
}

tStats BateuParede(tStats acao){
    acao.bateuParede++;//aumentar o nm de vezes que bateu na parede
    return acao;
}

tStats AumentaMov(tStats acao){
    acao.movimentos++;//aumentar o nm de vezes que se moveu
    return acao;
}

int ExisteFant(tFantasmas fantasma){
    return fantasma.hasF;
}

int TemFantasma(tFantasmas * fantasma, int x, int y){
    int i;
    for(i=0; i<FANTASMAS; i++){
        if(CoincidePonto(x, y, fantasma[i].fant_X, fantasma[i].fant_Y)){
            return 1;//retornar 1 se tiver um fantasma ali
        }
    }
    return 0;//retornar 0 se nao tiver nenhum fantasma ali
}

int TemParede(char p){
    return p=='#';//ver se e o char de parede
}

tJogo Movefantasmas(tJogo jogo){
    if(ExisteFant(jogo.fantasma[FANTASMA_B])){
        jogo.mapa=FazMovFantasma(jogo.fantasma, jogo.mapa, 0, 0, 1);
    }
    if(ExisteFant(jogo.fantasma[FANTASMA_C])){
        jogo.mapa=FazMovFantasma(jogo.fantasma, jogo.mapa, 1, 0, -1);
    }
    if(ExisteFant(jogo.fantasma[FANTASMA_I])){
        jogo.mapa=FazMovFantasma(jogo.fantasma, jogo.mapa, 2, -1, 0);
    }
    if(ExisteFant(jogo.fantasma[FANTASMA_P])){
        jogo.mapa=FazMovFantasma(jogo.fantasma, jogo.mapa, 3, 1, 0);//mover apenas os que existem
    }
    return jogo;
}

tMapa FazMovFantasma(tFantasmas * fantasmas, tMapa mapa, int i, int a, int b){
    fantasmas[i].fSombra_X=fantasmas[i].fant_X;
    fantasmas[i].fSombra_Y=fantasmas[i].fant_Y;//salvar a pos anterior do fantasma
    if(fantasmas[i].flagDir){//entrar aqui caso o fantasma esteja fazendo o movimento inverso
        fantasmas[i]=MovimentaUmFantasma(fantasmas[i], a, b, 0, mapa.mapaJogo[fantasmas[i].fant_Y+a][fantasmas[i].fant_X+b]);
    }
    else{//entrar aqui caso o fantasma esteja fazendo a movimentacao normal
        fantasmas[i]=MovimentaUmFantasma(fantasmas[i], a, b, 1, mapa.mapaJogo[fantasmas[i].fant_Y-a][fantasmas[i].fant_X-b]);
    }
    mapa=MudaCharDoMapa(mapa, fantasmas[i].fant_X, fantasmas[i].fant_Y, fantasmas[i].color);//colocar o char do fantasma na sua pos nova
    if(mapa.localFrutas[fantasmas[i].fSombra_Y][fantasmas[i].fSombra_X]){
        mapa=MudaCharDoMapa(mapa, fantasmas[i].fSombra_X, fantasmas[i].fSombra_Y, '*');//colocar o ponto se o fant tava obstruindo ela
    }
    else if(!TemFantasma(fantasmas, fantasmas[i].fSombra_X, fantasmas[i].fSombra_Y)){
        mapa=MudaCharDoMapa(mapa, fantasmas[i].fSombra_X, fantasmas[i].fSombra_Y, ' ');//colocar space se nao tem nada atras do fant
    }
    return mapa;
}

tFantasmas MovimentaUmFantasma(tFantasmas fantasma, int a, int b, int f, char parede){
    if(TemParede(parede)){
        fantasma.flagDir=1;//inverter a direcao de mov do fantasma
        fantasma=AndaFantasma(fantasma, a, b);//atualizar a pos do fantasma ja fazendo o mov inverso
    }
    else{
        fantasma=AndaFantasma(fantasma, -a, -b);//atualizar a mov do fantasma
    }
    return fantasma;
}

tFantasmas AndaFantasma(tFantasmas fantasma, int a, int b){
    fantasma.fant_X=fantasma.fant_X+b;//mudar o x do fantasmas
    fantasma.fant_Y=fantasma.fant_Y+a;//mudar o y do fantasma
    return fantasma;
}

int TemFantNaSombra(int x, int y, tFantasmas * fantasmas){
    int i;
    for(i=0; i<FANTASMAS; i++){
        if(CoincidePonto(x, y, fantasmas[i].fant_X, fantasmas[i].fant_Y)){
            return 1;//retornar verdadeiro se x e y (sombra de algo) sao os mesmos x e y do fantasma
        }
    }
    return 0;//retornar falso caso contrario
}

int TemPacNaSombra(int x, int y, tFantasmas * fantasmas){
    int i;
    for(i=0; i<FANTASMAS; i++){
        if(CoincidePonto(x, y, fantasmas[i].fSombra_X, fantasmas[i].fSombra_Y)){
            return 1;//retornar verdadeiro se x e y (sombra dos fantasmas) sao os mesmos x e y do pacman
        }
    }
    return 0;//retornar falso caso contrario
}

int CoincidePonto(int xa, int ya, int xf, int yf){
    return xa==xf && ya==yf;//ve se um x e y especificos coincidem com outro x e y
}

int TemFruta(int n){
    return n==1;//pos do mapa e 1, ou seja, tem pontos la
}

tMapa ComeFruta(tMapa mapa, int x, int y){
    mapa.localFrutas[y][x]=0;//colocar a pos no mapa auxiliar como 0, indicando que nao tem mais nada la
    return mapa;
}

void ImprimeSaida(tMapa mapa, char m, int p, FILE * pSaida){
    int i, j;
    fprintf(pSaida, "Estado do jogo apos o movimento '%c':\n", m);//indicar qual mov (wasd) foi feito
    for(i=0; i<mapa.lin; i++){
        for(j=0; j<mapa.col; j++){
            fprintf(pSaida, "%c", mapa.mapaJogo[i][j]);
        }
        fprintf(pSaida, "\n");//imprimir a situacao atual do mapa
    }
    fprintf(pSaida, "Pontuacao: %d\n\n", p);//imprimir a pontuacao atual
}

void ImprimeTrilha(FILE * pTrilha, tMapa mapa){
    int i, j;
    for(i=0; i<mapa.lin; i++){
        for(j=0; j<mapa.col; j++){
            if(mapa.trilha[i][j]>-1){//caso a pos seja diferente de -1, o pacman passou por la
                fprintf(pTrilha, "%d", mapa.trilha[i][j]);//assim, ela e impressa com o nm da ultima jogada que o pac passou por la
            }
            else{//caso seja -1, o pacman nao passou por la, e "#" eh impresso, como especificado no pdf
                fprintf(pTrilha, "#");
            }
            if((j<mapa.col-1)){
                fprintf(pTrilha, " ");//nao imprimir espaco no final de cada linha para o terminal nao reclamar 
            }
        }
        fprintf(pTrilha, "\n");//separar cada linha
    }
    fclose(pTrilha);//fechar o arquivo na propria funcao
}

int TerminouJogo(tJogo jogo){
    return jogo.fContinue=0;//setar a flag de continuidade do jogo para falso
}

int Venceu(tMapa mapa){
    int i, j;
    for(i=0; i<mapa.lin; i++){
        for(j=0; j<mapa.col; j++){
            if(mapa.localFrutas[i][j]) return 0; //se o mapa auxiliar com as pos dos pontos ainda tiver lugares com "1", 
                                                 //o pacman nao venceu pois nao pegou todos os pontos ainda
        }
    }
    return 1;
}

void ImprimeEstats(FILE * pStats, tJogo jogo){
    int semPontuar, colisoes;
    semPontuar=jogo.nJogada-jogo.pac.pontos;//mov sem pontuar é onm de movimentos menos o nm de pontos
    colisoes=FazSomatoriaColisoes(jogo.estatisticas, MOVIMENTOS);//nm de colisoes e a soma de quantas vezes cada tecla resultou num choque
    fprintf(pStats, "Numero de movimentos: %d\n", jogo.nJogada);
    fprintf(pStats, "Numero de movimentos sem pontuar: %d\n", semPontuar);
    fprintf(pStats, "Numero de colisoes com parede: %d\n", colisoes);
    fprintf(pStats, "Numero de movimentos para baixo: %d\n", jogo.estatisticas[MOV_S].movimentos);
    fprintf(pStats, "Numero de movimentos para cima: %d\n", jogo.estatisticas[MOV_W].movimentos);
    fprintf(pStats, "Numero de movimentos para esquerda: %d\n", jogo.estatisticas[MOV_A].movimentos);
    fprintf(pStats, "Numero de movimentos para direita: %d\n", jogo.estatisticas[MOV_D].movimentos);//imprimir cada estatistica
    fclose(pStats);//fechando o arquivo na funcao logo
}

int FazSomatoriaColisoes(tStats * vet, int lim){
    int soma=0, i;
    for(i=0; i<lim; i++){
        soma+=vet[i].bateuParede;
    }
    return soma;
}

void ImprimeRanking(FILE * pRank, tJogo jogo){
    int i;
    FazRank(jogo.estatisticas, MOVIMENTOS);//montar o rank
    for(i=MOVIMENTOS-1; i>=0; i--){//imprimir em ordem inversa(o vetor ficou em ordem crescente)
        PrintaColoc(jogo.estatisticas[i], pRank);
    }
    fclose(pRank);
}

void FazRank(tStats * stats, int q){
    int i, j;
    for(i=0; i<q; i++){
        for(j=0; j<q; j++){
            if(stats[i].movPontuou<stats[j].movPontuou){//caso o proximo item tenha mais pontos,
                TrocaPosicao(stats, i, j);              //ele vai para frente
            }
            else if(stats[i].movPontuou==stats[j].movPontuou){//caso sejam iguais
                if(stats[i].bateuParede>stats[j].bateuParede){//compara quem menos bateu na parede
                    TrocaPosicao(stats, i, j);//e troca
                }
                else if(stats[i].bateuParede==stats[j].bateuParede){//caso forem iguais
                    if(stats[i].movimentos<stats[j].movimentos){//compara quem se moveu mais
                        TrocaPosicao(stats, i, j);//e troca
                    }
                    else if(stats[i].movimentos==stats[j].movimentos){//caso forem iguais
                        if(stats[i].letra>stats[j].letra){//compara a ordem alfabetica
                            TrocaPosicao(stats, i, j);//e troca
                        }
                    }
                }
            }
        }
    }
}

void TrocaPosicao(tStats * stats, int a, int b){
    tStats aux;//mudar a pos de dois itens de um vetor
    aux=stats[a];
    stats[a]=stats[b];
    stats[b]=aux;
}

void PrintaColoc(tStats stat, FILE * pRank){
    fprintf(pRank, "%c,%d,%d,%d\n", stat.letra, stat.movPontuou, stat.bateuParede, stat.movimentos);//printa a colocacao e as infos de cada tecla
}