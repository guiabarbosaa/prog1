// bibliotecas inclusas

#include<stdio.h>
#include<stdlib.h>

// dados tipados usados

typedef struct{
    //dados temporarios, usados em "RealizaJogo()" para gerar o resumo
    int comida;
    int parede;
}tTemporarios;

typedef struct{
   
    // define os dados de cada letra
    int numComidas;
    int colPar;
    int numUsos;
    int letra;
}tLetra;

typedef struct{

    // define a respeito dos dados que serão usados no ranking e nas estatísticas
    tTemporarios temporarios;
    tLetra letras[4];
}tDados;

typedef struct{

    // define tudo que diz respeito à área jogável
    char area[40][100];
    int trilha[40][100];
    int linhas;
    int colunas;

}tMapa;

typedef struct{

    // define posicoes x (para as colunas) e y (para as linhas)
    int x;
    int y;

}tPosicao;

typedef struct{

    // correlaciona tudo que diz respeito ao player
    char backup;
    tPosicao posicao;
    tPosicao posicaoSombra;

}tPlayer;

typedef struct{

    // correlaciona tudo que diz respeito aos fantasmas do jogo
    tPosicao posicao;
    tPosicao posicaoSombra;
    char backup;
    char ID;
    char tipo;
    int orientacao;

}tFantasma;

typedef struct{

    // correlaciona tudo que envolve o jogo para facilitar passagem em funcoes
    tPosicao tunel1;
    tPosicao tunel2;
    tDados dados;
    tMapa mapa;
    tPlayer PacMan;
    tFantasma fantasmas[4];
    int derrota;
    int numFantasmas;
    int maxMovimentos;
    int numFrutas;
    int pontuacao;

}tJogo;

// funcoes usadas no programa
tJogo LeMapa(int argc, char const *argv[], tJogo jogo);
tJogo EncontraEntidades(tJogo jogo);
void InicializaJogo(char const *argv[], tMapa mapa, tPosicao posicao);
tJogo InicializaVariaveis(tJogo jogo);
tJogo RealizaJogo(char const *argv[], tJogo jogo);
tJogo MovimentaPlayer(char movimento, tJogo jogo);
tJogo MovimentaPlayerInterno(int modX, int modY, tJogo jogo);
tJogo MovimentaFantasmas(tJogo jogo);
tJogo TestaColisoes(tJogo jogo);
void ImprimeSituacao(tMapa mapa, int pontuacao);
void FimDeJogo(int derrota, int pontuacao);
void ImprimeTrilha(char const *argv[], tMapa mapa);
void ResumeJogo(char const *argv[], int numComidas, char letra, char tipo);
void EstatificaJogo(char const *argv[], tDados dados);
void RankingJogo(char const *argv[], tDados dados);
void OrdenaLetras(tLetra letras[4]);
tPlayer TrataTunel(tPlayer PacMan, tPosicao tunel1, tPosicao tunel2);


///////////////////////////////CABECALHO//////////////////////////////////

// main
int main(int argc, char const *argv[])
{
    tJogo jogo;
    // faz a leitura dos dados e inicializa o jogo
    jogo = LeMapa(argc, argv, jogo);
    jogo = InicializaVariaveis(jogo);
    jogo = EncontraEntidades(jogo);
    InicializaJogo(argv, jogo.mapa, jogo.PacMan.posicao);

    // faz o jogo acontecer
    jogo = RealizaJogo(argv, jogo);
    FimDeJogo(jogo.derrota, jogo.pontuacao);

    // gera os dados a respeito da partida
    ImprimeTrilha(argv, jogo.mapa);
    EstatificaJogo(argv, jogo.dados);
    RankingJogo(argv, jogo.dados);

    return 0;
}

