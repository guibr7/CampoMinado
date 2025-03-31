#include <stdio.h>
#include "funcoes.h"
#include "cores.h"
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void tabuleiroVazio(int lin, int col);
void estruturaJogo(ClasseJogador *player){

    int lin,col,**matriz; char **matrizStatus;

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

    //--------------------------------------------------//
    matrizStatus = malloc(lin * sizeof(int *)); //Matriz Status
    for(int i = 0; i < lin; i++){
        matrizStatus[i] = malloc(col * sizeof(int));
    }
    
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            matrizStatus[i][j] = 'f';  
        }
    }

    matrizStatus[3][5] = 'a';
    printf("\n");
    tabuleiroVazio(lin,col);

    char comando[20]; int x = 0 ;  int cmdLin,cmdCol; 

    do{ 
        printf("\nComando: ");
        scanf("%s",comando); // 12 45 70 28 5
        //printf("%s",comando);

        for (int i = 0; comando[i]; i++) {  // Converte caractere para minúscula
            comando[i] = tolower(comando[i]);   
        }

        if (strcmp(comando, "desistir") == 0) {  // Ignora maiúsculas e minúsculas
            printf("\nDesistiu!");
        }else if(strcmp(comando,"voltar") == 0){
            printf("\nVoltou!");
        }
        
        if(isdigit(comando[0])){ //Se a primeira entrada for um numero
            cmdLin = atoi(comando);
            
            scanf("%d", &cmdCol);
            if((cmdLin >= 0  && cmdLin <=lin) && (cmdCol >= 0  && cmdCol <=col)){ 
                printf("\nAbrir posição: Linha %d, Coluna %d", cmdLin, cmdCol);
                
            }else{
                printf("nao existe estas cordenadas");
            }
        } 
        else if(isalpha(comando[0])){ //Se a primeira entrada for uma letra
            switch (comando[0])
            {
                case 'm':
                    scanf("%d%d", &cmdLin,&cmdCol);
                    printf("\nmarcar posição: Linha %d, Coluna %d\n", cmdLin, cmdCol);
                    
                break;
                case 'd':
                    scanf("%d %d", &cmdLin, &cmdCol);
                    printf("\nDesmarcar posição: Linha %d, Coluna %d\n", cmdLin, cmdCol);
                    
                break;
                
                default:
                break;
            }
        }
    }while(x == 0);
        
    //printf("\nAção inválida ou posição inexistente. Tente novamente.");
    
    for(int i = 0; i < lin; i++){
        free(matriz[i]);
        free(matrizStatus[i]);
    }
    free(matriz);
    free(matrizStatus);
};



void tabuleiroVazio(int lin, int col){
//Cordenada coluna
    printf("    ");
    for(int c = 0; c < col ; c++){
        printf("%2d ",c);
    }
    printf("\n");
    printf("  "); 
    printf("%s",TAB_TL);
    for(int c = 0; c < col*3 ; c++){
        printf("%s",TAB_HOR);
    }
    printf("\n"); //Fim Cordenada Coluna
    for (int i = 0; i < lin; i++) {
        printf("%2d", i);
        printf("%2s",TAB_VER);
        printf(" ");
        
        for (int j = 0; j < col; j++) {
            // Alterna entre cinza escuro e cinza claro
            if ((i + j) % 2 == 0) {
                printf(BG_LIGHT_GRAY "   " RESET); // Cinza claro
            } else {
                printf(BG_DARK_GRAY "   " RESET); // Cinza escuro
            }
        }
        printf("\n"); // Nova linha para o próximo "andar" do tabuleiro
    }
    printf("\n");
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}