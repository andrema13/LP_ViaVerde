#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Veiculo.h"
#include "API_Leitura.h"
#include "Portico.h"
#include "Utils.h"
#include "Utilizador.h"
#include "Data.h"
#include "Viagem.h"

void client_info() {

    for (int i = 0; i < client_list_size; i++) {
        if (current_client_id == clients_list[i].ID) {
            printf("--Client Info--\n\n");
            printf("ID : %d\n", clients_list[i].ID);
            printf("Name : %s\n", clients_list[i].name);
            printf("NIF : %s\n", clients_list[i].NIF);
            printf("CC : %s\n", clients_list[i].CC);
            printf("NIB : %s\n", clients_list[i].NIB);
            printf("Street : %s\n", clients_list[i].street);
        }
    }
}

void vehicle_info() {

    for (int i = 0; i < client_list_size; i++) {
        if (current_client_id == clients_list[i].ID) {
            printf("--Vehicle Info--\n\n");
            printf("Manufacturer : %s\n", clients_list[i].vehicle.manufacturer);
            printf("Model : %s\n", clients_list[i].vehicle.model);
            printf("Registration : %s\n", clients_list[i].vehicle.registration);
        }
    }

}// ver info carro ( penso que seja uma funcionalidade p/relatorio)

void trip_info() {

    int choice;
    do {
        printf("---Trips---\n\n");
        printf("1. Add trip\n");
        printf("2. Trip history\n");//funcionalidade nova
        printf("3. Previous Menu \n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                add_trip();
                break;
            case 2:
                system("clear");
                trip_history();
                break;
            case 3:
                system("clear");
                break;
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

    int choice;
    do {
        printf("--Extracts--\n\n");
        printf("1. See extract  \n");
        printf("2. Previous Menu\n");
        printf("3. Exit\n");
        readInt(&choice, 1, 3, "Choose an option: ");

        switch (choice) {

            case 1:
                system("clear");
                extracts_page();
                break;
            case 2:
                system("clear");//menu anterior
                break;
            case 3:
                printf("\nSee you soon! ;\051");
                exit(0);

            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 2);
}

void points_info() {

    for (int i = 0; i < client_list_size; i++) {
        if (current_client_id == clients_list[i].ID) {
            printf("--Points Info--\n\n");
            printf("Points : %d\n", clients_list[i].VVPoints);
        }
    }
}// ver info pontos ( penso que seja uma funcionalidade p/relatorio)

void customer_area() {

    int choice;
    do {
        printf("---Customer area---\n\n");
        printf("1. Costumer\n");
        printf("2. Vehicle\n");
        printf("3. Trips\n");
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
                vehicle_info();// aqui o cliente podera ver o registo do seu carro
                break;
            case 3:
                system("clear");
                trip_info();// aqui o cliente podera ver o registo das suas viagens
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
                client_menu();
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
        printf("---Client Menu---\n\n");
        printf("1. Enter to your account\n");
        printf("2. Register new client\n");
        printf("3. Previous Menu\n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                if (client_list_size == 0) {//se nao existir clientes
                    printf("No clients yet!");
                    client_menu();
                } else {
                    id_verification(client_menu,customer_area);
                    //verifica se o id dado existe nos clientes registados
                }
                break;

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
                exit(0);

            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 3);
}

void id_verification(void (*f)(void),void (*e)(void)) {//para passar duas funçoes sem argumentos

    printf("--Registered Clients--\n");
    for (int i = 0; i < client_list_size; i++) {//mostra os clientes id/nome
        printf("Id: %d - Name: %s\n", clients_list[i].ID, clients_list[i].name);
    }
    printf("**Press 0 to exit**\n");
    printf("\n--Tell me your ID--\n");
    scanf("%d", &current_client_id);

    if (current_client_id == 0) {
        system("clear");
        (*f)();
    } else {
        for (int i = 0; i < client_list_size; i++) {//verifica se exite o id
            if (current_client_id == clients_list[i].ID) {
                system("clear");
                (*e)();
            }
        }//se chega aqui entao nao existe o id , logo volta a pedir um novo id
        printf("** 404 - Client not found **\n");
        system("clear");
        id_verification(client_menu,customer_area);
    }
}

void new_client() {

    struct Client client;

    if (client_list_size == 0) {
        client.ID = 1;
    } else {
        client.ID = clients_list[client_list_size - 1].ID + 1;//incrementa id do cliente
    }

    readString(client.name, 20, "Name: ");//Pede informaçoes pessoais ao utilizador
    readString(client.NIF, 9, "NIF: ");
    readString(client.CC, 8, "CC: ");
    readString(client.NIB, 20, "NIB: ");
    readString(client.street, 40, "Street: ");
    printf("\nEnter your vehicle information: \n ");
    readString(client.vehicle.manufacturer, 12, "Manufacturer: ");
    readString(client.vehicle.model, 12, "Model: ");
    readString(client.vehicle.registration, 10, "Registration: ");
    client.VVPoints = 0;

    clients_list[client_list_size++] = client;
    write_client_file();
    printf("Your ID is: %d", client.ID);
}
