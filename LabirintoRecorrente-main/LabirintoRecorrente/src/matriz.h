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

void printMatriz(readMatriz*matriz);

#endif
