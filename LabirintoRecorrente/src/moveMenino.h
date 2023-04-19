#ifndef _MOVEMENINO_H
#define _MOVEMENINO_H

#include "menino.h"
#include "matriz.h"

#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void Move(readMatriz*matriz, infoMenino*menino);
void Movimentar(int *x, int *y, int posicao, int *teleporte, int linha, int coluna);

#endif

