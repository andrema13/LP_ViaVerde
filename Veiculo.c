#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Veiculo.h"
#include "API_Leitura.h"

void register_vehicle() {

    //passar por parametro
    struct Client client;
    int c;
    FILE *file;

    printf("\nEnter your vehicle information: \n ");
    readString(client.vehicle.manufacturer, 12, "Manufacturer: ");
    readString(client.vehicle.model, 12, "Model: ");
    readString(client.vehicle.registration, 10, "Registration: ");
    client.VVPoints = 0;
    file = fopen("../info_cliente.txt", "a");

    if (file != NULL) {
        fprintf(file, "\t%s\t%s\t%s\t%d\n", client.vehicle.manufacturer, client.vehicle.model,
                client.vehicle.registration, client.VVPoints);
        if (ferror(file)) {
            perror("Error: ");
        }
        fclose(file);
    }
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
}