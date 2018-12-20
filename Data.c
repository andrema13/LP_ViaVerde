//
// Created by a-mar on 19/12/2018.
//

#include <stdio.h>
#include "Data.h"

struct Client clients_list[1000];
int client_list_size = 0;

void read_client_file() {

    int i;
    FILE *file;
    char line[256];
    file = fopen("../info_cliente.txt", "r");

    if (file == NULL) {
        perror("Error: ");
    } else {

        client_list_size = count_file_line_numbers();
        printf("%d\n", client_list_size);

        for (i = 0; i < client_list_size; i++) {
            while (fgets(line, sizeof(line), file) != NULL) {//pesquisa a info pessoal e do veiculo
                struct Client client;
                fscanf(file, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d",
                       &client.ID,
                       client.name,
                       client.NIF,
                       client.CC,
                       client.NIB,
                       client.street,
                       client.vehicle.manufacturer,
                       client.vehicle.model,
                       client.vehicle.registration,
                       &client.VVPoints
                );
                clients_list[i] = client;
            }
        }
    }
    for (i = 0; i < client_list_size; i++) {
        printf("%s\n", clients_list[0].name);
    }
    fclose(file);
}

int count_file_line_numbers() {

    int lines = 0;
    int ch; //char que define se tem palavras ou EOF
    FILE *file = fopen("../info_cliente.txt", "r");

    if (file == NULL) {
        perror("Error: ");
        return -1;
    }

    while (!feof(file)) {
        ch = fgetc(file);
        if (ch == '\n') {
            lines++;
        }
    }

    fclose(file);
    return lines;
}
