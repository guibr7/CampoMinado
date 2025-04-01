#include <stdio.h>
#include "funcoes.h"
#include "cores.h"
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void ExibirTabuleiro(int **matriz, char **matrizStatus, int lin, int col, int selectLin , int selectCol);
void preencherMatriz(ClasseJogador *player,int **matriz, char **matrizStatus, int l, int c);

void estruturaJogo(ClasseJogador *player){

    int lin,col,**matriz; char **matrizStatus;

    lin = player->lin;
    col = player->col;


    matriz = malloc(lin * sizeof(int *)); //Cria Matriz Principal
    for(int i = 0; i < lin; i++){
        matriz[i] = malloc(col * sizeof(int));
    }for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            matriz[i][j] = 0;
        }
    }

    matrizStatus = malloc(lin * sizeof(int *)); //Cria MatrizStatus
    for(int i = 0; i < lin; i++){
        matrizStatus[i] = malloc(col * sizeof(int));
    }for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            matrizStatus[i][j] = 'F';  
        }
    }

    preencherMatriz(player,matriz,matrizStatus,lin,col);
    ExibirTabuleiro(matriz, matrizStatus, lin, col,0,0);


//---------------LEITURA DE COMANDOS DURANTE PARTIDA------------------------------//
    char comando[20]; int x = 0 ; int cmdLin,cmdCol; 
    do{ 
        printf("Comando: ");
        scanf("%s",comando); 
        //printf("%s",comando);

        for (int i = 0; comando[i]; i++) {  // Converte caractere para minúscula
            comando[i] = tolower(comando[i]);   
        }

        if (strcmp(comando, "desistir") == 0) { 
            printf("\nDesistiu!");
        }else if(strcmp(comando,"voltar") == 0){
            printf("\nVoltou!");
        }
        
        if(isdigit(comando[0])){ //Se a primeira entrada for um numero
            cmdLin = atoi(comando);
            
            scanf("%d", &cmdCol);
            //Abrir celular
            if((cmdLin >= 0  && cmdLin <=lin) && (cmdCol >= 0  && cmdCol <=col)){ 
                matrizStatus[cmdLin][cmdCol] = 'A';
                system("clear");
                ExibirTabuleiro(matriz, matrizStatus, lin, col,cmdLin,cmdCol);
                //printf("\nAbrir posição: %c",  matrizStatus[cmdLin][cmdCol]);
            }else{
                printf("Posição inexistente\n");
            }
        } 
        else if(isalpha(comando[0])){ //Se a primeira entrada for uma letra
            scanf("%d%d", &cmdLin,&cmdCol); 
            if((cmdLin >= 0  && cmdLin <=lin) && (cmdCol >= 0  && cmdCol <=col)){ 
                switch (comando[0])
                {
                    case 'm':
                        printf("\nmarcar posição: Linha %d, Coluna %d\n", cmdLin, cmdCol);
                        
                    break;
                    case 'd':
                        
                        printf("\nDesmarcar posição: Linha %d, Coluna %d\n", cmdLin, cmdCol);
                        
                    break;
                    
                    default:
                        printf("Comando inválido.\n");
                    break;
                }
            }else{
                printf("Posição inexistente ou comando inválido\n");
            }
        }
    }while(x == 0);
    
    for(int i = 0; i < lin; i++){
        free(matriz[i]);
        free(matrizStatus[i]);
    }
    free(matriz);
    free(matrizStatus);
};

void ExibirTabuleiro(int **matriz, char **matrizStatus, int lin, int col, int selectLin , int selectCol){
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
        int r;
        for (int j = 0; j < col; j++) {
            r = (i + j) % 2;
            if ( r == 0) {
               if(matrizStatus[i][j] == 'F'){ 
                    printf(BG_LIGHT_GRAY "   " RESET); // Cinza claro
                }else if( matrizStatus[i][j] == 'A'){ 
                    if(matriz[i][j] == 99){ 
                    printf(BG_RED(BLACK_BRIGHT(" ✹ ")) RESET);
                    }else{
                        printf(BG_BLUE( "   " )RESET);
                    }
                }

            } else {
                if(matrizStatus[i][j] == 'F'){ 
                    printf(BG_DARK_GRAY"   " RESET); // Cinza escuro
                }else if( matrizStatus[i][j] == 'A'){ 
                    if(matriz[i][j] == 99){ 
                    printf(BG_RED(BLACK_BRIGHT(" ✹ ")) RESET);
                    }else{
                        printf(BG_BLUE( "   " )RESET);
                    }
                }

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
void preencherMatriz(ClasseJogador *player,int **matriz, char **matrizStatus, int l, int c){
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            matriz[i][j] = 0;
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            matrizStatus[i][j] = 'F'; 
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            matrizStatus[i][j] = 'F'; 
        }
    }
    srand(time(NULL)); 
    int linRandom,colRandom;
    for(int i = 0; i < player->numBomb;i++){ //Inserir bombas aleatoriamente
        do{ 
            linRandom = rand()% l;
            colRandom = rand()%c;
        }while(matriz[linRandom][colRandom] == 99);
        matriz[linRandom][colRandom] = 99;
    }
}