#ifndef STRCTJOGADOR_H  // Se STRCTJOGADOR_H não estiver definido
#define STRCTJOGADOR_H  // Define STRCTJOGADOR_H para evitar múltiplas inclusões

typedef struct {
    char *nome;
    char modo;
    int tamTabu;
    int numBomb;
    float tempo;
} ClasseJogador;

#endif  // Fecha a proteção
