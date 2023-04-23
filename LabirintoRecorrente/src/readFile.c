#include "readFile.h"

void fazCopia(copiaCheckpoint *matriz) {
    char *p = (char *)malloc(sizeof(char) * 100);
    sprintf(p, "dataset/copia/copia_%d.data", matriz->matrizAtual);

    FILE *file = fopen(p, "w");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo  FAZCOPIA\n");
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

void checkpoint(readMatriz *matriz) {
    //o arquivo gerado para o checkpoint chama-se output_1.data

    char *p = (char *)malloc(sizeof(char) * 100);
    sprintf(p, "dataset/checkpoint/checkpoint_%d.data", matriz->matrizAtual);

    FILE *file = fopen(p, "w");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo CHECK\n");
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
        printf("Nao foi possivel abrir o arquivo LEITURA\n");
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
        printf("Nao foi possivel abrir o arquivo READCHECK\n");
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
        printf("Nao foi possivel abrir o arquivo READCOPIACHECK\n");
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

void tamanho(int *linha, int *coluna, int *total) {
    FILE *file = fopen("dataset/input.data", "r");
    int cont = 0;
    char *result, linha_str[MAX];

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo TAMANHO\n");
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

void output(int x, int y, readMatriz*matriz){
    FILE *file = fopen("dataset/output.data", "a");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo OUTPUT\n");
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

void relatorio(infoMenino*menino){
    FILE *file = fopen("dataset/relatorio.data", "w");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo RELATORIO\n");
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

void readMatrizPercorrida(int *caminhoPercorrido, int *caminhoNaoPercorrido, int quantMatriz) {
    for(int i = 0; i < quantMatriz; i++){
        char *p = (char *)malloc(sizeof(char) * 100);
        sprintf(p, "dataset/copia/copia_%d.data", i+1);

        FILE *file = fopen(p, "r");

        char *result, linha[MAX];

        int convert;

        int aux = 0;

        if (file == NULL) {
            printf("Nao foi possivel abrir o arquivo readMatrizPercorrida\n");
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