#ifndef _READFILE_H
#define _READFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matriz.h"
#include "menino.h"

#define MAX 100

void checkpoint(readMatriz *matriz);
void leitura(readMatriz *matriz, int t, copiaCheckpoint *copia);
void readCheckpoint(readMatriz *matriz);
void tamanho(int *linha, int *coluna, int *total);
void output(int x, int y, readMatriz*matriz);
void relatorio(infoMenino*menino);
void fazCopia(copiaCheckpoint *matriz);
void readMatrizPercorrida(int *caminhoPercorrido, int *caminhoNaoPercorrido, int quantMatriz);
void readCopiaCheckpoint(copiaCheckpoint *matriz);

#endif