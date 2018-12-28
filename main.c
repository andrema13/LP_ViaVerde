#include <stdio.h>
#include <stdlib.h>
#include "API_Leitura.h"
#include "Cliente.h"
#include "Utilizador.h"
#include "Data.h"
#include "Viagem.h"

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
                id_verification(main_menu,user_screen);
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
//
//    FILE *file;
//    file = fopen("../info_cliente.txt", "w");
//    if (file == NULL) {
//        perror("Error: ");
//    }
//    fclose(file);

    read_client_file();
    read_trip_file();
    main_menu();
    return 0;
}