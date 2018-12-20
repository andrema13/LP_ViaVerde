#ifndef VIAVERDE_DATA_H
#define VIAVERDE_DATA_H
#include "Cliente.h"

extern struct Client clients_list[1000];
extern int client_list_size;
int current_client_id;

void read_client_file();

int count_file_line_numbers();

#endif //VIAVERDE_DATA_H
