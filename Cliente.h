#ifndef CLIENTE_H
#define CLIENTE_H
#include "Veiculo.h"

void client_info();
void trip_info();
void points_info();
void extracts_info();
void vehicle_info();
void customer_area();
void client_menu();
void new_client();

struct Client{

        int ID;
        char name[20];
        char NIF[9];
        char CC[8];
        char NIB[20];
        char street[40];
        int VVPoints;
        struct Vehicle vehicle;
    };
    
#endif
