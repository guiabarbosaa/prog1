#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define teclaW 0
#define teclaS 1
#define teclaD 2
#define teclaA 3

#define GhostB 0
#define GhostP 1
#define GhostI 2
#define GhostC 3

typedef struct{
	int CoordenadaX;
	int CoordenadaY;
}tPortal_Pac;//guarda coordenada dos portais

typedef struct{
	int Num_Mov;
	int Num_Com;
	int Num_Colisoes;
	char tecla;
}tTeclas_Mov;//guarda as informacoes das teclas

typedef struct{
	int CoordenadaFantX;
	int CoordenadaFantY;
	int CoordenadaX;
	int CoordenadaY;

	int Num_Movimentos;
	int Num_MovimSemPontos;
	int Num_Comidas;
	int Num_Colisoes;

	tTeclas_Mov movimentos[4];

	int Flag_Perdeu;
	int Flag_PisouPortal;
	int limMovimentos;
}tPlayer_Pac_Man; //struct que contem as coordenadas do player, sua sombra, flag de indicar que pisou no portal ou perdeu, guarda o limite
				  //de movimento, alem de guardar estatisticas do game, tanto do player, no geral, quanto das teclas utilizadas

typedef struct{
	int CoordenadaFantX;
	int CoordenadaFantY;
	int CoordenadaX;
	int CoordenadaY;
	int FlagDirecao;
	char ghost_ID;
}tGhost_Pac_Man; //struct que contem as coordenadas dos fantasmas, sua sombra, a flag de indicar qual movimento e seu devido caractere

typedef struct{
	tPortal_Pac portais[2];
	char mapa_PM[100][100];
	int linhas;
	int colunas;
	int LocalizaPortal[100][100];
	char mapaAuxiliar[100][100];
	int mapaTrilha[100][100];
	int countComidas;
}tMapaPac; //struct que contem tudo relacionado ao mapa, mapas auxiliares e informacoes do mapa, como numero de comidas e portais

typedef struct{
	tPlayer_Pac_Man jogador;
	tGhost_Pac_Man fantasmas[4];
	tMapaPac mapa;
}tJogo; //struct que engloba tudo

//////////////////////////////////////STRUCTS PARA GUARDAR INFORMACOES DO MAPA, DO JOGADOR E DOS FANTASMAS//////////////////////////////////
 
tMapaPac LeMapa(tMapaPac mapas, FILE *mapa);
void ImprimeMapaPac_Man(tMapaPac mapas, FILE *mapa);
void AondeEstahInicializaPac_Man(tMapaPac mapas, FILE *mapa);
//UTILIZADOS PARA GERAR O ARQUIVO INICIALIZACAO.TXT
void ImprimeSaidatxt(tMapaPac mapa,tPlayer_Pac_Man jogador, char ordem);
tJogo PreencheFlags(tJogo jogo);
tJogo PreGame(tJogo jogo, FILE* mapa, FILE* inicializa);
//PREENCHER A STRUCT tJOGO
tGhost_Pac_Man VerificaFantasma(tMapaPac mapa, tGhost_Pac_Man fantasma);
tJogo LocalizaFantasma(tJogo jogo);
tJogo LocalizaJogador(tJogo jogo);
//LOCALIZACAO DOS PERSONAGENS
//////////////////////////////////////////////FUNCOES UTILIZADAS ANTES DE INICIAR O JOGO/////////////////////////////////////////////////////
int ExisteFantasma(tMapaPac mapa, tGhost_Pac_Man fantasma);
//VERIFICACAO DE EXISTENCIA QUE SERA NECESSARIO AO INICIALIZAR O GAME
tMapaPac MovimenteFantasmaDireita(tMapaPac mapa, tGhost_Pac_Man fantasma);
tMapaPac MovimenteFantasmaEsquerda(tMapaPac mapa, tGhost_Pac_Man fantasma);
tMapaPac MovimenteFantasmaCima(tMapaPac mapa, tGhost_Pac_Man fantasma);
tMapaPac MovimenteFantasmaBaixo(tMapaPac mapa, tGhost_Pac_Man fantasma);
//COM A MOVIMENTACAO DO FANTASMA, ESSAS FUNCOES IRAO ATUALIZAR O MAPA
tGhost_Pac_Man AtualizaPosicaoDireita(tGhost_Pac_Man fantasmas);
tGhost_Pac_Man AtualizaPosicaoEsquerda(tGhost_Pac_Man fantasmas);
tGhost_Pac_Man AtualizaPosicaoCima(tGhost_Pac_Man fantasmas);	   
tGhost_Pac_Man AtualizaPosicaoBaixo(tGhost_Pac_Man fantasmas);
//ATUALIZA A COORDENADA DOS FANTASMAS 
tPlayer_Pac_Man AtualizaNumTecla(tPlayer_Pac_Man jogador, char ordem);
tPlayer_Pac_Man AtualizaFantasmaPac(tPlayer_Pac_Man jogador);
tGhost_Pac_Man AtualizaFantasma(tGhost_Pac_Man fantasma);
tJogo InicializaFantasma(tJogo jogo);                  
//FUNCOES PARA AUXILIAR NA ATUALIZACAO DA STRUCT DA SOMBRA DO FANTASMA E DO PLAYER, DURANTE O JOGO
int VerificaHahParede(tPlayer_Pac_Man jogador,tMapaPac mapa, char ordem);
int VerificaHahComida(tPlayer_Pac_Man jogador,tMapaPac mapa, char ordem);
int VerificaHahFantasma(tPlayer_Pac_Man jogador,tMapaPac mapa, char ordem);
int VerificaHahSombra(tJogo jogo, char ordem);
int ColideFantasma(tPlayer_Pac_Man jogador, tMapaPac mapa);
//CONDICOES DE EXISTENCIA PARA A MOVIMENTACAO DO JOGADOR
tMapaPac MovimentePlayer(tPlayer_Pac_Man jogador, tMapaPac mapa, char ordem);
tJogo ComidaPac(tJogo jogo, char ordem, FILE* Resumo);
tJogo ParedePac(tJogo jogo, char ordem, FILE* Resumo);
tJogo FantasmaPac(tJogo jogo, char ordem, FILE* Resumo);
tJogo NormalPac(tJogo jogo, char ordem, FILE* Resumo);
//COM A MOVIMENTACAO DO PLAYER, ESSAS FUNCOES IRAO ATUALIZAR O MAPA E A COORDENADA DO PLAYER
tPlayer_Pac_Man AtualizaLocal(tPlayer_Pac_Man jogador, char ordem);
tMapaPac DevolvePortal(tMapaPac mapa, tPlayer_Pac_Man jogador);
tPlayer_Pac_Man AtualizaNumColisao(tPlayer_Pac_Man jogador, char ordem);
tPlayer_Pac_Man AtualizaNumComida(tPlayer_Pac_Man jogador, char ordem);
tMapaPac AtualizaMapaAuxiliar(tMapaPac mapa, tPlayer_Pac_Man jogador, char ordem);
//FUNCOES AUXILIARES PARA AS FUNCOES DE MOVIMENTACAO DO PLAYER
tJogo JogarPartida(tJogo jogo, char ordem, FILE *Resumo);
//FUNCAO QUE EFETUA O GAME
void ResumoGameParede(tPlayer_Pac_Man jogador, char ordem, FILE *Resumo);
void ResumoGameComida(tPlayer_Pac_Man jogador, char ordem, FILE *Resumo);
void ResumoGameFantasma(tPlayer_Pac_Man jogador, char ordem, FILE *Resumo);
tMapaPac PreencheTrilha(tPlayer_Pac_Man jogador, tMapaPac mapa);
//FUNCOES QUE PREENCHEM ARQUIVOS ABERTOS
//////////////////////////////////////////////FUNCOES QUE SERAO UTILIZADAS PARA A OCORRENCIA DO GAME//////////////////////////////////////////
void GameOver(tPlayer_Pac_Man jogador);
void VenceuPartida(tPlayer_Pac_Man jogador);
void Estatistica(tPlayer_Pac_Man jogador, FILE *Estatisticah);
void ImprimeTrilha(tMapaPac mapa,tPlayer_Pac_Man jogador, FILE *trilha);
tPlayer_Pac_Man MoveTeclas(tPlayer_Pac_Man jogador, int i, int j);
tPlayer_Pac_Man OrganizaTeclas(tPlayer_Pac_Man jogador);
void ImprimeRanking(tPlayer_Pac_Man jogador, FILE *ranking);
//SAIDA DOS ARQUIVOS
tJogo FinalizaGame(tJogo jogo, FILE *saida, FILE *resumo, FILE *trilha, FILE *mapa, FILE *Estatisticah, FILE *ranking);
//FECHA ARQUIVOS E ACOPLA AS FUNCOES NECESSARIAS AO FECHAR O GAME