// funcao que le o mapa do jogo, utiliza-se de funcoes de leitura de arquivo
tJogo LeMapa(int argc, char const *argv[], tJogo jogo){
    FILE * pFile;
    char nome[1000];
    int linhaAtual = 0, colunaAtual = 0;

    // testa se foi recebido algum diretorio
    if (argc <= 1){
        printf("ERRO:  O  diretorio  de  arquivos  de configuracao nao foi informado\n");
       
        exit(0);
    }

    // tenta acessar o diretorio e averigua sua validade
    sprintf(nome, "%s/mapa.txt", argv[1]);
    pFile = fopen (nome,"r");
    if (!pFile){
        printf("Arquivo %s nao foi encontrado!\n", nome);
       
        exit(0);
    }

    // lê todo o conteúdo do arquivo mapa
    fscanf(pFile, "%d %d %d", &jogo.mapa.linhas, &jogo.mapa.colunas, &jogo.maxMovimentos);

    fscanf(pFile, "\n ");

    for (linhaAtual = 0; linhaAtual < jogo.mapa.linhas; linhaAtual++)
    {
        for (colunaAtual = 0; colunaAtual < jogo.mapa.colunas; colunaAtual++)
        {
            fscanf(pFile, "%c", &jogo.mapa.area[linhaAtual][colunaAtual]);
        }
        fscanf(pFile, "\n");
    }

    fclose(pFile);
   
    return jogo;
}

// procura por entidades para adicionar no jogo
tJogo EncontraEntidades(tJogo jogo){
    int linhaAtual = 0, colunaAtual = 0, contadorFantasmas = 0;
    int leuTunel = 0;
    for (linhaAtual = 0; linhaAtual < jogo.mapa.linhas; linhaAtual++)
    {
        for (colunaAtual = 0; colunaAtual < jogo.mapa.colunas; colunaAtual++)
        {            
            switch (jogo.mapa.area[linhaAtual][colunaAtual])
            {

                // contabiliza o número de frutas
                case '*':
                    jogo.numFrutas++;
                    break;

                // indentifica e gera o player e os fantasmas
                case '>':
                    jogo.PacMan.posicao.x = colunaAtual;
                    jogo.PacMan.posicao.y = linhaAtual;
                    break;

                case 'B':
                    jogo.fantasmas[contadorFantasmas].posicao.x = colunaAtual;
                    jogo.fantasmas[contadorFantasmas].posicao.y = linhaAtual;
                    jogo.fantasmas[contadorFantasmas].ID = 'B';
                    jogo.fantasmas[contadorFantasmas].tipo = 'H';
                    jogo.fantasmas[contadorFantasmas].orientacao = -1;
                    jogo.fantasmas[contadorFantasmas].backup = ' ';
                    contadorFantasmas++;
                    break;
                case 'P':
                    jogo.fantasmas[contadorFantasmas].posicao.x = colunaAtual;
                    jogo.fantasmas[contadorFantasmas].posicao.y = linhaAtual;
                    jogo.fantasmas[contadorFantasmas].ID = 'P';
                    jogo.fantasmas[contadorFantasmas].tipo = 'V';
                    jogo.fantasmas[contadorFantasmas].orientacao = -1;
                    jogo.fantasmas[contadorFantasmas].backup = ' ';
                    contadorFantasmas++;
                    break;
                case 'I':
                    jogo.fantasmas[contadorFantasmas].posicao.x = colunaAtual;
                    jogo.fantasmas[contadorFantasmas].posicao.y = linhaAtual;
                    jogo.fantasmas[contadorFantasmas].ID = 'I';
                    jogo.fantasmas[contadorFantasmas].tipo = 'V';
                    jogo.fantasmas[contadorFantasmas].orientacao = 1;
                    jogo.fantasmas[contadorFantasmas].backup = ' ';
                    contadorFantasmas++;
                    break;
                case 'C':
                    jogo.fantasmas[contadorFantasmas].posicao.x = colunaAtual;
                    jogo.fantasmas[contadorFantasmas].posicao.y = linhaAtual;
                    jogo.fantasmas[contadorFantasmas].ID = 'C';
                    jogo.fantasmas[contadorFantasmas].tipo = 'H';
                    jogo.fantasmas[contadorFantasmas].orientacao = 1;
                    jogo.fantasmas[contadorFantasmas].backup = ' ';
                    contadorFantasmas++;
                    break;

                case '@':
                    if(!leuTunel){
                        jogo.tunel1.x = colunaAtual;
                        jogo.tunel1.y = linhaAtual;
                        leuTunel = 1;
                    }else{
                        jogo.tunel2.x = colunaAtual;
                        jogo.tunel2.y = linhaAtual;
                    }
                    break;
                   
                default:
                    break;
            }
        }
    }
    jogo.numFantasmas = contadorFantasmas;
    return jogo;
}

