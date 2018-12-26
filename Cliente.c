#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Veiculo.h"
#include "API_Leitura.h"
#include "Portico.h"
#include "Utils.h"
#include "time.h"
#include "Utilizador.h"
#include "Data.h"

void add_trip() {

    struct lanco matrix[NUM_PORTAGENS * NUM_PORTAGENS];
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
        add_trip();
    } else {
        printf("Success! Trip registered.\n");
        travel_cost = matrix[(choice_x - 1) * NUM_PORTAGENS + (choice_y - 1)].price;
        printf("Price: %f\n", travel_cost);
        printf("time: %d-%d-%d %d:%d:%d\n", tm.tm_mday,
               tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    }
}

void travel_history() {
    printf("travel history");
}

void client_info() {
    
    for(int i = 0; i < client_list_size; i++){
        if(current_client_id == clients_list[i].ID){
            printf("Id : %d\n",clients_list[i].ID);
            printf("Name : %s\n",clients_list[i].name);
        }
    }



}


void vehicle_info() {


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
                add_trip();
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
        printf("\n---Client Menu---\n\n");
        printf("1. Enter to your account\n");
        printf("2. Register new client\n");
        printf("3. Previous Menu\n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                if (client_list_size == 0) {
                    printf("No clients yet!");
                    client_menu();
                }
                else {
                    for (int i = 0; i < client_list_size; i++) {
                        printf("Id: %d - Name: %s\n", clients_list[i].ID, clients_list[i].name);
                    }

                    printf("\n--Tell me your ID--\n");
                    scanf("%d",&current_client_id);

                    for (int i = 0; i < client_list_size; i++) {
                        if (current_client_id == clients_list[i].ID) {
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

    if(client_list_size == 0) {
        client.ID = 1;
    }
    else {
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
