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
    
struct lanco {
    float preco, dist;
};

/**
 * Função que preenche uma matriz quadrada de lado NUM_PORTAGENS com o
 * conteúdo do ficheiro especificado. A função pode ser utilizada para preencher
 * a matriz de distâncias ou a matriz de preços.
 * 
 * @param matriz A matriz a preencher, que deve ser previamente alocada
 * @param ficheiro O ficheiro de onde vão ser lidos os dados
 * @param distancia Indica se será preenchida a matriz de distâncias ou de preços
 * 
 * @return Indica se a função terminou com sucesso
 */
bool preencheMatriz(struct lanco *matriz, char *ficheiro, bool distancia);


#ifdef __cplusplus
}
#endif

#endif /* UTILS_H */

