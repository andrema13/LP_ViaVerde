#ifndef VIAVERDE_DATA_H
#define VIAVERDE_DATA_H
#include "Cliente.h"
#include "Viagem.h"

extern struct Client clients_list[100];
extern struct Trip trips_list[100];
extern int client_list_size;
int current_client_id;
int current_user_id;
void read_client_file();
void write_client_file();
int count_file_line_numbers();
void search_last_id();
#endif //VIAVERDE_DATA_H
