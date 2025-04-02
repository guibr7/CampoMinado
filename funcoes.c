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

    matrizStatus = malloc(lin * sizeof(char *)); //Cria MatrizStatus
    for(int i = 0; i < lin; i++){
        matrizStatus[i] = malloc(col * sizeof(char));
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
                if(matrizStatus[cmdLin][cmdCol] == 'F' || matrizStatus[cmdLin][cmdCol] == 'B'){ 
                    matrizStatus[cmdLin][cmdCol] = 'A';
                    system("clear");
                    ExibirTabuleiro(matriz, matrizStatus, lin, col,cmdLin,cmdCol);
                    //printf("\nAbrir posição: %c",  matrizStatus[cmdLin][cmdCol]);
                }else{
                    system("clear");
                    ExibirTabuleiro(matriz, matrizStatus, lin, col,cmdLin,cmdCol);
                    printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" Posição já aberta!\n"))) ANSI_RESET);
                }
            }else{
                printf("Posição inexistente\n");
            }
        } 
        else if(isalpha(comando[0])){ //Se a primeira entrada for uma letra
            scanf("%d%d", &cmdLin,&cmdCol); 
            limparBuffer();
            if((cmdLin >= 0  && cmdLin <=lin) && (cmdCol >= 0  && cmdCol <=col)){ 
                switch (comando[0])
                {
                    case 'm':
                    if(matrizStatus[cmdLin][cmdCol] == 'F'){ 
                        matrizStatus[cmdLin][cmdCol] = 'B';
                        system("clear");
                        ExibirTabuleiro(matriz, matrizStatus, lin, col,cmdLin,cmdCol);
                    }else if(matrizStatus[cmdLin][cmdCol] == 'A'){
                        system("clear");
                        ExibirTabuleiro(matriz, matrizStatus, lin, col,cmdLin,cmdCol);
                        printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" Não é possível marcar uma posição já aberta!   \n"))) ANSI_RESET);
                    }else{
                        system("clear");
                        ExibirTabuleiro(matriz, matrizStatus, lin, col,cmdLin,cmdCol);
                        printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" Posição já marcada.\n"))) ANSI_RESET);
                    }
                    break;
                    case 'd':
                        if(matrizStatus[cmdLin][cmdCol] == 'B'){
                            matrizStatus[cmdLin][cmdCol] = 'F';
                            system("clear");
                            ExibirTabuleiro(matriz, matrizStatus, lin, col,cmdLin,cmdCol);
                        }else{
                            system("clear");
                            ExibirTabuleiro(matriz, matrizStatus, lin, col,cmdLin,cmdCol);
                            printf(BG_WHITE_BRIGHT(BLACK_BRIGHT(BOLD(" Não é possível desmarcar uma posição não marcada!   \n"))) ANSI_RESET);
                        }
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

    /*for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            matrizStatus[i][j] = 'F'; 
        }
    }*/

/*---------------- INSERIR BOMBAS ------------------*/
    srand(time(NULL)); 
    int linRandom,colRandom;
    for(int i = 0; i < player->numBomb;i++){ //Inserir bombas aleatoriamente
        do{ 
            linRandom = rand()% l;
            colRandom = rand()%c;
        }while(matriz[linRandom][colRandom] == 99);
        matriz[linRandom][colRandom] = 99;
    }
/*-----------------BOMBAS ADJACENTES ------------------*/
    int bombas;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(matriz[i][j] == 99){
                continue;
            }else{ 
                bombas = 0;
                if (i > 0 && matriz[i-1][j] == 99) bombas++;
                if (i < l-1 && matriz[i+1][j] == 99) bombas++;
                if (j > 0 && matriz[i][j-1] == 99) bombas++;
                if (j < c-1 && matriz[i][j+1] == 99) bombas++;
                if (i > 0 && j > 0 && matriz[i-1][j-1] == 99) bombas++;
                if (i > 0 && j < c-1 && matriz[i-1][j+1] == 99) bombas++;
                if (i < l-1 && j > 0 && matriz[i+1][j-1] == 99) bombas++;
                if (i < l-1 && j < c-1 && matriz[i+1][j+1] == 99) bombas++;
            }
            matriz[i][j] = bombas;
        }
     
    }
}

void ExibirTabuleiro(int **matriz, char **matrizStatus, int lin, int col, int selectLin , int selectCo){

   

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
                        }else if(!matriz[i][j]){ 
                            printf(BG_GRAY "   " RESET);
                        }else{ 
                            printf(BG_LIGHT_GRAY BOLD(" %d " )RESET, matriz[i][j]);
                        }
                    }else if(matrizStatus[i][j] == 'B'){
                        printf(BG_GREEN(" ⚑ ") RESET); // Cinza claro
                    }
    
                } else {
                    if(matrizStatus[i][j] == 'F'){ 
                        printf(BG_DARK_GRAY"   " RESET); // Cinza escuro
                    }else if( matrizStatus[i][j] == 'A'){ 
                        if(matriz[i][j] == 99){ 
                        printf(BG_RED(BLACK_BRIGHT(" ✹ ")) RESET);
                        }else if(!matriz[i][j]){
                            printf(BG_GRAY "   " RESET);
                        }else{
                            printf(BG_DARK_GRAY BOLD(WHITE_BRIGHT(" %d " ))RESET, matriz[i][j]);
                            
                        }
                    }else if(matrizStatus[i][j] == 'B'){
                        printf(BG_GREEN(" ⚑ ") RESET); // Cinza claro
                    }
    
                }
            }
            printf("\n"); // Nova linha para o próximo "andar" do tabuleiro
        }
        printf("\n");
    }