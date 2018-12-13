#include "Portico.h"
#include "Utils.h"

void toll_id() {//faz corresponder a cada id de portico a sua respetiva distancia

    struct lanco matrix[NUM_PORTAGENS * NUM_PORTAGENS];
    struct portico portico;

    fill_matrix(matrix, "../Distancias.txt", true);

    int i, j, k = 0;

    printf("---Tolls---\n\n");

    for (i = 0; i < NUM_PORTAGENS; i++) {
        for (j = 0; j < NUM_PORTAGENS; j++) {

            if (i != j) {
                portico.ID[k] = matrix[i * NUM_PORTAGENS + j].dist;
                //printf("%f\n", portico.ID[k]); imprime no ecra o valor do portico com o k id
                k++;
            }
        }
    }
}