/////////////////////////////////////////////// APOS O FIM DA PARTIDA, ESSAS FUNCOES SERAO UTILIZADAS/////////////////////////////////////////

//////////////////////////////////////////////////////////////////CABECALHO///////////////////////////////////////////////////////////////////

int main(int argc, char * argv[])
{
	FILE *mapa, *inicializa, *saida, *resumo, *estatistica, *trilha, *ranking;
	tJogo jogo;
	char diretorio[1000], ordem;
	int movimentos = 0;
	sprintf(diretorio, "%s/mapa.txt", argv[1]);
	mapa = fopen(diretorio, "r");
	if (mapa == NULL) {
    printf("ERRO: O diretorio de arquivos de configuracao nao foi informado");
    return 1;
	}	
	sprintf(diretorio, "%s/saida/inicializacao.txt", argv[1]);
	inicializa = fopen(diretorio, "w");
	sprintf(diretorio, "%s/saida/saida.txt", argv[1]);
	saida = fopen(diretorio, "w");
	sprintf(diretorio, "%s/saida/resumo.txt", argv[1]);
	resumo = fopen(diretorio, "w");
	sprintf(diretorio, "%s/saida/estatisticas.txt", argv[1]);
	estatistica = fopen(diretorio, "w");
	sprintf(diretorio, "%s/saida/trilha.txt", argv[1]);
	trilha = fopen(diretorio, "w");
	sprintf(diretorio, "%s/saida/ranking.txt", argv[1]);
	ranking = fopen(diretorio, "w");
	jogo = PreGame(jogo,mapa,inicializa);
	while(scanf("%c\n", &ordem)== 1)//enquanto estiver recebendo ordem, o game continua
	{
		movimentos++;//contador de movimentos
		if(movimentos <= jogo.jogador.limMovimentos) //se esta dentro dos limites
		{
			jogo = JogarPartida(jogo,ordem,resumo);
			ImprimeSaidatxt(jogo.mapa,jogo.jogador,ordem);
			if(jogo.jogador.Num_Comidas == jogo.mapa.countComidas)
			{
				VenceuPartida(jogo.jogador);
				break;//quebra de loop;
			}	
		}
		if(movimentos >= jogo.jogador.limMovimentos)//se excedeu o numero de movimentos
		{
			GameOver(jogo.jogador);
			break;
		}
		if(jogo.jogador.Flag_Perdeu == 10)//se, ao movimentar o game, o player perdeu
		{	 
			GameOver(jogo.jogador);
			break;
		}
	}
jogo = FinalizaGame(jogo,saida,resumo,trilha,mapa,estatistica,ranking);
return 0;
}
  	
