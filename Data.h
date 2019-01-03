#ifndef VIAVERDE_DATA_H
#define VIAVERDE_DATA_H
#define LIST_SIZE 10
#define TRIP_SIZE 100
#include "Cliente.h"
#include "Viagem.h"
#include "Utils.h"

extern struct Client *clients_list;
extern struct Trip *trips_list;
extern struct Lanco price_matrix_list[NUM_PORTAGENS * NUM_PORTAGENS];
extern struct Lanco distance_matrix_list[NUM_PORTAGENS * NUM_PORTAGENS];
extern int client_list_max_size;
extern int trip_list_max_size;
extern int client_list_size;
extern int trip_list_size;
int current_client_id;
void read_client_file();
void write_client_file();
int count_file_line_numbers();
void read_trip_file();
void write_trip_file();
void show_prices();
void show_distances();
#endif //VIAVERDE_DATA_H
