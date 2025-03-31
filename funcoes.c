#include <stdio.h>
#include "funcoes.h"
#include "cores.h"
#include <time.h>
#include <stdlib.h>
void estruturaJogo(){
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int matriz[8][8];

    // Preenche a matriz com números aleatórios de 1 a 99
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matriz[i][j] = rand() % 100;
        }
    }

    // Imprime o tabuleiro com tons reais de cinza
    printf("\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Alterna entre cinza escuro e cinza claro
            if ((i + j) % 2 == 0) {
                printf(BG_LIGHT_GRAY " %2d " RESET, matriz[i][j]); // Cinza claro
            } else {
                printf(BG_DARK_GRAY " %2d " RESET, matriz[i][j]); // Cinza escuro
            }
        }
        printf("\n"); // Nova linha para o próximo "andar" do tabuleiro
    }
    printf("\n");

};