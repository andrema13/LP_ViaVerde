#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Client.h"
#include "API_Read.h"
#include "API_Utils.h"
#include "Utils.h"
#include "User.h"
#include "Data.h"
#include "Trip.h"

/**
 *@brief Displays customer information if your id is equal to an id of the customer list
 */
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

/**
 * @brief Displays the information of the associated vehicle with the customer,
if the client id is equal to an id of the client list
 */
void vehicle_info() {

    for (int i = 0; i < client_list_size; i++) {
        if (current_client_id == clients_list[i].ID) {
            printf("--Vehicle Info--\n\n");
            printf("Manufacturer : %s\n", clients_list[i].vehicle.manufacturer);
            printf("Model : %s\n", clients_list[i].vehicle.model);
            printf("Registration : %s\n", clients_list[i].vehicle.registration);
        }
    }

}
/**
 * @brief In this function we have a menu where it is possible:
 * Add a new trip to the current customer
 * View the client's trip history currently on the show
 * See the total number of kilometers traveled by the customer in all his use of Via Verde
 * Back to previous menu
 * Exit program
 */
void trip_info() {

    int choice;
    do {
        printf("---Trips---\n\n");
        printf("1. Add trip\n");
        printf("2. Trip history\n");
        printf("3. Total Distance\n");
        printf("4. Previous Menu \n");
        printf("5. Exit\n");
        readInt(&choice, 1, 5, "Choose an option: ");

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
                show_distance();
                break;
            case 4:
                system("clear");
                break;
            case 5:
                printf("\nSee you soon! ;\051");
                free(clients_list);
                free(trips_list);
                exit(0);
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 4);
}

/**
 * @brief Check the statements available to the client that is currently on the program
 * Back to previous menu
 * Exit program
 */
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
                system("clear");
                break;
            case 3:
                printf("\nSee you soon! ;\051");
                free(clients_list);
                free(trips_list);
                exit(0);

            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 2);
}

/**
  * Sums points obtained from trips made by the current customer
  * Check the total of points accumulated by the current customer
  * @return the customer's current number of points
 */
int points_info() {

    int total_points = 0;
    for (int i = 0; i < trip_list_size; i++) {
        if (current_client_id == trips_list[i].client_id) {
            total_points += (int) trips_list[i].trip_cost;
        }
    }
    printf("--Points Info--\n\n");
    printf("Points : %d\n", total_points);

    return total_points;
}
/**
  * @brief This is the client's home menu as soon as you log in, so you can see:
  * Your registered personal information
  * The data of your associated vehicle
  * Enter the travel menu, so you can add trips and check your history
  * Generate an extract of trips already made
  * Check your accumulated points
  * Return to previous menu (customer menu)
  * Quit the program
 */
void customer_area() {

    int choice;
    do {
        printf("---Customer area---\n\n");
        printf("1. Costumer Data\n");
        printf("2. Vehicle Data\n");
        printf("3. Trips\n");
        printf("4. Extracts\n");
        printf("5. Points\n");
        printf("6. Previous Menu\n");
        printf("7. Exit\n");
        readInt(&choice, 1, 7, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                client_info();
                break;
            case 2:
                system("clear");
                vehicle_info();
                break;
            case 3:
                system("clear");
                trip_info();
                break;
            case 4:
                system("clear");
                extracts_info();
                break;
            case 5:
                system("clear");
                points_info();
                break;
            case 6:
                system("clear");
                client_menu();
                break;
            case 7:
                printf("\nSee you soon! ;\051");
                free(clients_list);
                free(trips_list);
                exit(0);
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 6);
}

/**
  * @brief Customer part menu
  * Login to your account through the indicated id
  * Register a new customer
  * Return to the previous menu (initial screen)
  * Quit the program
 */
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
                if (client_list_size == 0) {//if no clients
                    printf("\nNo clients yet!\n");
                    client_menu();
                } else {
                    id_verification(client_menu, customer_area);
                    //verify if id exists in registered clients
                }
                break;

            case 2:
                system("clear");
                printf("\nEnter your data: \n");
                new_client();
                printf("\nRegistered successfully!\n");
                break;
            case 3:
                system("clear");
                break;
            case 4:
                printf("\nSee you soon! ;\051");
                free(clients_list);
                free(trips_list);
                exit(0);

            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 3);
}

/**
  * @brief This is a function that verifies if the given id exists in the already registered clients,
  * if it does not exist, a new id will be requested
  * @param f - A pointer that expects a function with no arguments and no return
  * @param e - Pointer that expects a function without arguments and without return
  * First customers will be printed already registered
  * A user id will be requested later
  * It is checked if the id corresponds to the ids already registered in the program
  * If the user enters your account (client / user)
  * If it does not match, prints a message and asks for a new id
  * The respective cleaning of the input is also effected for a new login attempt
 */
void id_verification(void (*f)(void), void (*e)(void)) {

    printf("--Registered Clients--\n");
    for (int i = 0; i < client_list_size; i++) {
        printf("Id: %d - Name: %s\n", clients_list[i].ID, clients_list[i].name);
    }

    printf("\n--Tell me your ID--\n");
    current_client_id = 0;
    scanf(" %d", &current_client_id);

    for (int i = 0; i < client_list_size; i++) {

        if (current_client_id == clients_list[i].ID) {
            system("clear");
            (*e)();
            return;
        }
    }
    printf("** 404 - Client not found **\n");
    system("clear");
    cleanInputBuffer();
    id_verification((*f), (*e));
}

/**
  * @brief Registration of a new customer
  * A unique id is assigned, if there are no clients yet, the id assigned to this new one
  * registration will be 1. If clients already exist, the last client is verified (position in the array)
  * and 1 is added.
  * Information is requested to be registered a new customer, such as:
  * Name, NIF, Citizen Card, NIB, Street, Vehicle Make, Model and vehicle registration.
  * The corresponding points are assigned so that it will start at 0, in the case of a new client.
  * It is then inserted into the customer array the new client with the information given and is incrmented
  * a position for the next client to be registered
  * write_cliente_file () is the function responsible for writing to the client file its registration
  * The id assigned to this new customer is also shown on the screen.
 */
void new_client() {

    struct Client client;
    if (client_list_size == 0) {
        client.ID = 1;
    } else {
        client.ID = clients_list[client_list_size - 1].ID + 1;
    }

    input_validation(client.name, "Name: ", 20);
    input_validation(client.NIF, "NIF : ", 10);
    input_validation(client.CC, "CC : ", 9);
    input_validation(client.NIB, "NIB: ", 22);
    input_validation(client.street, "Street: ", 40);
    printf("\nEnter your vehicle information: \n ");
    input_validation(client.vehicle.manufacturer, "Manufacturer: ", 12);
    input_validation(client.vehicle.model, "Model: ", 12);
    input_validation(client.vehicle.registration, "Registration: ", 10);
    client.VVPoints = 0;

    clients_list[client_list_size++] = client;
    write_client_file();
    printf("Your ID is: %d", client.ID);
}

/**
  * @brief Validation of input
  * It is validated if the user has entered a comma so it is not possible to insert it
  * @param str string to be validated
 */

void input_validation(char *str, char *msg, const unsigned int size) {
    readString(str, size, msg);
    for (int i = 0; i < strlen(str); i++) {
        if (44 == str[i]) {
            printf("Cannot have commas, please try again!");
            input_validation(str, msg, size);
        }
    }
}
