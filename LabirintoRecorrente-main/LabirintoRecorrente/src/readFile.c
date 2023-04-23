#include "readFile.h"

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

void leitura(readMatriz *matriz, int t) {
    FILE *file = fopen("dataset/input.data", "r");

    char *result, linha[MAX];

    int contLinha = 0;

    int convert, coluna = 0;

    int aux = 0;

    matriz->matrizAtual = 1;

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

                        matriz->mat[contLinha][coluna++] = convert;
                        tokens = strtok(NULL, sep);
                    }
                    contLinha++;
                    
                    if(contLinha == t){
                        checkpoint(matriz);
                        matriz->matrizAtual++;
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