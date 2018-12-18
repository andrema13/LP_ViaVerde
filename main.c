#include <stdio.h>
#include <stdlib.h>
#include "API_Leitura.h"
#include "Cliente.h"
#include "Utilizador.h"

void main_menu() {

    int choice;
    do {
        printf("---Welcome to Via Verde---\n\n");
        printf("1. Client\n");
        printf("2. User\n");
        printf("3. Exit\n");
        readInt(&choice, 1, 3, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                client_menu();
                break;
            case 2:
                system("clear");
                user_screen();
                break;
            case 3: // Exit
                printf("\nSee you soon! ;\051");
                exit(0);
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 3);
}

int main() {

    int i;
    struct Client client[client_id()];
    FILE *file;
    char line[256];
    file = fopen("../info_cliente.txt", "r");

    if (file == NULL) {
        perror("Error: ");
    } else {
        for(i=0;i <= client_id();i++){

            while (fgets(line, sizeof(line), file) != NULL) {//pesquisa a info pessoal e do veiculo

                fscanf(file, "%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%d",
                       &client[i].ID, client[i].name, client[i].NIF,
                       client[i].CC, client[i].NIB, client[i].street, client[i].vehicle.manufacturer,
                       client[i].vehicle.model, client[i].vehicle.registration, &client[i].VVPoints);
            }
        }
    }
    fclose(file);
    main_menu();
    return 0;
}