tMapaPac LeMapa(tMapaPac mapas, FILE *mapa)
{
	int i, j;
	char c;
	
	for(i = 0; i < mapas.linhas; i++)
	{
		for(j = 0; j < mapas.colunas; j++)
		{
			fscanf(mapa,"%c", &c);
			mapas.mapa_PM[i][j] = c;
			mapas.mapaAuxiliar[i][j] = c;
		}
		fgetc(mapa); //Utilizado para ler o caractere de nova linha
	}
	return mapas;
}   
void ImprimeMapaPac_Man(tMapaPac mapas, FILE *situacao)
{
	int i, j;//Imprime o mapa no inicializacao.txt
	
	for(i = 0; i < mapas.linhas; i++)
	{
		for(j = 0; j < mapas.colunas; j++)
		{
			fprintf(situacao,"%c", mapas.mapa_PM[i][j]);
		}
	fprintf(situacao, "\n");
	}
}	
void AondeEstahInicializaPac_Man(tMapaPac mapas, FILE *situacao)			
{
	int i, j;

	for(i = 0; i < mapas.linhas; i++)
	{
		for(j = 0; j < mapas.colunas; j++)
		{
			if(mapas.mapa_PM[i][j] == '>')
			{
				fprintf(situacao,"Pac-Man comecara o jogo na linha %d e coluna %d\n", i+1 , j+1);
				fclose(situacao);
				return;
			}
		}
	}
}
void ImprimeSaidatxt(tMapaPac mapa,tPlayer_Pac_Man jogador, char ordem)
{
	int i,j;
	printf("Estado do jogo apos o movimento '%c':\n", ordem);
	for(i = 0; i < mapa.linhas; i++)
	{
		for(j = 0; j < mapa.colunas; j++)
		{
			printf("%c", mapa.mapa_PM[i][j]);
		}
	printf("\n");
	}
	printf("Pontuacao: %d\n\n", jogador.Num_Comidas); //serve para indicar qual movimento, como esta o mapa e a pontuacao do player
}
tJogo PreencheFlags(tJogo jogo)
{
	int i, j, countNumCom = 0,Portal = 0;

	jogo.jogador.Flag_Perdeu = 0;
	jogo.jogador.Num_Colisoes = 0;
	jogo.jogador.movimentos[0].Num_Colisoes = 0;
	jogo.jogador.movimentos[1].Num_Colisoes = 0;
	jogo.jogador.movimentos[2].Num_Colisoes = 0;
	jogo.jogador.movimentos[3].Num_Colisoes = 0;
	jogo.jogador.Num_Comidas = 0;
	jogo.jogador.movimentos[0].Num_Com = 0;
	jogo.jogador.movimentos[1].Num_Com = 0;
	jogo.jogador.movimentos[2].Num_Com = 0;
	jogo.jogador.movimentos[3].Num_Com = 0;
	jogo.jogador.Num_Movimentos = 0;
	jogo.jogador.Num_MovimSemPontos = 0;
	jogo.jogador.movimentos[0].Num_Mov = 0;
	jogo.jogador.movimentos[1].Num_Mov = 0;
	jogo.jogador.movimentos[2].Num_Mov = 0;
	jogo.jogador.movimentos[3].Num_Mov = 0;
	jogo.fantasmas[0].FlagDirecao = -1;
	jogo.fantasmas[1].FlagDirecao = 1;
	jogo.fantasmas[2].FlagDirecao = -1;
	jogo.fantasmas[3].FlagDirecao = 1;
	jogo.jogador.movimentos[teclaW].tecla = 'w';
	jogo.jogador.movimentos[teclaS].tecla = 's';
	jogo.jogador.movimentos[teclaA].tecla = 'a';
	jogo.jogador.movimentos[teclaD].tecla = 'd';
	jogo.fantasmas[0].ghost_ID = 'B';
	jogo.fantasmas[1].ghost_ID = 'P';
	jogo.fantasmas[2].ghost_ID = 'I';
	jogo.fantasmas[3].ghost_ID = 'C';

	//Tudo acima e inicializacao de variavel, ou identificacao das teclas ou indicador de movimento dos fantasmas
	for(i = 0; i < jogo.mapa.linhas; i++)
	{
		for(j = 0; j < jogo.mapa.colunas; j++)
		{
			if(jogo.mapa.mapa_PM[i][j] == '*')
			{
				countNumCom++;
			}
			if(jogo.mapa.mapa_PM[i][j] == '@')
			{
				jogo.mapa.portais[Portal].CoordenadaX = j; 
				jogo.mapa.portais[Portal].CoordenadaY = i; //localizacao dos tuneis
				jogo.mapa.LocalizaPortal[i][j] = Portal; //mapa auxiliar para facilitar a identificacao de X portal
				Portal++;
			}
			jogo.mapa.mapaTrilha[i][j] = -1; //Mapa de trilha que será usando como referencia para elaborar o trilha.txt
		}
	}
	jogo.jogador.Flag_PisouPortal =  10; //flag necessaria para devolver o portal ao mapa
	jogo.mapa.countComidas = countNumCom; // necessario para verificar se o player venceu, ao comer todas as frutas
	
	return jogo;
}
tJogo PreGame(tJogo jogo, FILE* mapa, FILE* inicializa)
{   //Funcao que engloba tudo que permite a leitura do arquivo mapa.txt, fazer a inicializacao e preencher informacoes da struct
	fscanf(mapa, "%d", &jogo.mapa.linhas);
	fscanf(mapa, "%d", &jogo.mapa.colunas);
	fscanf(mapa, "%d", &jogo.jogador.limMovimentos); 
	fgetc(mapa); //Utilizado para ler o caractere de nova linha apos o ultimo numero
	jogo.mapa = LeMapa(jogo.mapa,mapa);
	ImprimeMapaPac_Man(jogo.mapa,inicializa);
	AondeEstahInicializaPac_Man(jogo.mapa,inicializa);
	jogo = PreencheFlags(jogo);
	jogo = LocalizaFantasma(jogo);
	jogo = LocalizaJogador(jogo);

	return jogo;
}
tGhost_Pac_Man VerificaFantasma(tMapaPac mapa, tGhost_Pac_Man fantasma)
{
	int i, j;

	for(i=0; i<mapa.linhas; i++)
	{
		for(j=0;j<mapa.colunas;j++)
		{
			if(mapa.mapa_PM[i][j]== fantasma.ghost_ID)
			{
				fantasma.CoordenadaX = j;
				fantasma.CoordenadaY = i;
			}
		}
	}
	return fantasma;
}
tJogo LocalizaJogador(tJogo jogo)
{
	int i, j;

	for(i=0; i<jogo.mapa.linhas; i++)
	{
		for(j=0;j<jogo.mapa.colunas;j++)
		{
			if(jogo.mapa.mapa_PM[i][j]== '>')
			{
				jogo.jogador.CoordenadaX = j;
				jogo.jogador.CoordenadaY = i;
			}
		}
	}
	jogo.mapa.mapaTrilha[jogo.jogador.CoordenadaY][jogo.jogador.CoordenadaX] = 0;
	return jogo;
}
tJogo LocalizaFantasma(tJogo jogo)
{
	jogo.fantasmas[GhostB] = VerificaFantasma(jogo.mapa,jogo.fantasmas[GhostB]);
	jogo.fantasmas[GhostP] = VerificaFantasma(jogo.mapa,jogo.fantasmas[GhostP]);
	jogo.fantasmas[GhostI] = VerificaFantasma(jogo.mapa,jogo.fantasmas[GhostI]);
	jogo.fantasmas[GhostC] = VerificaFantasma(jogo.mapa,jogo.fantasmas[GhostC]);

	return jogo;
}
// e importante localizar o player e o fantasma, guardando suas coordenadas, pois futuramente so sera necessario atualiza-las
int ExisteFantasma(tMapaPac mapa, tGhost_Pac_Man fantasma)
{   //Condicao de existencia necessaria, pois nem sempre haverá 4 fantasmas.
	int i, j;

	for(i=0; i<mapa.linhas; i++)
	{
		for(j=0;j<mapa.colunas;j++)
		{
			if(mapa.mapaAuxiliar[i][j]== fantasma.ghost_ID)
			{
				return 1;
			}
		}
	}
	return 0;
}
tMapaPac DevolveChaoFantasma(tMapaPac mapa, tGhost_Pac_Man fantasma)
{ //atualiza o mapa apos o fantasma andar
	if(mapa.mapaAuxiliar[fantasma.CoordenadaY][fantasma.CoordenadaX] == '*') //verifica no mapa auxiliar se la contem comida ou nao
	{
		mapa.mapa_PM[fantasma.CoordenadaY][fantasma.CoordenadaX] = '*';
	}
	else
	{
		if(mapa.mapa_PM[fantasma.CoordenadaY][fantasma.CoordenadaX] == fantasma.ghost_ID) //verifica se hah um outro fantasma na posicao dele, se nao, printa white space
		{
			mapa.mapa_PM[fantasma.CoordenadaY][fantasma.CoordenadaX] = ' ';
		}
	}
	return mapa;
}
tMapaPac MovimenteFantasmaDireita(tMapaPac mapa, tGhost_Pac_Man fantasma)
{
	mapa.mapa_PM[fantasma.CoordenadaY][fantasma.CoordenadaX + 1] = fantasma.ghost_ID;
	mapa = DevolveChaoFantasma(mapa,fantasma);
	return mapa;
}
tMapaPac MovimenteFantasmaEsquerda(tMapaPac mapa, tGhost_Pac_Man fantasma)
{
	mapa.mapa_PM[fantasma.CoordenadaY][fantasma.CoordenadaX - 1] = fantasma.ghost_ID;
	mapa = DevolveChaoFantasma(mapa,fantasma);
	return mapa;
}
tMapaPac MovimenteFantasmaCima(tMapaPac mapa, tGhost_Pac_Man fantasma)
{
	mapa.mapa_PM[fantasma.CoordenadaY - 1][fantasma.CoordenadaX] = fantasma.ghost_ID;
	mapa = DevolveChaoFantasma(mapa,fantasma);
	return mapa;
}
tMapaPac MovimenteFantasmaBaixo(tMapaPac mapa, tGhost_Pac_Man fantasma)
{
	mapa.mapa_PM[fantasma.CoordenadaY + 1][fantasma.CoordenadaX] = fantasma.ghost_ID;
	mapa = DevolveChaoFantasma(mapa,fantasma);
	return mapa;
}
// atualizacao do mapa de acordo com o sentido de movimento do fantasma
tGhost_Pac_Man AtualizaPosicaoDireita(tGhost_Pac_Man fantasmas)
{
	fantasmas.CoordenadaX += 1;
	
	return fantasmas;
}
tGhost_Pac_Man AtualizaPosicaoEsquerda(tGhost_Pac_Man fantasmas)
{
	fantasmas.CoordenadaX -= 1;

	return fantasmas;
}
tGhost_Pac_Man AtualizaPosicaoCima(tGhost_Pac_Man fantasmas)
{
	fantasmas.CoordenadaY -= 1;

	return fantasmas;
}
tGhost_Pac_Man AtualizaPosicaoBaixo(tGhost_Pac_Man fantasmas)
{
	fantasmas.CoordenadaY += 1;
	
	return fantasmas;
}
// Atualizacao de Coordenada dos fantasmas, após sua movimentacao.
tPlayer_Pac_Man AtualizaFantasmaPac(tPlayer_Pac_Man jogador)
{
	jogador.CoordenadaFantX = jogador.CoordenadaX;
	jogador.CoordenadaFantY = jogador.CoordenadaY;

	return jogador;
}
tGhost_Pac_Man AtualizaFantasma(tGhost_Pac_Man fantasma)
{
	fantasma.CoordenadaFantX = fantasma.CoordenadaX;
	fantasma.CoordenadaFantY = fantasma.CoordenadaY;

	return fantasma;
}
tJogo InicializaFantasma(tJogo jogo)
{
	jogo.jogador = AtualizaFantasmaPac(jogo.jogador);
	jogo.fantasmas[0] = AtualizaFantasma(jogo.fantasmas[0]);
	jogo.fantasmas[1] = AtualizaFantasma(jogo.fantasmas[1]);
	jogo.fantasmas[2] = AtualizaFantasma(jogo.fantasmas[2]);
	jogo.fantasmas[3] = AtualizaFantasma(jogo.fantasmas[3]);

	return jogo;
}
// Atualizacao das sombras dos fantasmas, pois sera necessario para verificar se houve colisao entre ambos e, sendo assim, ocorrer gamer over
int VerificaHahParede(tPlayer_Pac_Man jogador,tMapaPac mapa, char ordem)
{ //checar se havera colisao com a parede
	if(ordem == 'w')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY-1][jogador.CoordenadaX] == '#')
		{
			return 1;
		}
	}
	if(ordem == 'a')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX-1] == '#')
		{
			return 1;
		}
	}
	if(ordem == 's')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY+1][jogador.CoordenadaX] == '#')
		{
			return 1;
		}
	}
	if(ordem == 'd')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX+1] == '#')
		{
			return 1;
		}
	}
	return 0;
}
int VerificaHahComida(tPlayer_Pac_Man jogador,tMapaPac mapa, char ordem)
{ //verificar se ha comida, para atualizar a pontuacao do PACMAN
	if(ordem == 'w')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY-1][jogador.CoordenadaX] == '*')
		{
			return 1;
		}
	}
	if(ordem == 'a')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX-1] == '*')
		{
			return 1;
		}
	}
	if(ordem == 's')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY+1][jogador.CoordenadaX] == '*')
		{
			return 1;
		}
	}
	if(ordem == 'd')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX+1] == '*')
		{
			return 1;
		}
	}
	return 0;
}
int VerificaHahFantasma(tPlayer_Pac_Man jogador,tMapaPac mapa, char ordem)
{ //ao player se movimentar, se la estara algum fantasma
	if(ordem == 'w')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY-1][jogador.CoordenadaX] == 'B'||mapa.mapa_PM[jogador.CoordenadaY-1][jogador.CoordenadaX] == 'P'||
		   mapa.mapa_PM[jogador.CoordenadaY-1][jogador.CoordenadaX] == 'I'||mapa.mapa_PM[jogador.CoordenadaY-1][jogador.CoordenadaX] == 'C')
		{
			return 1;
		}
	}
	if(ordem == 'a')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX-1] == 'B'||mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX-1] == 'P'||
		   mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX-1] == 'I'||mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX-1] == 'C')
		{
			return 1;
		}
	}
	if(ordem == 's')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY+1][jogador.CoordenadaX] == 'B'||mapa.mapa_PM[jogador.CoordenadaY+1][jogador.CoordenadaX] == 'P'||
		   mapa.mapa_PM[jogador.CoordenadaY+1][jogador.CoordenadaX] == 'I'||mapa.mapa_PM[jogador.CoordenadaY+1][jogador.CoordenadaX] == 'C')
		{
			return 1;
		}
	}
	if(ordem == 'd')
	{
		if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX+1]== 'B'||mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX+1] == 'P'||
		   mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX+1] == 'I'||mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX+1] == 'C')
		{
			return 1;
		}
	}
	return 0;
}
int VerificaHahSombra(tJogo jogo, char ordem)
{	//verifica se houve coilisao entre algum fantasma e o pacman
	jogo.jogador = AtualizaLocal(jogo.jogador,ordem);
	if(jogo.jogador.CoordenadaFantX == jogo.fantasmas[GhostB].CoordenadaX && jogo.jogador.CoordenadaFantY == jogo.fantasmas[GhostB].CoordenadaY &&
		jogo.jogador.CoordenadaX == jogo.fantasmas[GhostB].CoordenadaFantX && jogo.jogador.CoordenadaY == jogo.fantasmas[GhostB].CoordenadaFantY)
	{
		return 1;
	}
	if(jogo.jogador.CoordenadaFantX == jogo.fantasmas[GhostP].CoordenadaX && jogo.jogador.CoordenadaFantY == jogo.fantasmas[GhostP].CoordenadaY &&
		jogo.jogador.CoordenadaX == jogo.fantasmas[GhostP].CoordenadaFantX && jogo.jogador.CoordenadaY == jogo.fantasmas[GhostP].CoordenadaFantY)
	{
		return 1;
	}
	if(jogo.jogador.CoordenadaFantX == jogo.fantasmas[GhostI].CoordenadaX && jogo.jogador.CoordenadaFantY == jogo.fantasmas[GhostI].CoordenadaY &&
		jogo.jogador.CoordenadaX == jogo.fantasmas[GhostI].CoordenadaFantX && jogo.jogador.CoordenadaY == jogo.fantasmas[GhostI].CoordenadaFantY)
	{
		return 1;
	}
	if(jogo.jogador.CoordenadaFantX == jogo.fantasmas[GhostC].CoordenadaX && jogo.jogador.CoordenadaFantY == jogo.fantasmas[GhostC].CoordenadaY &&
		jogo.jogador.CoordenadaX == jogo.fantasmas[GhostC].CoordenadaFantX && jogo.jogador.CoordenadaY == jogo.fantasmas[GhostC].CoordenadaFantY)
	{
		return 1;
	}
	return 0;	
}
int ColideFantasma(tPlayer_Pac_Man jogador, tMapaPac mapa)
{ //Caso de o PACMAN colidir com a parede e o fantasma encosta-lo, ocorre gamer over
	if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX]== 'B'||mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] == 'P'||
		mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] == 'I'||mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] == 'C')
	{
			return 1;
	}
	return 0;
}
int PisouPortal(tPlayer_Pac_Man jogador, tMapaPac mapa)
{ //verifica se o PAC MAN pisou em algum portal, para assim ele ser teletransportado
	int i;
	for(i=0;i<2;i++)
	{
		if(jogador.CoordenadaX == mapa.portais[i].CoordenadaX && jogador.CoordenadaY == mapa.portais[i].CoordenadaY)
		{
			return 1;
		}
	}
	return 0;
}
// Todos acima sao condicoes de existencia que podem impactar no PAC MAN, seja na pontuacao, movimentacao ou gamer over
tMapaPac MovimentePlayer(tPlayer_Pac_Man jogador, tMapaPac mapa, char ordem)
{
	if(ordem == 'w')		
	{
		mapa.mapa_PM[jogador.CoordenadaY-1][jogador.CoordenadaX] = '>';
		if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] == '>')//verifica se na posicao anterior ao movimento nao hah um fantasma
		{
			mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] = ' ';
		}
	}
	if(ordem == 'd')
	{
		mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX+1] = '>';
		if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] == '>')
		{
			mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] = ' ';
		}
	}
	if(ordem == 's')
	{
		mapa.mapa_PM[jogador.CoordenadaY+1][jogador.CoordenadaX] = '>';
		if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] == '>')
		{
			mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] = ' ';
		}
	}
	if(ordem == 'a')
	{
		mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX-1] = '>';
		if(mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] == '>')
		{
			mapa.mapa_PM[jogador.CoordenadaY][jogador.CoordenadaX] = ' ';
		}
	}
	return mapa;
}
tJogo MovimentePortalPlayer(tJogo jogo)
{ //se pisou em algum portal, verifica em qual ele pisou e teletransporta ele para outro
	int pisou = 10;
	jogo.mapa.mapa_PM[jogo.jogador.CoordenadaY][jogo.jogador.CoordenadaX] = '@';
	pisou = jogo.mapa.LocalizaPortal[jogo.jogador.CoordenadaY][jogo.jogador.CoordenadaX]; 
	if(pisou == 0)
	{
		jogo.mapa.mapa_PM[jogo.mapa.portais[1].CoordenadaY][jogo.mapa.portais[1].CoordenadaX] = '>';
		jogo.jogador.CoordenadaX = jogo.mapa.portais[1].CoordenadaX;
		jogo.jogador.CoordenadaY = jogo.mapa.portais[1].CoordenadaY;
		jogo.jogador.Flag_PisouPortal = 1;
	}
	else if(pisou == 1)
	{
		jogo.mapa.mapa_PM[jogo.mapa.portais[0].CoordenadaY][jogo.mapa.portais[0].CoordenadaX] = '>';
		jogo.jogador.CoordenadaX = jogo.mapa.portais[0].CoordenadaX;
		jogo.jogador.CoordenadaY = jogo.mapa.portais[0].CoordenadaY;
		jogo.jogador.Flag_PisouPortal = 0;
	}
	return jogo;
}
tJogo ComidaPac(tJogo jogo, char ordem, FILE* Resumo)
{
	jogo.mapa = MovimentePlayer(jogo.jogador,jogo.mapa,ordem);
	jogo.jogador.Num_Comidas +=1;
	ResumoGameComida(jogo.jogador,ordem,Resumo);
	jogo.jogador = AtualizaNumComida(jogo.jogador,ordem);
	jogo.mapa = AtualizaMapaAuxiliar(jogo.mapa,jogo.jogador,ordem);
	jogo.jogador = AtualizaLocal(jogo.jogador,ordem);
	return jogo;
}
tJogo ParedePac(tJogo jogo, char ordem, FILE* Resumo)
{
	jogo.jogador.Num_Colisoes +=1;
	jogo.jogador.Num_MovimSemPontos +=1;
	jogo.jogador = AtualizaNumColisao(jogo.jogador,ordem);
	if(ColideFantasma(jogo.jogador,jogo.mapa))
	{
		jogo.jogador.Flag_Perdeu = 10;
		ResumoGameFantasma(jogo.jogador,ordem,Resumo);
	}
	jogo.mapa = DevolvePortal(jogo.mapa,jogo.jogador);
	if(PisouPortal(jogo.jogador,jogo.mapa))
	{
		jogo = MovimentePortalPlayer(jogo);
	}
	else
	{
		ResumoGameParede(jogo.jogador,ordem,Resumo);
	}
	return jogo;
}
tJogo FantasmaPac(tJogo jogo, char ordem, FILE* Resumo)
{
	jogo.jogador.Flag_Perdeu = 10;
	jogo.mapa.mapa_PM[jogo.jogador.CoordenadaY][jogo.jogador.CoordenadaX] = ' ';
	jogo.jogador.Num_MovimSemPontos +=1;
	ResumoGameFantasma(jogo.jogador,ordem,Resumo);
	return jogo;
}
tJogo NormalPac(tJogo jogo, char ordem, FILE* Resumo)
{
	jogo.mapa = MovimentePlayer(jogo.jogador,jogo.mapa,ordem);
	jogo.jogador = AtualizaLocal(jogo.jogador,ordem);
	jogo.mapa = DevolvePortal(jogo.mapa,jogo.jogador);
	if(PisouPortal(jogo.jogador,jogo.mapa))
	{
		jogo = MovimentePortalPlayer(jogo);
	}
	jogo.jogador.Num_MovimSemPontos +=1;
	return jogo;
}
// Todos acimas englobam varias coisas do PACMAN: movimentacao do player, atualizacao de pontos, checar gamerover e etc... 
tMapaPac DevolvePortal(tMapaPac mapa, tPlayer_Pac_Man jogador)
{ // necessario para devolver o portal ao mapa, apos o PAC MAN sair de cima do portal
	if(jogador.Flag_PisouPortal == 0)
	{
		mapa.mapa_PM[mapa.portais[0].CoordenadaY][mapa.portais[0].CoordenadaX] = '@';
	}
	else if(jogador.Flag_PisouPortal == 1)
	{
		mapa.mapa_PM[mapa.portais[1].CoordenadaY][mapa.portais[1].CoordenadaX] = '@';
	}
	return mapa;
}
tPlayer_Pac_Man AtualizaLocal(tPlayer_Pac_Man jogador, char ordem)
{ //atualizacao basica de coordenada
	if(ordem == 'w'){
		jogador.CoordenadaY -=1;
	}
	else if(ordem == 'd'){
		jogador.CoordenadaX +=1;
	}
	else if(ordem == 's'){
		jogador.CoordenadaY +=1;
	}
	else if(ordem == 'a'){
		jogador.CoordenadaX -=1;
	}
	return jogador;
}
tPlayer_Pac_Man AtualizaNumTecla(tPlayer_Pac_Man jogador, char ordem)
{ //atualizacao necessaria para o ranking de teclas
	if(ordem == 'w'){
		jogador.movimentos[teclaW].Num_Mov +=1;
	}
	else if(ordem == 'd'){
		jogador.movimentos[teclaD].Num_Mov +=1;
	}
	else if(ordem == 's'){
		jogador.movimentos[teclaS].Num_Mov +=1;
	}
	else if(ordem == 'a'){
		jogador.movimentos[teclaA].Num_Mov +=1;
	}
	return jogador;
}
tPlayer_Pac_Man AtualizaNumColisao(tPlayer_Pac_Man jogador, char ordem)
{ //atualizacao necessaria para o ranking de teclas
	if(ordem == 'w'){
		jogador.movimentos[teclaW].Num_Colisoes +=1;
	}
	else if(ordem == 'd'){
		jogador.movimentos[teclaD].Num_Colisoes +=1;
	}
	else if(ordem == 's'){
		jogador.movimentos[teclaS].Num_Colisoes +=1;
	}
	else if(ordem == 'a'){
		jogador.movimentos[teclaA].Num_Colisoes +=1;
	}
	return jogador;
}
tPlayer_Pac_Man AtualizaNumComida(tPlayer_Pac_Man jogador, char ordem)
{ //atualizacao necessaria para o ranking de teclas
	if(ordem == 'w'){
		jogador.movimentos[teclaW].Num_Com +=1;
	}
	else if(ordem == 'd'){
		jogador.movimentos[teclaD].Num_Com +=1;
	}
	else if(ordem == 's'){
		jogador.movimentos[teclaS].Num_Com +=1;
	}
	else if(ordem == 'a'){
		jogador.movimentos[teclaA].Num_Com +=1;
	}
	return jogador;
}
tMapaPac AtualizaMapaAuxiliar(tMapaPac mapa, tPlayer_Pac_Man jogador, char ordem)
{ //Caso algum intem do mapa padrao seja retirado ao se movimentar, retira tambem do mapa auxiliar
	if(ordem == 'w'){
		mapa.mapaAuxiliar[jogador.CoordenadaY - 1][jogador.CoordenadaX] = ' ';
	}
	else if(ordem == 'd'){
		mapa.mapaAuxiliar[jogador.CoordenadaY][jogador.CoordenadaX + 1] = ' ';
	}
	else if(ordem == 's'){
		mapa.mapaAuxiliar[jogador.CoordenadaY + 1][jogador.CoordenadaX] = ' ';
	}
	else if(ordem == 'a'){
		mapa.mapaAuxiliar[jogador.CoordenadaY][jogador.CoordenadaX - 1] = ' ';
	}
	return mapa;
}
tJogo JogarPartida(tJogo jogo, char ordem, FILE *Resumo)
{ //literalmente a partida sera jogada aqui e tudo que for necessario para que ela ocorra, esta aqui.
	jogo = InicializaFantasma(jogo);
	if(ordem != 'w' && ordem != 'a' && ordem != 's' && ordem != 'd')
	{
		printf("TECLA ERRADOA");
		return jogo;
	}
	if(ExisteFantasma(jogo.mapa,jogo.fantasmas[GhostB])) //se existe o fantasma, entao fara os seus movimentos no mapa
	{
		if(jogo.fantasmas[GhostB].FlagDirecao == -1) 
		{
			if(jogo.mapa.mapa_PM[jogo.fantasmas[GhostB].CoordenadaY][jogo.fantasmas[GhostB].CoordenadaX - 1] == '#' ) //checa se o fanstama colidiu com a parede
			{
				jogo.fantasmas[GhostB].FlagDirecao = 1; // caso colida, atualiza a flag para indicar movimentacao em sentido contrario
			}
			else
			{
				jogo.mapa = MovimenteFantasmaEsquerda(jogo.mapa, jogo.fantasmas[GhostB]);
				jogo.fantasmas[GhostB] = AtualizaPosicaoEsquerda(jogo.fantasmas[GhostB]);
			}
		}

		if(jogo.fantasmas[GhostB].FlagDirecao == 1)
		{
			if(jogo.mapa.mapa_PM[jogo.fantasmas[GhostB].CoordenadaY][jogo.fantasmas[GhostB].CoordenadaX + 1] == '#' )
			{
				jogo.fantasmas[GhostB].FlagDirecao = -1;
				jogo.mapa = MovimenteFantasmaEsquerda(jogo.mapa, jogo.fantasmas[GhostB]);
				jogo.fantasmas[GhostB] = AtualizaPosicaoEsquerda(jogo.fantasmas[GhostB]);
			}
			else
			{
				jogo.mapa = MovimenteFantasmaDireita(jogo.mapa,jogo.fantasmas[GhostB]);
				jogo.fantasmas[GhostB] = AtualizaPosicaoDireita(jogo.fantasmas[GhostB]);
			}	
		}
	}

	if(ExisteFantasma(jogo.mapa,jogo.fantasmas[GhostP]))
	{
		if(jogo.fantasmas[GhostP].FlagDirecao == -1)
		{
			if(jogo.mapa.mapa_PM[jogo.fantasmas[GhostP].CoordenadaY + 1][jogo.fantasmas[GhostP].CoordenadaX] == '#' )
			{
				jogo.fantasmas[GhostP].FlagDirecao = 1;
			}
			else
			{
				jogo.mapa = MovimenteFantasmaBaixo(jogo.mapa, jogo.fantasmas[GhostP]);
				jogo.fantasmas[GhostP] = AtualizaPosicaoBaixo(jogo.fantasmas[GhostP]);
			}
		}
		
		if(jogo.fantasmas[GhostP].FlagDirecao == 1)
		{
			if(jogo.mapa.mapa_PM[jogo.fantasmas[GhostP].CoordenadaY - 1][jogo.fantasmas[GhostP].CoordenadaX] == '#' )
			{
				jogo.fantasmas[GhostP].FlagDirecao = -1;
				jogo.mapa = MovimenteFantasmaBaixo(jogo.mapa, jogo.fantasmas[GhostP]);
				jogo.fantasmas[GhostP] = AtualizaPosicaoBaixo(jogo.fantasmas[GhostP]);
			}
			else
			{
				jogo.mapa = MovimenteFantasmaCima(jogo.mapa,jogo.fantasmas[GhostP]);
				jogo.fantasmas[GhostP] = AtualizaPosicaoCima(jogo.fantasmas[GhostP]);
			}	
		}
	}

	if(ExisteFantasma(jogo.mapa,jogo.fantasmas[GhostI]))
	{
		if(jogo.fantasmas[GhostI].FlagDirecao == -1)
		{
			if(jogo.mapa.mapa_PM[jogo.fantasmas[GhostI].CoordenadaY + 1][jogo.fantasmas[GhostI].CoordenadaX] == '#' )
			{
				jogo.fantasmas[GhostI].FlagDirecao = 1;
			}
			else
			{
				jogo.mapa = MovimenteFantasmaBaixo(jogo.mapa, jogo.fantasmas[GhostI]);
				jogo.fantasmas[GhostI] = AtualizaPosicaoBaixo(jogo.fantasmas[GhostI]);
			}
		}
		
		if(jogo.fantasmas[GhostI].FlagDirecao == 1)
		{
			if(jogo.mapa.mapa_PM[jogo.fantasmas[GhostI].CoordenadaY - 1][jogo.fantasmas[GhostI].CoordenadaX] == '#' )
			{
				jogo.fantasmas[GhostI].FlagDirecao = -1;
				jogo.mapa = MovimenteFantasmaBaixo(jogo.mapa, jogo.fantasmas[GhostI]);
				jogo.fantasmas[GhostI] = AtualizaPosicaoBaixo(jogo.fantasmas[GhostI]);
			}
			else
			{
				jogo.mapa = MovimenteFantasmaCima(jogo.mapa,jogo.fantasmas[GhostI]);
				jogo.fantasmas[GhostI] = AtualizaPosicaoCima(jogo.fantasmas[GhostI]);
			}	
		}
	}

	if(ExisteFantasma(jogo.mapa,jogo.fantasmas[GhostC]))
	{
		if(jogo.fantasmas[GhostC].FlagDirecao == -1)
		{
			if(jogo.mapa.mapa_PM[jogo.fantasmas[GhostC].CoordenadaY][jogo.fantasmas[GhostC].CoordenadaX - 1] == '#' )
			{
				jogo.fantasmas[GhostC].FlagDirecao = 1;
			}
			else
			{
				jogo.mapa = MovimenteFantasmaEsquerda(jogo.mapa, jogo.fantasmas[GhostC]);
				jogo.fantasmas[GhostC] = AtualizaPosicaoEsquerda(jogo.fantasmas[GhostC]);
			}
		}

		if(jogo.fantasmas[GhostC].FlagDirecao == 1)
		{
			if(jogo.mapa.mapa_PM[jogo.fantasmas[GhostC].CoordenadaY][jogo.fantasmas[GhostC].CoordenadaX + 1] == '#' )
			{
				jogo.fantasmas[GhostC].FlagDirecao = -1;
				jogo.mapa = MovimenteFantasmaEsquerda(jogo.mapa, jogo.fantasmas[GhostC]);
				jogo.fantasmas[GhostC] = AtualizaPosicaoEsquerda(jogo.fantasmas[GhostC]);
			}
			else
			{
				jogo.mapa = MovimenteFantasmaDireita(jogo.mapa,jogo.fantasmas[GhostC]);
				jogo.fantasmas[GhostC] = AtualizaPosicaoDireita(jogo.fantasmas[GhostC]);
			}	
		}
	}
	jogo.jogador.Num_Movimentos += 1; //Num de vezes que o player clicou nas teclas W A S D, no geral
	jogo.jogador = AtualizaNumTecla(jogo.jogador,ordem); //Num de vezes que o player clicou nas teclas W A S D, em especifico
	if(VerificaHahSombra(jogo,ordem)) //Se apos o movimento do fantasma e um suposto movimento do player, ambos pisao na sombra do outro, e gameover
	{
		jogo.jogador.Flag_Perdeu = 10;//indica que o player perdeu
		ResumoGameFantasma(jogo.jogador,ordem,Resumo);
		jogo.jogador.Num_MovimSemPontos +=1; //Num de vezes que o player clicou nas teclas W A S D e nao obteve pontos, ou seja, nao comeu a comida
		return jogo;
	}
	
	if(VerificaHahComida(jogo.jogador,jogo.mapa,ordem)) //na posicao que o player for se movimentar, se la hah comida
	{
		jogo = ComidaPac(jogo,ordem,Resumo);
	}
	else if(VerificaHahParede(jogo.jogador,jogo.mapa,ordem)) //na posicao que o player for se movimentar, se la hah parede
	{
		jogo = ParedePac(jogo,ordem,Resumo);
	}
	else if(VerificaHahFantasma(jogo.jogador,jogo.mapa,ordem)) //na posicao que o player for se movimentar, se la hah fantasma
	{
		jogo = FantasmaPac(jogo,ordem,Resumo);
	}
	else //movimentacao padrao do player, sem modificar nada do jogo
	{
		jogo = NormalPac(jogo,ordem,Resumo); 
	}

	if(jogo.jogador.Flag_Perdeu == 10)
	{ //se o jogador perdeu, isso impede que o suposto movimento de gamer over seja preenchido no mapa de trilha
		return jogo;
	}
	jogo.mapa = PreencheTrilha(jogo.jogador, jogo.mapa); //mapa que indica em qual num de movimento o player ficou em tal local
	return jogo;
}
void GameOver(tPlayer_Pac_Man jogador)
{
	printf("Game over!\n");
	printf("Pontuacao final: %d", jogador.Num_Comidas);
}
void VenceuPartida(tPlayer_Pac_Man jogador)
{
	printf("Voce venceu!\n");
	printf("Pontuacao final: %d", jogador.Num_Comidas);
}
//demonstra ao player se ele venceu ou perdeu o game
void ResumoGameParede(tPlayer_Pac_Man jogador, char ordem, FILE *Resumo)
{
	fprintf(Resumo,"Movimento %d (%c) colidiu na parede\n", jogador.Num_Movimentos, ordem);
}
void ResumoGameComida(tPlayer_Pac_Man jogador, char ordem, FILE *Resumo)
{
	fprintf(Resumo,"Movimento %d (%c) pegou comida\n", jogador.Num_Movimentos, ordem);
}
void ResumoGameFantasma(tPlayer_Pac_Man jogador, char ordem, FILE *Resumo)
{
	fprintf(Resumo,"Movimento %d (%c) fim de jogo por encostar em um fantasma\n", jogador.Num_Movimentos, ordem);
}
// funcoes de atualizar o resumo da partida
void Estatistica(tPlayer_Pac_Man jogador, FILE *Estatisticah)
{ //faz a estatistica do jogo, falando do player
	fprintf(Estatisticah,"Numero de movimentos: %d\n",jogador.Num_Movimentos);
	fprintf(Estatisticah,"Numero de movimentos sem pontuar: %d\n",jogador.Num_MovimSemPontos);
	fprintf(Estatisticah,"Numero de colisoes com parede: %d\n", jogador.Num_Colisoes);
	fprintf(Estatisticah,"Numero de movimentos para baixo: %d\n", jogador.movimentos[teclaS].Num_Mov);
	fprintf(Estatisticah,"Numero de movimentos para cima: %d\n",jogador.movimentos[teclaW].Num_Mov);
	fprintf(Estatisticah,"Numero de movimentos para esquerda: %d\n",jogador.movimentos[teclaA].Num_Mov);
	fprintf(Estatisticah,"Numero de movimentos para direita: %d", jogador.movimentos[teclaD].Num_Mov);
}
tMapaPac PreencheTrilha(tPlayer_Pac_Man jogador, tMapaPac mapa)
{ 
	mapa.mapaTrilha[jogador.CoordenadaY][jogador.CoordenadaX] = jogador.Num_Movimentos;
	return mapa;
}
void ImprimeTrilha(tMapaPac mapa,tPlayer_Pac_Man jogador, FILE *trilha)
{ //faz a trilha, aonde o player percorreu e em qual movimento
	int i, j;
		
	for(i = 0; i < mapa.linhas; i++)
	{
		for(j = 0; j < mapa.colunas; j++)
		{
			if(mapa.mapaTrilha[i][j] == -1)
			{
				fprintf(trilha,"# ");
			}
			else
			{						
			fprintf(trilha,"%d ", mapa.mapaTrilha[i][j]);
			}
		}
	fprintf(trilha,"\n");
	}	
}
tPlayer_Pac_Man MoveTeclas(tPlayer_Pac_Man jogador, int i, int j)
{ //funcao para reorganizar o vetor de teclas, que esta na struct do tplayer
	tTeclas_Mov teclas;

	teclas = jogador.movimentos[i];
	jogador.movimentos[i] = jogador.movimentos[j];
	jogador.movimentos[j] = teclas;

	return jogador;
}
tPlayer_Pac_Man OrganizaTeclas(tPlayer_Pac_Man jogador)
{ //organiza o vetor de teclas, para elaborar o ranking, de acordo com alguns requisitos
	int i, j;
	tTeclas_Mov teclas;

	for(i = 0; i < 3; i++)
	{
		for(j = i + 1; j < 4; j++)
		{
			if(jogador.movimentos[j].Num_Com > jogador.movimentos[i].Num_Com)
			{
				jogador = MoveTeclas(jogador,i,j);
			}
			else if(jogador.movimentos[i].Num_Com == jogador.movimentos[j].Num_Com)
			{
				if(jogador.movimentos[j].Num_Colisoes < jogador.movimentos[i].Num_Colisoes)
				{
					jogador = MoveTeclas(jogador,i,j);
				}
				else if(jogador.movimentos[i].Num_Colisoes == jogador.movimentos[j].Num_Colisoes)
				{
					if(jogador.movimentos[j].Num_Mov > jogador.movimentos[i].Num_Mov)
					{
						jogador = MoveTeclas(jogador,i,j);
					}
					else if(jogador.movimentos[j].Num_Mov == jogador.movimentos[i].Num_Mov)
					{
						if(jogador.movimentos[j].tecla < jogador.movimentos[i].tecla)
						{
							jogador = MoveTeclas(jogador,i,j);
						}
					}
				}
			}
		}
	}
	return jogador;
}
void ImprimeRanking(tPlayer_Pac_Man jogador, FILE *ranking)
{ //apos reorganizar, imprime o ranking em ordem decrescente
	fprintf(ranking,"%c,%d,%d,%d\n", jogador.movimentos[0].tecla, jogador.movimentos[0].Num_Com, jogador.movimentos[0].Num_Colisoes, jogador.movimentos[0].Num_Mov);
	fprintf(ranking,"%c,%d,%d,%d\n", jogador.movimentos[1].tecla, jogador.movimentos[1].Num_Com, jogador.movimentos[1].Num_Colisoes, jogador.movimentos[1].Num_Mov);
	fprintf(ranking,"%c,%d,%d,%d\n", jogador.movimentos[2].tecla, jogador.movimentos[2].Num_Com, jogador.movimentos[2].Num_Colisoes, jogador.movimentos[2].Num_Mov);
	fprintf(ranking,"%c,%d,%d,%d", jogador.movimentos[3].tecla, jogador.movimentos[3].Num_Com, jogador.movimentos[3].Num_Colisoes, jogador.movimentos[3].Num_Mov);
}
tJogo FinalizaGame(tJogo jogo, FILE *saida, FILE *resumo, FILE *trilha, FILE *mapa, FILE *Estatisticah, FILE *ranking)
{ //funcao necessaria e engloba tudo que sera feito apos acabar o jogo
	Estatistica(jogo.jogador, Estatisticah);
	ImprimeTrilha(jogo.mapa,jogo.jogador,trilha);
	jogo.jogador=OrganizaTeclas(jogo.jogador);
	ImprimeRanking(jogo.jogador,ranking);		
	fclose(resumo);
	fclose(saida);
	fclose(mapa);
	fclose(Estatisticah);
	fclose(trilha);
	fclose(ranking);
	return jogo;
}


						
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
