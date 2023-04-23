#include "readFile.h"

//Função responsável por fazer a cópia da matriz do checkpoint, mantendo as paredes e os perigos existentes.  
//Inicialmente, para indicar se o garoto não passou pelo caminho, o valor será igual a zero.
//Caso tenha passado pelo caminho, o valor será igual a 1 e, então, mudará o arquivo cópia.
void fazCopia(copiaCheckpoint *matriz) {
    char *p = (char *)malloc(sizeof(char) * 100);
    sprintf(p, "dataset/copia/copia_%d.data", matriz->matrizAtual);

    FILE *file = fopen(p, "w");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    } else {
        fprintf(file, "%d %d %d\n", matriz->linha, matriz->coluna, 1);

        for (int i = 0; i < matriz->linha; i++) {
            for (int j = 0; j < matriz->coluna; j++) {
                fprintf(file, "%2d ", matriz->mat[i][j]);
            }

            fprintf(file, "\n");
        }
    }
    fclose(file);
}

//Função responsável por fazer o backup do arquivo das matrizes originais (input.data).
void checkpoint(readMatriz *matriz) {
    //o arquivo gerado para o checkpoint chama-se output_1.data
    
    char *p = (char *)malloc(sizeof(char) * 100);
    sprintf(p, "dataset/checkpoint/checkpoint_%d.data", matriz->matrizAtual);

    FILE *file = fopen(p, "w");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    } else {
        fprintf(file, "%d %d %d\n", matriz->linha, matriz->coluna, 1);

        for (int i = 0; i < matriz->linha; i++) {
            for (int j = 0; j < matriz->coluna; j++) {
                fprintf(file, "%2d ", matriz->mat[i][j]);
            }

            fprintf(file, "\n");
        }
    }
    fclose(file);
}

//Função responsável para fazer a leitura do arquivo original (input.data).
//Também faz a conversão dos símbolos de parede (#) e perigo (*) para -1 e -2, respectivamente.
//Essa conversão será exibida no arquivo do checkpoint, arquivo do qual será editado sempre que o algoritmo for compilado.
void leitura(readMatriz *matriz, int t, copiaCheckpoint *copia) {
    FILE *file = fopen("dataset/input.data", "r");
    
    FILE *fileSaida = fopen("dataset/output.data", "w");
    fclose(fileSaida);

    char *result, linha[MAX];

    int contLinha = 0;

    int convert, coluna = 0;

    int aux = 0;

    matriz->matrizAtual = 1;
    copia->matrizAtual = 1;

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    } else {
        while (!feof(file)) {
            result = fgets(linha, sizeof(linha), file);

            if (result && aux == 1) {
                if (strlen(linha) > 1) {
                    const char sep[] = " ";
                    char *tokens;
                    coluna = 0;

                    tokens = strtok(linha, sep);

                    while (tokens != NULL) {
                        if (strcmp(tokens, "#") == 0) convert = -1;
                        else if (strcmp(tokens, "*") == 0) convert = -2;
                        else convert = atoi(tokens);
                            
                        if(matriz->mat[contLinha][coluna] != -1 && matriz->mat[contLinha][coluna] != -2){
                            copia->mat[contLinha][coluna] = 0;
                        } else {
                            copia->mat[contLinha][coluna] = convert;
                            }

                        matriz->mat[contLinha][coluna++] = convert;
                        tokens = strtok(NULL, sep);
                    }
                    contLinha++;
                    
                    if(contLinha == t){
                        checkpoint(matriz);
                        fazCopia(copia);
                        matriz->matrizAtual++;
                        copia->matrizAtual++;
                    }

                } else {
                    contLinha = 0;
                }
            }
            aux = 1;
        }
    }
    fclose(file);
}

//Função responsável por fazer o checkpoint da matriz original, 
//na qual irá ser criado três arquivos, cada um desses arquivos contendo a alteração da matriz original e salvando-a.
void readCheckpoint(readMatriz *matriz) {
    char *p = (char *)malloc(sizeof(char) * 100);
    sprintf(p, "dataset/checkpoint/checkpoint_%d.data", matriz->matrizAtual);

    FILE *file = fopen(p, "r");

    char *result, linha[MAX];

    int contLinha = 0;

    int convert, coluna = 0;

    int aux = 0;

    tamanho(&matriz->linha, &matriz->coluna, &matriz->q);

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    } else {
        while (!feof(file)) {
            result = fgets(linha, sizeof(linha), file);

            if (result && aux == 1) {
                if (strlen(linha) > 1) {
                    const char sep[] = " ";
                    char *tokens;
                    coluna = 0;

                    tokens = strtok(linha, sep);

                    while (tokens != NULL) {
                        convert = atoi(tokens);

                        matriz->mat[contLinha][coluna++] = convert;
                        tokens = strtok(NULL, sep);
                    }
                    contLinha++;
                } 
            }
            aux = 1;
        }
    }
    fclose(file);
}

