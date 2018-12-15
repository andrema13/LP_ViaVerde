#ifndef CLIENTE_H
#define CLIENTE_H
#include "Veiculo.h"

void client_info();
void travel_info();
void add_travel();
void travel_history();
void points_info();
void extracts_info();
void vehicle_info();
void customer_area();
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
