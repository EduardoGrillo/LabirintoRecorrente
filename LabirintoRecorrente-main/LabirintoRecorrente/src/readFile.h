#ifndef _READFILE_H
#define _READFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matriz.h"

#define MAX 100

void checkpoint(readMatriz *matriz);
void leitura(readMatriz *matriz, int t);
void readCheckpoint(readMatriz *matriz);
void tamanho(int *linha, int *coluna, int *total);

#endif