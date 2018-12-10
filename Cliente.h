#ifndef CLIENTE_H
#define CLIENTE_H

#include "Veiculo.h"
// structs , funções , variaveis globais
void ler_ficheiro();

struct Cliente{

        char nome[20];
        int nif;
        int cc;
        int NIB;
        char morada[20];
        int pontosVV;
        struct Veiculo veiculo;
       
    };
    
#endif