// gera o arquivo inicializacao.txt, que contem o mapa e a posicao incicial do player
void InicializaJogo(char const *argv[], tMapa mapa, tPosicao posicao){

    FILE * pFile;
    char nome[1000];
    int linhaAtual = 0, colunaAtual = 0;

    sprintf(nome, "%s/saida/inicializacao.txt", argv[1]);
    pFile = fopen(nome, "w");

    for (linhaAtual = 0; linhaAtual < mapa.linhas; linhaAtual++)
    {
        for (colunaAtual = 0; colunaAtual < mapa.colunas; colunaAtual++)
        {
            fprintf(pFile, "%c", mapa.area[linhaAtual][colunaAtual]);
        }
        fprintf(pFile, "\n");
    }
    fprintf(pFile, "Pac-Man comecara o jogo na linha %d e coluna %d", posicao.y+1, posicao.x+1);
   
     
   
    fclose(pFile);

    return;
}

tJogo InicializaVariaveis(tJogo jogo){
    int linhaAtual = 0, colunaAtual = 0;

    // gera a trilha
    for (linhaAtual = 0; linhaAtual < jogo.mapa.linhas; linhaAtual++)
    {
        for (colunaAtual = 0; colunaAtual < jogo.mapa.colunas; colunaAtual++)
        {
            jogo.mapa.trilha[linhaAtual][colunaAtual] = -1;
        }
    }
   
    // inicializa as letras
    jogo.dados.letras[0].letra = 'w';
    jogo.dados.letras[1].letra = 'a';
    jogo.dados.letras[2].letra = 's';
    jogo.dados.letras[3].letra = 'd';
    jogo.dados.letras[0].colPar = 0, jogo.dados.letras[0].numComidas = 0, jogo.dados.letras[0].numUsos = 0;
    jogo.dados.letras[1].colPar = 0, jogo.dados.letras[1].numComidas = 0, jogo.dados.letras[1].numUsos = 0;
    jogo.dados.letras[2].colPar = 0, jogo.dados.letras[2].numComidas = 0, jogo.dados.letras[2].numUsos = 0;
    jogo.dados.letras[3].colPar = 0, jogo.dados.letras[3].numComidas = 0, jogo.dados.letras[3].numUsos = 0;
   
    // outras
    jogo.numFantasmas = 0;
    jogo.numFrutas = 0;

   
    return jogo;
}

