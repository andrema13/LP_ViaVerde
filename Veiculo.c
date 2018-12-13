#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Veiculo.h"
#include "API_Leitura.h"

void register_vehicle(){

    struct Client client;
    int c;
    FILE *file;

    printf("\nEnter your vehicle information: \n ");
    readString(client.vehicle.manufacturer,12, "Manufacturer: ");
    readString(client.vehicle.model,12, "Model: ");
    readString(client.vehicle.registration,10, "Registration: ");
    client.VVPoints = 0;
    file = fopen("../info_cliente.txt", "a");

    fprintf(file,",%s,%s,%s,%d;\n", client.vehicle.manufacturer, client.vehicle.model,
            client.vehicle.registration,client.VVPoints);
    if (file) {
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
    }
}
