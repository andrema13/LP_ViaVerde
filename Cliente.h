#ifndef CLIENTE_H
#define CLIENTE_H

void client_info();
void trip_info();
int points_info();
void extracts_info();
void vehicle_info();
void customer_area();
void client_menu();
void new_client();
void id_verification(void (*f)(void),void (*e)(void));
void string_replace(char s[], char chr, char repl_chr);
struct Vehicle {

    char registration[10];
    char manufacturer[12];
    char model[12];

};
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
