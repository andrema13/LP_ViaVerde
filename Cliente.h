#ifndef CLIENTE_H
#define CLIENTE_H
// structs , funções , variaveis globais
void ler_ficheiro();
void registar_cliente();

typedef struct cliente {

        char nome[20];
        int nif[10];
        int cc[10];
        char NIB[22];
        char morada[30];
        //int pontosVV;
       
    }reg_cliente;
    
#endif
