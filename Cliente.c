#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Veiculo.h"
#include "API_Leitura.h"
#include "Portico.h"

void client_screen() {

    int choice;
    do {
        printf("---Customer area---\n\n");
        printf("1. Costumer\n");
        printf("2. Vehicle\n");
        printf("3. Travels\n");
        printf("4. Extracts\n");
        printf("5. Points\n");
        printf("6. Previous Menu\n");
        printf("7. Exit\n");
        readInt(&choice, 1, 7, "Choose an option: ");

        switch (choice) {
            case 1:
                //system("clear");
                // aqui o cliente podera ver o  registo dos seus dados pessoais
                break;
            case 2:
                printf("Veiculo");
                // aqui o cliente podera ver o registo do seu carro(s)
                break;
            case 3:
                system("clear");
                //printf("Viagens");
                toll_id();
                break;
            case 4:
                system("clear");
                printf("Extratos");
                break;
            case 5:
                system("clear");
                printf("Pontos");
                break;
            case 6:
                system("clear");
                break;//menu anterior
            case 7:
                printf("\nSee you soon! ;\051");
                exit(0);
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 6);
}

void client_menu() {

    int choice;
    int id = 1;
    do {
        printf("\n---Initial Menu---\n\n");
        printf("1. Login\n");
        printf("2. Register new client\n");
        printf("3. Previous Menu\n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                client_screen();
                break; // Login
            case 2:
                system("clear");
                printf("\nEnter your data: \n");
                new_client();
                printf("\nRegistered successfully!\n");
                id++;
                break;
            case 3:
                system("clear");//menu anterior
                break;
            case 4:
                printf("\nSee you soon! ;\051");
                exit(0);//sair da aplicacao

            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 3);
}

void new_client() {

    struct Client client;
    int c;
    FILE *file;

    readString(client.name, 20, "Name: ");
    readString(client.NIF, 10, "NIF: ");
    readString(client.CC, 9, "CC: ");
    readString(client.NIB, 22, "NIB: ");
    readString(client.street, 20, "Street: ");
    file = fopen("../info_cliente.txt", "a");

    fprintf(file, "%d,%s,%s,%s,%s,%s", client.ID, client.name, client.NIF, client.CC, client.NIB,
            client.street);
    if (file) {
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
    }
    register_vehicle();
}