// Lê e processa as jogadas fornecidas, em seguida, imprime na saida o estado do jogo
tJogo RealizaJogo(char const *argv[], tJogo jogo){
    int jogadaAtual = 0, letraAtual = 0;
    char movimentoAtual = ' ';
   
    // altera a trilha;
    jogo.mapa.trilha[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x] = jogadaAtual;
   
    while (scanf("%c", &movimentoAtual) == 1)
    {
        jogo.dados.temporarios.comida = 0;
        jogo.dados.temporarios.parede = 0;
        scanf("\n");

        printf("Estado do jogo apos o movimento '%c':\n", movimentoAtual);

        // opera o jogo
        jogo = MovimentaFantasmas(jogo);
        jogo = MovimentaPlayer(movimentoAtual, jogo);
        jogo = TestaColisoes(jogo);

        // ativa a função de gerar resumo e adiciona os dados para o ranking e as estatisticas
        for (letraAtual = 0; letraAtual < 4; letraAtual++)
        {
            if(jogo.dados.letras[letraAtual].letra==movimentoAtual){
                if(jogo.derrota){
                    ResumeJogo(argv, jogadaAtual+1, movimentoAtual, 'M');
                }
                if(jogo.dados.temporarios.comida){
                    ResumeJogo(argv, jogadaAtual+1, movimentoAtual, 'C');
                    jogo.dados.letras[letraAtual].numComidas++;
                }
                if(jogo.dados.temporarios.parede){
                    ResumeJogo(argv, jogadaAtual+1, movimentoAtual, 'P');
                    jogo.dados.letras[letraAtual].colPar++;
                }
                jogo.dados.letras[letraAtual].numUsos++;
            }
        }

        if(jogo.derrota){
            return jogo;
        }

        ImprimeSituacao(jogo.mapa, jogo.pontuacao);
       
        // incrementa as jogadas
        jogadaAtual++;
       
        // altera a trilha;
        jogo.mapa.trilha[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x] = jogadaAtual;

        // testa fim de jogo
        if(jogo.pontuacao == jogo.numFrutas){
                return jogo;
        }
        if(jogadaAtual == jogo.maxMovimentos){
                jogo.derrota = 1;
                return jogo;
        }
       
    }
    return jogo;
}

// imprime o estado atual do jogo
void ImprimeSituacao(tMapa mapa, int pontuacao){
    int linhaAtual = 0, colunaAtual = 0;
        for (linhaAtual = 0; linhaAtual < mapa.linhas; linhaAtual++)
        {
            for (colunaAtual = 0; colunaAtual < mapa.colunas; colunaAtual++)
            {
                printf("%c", mapa.area[linhaAtual][colunaAtual]);
            }
            printf("\n");
        }

        printf("Pontuacao: %d\n\n", pontuacao);
}

// aciona a funcao de movimento de player parametros variaveis
tJogo MovimentaPlayer(char movimento, tJogo jogo){
    int modY = 0, modX = 0;
    switch (movimento)
    {
    case 'w':
        modY = -1, modX = 0;
        jogo = MovimentaPlayerInterno(modX, modY, jogo);
        break;

    case 'a':
        modY = 0, modX = -1;
        jogo = MovimentaPlayerInterno(modX, modY, jogo);
        break;

    case 's':
        modY = 1, modX = 0;
        jogo = MovimentaPlayerInterno(modX, modY, jogo);
        break;

    case 'd':
        modY = 0, modX = 1;
        jogo = MovimentaPlayerInterno(modX, modY, jogo);
        break;
   
    default:
        printf("!!!Erro interno, movimento inexistente para Player!!!");
        break;
    }

    return jogo;
}

// faz o moviemnto literal do player, reagindo com # e @
tJogo MovimentaPlayerInterno(int modX, int modY, tJogo jogo){
    if(jogo.mapa.area[jogo.PacMan.posicao.y+modY][jogo.PacMan.posicao.x+modX] != '#'){
        // modifica o antigo espaço do player
        if(jogo.mapa.area[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x] == '>'){
            jogo.mapa.area[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x] = ' ';
            if(jogo.PacMan.backup == '@'){
                jogo.mapa.area[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x] = '@';
            }
        }
        jogo.PacMan.posicaoSombra = jogo.PacMan.posicao;

        // move o player
        if(modX){
            jogo.PacMan.posicao.x+=modX;
        }else{
            jogo.PacMan.posicao.y+=modY;
        }

        // guarda o backup do player
        jogo.PacMan.backup = jogo.mapa.area[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x];

        // trata tunel s ehouver algum
        if(jogo.mapa.area[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x] == '@'){
            jogo.PacMan = TrataTunel(jogo.PacMan, jogo.tunel1, jogo.tunel2);
        }
        // muda o ascii da posicao do player
        jogo.mapa.area[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x] = '>';
       
    }else{
        // trata tunel no caso do player ficar em cima do mesmo
        if(jogo.PacMan.backup == '@'){
            jogo.mapa.area[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x] = '@';
            jogo.PacMan = TrataTunel(jogo.PacMan, jogo.tunel1, jogo.tunel2);
            jogo.mapa.area[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x] = '>';
        }else{
            jogo.dados.temporarios.parede = 1;
        }
    }
   
    return jogo;
}

