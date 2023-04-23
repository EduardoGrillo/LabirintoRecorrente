#include "moveMenino.h"
#include "readFile.h"

int main(){
    infoMenino jogador;
    readMatriz matriz;
    copiaCheckpoint copia;

    jogador.vida = 10;
    jogador.sacola = 0;
    jogador.item = 0;
    jogador.perigo = 0;
    jogador.status = 1;

    tamanho(&matriz.linha, &matriz.coluna, &matriz.q);
    
    copia.linha = matriz.linha;
    copia.coluna = matriz.coluna;
    copia.q = matriz.q;

    jogador.q = matriz.q;
    
    matriz.mat = (int**)malloc(sizeof(int*) * matriz.linha); //alocando as linhas da matriz
    copia.mat = (int**)malloc(sizeof(int*) * copia.linha); //alocando as linhas da matriz
    
    for(int i = 0; i < matriz.linha; i++){
        matriz.mat[i] = (int*)malloc(sizeof(int) * matriz.coluna);
        copia.mat[i] = (int*)malloc(sizeof(int) * copia.coluna);
    }

    leitura(&matriz, matriz.linha, &copia);
    
    matriz.matrizAtual = 1; 
    copia.matrizAtual = 1;   
    
    Move(&matriz, &jogador, &copia);
    relatorio(&jogador);
    
    return 0;
}
