#include "moveMenino.h"
#include "readFile.h"

int main(){
    infoMenino jogador;
    readMatriz matriz;

    jogador.vida = 10;
    jogador.sacola = 0;
    jogador.item = 0;

    tamanho(&matriz.linha, &matriz.coluna, &matriz.q);
    jogador.q = matriz.q;
    
    printf("valores: %d, %d, %d\n", matriz.linha, matriz.coluna, matriz.q);

    matriz.mat = (int**)malloc(sizeof(int*) * matriz.linha); //alocando as linhas da matriz
    
    for(int i = 0; i < matriz.linha; i++){
        matriz.mat[i] = (int*)malloc(sizeof(int) * matriz.coluna);
    }

    leitura(&matriz, matriz.linha);
    printMatriz(&matriz);

    matriz.matrizAtual = 1;    
    
    Move(&matriz, &jogador);
    
    printf("\n");

    printf("Vida do menino: %d\n", jogador.vida);
    printf("Itens coletados: %d\n", jogador.item);

    printf("quantidade: %d\n", jogador.q);

    return 0;
}