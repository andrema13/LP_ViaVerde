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
                break;
            case 4:
                system("clear");
                printf("Extratos");
                client_id();
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

int client_id() {

    struct Client client;
    int id = 0;
    FILE *file;
    char line[256];
    file = fopen("../info_cliente.txt", "r");

    if (file == NULL) {
        perror("Error: ");
        return -1;
    }
    while (fgets(line, sizeof(line), file)) {
        fscanf(file, "%d", &client.ID);//pesquisa pelo ultimo id
        id = client.ID++; // acrescenta o id
    }
    fclose(file);

    return id;
}

void new_client() {

    struct Client client;
    int c;
    FILE *file;

    readString(client.name, 20, "Name: ");//Pede informaçoes pessoais ao utilizador
    readString(client.NIF, 10, "NIF: ");
    readString(client.CC, 9, "CC: ");
    readString(client.NIB, 22, "NIB: ");
    readString(client.street, 40, "Street: ");
    file = fopen("../info_cliente.txt", "a");

    if (file != NULL) {
        fprintf(file, "%d\t%s\t%s\t%s\t%s\t%s", client_id(), client.name, client.NIF, client.CC, client.NIB,
                client.street);
        if (ferror(file)) {
            perror("Error: ");
        }
        fclose(file);
    }
    while ((c = fgetc(file)) != EOF) {//escreve no ficheiro as informaçoes dadas pelo utilizador
        putchar(c);
    }
    register_vehicle(); // vai pedir as informaçoes do veiculo ao utilizador
}
