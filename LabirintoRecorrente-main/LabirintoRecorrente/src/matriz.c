#include "matriz.h"

void printMatriz(readMatriz*matriz){
    for(int i = 0; i <  matriz->linha; i++){
        for(int j = 0; j <  matriz->coluna; j++){
            if(matriz->mat[i][j] == -1) {
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