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

int main() { 
    int opcao = -1;
    do{
        menu();
        scanf("%d", &opcao);
        limparBuffer();
        switch (opcao) {
            case 0:
                break;
            case 1: {
                ClasseJogador jogador;
                //InserirNome(&jogador);
                ModoJogo(&jogador);
                system("clear");
                estruturaJogo(&jogador);
                //printf("Nome digitado: %s\n", jogador.nome);
                opcao = 0;
                break;
            }
            case 2:
                ClasseJogador jogador;
                InserirNome(&jogador);
            break;
            default:
                printf("\033[1;31m[ERRO]\033[0m Número inválido! Por favor, tente novamente.\n");
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
    } while (numCaracteres == 0);
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
            player->numMina = 10;
        break;
        case 'm':
            x = 0;
            player->tamTabu = 15;
            player->col = 15;
            player->lin = 15;
            player->numMina = 25;
        break;
        case 'd':
            x = 0;
            player->tamTabu = 20;
            player->col = 20;
            player->lin = 20;
            player->numMina = 45;
        break;
            
        default:
            printf("\033[1;31m[ERRO]\033[0m Modo inválido! Por favor, tente novamente.\n");
        
        break;
        }
    }while(x != 0);
    //printf("Mode %c\n",player->modo);
    printf("col %d",player->col);
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