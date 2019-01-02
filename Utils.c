#include "Utils.h"
/**
 * Função que preenche uma matriz quadrada de lado NUM_PORTAGENS com o
 * conteúdo do ficheiro especificado. A função pode ser utilizada para preencher
 * a matriz de distâncias ou a matriz de preços.
 *
 * @param matrix A matriz a preencher, que deve ser previamente alocada
 * @param file O ficheiro de onde vão ser lidos os dados
 * @param is_distance Indica se será preenchida a matriz de distâncias ou de preços
 *
 * @return Indica se a função terminou com sucesso
 */
bool fill_matrix(struct Lanco *f, char *file, bool is_distance) {

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    const char s[] = "\t\n\0";
    char *token;
    int i = 0, j = 0;

    fp = fopen(file, "r");
    if (fp == NULL)
        return false;
    while ((getline(&line, &len, fp)) != -1) {
        j = 0;
        token = strtok(line, s);
        if (is_distance) {
            f[i * NUM_PORTAGENS + j].distance = atof(token);
        } else {
            f[i * NUM_PORTAGENS + j].price = atof(token);
        }

        j++;
        while (token != NULL) {
            token = strtok(NULL, s);

            if (token != NULL) {
                if (is_distance) {
                    f[i * NUM_PORTAGENS + j].distance = atof(token);
                } else {
                    f[i * NUM_PORTAGENS + j].price = atof(token);
                }
            }
            j++;
        }
        i++;
    }

    fclose(fp);
    if (line)
        free(line);

    return true;
}
/**
 * Funçao que escreve a matriz no ficheiro indicado .
 * Esta funçao pode ser utilizada para escrever a matriz de preços ou de distancias
 * @param f matriz que sera escrita
 * @param file Ficheiro onde vao ser escritos os dados
 * @param is_price  Indica se sera escrita a matriz dos preços ou da distancia
 * @return Indica se a funçao terminou com sucesso
 */
bool write_matrix(struct Lanco *f, char *file, bool is_price) {

    FILE *fp;
    int i, j;

    fp = fopen(file, "w");
    if (fp == NULL) {
        return false;
    }

    for (i = 0; i < NUM_PORTAGENS; i++) {
        for (j = 0; j < NUM_PORTAGENS; j++) {
            if (is_price) {
                fprintf(fp, "%f\t", f[i * NUM_PORTAGENS + j].price);
            } else {
                fprintf(fp, "%f\t", f[i * NUM_PORTAGENS + j].distance);
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return true;
}

