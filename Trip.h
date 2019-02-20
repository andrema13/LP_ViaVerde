#ifndef VIAGEM_H
#define VIAGEM_H
#include "time.h"

struct Trip {
    int client_id;
    struct tm date;
    int choice_x;
    int choice_y;
    float trip_cost;
    float distance;
};

void add_trip();

void show_distance();

void trip_history();

void extracts_page();

#endif