// cuida dos casos em que o player usa tuneis
tPlayer TrataTunel(tPlayer PacMan, tPosicao tunel1, tPosicao tunel2){
    if(PacMan.posicao.x==tunel1.x && PacMan.posicao.y==tunel1.y){
        PacMan.posicao.x = tunel2.x;
        PacMan.posicao.y = tunel2.y;
    }else{
        PacMan.posicao.x = tunel1.x;
        PacMan.posicao.y = tunel1.y;
    }
    PacMan.posicaoSombra = PacMan.posicao;
    PacMan.backup = '@';
    return PacMan;
}

// faz as movimentacoes dos fantasmas pelo mapa, cada qual por seu tipo
tJogo MovimentaFantasmas(tJogo jogo){
    int fantasmaAtual = 0;
    int px = 0, py = 0;

    for (fantasmaAtual = 0; fantasmaAtual < jogo.numFantasmas; fantasmaAtual++)
    {
        jogo.fantasmas[fantasmaAtual].posicaoSombra = jogo.fantasmas[fantasmaAtual].posicao;
        jogo.mapa.area[jogo.fantasmas[fantasmaAtual].posicao.y][jogo.fantasmas[fantasmaAtual].posicao.x] = jogo.fantasmas[fantasmaAtual].backup;

        px = jogo.fantasmas[fantasmaAtual].posicao.x;
        py = jogo.fantasmas[fantasmaAtual].posicao.y;

        switch (jogo.fantasmas[fantasmaAtual].tipo)
        {
            case 'H':
                if(jogo.mapa.area[py][px+jogo.fantasmas[fantasmaAtual].orientacao] == '#'){
                    jogo.fantasmas[fantasmaAtual].orientacao = jogo.fantasmas[fantasmaAtual].orientacao * -1;
                }
                jogo.fantasmas[fantasmaAtual].posicao.x+=jogo.fantasmas[fantasmaAtual].orientacao;

                break;
           
            case 'V':
                if(jogo.mapa.area[py+jogo.fantasmas[fantasmaAtual].orientacao][px] == '#'){
                    jogo.fantasmas[fantasmaAtual].orientacao = jogo.fantasmas[fantasmaAtual].orientacao * -1;
                }
                jogo.fantasmas[fantasmaAtual].posicao.y+=jogo.fantasmas[fantasmaAtual].orientacao;

                break;

            default:

                printf("!!!Erro interno, movimento inexistente para fantasma %c!!!", jogo.fantasmas[fantasmaAtual].ID);
                break;
        }
        // guarda o backup e imprime ' ' se for um player que ainda nao se moveu
        jogo.fantasmas[fantasmaAtual].backup = jogo.mapa.area[jogo.fantasmas[fantasmaAtual].posicao.y][jogo.fantasmas[fantasmaAtual].posicao.x];
        if(jogo.fantasmas[fantasmaAtual].backup == '>'){
            jogo.fantasmas[fantasmaAtual].backup = ' ';
        }
        //imprime o fantasma no mapa
        jogo.mapa.area[jogo.fantasmas[fantasmaAtual].posicao.y][jogo.fantasmas[fantasmaAtual].posicao.x] = jogo.fantasmas[fantasmaAtual].ID;
    }

    return jogo;
}

