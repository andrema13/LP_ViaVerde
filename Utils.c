#include "Utils.h"

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
 *
 * @param matrix
 * @param file
 * @return
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

void clear_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
