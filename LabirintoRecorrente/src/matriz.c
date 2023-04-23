#include "matriz.h"

void printMatriz(readMatriz*matriz, int x, int y){
    printf("matriz atual: %d\n", matriz->matrizAtual);
    printf("coordenadas: [%d] x [%d]\n", x, y);

    for(int i = 0; i <  matriz->linha; i++){
        for(int j = 0; j <  matriz->coluna; j++){
            if(i == x && i == j){
                printf(" @ ");
            }
            else if(matriz->mat[i][j] == -1) {
                printf(" # ");
            } else if(matriz->mat[i][j] == -2) {
                printf(" * ");
            }else {
                printf("%2d ", matriz->mat[i][j]);
            }
        }
        printf("\n");
    }
}