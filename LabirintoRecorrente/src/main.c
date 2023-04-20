#include "moveMenino.h"
#include "readFile.h"

int main(){
    infoMenino jogador;
    readMatriz matriz;

    tamanho(&matriz.linha, &matriz.coluna, &matriz.q);
    printf("valores: %d, %d, %d\n", matriz.linha, matriz.coluna, matriz.q);

    matriz.mat = (int**)malloc(sizeof(int*) * matriz.linha); //alocando as linhas da matriz
    
    for(int i = 0; i < matriz.linha; i++){
        matriz.mat[i] = (int*)malloc(sizeof(int) * matriz.coluna);
    }

    leitura(&matriz, matriz.linha);
    printMatriz(&matriz);


    return 0;
}