// testa as colisoes do jogador com as frutas, bem como do jogador com os fantasmas, forçando o fim do jogo nesse segundo caso
tJogo TestaColisoes(tJogo jogo){
    int fantasmaAtual = 0;

    for (fantasmaAtual = 0; fantasmaAtual < jogo.numFantasmas; fantasmaAtual++)
    {
        // testa colisão ordinária
        if(jogo.fantasmas[fantasmaAtual].posicao.x == jogo.PacMan.posicao.x && jogo.fantasmas[fantasmaAtual].posicao.y == jogo.PacMan.posicao.y){
            jogo.mapa.area[jogo.fantasmas[fantasmaAtual].posicao.y][jogo.fantasmas[fantasmaAtual].posicao.x] = jogo.fantasmas[fantasmaAtual].ID;
           
            ImprimeSituacao(jogo.mapa, jogo.pontuacao);
           
            jogo.derrota = 1;
            return jogo;
        }
        // testa colisão "sombra-sombra"
        if(jogo.fantasmas[fantasmaAtual].posicaoSombra.x == jogo.PacMan.posicao.x && jogo.fantasmas[fantasmaAtual].posicaoSombra.y == jogo.PacMan.posicao.y){
            if(jogo.fantasmas[fantasmaAtual].posicao.x == jogo.PacMan.posicaoSombra.x && jogo.fantasmas[fantasmaAtual].posicao.y == jogo.PacMan.posicaoSombra.y){
                jogo.mapa.area[jogo.fantasmas[fantasmaAtual].posicao.y][jogo.fantasmas[fantasmaAtual].posicao.x] = jogo.fantasmas[fantasmaAtual].ID;
                jogo.mapa.area[jogo.PacMan.posicao.y][jogo.PacMan.posicao.x] = jogo.PacMan.backup;

                ImprimeSituacao(jogo.mapa, jogo.pontuacao);

                jogo.derrota = 1;
                return jogo;
            }
        }
    }
   
    // testa se houve ganho de pontos
    if (jogo.PacMan.backup == '*')
    {
        jogo.pontuacao ++;
        jogo.PacMan.backup = ' ';
       
        jogo.dados.temporarios.comida = 1;

    }
   
   
    return jogo;

}

// Imprime se o jogador foi ou não vitorioso, quebra o jogo após isso
void FimDeJogo(int derrota, int pontuacao){
    if(!derrota){
        printf("Voce venceu!\n");
        printf("Pontuacao final: %d\n", pontuacao);
    }else{
        printf("Game over!\n");
        printf("Pontuacao final: %d\n", pontuacao);
    }
}

// faz a impressao do arquivo de trilha
void ImprimeTrilha(char const *argv[], tMapa mapa){
    FILE * pFile;
    char nome[1000];
    int linhaAtual = 0, colunaAtual = 0;

    sprintf(nome, "%s/saida/trilha.txt", argv[1]);
    pFile = fopen(nome, "w");

    for (linhaAtual = 0; linhaAtual < mapa.linhas; linhaAtual++)
    {
        for (colunaAtual = 0; colunaAtual < mapa.colunas; colunaAtual++)
        {
            if(mapa.trilha[linhaAtual][colunaAtual] == -1){
                fprintf(pFile, "# ");
            }else{
                fprintf(pFile, "%d ", mapa.trilha[linhaAtual][colunaAtual]);
            }
        }
        fprintf(pFile, "\n");
    }
   
    fclose(pFile);

    return;
}


// e chamado constantemente pelo RealizaJogo() para imprimir o estado do jogo
void ResumeJogo(char const *argv[], int numComidas, char letra, char tipo){
    FILE * pFile;
    char nome[1000];
    int linhaAtual = 0, colunaAtual = 0;

    sprintf(nome, "%s/saida/resumo.txt", argv[1]);
    pFile = fopen(nome, "a");
    if(tipo == 'C'){
        fprintf(pFile, "Movimento %d (%c) pegou comida\n", numComidas, letra);
    }else if(tipo == 'P'){
        fprintf(pFile, "Movimento %d (%c) colidiu na parede\n", numComidas, letra);
    }else if(tipo == 'M'){
        fprintf(pFile, "Movimento %d (%c) fim de jogo por encostar em um fantasma\n", numComidas, letra);
    }

    fclose(pFile);

    return;
}