// Função responsável por fazer a leitura da cópia do checkpoint. Ou seja, irá abrir o arquivo contendo todas as informações copiadas.
void readCopiaCheckpoint(copiaCheckpoint *matriz) {
    char *p = (char *)malloc(sizeof(char) * 100);
    sprintf(p, "dataset/copia/copia_%d.data", matriz->matrizAtual);

    FILE *file = fopen(p, "r");

    char *result, linha[MAX];

    int contLinha = 0;

    int convert, coluna = 0;

    int aux = 0;

    tamanho(&matriz->linha, &matriz->coluna, &matriz->q);

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    } else {
        while (!feof(file)) {
            result = fgets(linha, sizeof(linha), file);

            if (result && aux == 1) {
                if (strlen(linha) > 1) {
                    const char sep[] = " ";
                    char *tokens;
                    coluna = 0;

                    tokens = strtok(linha, sep);

                    while (tokens != NULL) {
                        convert = atoi(tokens);

                        matriz->mat[contLinha][coluna++] = convert;
                        tokens = strtok(NULL, sep);
                    }
                    contLinha++;
                } 
            }
            aux = 1;
        }
    }
    fclose(file);
}

//Função responsável para definir o tamanho da matriz.
void tamanho(int *linha, int *coluna, int *total) {
    FILE *file = fopen("dataset/input.data", "r");
    int cont = 0;
    char *result, linha_str[MAX];

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    } else {
        while (!feof(file)) {
            result = fgets(linha_str, sizeof(linha_str), file);

            if (result) {
                const char sep[] = " ";
                char *tokens;

                tokens = strtok(linha_str, sep);

                while (tokens != NULL) {
                    if (cont == 0) {
                        (*linha) = atoi(tokens);
                    } else if (cont == 1) {
                        (*coluna) = atoi(tokens);
                    } else if (cont == 2) {
                        (*total) = atoi(tokens);
                    }

                    tokens = strtok(NULL, sep);

                    cont++;
                }
            }
        }
    }
    fclose(file);
}

// Função responsável para a criação de outro arquivo na qual mostrará o caminho impresso percorrido pelo menino.
void output(int x, int y, readMatriz*matriz){
    FILE *file = fopen("dataset/output.data", "a");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    } else {
        fprintf(file, "matriz atual: %d\n", matriz->matrizAtual);
        fprintf(file, "coordenadas: [%d] x [%d]\n", x, y);

        for(int i = 0; i <  matriz->linha; i++){
            for(int j = 0; j <  matriz->coluna; j++){
                if(i == x && i == j){
                    fprintf(file, " @ ");
                }
                else if(matriz->mat[i][j] == -1) {
                    fprintf(file, " # ");
                } else if(matriz->mat[i][j] == -2) {
                    fprintf(file, " * ");
                }else {
                    fprintf(file, "%2d ", matriz->mat[i][j]);
                }
            }
            
            fprintf(file, "\n");
        }
        
        fprintf(file, "\n");
    }
    fclose(file);
}

// Função responsável apenas para mostrar as informações do menino, na qual ao final do processo, será impresso o resultado de todo o caminho percorrido.
void relatorio(infoMenino*menino){
    FILE *file = fopen("dataset/relatorio.data", "w");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    } else {
        int caminhoPercorrido=0, caminhoNaoPercorrido=0;

        readMatrizPercorrida(&caminhoPercorrido, &caminhoNaoPercorrido, menino->q);

        if(menino->status == 0){
            fprintf(file, "Garoto morto!\n");
        } else {
            fprintf(file, "Garoto vivo!\n");
        }

        fprintf(file, "Vida do menino: %d\n", menino->vida);
        fprintf(file, "Itens coletados: %d\n", menino->item);
        fprintf(file, "Perigos enfrentados: %d\n", menino->perigo);
        fprintf(file, "quantidade: %d\n", menino->q);
        fprintf(file, "caminho percorrido: %d\n", caminhoPercorrido);
        fprintf(file, "caminho nao percorrico: %d\n", caminhoNaoPercorrido);
    }
    fclose(file);
}

//Função responsável para mostrar se o garoto percorreu o caminho ou não. 
//Para tal, foi criada uma condição para verificar, onde se o convert (variável encarregada da tokenização) for igual a zero, então o caminho não foi percorrido. 
//Se o convert for igual a 1, o caminho será percorrido.
void readMatrizPercorrida(int *caminhoPercorrido, int *caminhoNaoPercorrido, int quantMatriz) {
    for(int i = 0; i < quantMatriz; i++){
        char *p = (char *)malloc(sizeof(char) * 100);
        sprintf(p, "dataset/copia/copia_%d.data", i+1);

        FILE *file = fopen(p, "r");

        char *result, linha[MAX];

        int convert;

        int aux = 0;

        if (file == NULL) {
            printf("Nao foi possivel abrir o arquivo\n");
        } else {
            while (!feof(file)) {
                result = fgets(linha, sizeof(linha), file);

                if (result && aux == 1) {
                    if (strlen(linha) > 1) {
                        const char sep[] = " ";
                        char *tokens;

                        tokens = strtok(linha, sep);

                        while (tokens != NULL) {
                            convert = atoi(tokens);
                            if(convert == 0){
                                (*caminhoNaoPercorrido)++;
                            } else if(convert == 1){
                                (*caminhoPercorrido)++;
                            }

                            tokens = strtok(NULL, sep);
                        }
                    } 
                }
                aux = 1;
            }
        }
        fclose(file);
    }
}
