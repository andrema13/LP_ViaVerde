#include "Utils.h"

bool fill_matrix(struct lanco *matrix, char *file, bool is_distance) {

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
        if (is_distance) matrix[i * NUM_PORTAGENS + j].dist = atof(token);
        else matrix[i * NUM_PORTAGENS + j].price = atof(token);

        j++;
        while (token != NULL) {
            token = strtok(NULL, s);

            if (token != NULL) {
                if (is_distance) matrix[i * NUM_PORTAGENS + j].dist = atof(token);
                else matrix[i * NUM_PORTAGENS + j].price = atof(token);
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
 * 
 * @param matrix
 * @param file
 * @return
 */
bool write_matrix(struct lanco *matrix, char *file) {

    FILE *fp;

    fp = fopen(file, "w");
    if (fp == NULL)
        return false;

    int i, j;
    for (i = 0; i < NUM_PORTAGENS; i++) {
        for (j = 0; j < NUM_PORTAGENS; j++) {
            fprintf(fp, "%f\t", matrix[i * NUM_PORTAGENS + j].price);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return true;
}