#include <stdio.h>
#include "funcoes.h"
#include "cores.h"
#include <time.h>
#include <stdlib.h>
void estruturaJogo(ClasseJogador *player){
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    int lin,col,**matriz;
    lin = player->lin;
    col = player->col;
   
    matriz = malloc(lin * sizeof(int *)); //Inicializa matriz dinamica
    for(int i = 0; i < lin; i++){
        matriz[i] = malloc(col * sizeof(int));
    }
    
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            matriz[i][j] = 0;
        }
    }

    
    printf("\n");

    //Cordenada coluna
    printf("   ");
    for(int c = 1; c <= col ; c++){
        printf(" %1d",c);
    }
    printf("\n");
    printf("  "); 
    printf("%s",TAB_TL);
    for(int c = 1; c <= col*4 ; c++){
        printf("%s",TAB_HOR);
    }
    printf("\n"); //Fim Cordenada Coluna
    for (int i = 0; i < lin; i++) {
        printf("%2d", i+1);
        printf("%2s",TAB_VER);
        printf(" ");
        
        for (int j = 0; j < col; j++) {
            // Alterna entre cinza escuro e cinza claro
       
            if ((i + j) % 2 == 0) {
                printf(BG_LIGHT_GRAY " %1d " RESET, matriz[i][j]); // Cinza claro
            } else {
                printf(BG_DARK_GRAY " %1d " RESET, matriz[i][j]); // Cinza escuro
            }
        }
        printf("\n"); // Nova linha para o próximo "andar" do tabuleiro
    }
    printf("\n");

};