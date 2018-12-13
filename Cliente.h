#ifndef CLIENTE_H
#define CLIENTE_H

#include "Veiculo.h"
// structs , funções , variaveis globais
void client_screen();
void client_menu();
void new_client();

struct Client{

        int ID;
        char name[20];
        char NIF[10];
        char CC[9];
        char NIB[22];
        char street[20];
        int VVPoints;
        struct Vehicle vehicle;
       
    };
    
#endif
