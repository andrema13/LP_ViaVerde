#ifndef VIAGEM_H
#define VIAGEM_H
#endif
#include "time.h"

struct Trip {
    int client_id;
    struct tm date;
    float travel_cost;
};

//char Toll[] = {
//    "Braga", "Porto", "Coimbra", "Lisboa", "Algarve"
//};