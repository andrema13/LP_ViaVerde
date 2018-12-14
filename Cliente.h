#ifndef CLIENTE_H
#define CLIENTE_H
#include "Veiculo.h"

void client_screen();
void client_menu();
void new_client();
int client_id();

struct Client{

        int ID;
        char name[20];
        char NIF[10];
        char CC[9];
        char NIB[22];
        char street[40];
        int VVPoints;
        struct Vehicle vehicle;
       
    };
    
#endif
