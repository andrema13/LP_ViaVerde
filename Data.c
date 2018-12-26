#include <stdio.h>
#include "Data.h"

struct Client clients_list[100];
struct Trip trips_list[100];
int client_list_size = 0;

void read_client_file() {

    FILE *file;
    int i = 0;
    file = fopen("../info_cliente.txt", "r");
    if (file == NULL) {
        perror("Error: ");
    } else {
        struct Client client;

        while (fscanf(file, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d",
                      &client.ID, client.name, client.NIF,
                      client.CC, client.NIB, client.street,
                      client.vehicle.manufacturer, client.vehicle.model,
                      client.vehicle.registration,
                      &client.VVPoints
        ) != EOF) {
            clients_list[i] = client;
            i++;
        }
    }
    client_list_size = i;

    fclose(file);
}

void write_client_file() {

    int i, c;
    FILE *file;

    file = fopen("../info_cliente.txt", "w");//Creates an empty file for writing. If a file with the same name already exists,
                                            // its content is erased and the file is considered as a new empty file.

    for (i = 0; i < client_list_size; i++) {

        fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%d\n",
                clients_list[i].ID,
                clients_list[i].name,
                clients_list[i].NIF,
                clients_list[i].CC,
                clients_list[i].NIB,
                clients_list[i].street,
                clients_list[i].vehicle.manufacturer,
                clients_list[i].vehicle.model,
                clients_list[i].vehicle.registration,
                clients_list[i].VVPoints);
    }
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
    fclose(file);
}

int count_file_line_numbers() {

    int lines = 0;
    int ch; //char que define se tem palavras ou EOF
    FILE *file;
    file = fopen("../info_cliente.txt", "r");

    if (file == NULL) {
        perror("Error: ");
        return lines;
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
