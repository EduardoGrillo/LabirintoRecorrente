#include "moveMenino.h"

void Move(readMatriz*matriz, infoMenino*menino){
    srand(time(NULL));
    
    int posicao;
    int teleporte = 0;
    
    int x_atual = 0;
    int y_atual = 0; 

    int x_aux;
    int y_aux;

    while(true){
        //printf("matriz atual: %d\n", matriz->matrizAtual);
        posicao = 1+rand() % 8;
        
        //printf("Matriz Atual: %d\n", matriz->matrizAtual);

        x_aux = x_atual;
        y_aux = y_atual;

        Movimentar(&x_atual, &y_atual, posicao, &teleporte, matriz->linha, matriz->coluna);

        //-1 representa a parede. -2 representa o perigo.
        if(!(x_aux == x_atual && y_aux == y_atual)){
            if(matriz->mat[x_atual][y_atual] == -1){
                x_atual = x_aux;
                y_atual = y_aux;
            } else if(matriz->mat[x_atual][y_atual] == -2){
                menino->vida--;
                menino->sacola = 0; 
                
                if(menino->vida == 0){
                    printf("GAME OVER!\n");
                    return;
                }
            } 
            if(matriz->mat[x_aux][y_aux] > 0){
                matriz->mat[x_aux][y_aux]--;
                menino->item++;
                menino->sacola++;
                
                if(menino->sacola == 4){
                    if(menino->vida < 10){
                        menino->vida++;
                    }
                
                    menino->sacola = 0;
                }
            }
        } else {
            //printf("testando aqui: %d\n", matriz->matrizAtual);
            if(teleporte == 1){ //teleporte vai para direita
                printf("matriz atual antes: %d\n", matriz->matrizAtual);
                checkpoint(matriz);

                if(matriz->matrizAtual == menino->q){ 
                    matriz->matrizAtual = 1; 
                } else{
                    matriz->matrizAtual++;
                }

                readCheckpoint(matriz);
                printf("matriz atual depois: %d\n", matriz->matrizAtual);
            } else if(teleporte == 2){ //teleporte vai para esquerda
                checkpoint(matriz);

                if(matriz->matrizAtual == 1){
                    matriz->matrizAtual = menino->q;
                } else{
                    matriz->matrizAtual--;
                }

                readCheckpoint(matriz);
            }

            teleporte = 0;
        }
    }
}

void Movimentar(int *x, int *y, int posicao, int *teleporte, int linha, int coluna){
    
    switch (posicao){
        case 1: //direita
            if((*y)+1 < coluna){(*y)++;} else {*teleporte = 1;}
            break;
        case 2: //esquerda
            if((*y)-1 >= 0){(*y)--;} else {*teleporte = 2;}
            break;
        case 3: //baixo
            if((*x)+1 < linha){(*x)++;}
            break;
        case 4: //cima
            if((*x)-1 >= 0){(*x)--;}
            break;
        case 5: //diagonal superior esquerda
            if((*x)-1 >= 0 && (*y)-1 >= 0){(*x)--; (*y)--;}
            break;
        case 6: //diagonal superior direita
            if((*x)-1 >= 0 && (*y) < coluna){(*x)--; (*y)++;}
            break;
        case 7: //diagonal inferior esquerda
            if((*x)+1 < linha && (*y)-1 >= 0){(*x)++; (*y)--;}
            break;
        case 8: //diagonal inferior direita
            if((*x)+1 < linha && (*y) < coluna){(*x)++; (*y)++;}
            break;
        }

}