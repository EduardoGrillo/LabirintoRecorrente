#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct readMatriz readMatriz;

struct readMatriz{
    int linha, coluna;
    int q; //letra q representa quantidade
    int **mat;
    int matrizAtual;
};



#endif
