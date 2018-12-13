#include "Utils.h"

bool preencheMatriz(struct lanco *matriz, char *ficheiro, bool distancia) {
    FILE *fp;
    char *linha = NULL;
    size_t len = 0;
    const char s[] = "\t\n\0";
    char *token;
    int i = 0, j = 0;

    fp = fopen(ficheiro, "r");
    if (fp == NULL)
        return false;

    while ((getline(&linha, &len, fp)) != -1) {
        j = 0;
        token = strtok(linha, s);

        if (distancia) matriz[i * NUM_PORTAGENS + j].dist = atof(token);
        else matriz[i * NUM_PORTAGENS + j].preco = atof(token);

        j++;
        while (token != NULL) {
            token = strtok(NULL, s);

            if (token != NULL) {
                if (distancia) matriz[i * NUM_PORTAGENS + j].dist = atof(token);
                else matriz[i * NUM_PORTAGENS + j].preco = atof(token);
            }
            j++;
        }
        i++;
    }

    fclose(fp);
    if (linha)
        free(linha);

    return true;
}

bool write_matrix(struct lanco *matriz, char *ficheiro) {

    FILE *fp;

    fp = fopen(ficheiro, "w");
    if (fp == NULL)
        return false;

    int i, j;
    for (i = 0; i < NUM_PORTAGENS; i++) {
        for (j = 0; j < NUM_PORTAGENS; j++) {
            fprintf(fp, "%f\t", matriz[i * NUM_PORTAGENS + j].preco);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return true;
}