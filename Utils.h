#ifndef UTILS_H
#define UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PORTAGENS 5

struct Lanco {
    float price, distance;
};

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
bool fill_matrix(struct Lanco *f, char *file, bool is_distance);

bool write_matrix(struct Lanco *f, char *file, bool is_price);

void clear_buffer();

#ifdef __cplusplus
}
#endif

#endif /* UTILS_H */

