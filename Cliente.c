#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Veiculo.h"
#include "API_Leitura.h"
#include "Portico.h"
#include "Utils.h"
#include "time.h"
#include "Utilizador.h"

void add_travel() {

    struct lanco matrix[NUM_PORTAGENS * NUM_PORTAGENS];
    struct Client client;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int choice_x, choice_y;
    float travel_cost;

    fill_matrix(matrix, "../Precos.txt", false);
    show_prices();
    printf("Enter where you want to go:\n");
    readInt(&choice_x, 1, NUM_PORTAGENS, "Choose between 1-5:\nX:");
    readInt(&choice_y, 1, NUM_PORTAGENS, "Choose between 1-5:\nY:");

    if (choice_x == choice_y) {
        printf("Cannot go to the same place!\n");
        printf("Please try another one.\n");
        add_travel();
    } else {
        printf("Sucess! Trip registered.");
        travel_cost = matrix[(choice_x - 1) * NUM_PORTAGENS + (choice_y - 1)].price;
        printf("Price: %f\n", travel_cost);
        printf("time: %d-%d-%d %d:%d:%d\n", tm.tm_mday,
               tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("%d", client_id()-1);
    }
}

void travel_history() {
    printf("travel history");
}

void client_info() {
    struct Client client;
    FILE *file;
    char line[256];
    file = fopen("../info_cliente.txt", "r");

    if (file == NULL) {
        perror("Error: ");
    } else {
        while (fgets(line, sizeof(line), file) != NULL) {

            fscanf(file, "%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%d",
                   &client.ID, client.name, client.NIF,
                   client.CC, client.NIB, client.street, client.vehicle.manufacturer,
                   client.vehicle.model, client.vehicle.registration, &client.VVPoints);
            //pesquisa a info pessoal
        }
        if (client.ID == client_id() - 1) {

            printf("---Personal Info---\n");//imprime as info do cliente (ultimo da lista)
            printf("ID: %d\n", client.ID);
            printf("Nome: %s\n", client.name);
            printf("NIF: %s\n", client.NIF);
            printf("CC: %s\n", client.CC);
            printf("NIB: %s\n", client.NIB);
            printf("Street: %s\n\n", client.street);
        }
    }
    fclose(file);
} // ver info cliente ( penso que seja uma funcionalidade p/relatorio)

void vehicle_info() {

    struct Client client;
    FILE *file;
    char line[256];
    file = fopen("../info_cliente.txt", "r");

    if (file == NULL) {
        perror("Error: ");
    } else {
        while (fgets(line, sizeof line, file) != NULL) {

            fscanf(file, "%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%d",
                   &client.ID, client.name, client.NIF,
                   client.CC, client.NIB, client.street, client.vehicle.manufacturer,
                   client.vehicle.model, client.vehicle.registration, &client.VVPoints);//pesquisa a info do carro
        }
        if (client.ID == client_id() - 1) {

            printf("---Vehicle Info---\n");
            printf("Manufacturer: %s\n", client.vehicle.manufacturer);
            printf("Model: %s\n", client.vehicle.model);
            printf("Registration: %s\n\n", client.vehicle.registration);

        }
    }
    fclose(file);
}// ver info carro ( penso que seja uma funcionalidade p/relatorio)

void travel_info() {

    int choice;
    do {
        printf("---Travels---\n\n");
        printf("1. Add travel\n");
        printf("2. Travel history\n");
        printf("3. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                add_travel();
                break;
            case 2:
                system("clear");
                travel_history();
                break;
            case 3:
                system("clear");
            case 4:
                printf("\nSee you soon! ;\051");
                exit(0);
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 3);
}

void extracts_info() {

}

void points_info() {

    struct Client client;
    FILE *file;
    char line[256];
    file = fopen("../info_cliente.txt", "r");

    if (file == NULL) {
        perror("Error: ");
    } else {
        while (fgets(line, sizeof line, file) != NULL) {

            fscanf(file, "%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%d",
                   &client.ID, client.name, client.NIF,
                   client.CC, client.NIB, client.street, client.vehicle.manufacturer,
                   client.vehicle.model, client.vehicle.registration, &client.VVPoints);//pesquisa a info do carro
        }
        if (client.ID == client_id() - 1) {

            printf("---Points Info---\n");
            printf("VV Points: %d\n\n", client.VVPoints);
        }
    }
    fclose(file);
}// ver info pontos ( penso que seja uma funcionalidade p/relatorio)

void customer_area() {

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
                system("clear");
                client_info();// aqui o cliente podera ver o  registo dos seus dados pessoais
                break;
            case 2:
                system("clear");
                vehicle_info();// aqui o cliente podera ver o registo do seu carro(s)
                break;
            case 3:
                system("clear");
                travel_info();// aqui o cliente podera ver o registo das suas viagens
                break;
            case 4:
                system("clear");
                extracts_info();// aqui o cliente podera ver o extrato das viagens ja efetuadas
                break;
            case 5:
                system("clear");
                points_info();// aqui o cliente podera ver o registo dos seus pontos
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
        printf("1. Enter to your account\n");
        printf("2. Register new client\n");
        printf("3. Previous Menu\n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                customer_area();
                break; // Login
            case 2:
                system("clear");
                printf("\nEnter your data: \n");
                client_id();
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
        fprintf(file, "%d\t%s\t%s\t%s\t%s\t%s", client_id(), client.name, client.NIF,
                client.CC, client.NIB, client.street);
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
