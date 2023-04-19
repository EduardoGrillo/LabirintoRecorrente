#include "moveMenino.h"
#include "readFile.h"

int main(){
    infoMenino jogador;
    readMatriz matriz;

    tamanho(&matriz.linha, &matriz.coluna, &matriz.q);

    matriz.mat = (int**)malloc(sizeof(int*) * matriz.linha); //alocando as linhas da matriz
    
    for(int i = 0; i < matriz.linha; i++){
        matriz.mat[i] = (int*)malloc(sizeof(int) * matriz.coluna);
    }

    leitura(matriz.mat, 0);


    return 0;
}