// gera o arquivo de estatistica.txt
void EstatificaJogo(char const *argv[], tDados dados){
    FILE * pFile;
    char nome[1000];
    int linhaAtual = 0, colunaAtual = 0;
    int somaColPar = 0, somaMovimentos = 0, somaPontos = 0, letraAtual = 0;
   
    for (letraAtual = 0; letraAtual < 4; letraAtual++)
    {
        somaPontos += dados.letras[letraAtual].numComidas;
        somaMovimentos += dados.letras[letraAtual].numUsos;
        somaColPar += dados.letras[letraAtual].colPar;
    }

    sprintf(nome, "%s/saida/estatisticas.txt", argv[1]);
    pFile = fopen(nome, "w");

    fprintf(pFile, "Numero de movimentos: %d\n", somaMovimentos);
    fprintf(pFile, "Numero de movimentos sem pontuar: %d\n", somaMovimentos - somaPontos);
    fprintf(pFile, "Numero de colisoes com parede: %d\n", somaColPar);
    fprintf(pFile, "Numero de movimentos para baixo: %d\n", dados.letras[2].numUsos);
    fprintf(pFile, "Numero de movimentos para cima: %d\n", dados.letras[0].numUsos);
    fprintf(pFile, "Numero de movimentos para esquerda: %d\n", dados.letras[1].numUsos);
    fprintf(pFile, "Numero de movimentos para direita: %d\n", dados.letras[3].numUsos);

    fclose(pFile);

    return;
}

// gera o ranking do jogo

void RankingJogo(char const *argv[], tDados dados){
    FILE * pFile;
    char nome[1000];
    int linhaAtual = 0, colunaAtual = 0, letraAtual = 0;
   
    OrdenaLetras(dados.letras);

    sprintf(nome, "%s/saida/ranking.txt", argv[1]);
    pFile = fopen(nome, "w");
   
    for (letraAtual = 0; letraAtual < 4; letraAtual++)
    {
        fprintf(pFile, "%c,%d,%d,%d\n", dados.letras[letraAtual].letra, dados.letras[letraAtual].numComidas, dados.letras[letraAtual].colPar, dados.letras[letraAtual].numUsos);
    }
   
    fclose(pFile);

    return;
}

// ordena as letras para sua posterior impressão no ranking

void OrdenaLetras(tLetra letras[4]){

    //Foi usado um algoritmo de "Bubble Sort"

    int i = 0, breaker = 1;
    tLetra helper;
    while(1){
        for (i = 0; i <3 ; i++)
        {
            if (letras[i].numComidas<letras[i+1].numComidas)
            {
                helper = letras[i];
                letras[i] = letras[i+1];
                letras[i+1] = helper;
                breaker = 0;
            }else if (letras[i].numComidas==letras[i+1].numComidas)
            {
                if (letras[i].colPar>letras[i+1].colPar)
                {
                    helper = letras[i];
                    letras[i] = letras[i+1];
                    letras[i+1] = helper;
                    breaker = 0;
                }else if (letras[i].colPar==letras[i+1].colPar)
                {
                    if (letras[i].numUsos<letras[i+1].numUsos)
                    {
                        helper = letras[i];
                        letras[i] = letras[i+1];
                        letras[i+1] = helper;
                        breaker = 0;
                    }else if (letras[i].numUsos==letras[i+1].numUsos)
                    {
                        if ((int)letras[i].letra>(int)letras[i+1].letra)
                        {
                            helper = letras[i];
                            letras[i] = letras[i+1];
                            letras[i+1] = helper;
                            breaker = 0;
                        }
                    }
                }  
            }
        }
        if (breaker)
        {
            break;
        }
        breaker = 1;
    }
    return;
}