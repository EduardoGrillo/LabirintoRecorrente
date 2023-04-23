#ifndef _MATRIZ_H
#define _MATRIZ_H

#include <stdio.h>

typedef struct readMatriz readMatriz;

struct readMatriz{
    int linha, coluna;
    int q; //letra q representa quantidade
    int **mat;
    int matrizAtual;
};

typedef struct copiaCheckpoint copiaCheckpoint;

struct copiaCheckpoint{
    int linha, coluna;
    int q; //letra q representa quantidade
    int **mat;
    int matrizAtual;
};

void printMatriz(readMatriz*matriz, int x, int y);

#endif
