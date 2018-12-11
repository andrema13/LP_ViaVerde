#ifndef CLIENTE_H
#define CLIENTE_H

#include "Veiculo.h"
// structs , funções , variaveis globais
void ecra_cliente();
void menu_cliente();
void criar_cliente();

struct Cliente{

        char nome[20];
        char nif[10];
        char cc[9];
        char NIB[21];
        char morada[20];
        int pontosVV;
        struct Veiculo veiculo;
       
    };
    
#endif
