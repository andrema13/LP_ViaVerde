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
            printf("NIB : %s\n",clients_list[i].NIB);
            printf("Street : %s\n",clients_list[i].street);
        }
    }
}

void vehicle_info() {

    for (int i = 0; i < client_list_size; i++) {
        if (current_client_id == clients_list[i].ID) {
            printf("--Vehicle Info--\n\n");
            printf("Manufacturer : %s\n", clients_list[i].vehicle.manufacturer);
            printf("Model : %s\n",clients_list[i].vehicle.model);
            printf("Registration : %s\n",clients_list[i].vehicle.registration);
        }
    }

}// ver info carro ( penso que seja uma funcionalidade p/relatorio)

void trip_info() {

    int choice;
    do {
        printf("---Travels---\n\n");
        printf("1. Add trip\n");
        printf("2. Trip history\n");
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

    for (int i = 0; i < client_list_size; i++) {
        if (current_client_id == clients_list[i].ID) {
            printf("--Points Info--\n\n");
            printf("Points : %d\n",clients_list[i].VVPoints);
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
        printf("\n---Client Menu---\n\n");
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
                    for (int i = 0; i < client_list_size; i++) {//mostra os clientes id/nome
                        printf("Id: %d - Name: %s\n", clients_list[i].ID, clients_list[i].name);
                    }

                    printf("\n--Tell me your ID--\n");
                    scanf("%d", &current_client_id);

                    for (int i = 0; i < client_list_size; i++) {
                        if (current_client_id == clients_list[i].ID) {//entra na conta se o Id estiver
                                                                //correcto.
                            customer_area();
                        }
                    }
                    printf("\n-- 404 - Client not found --\n");
                    client_menu();
                }
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
