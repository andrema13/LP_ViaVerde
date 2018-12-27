#ifndef VIAGEM_H
#define VIAGEM_H
#include "time.h"

struct Trip {
    int client_id;
    struct tm date;
    int choice_x;
    int choice_y;
    float trip_cost;
};
void add_trip();
void add_trip();
void trip_history();
#endif