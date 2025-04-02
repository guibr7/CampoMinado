#include <stdio.h>
#include <limits.h>
#include "StrctJogador.h"
#include <stdlib.h>
#include <ctype.h>

#include "cores.h"
#include "funcoes.h"

void menu();
void ModoJogo(ClasseJogador *player);
void InserirNome(ClasseJogador *player);
void ajuda();
int main() { 
    int opcao = -1;
    do{
        menu();
        scanf("%d", &opcao);
        limparBuffer();
        switch (opcao) {
            case 0:
                break;
            case 1: { //Novo jogo
                ClasseJogador jogador;
                InserirNome(&jogador);
                ModoJogo(&jogador);
                system("clear");
                estruturaJogo(&jogador);
                opcao = 0;
                break;
            }
            case 2: //Jogo personalizado
                ClasseJogador jogador;
                InserirNome(&jogador);
                printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" Digite as dimensões do tabuleiro <lin> <col> <Quantidade de minas> respectivamente: \n"))) ANSI_RESET);
                scanf("%d%d%d",&jogador.col,&jogador.lin,&jogador.numBomb);
                estruturaJogo(&jogador);
                opcao = 0;
            break;
            case 7: //Ajuda
            system("clear");
                ajuda();
            break;
            default:
                printf("\x1B[1J");
                system("clear");
                printf("\033[1;31m[ERRO]\033[0m Número inválido! Por favor, tente novamente.");
            break;
        }
        printf("\n");
    }while(opcao != 0);
    return 0;
}
void InserirNome(ClasseJogador *player){
    size_t tamBuffer = 0;
    __ssize_t numCaracteres = 0;
    do {
        player->nome = NULL;
        printf(" Digite seu nome: ");
        numCaracteres = getline(&player->nome, &tamBuffer, stdin);
        if (numCaracteres == -1 || numCaracteres == 1) { // Erro na leitura ou sem nome
            numCaracteres = 0;
            printf("Nenhum nome foi digitado. Digite novamente:\n");
            free(player->nome); 
            tamBuffer = 0; // Reinicia o buffer
        } else {
            if (player->nome[numCaracteres - 1] == '\n') {
                player->nome[numCaracteres - 1] = '\0'; 
            } 
        }
    } while (!numCaracteres);
}
void ModoJogo(ClasseJogador *player) {
    int x = -1;
    char temp;
    do{
        printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD("          ESCOLHA A DIFICULDADE:           \n"))) ANSI_RESET);
        printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" ("))) BG_WHITE_BRIGHT(BLUE(BOLD("F"))) BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(") FÁCIL   | 10 MINAS                    \n"))) ANSI_RESET);
        printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" ("))) BG_WHITE_BRIGHT("\x1b[38;5;208m" BOLD("M") ANSI_RESET) BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(") MÉDIO   | 25 MINAS                    \n"))) ANSI_RESET);
        printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" ("))) BG_WHITE_BRIGHT(RED(BOLD("D"))) BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(") DIFÍCIL | 45 MINAS                    \n"))) ANSI_RESET);
        printf(" DIGITE A LETRA CORRESPONDENTE: ");
        scanf("%c",&temp);
        limparBuffer();
        player->modo = tolower(temp);
        switch (player->modo)
        {
        case 'f':
            x = 0;
            player->tamTabu = 9;
            player->col = 9;
            player->lin = 9;
            player->numBomb = 10;
        break;
        case 'm':
            x = 0;
            player->tamTabu = 15;
            player->col = 15;
            player->lin = 15;
            player->numBomb = 25;
        break;
        case 'd':
            x = 0;
            player->tamTabu = 20;
            player->col = 20;
            player->lin = 20;
            player->numBomb = 45;
        break;     
        default:
            printf("\033[1;31m[ERRO]\033[0m Modo inválido! Por favor, tente novamente.\n");
        
        break;
        }
    }while(x != 0);
}
void menu(){
    //printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD("  "))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD("    #### BEM VINDO AO "))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(RED(BOLD(" CAMPO MINADO")))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" ####   " "\n"))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" 1 ⮞  NOVO JOGO PADRÃO                     ""\n"))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" 2 ⮞  NOVO JOGO PERSONALIZADO              ""\n"))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" 3 ⮞  VOLTAR PARA O JOGO ATUAL             ""\n"))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" 4 ⮞  CARREGAR UM JOGO SALVO               ""\n"))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" 5 ⮞  SALVAR O JOGO ATUAL                 "" \n"))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" 6 ⮞  RANKING                              \n"))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" 7 ⮞  AJUDA                                \n"))) ANSI_RESET);
    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(RED(BOLD(" 0 ⮞  SAIR                                 \n")))) ANSI_RESET);
    printf(" Digite o número da opção escolhida: ");
}
void ajuda(){
    printf("\n");
    printf(BOLD(" COMO JOGAR - CAMPO MINADO "));
    printf("\n\n");
    printf(BOLD(" O objetivo do jogo é revelar todas as posições que não contêm bombas, sem explodir nenhuma delas. "));
    printf("\n");
    printf(BOLD(" O tabuleiro contém números que indicam quantas bombas estão nas posições adjacentes. "));
    printf("\n");
    printf(BOLD(" Use sua lógica para deduzir onde estão as bombas e marque-as com bandeiras! "));
    printf("\n\n");

    printf(BOLD(" COMANDOS DO JOGO: "));
    printf("\n\n");
    printf(BOLD(" <lin col>: Posição linha e coluna que deseja abrir."));
    printf("\n");
    printf(BOLD(" m <lin col>: Marcar a posição linha e coluna com uma bandeira."));
    printf("\n");
    printf(BOLD(" d <lin col>: Desmarcar a posição linha e coluna previamente marcada com uma bandeira."));
    printf("\n\n");
    printf(BOLD(" desistir: Mostra o jogo com todas as posições abertas. Com este comando o jogador não pode continuar a jogar e só pode voltar ao menu inicial."));
    printf("\n");
    printf(BOLD(" voltar: Volta para o menu inicial."));
    printf("\n");
}    