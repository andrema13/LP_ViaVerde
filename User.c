#include <stdio.h>
#include <stdlib.h>
#include "User.h"
#include "API_Read.h"
#include "API_Utils.h"
#include "Utils.h"
#include "Client.h"
#include "Trip.h"
#include "Data.h"

void user_management() {

    int choice;
    do {
        printf("---User Management---\n\n");
        printf("1. Create new user\n");
        printf("2. Edit user\n");
        printf("3. Remove user\n");
        printf("4. Search\\list user\n");
        printf("5. Previous Menu\n");
        printf("6. Exit\n");
        readInt(&choice, 1, 6, "Choose an option: ");
        switch (choice) {
            case 1:
                system("clear");
                printf("\nEnter new client data: \n");
                new_client();
                printf("\nRegistered successfully!\n");
                break;
            case 2:
                system("clear");
                edit_client();
                break;
            case 3:
                system("clear");
                delete_client_data();
                break;
            case 4:
                system("clear");
                search_user();
                break;
            case 5:
                system("clear");
                break;
            case 6:
                printf("\nSee you soon! ;\051");
                free(clients_list);
                free(trips_list);
                exit(0);
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 5);
}
void trip_management() {

    int choice;
    do {
        printf("---Trip Management---\n\n");
        printf("1. Add trip\n");
        printf("2. Search trips\n");
        printf("3. Previous Menu\n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");
        switch (choice) {
            case 1:
                system("clear");
                add_trip();
                break;
            case 2:
                system("clear");
                search_trip();
                break;
            case 3:
                system("clear");
                break;
            case 4:
                printf("\nSee you soon!;\051");
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
 * @brief Trip Search
 * It's possible to search for different filters as well as to use the combination of two filters
 */

void search_trip() {

    int choice, input_id, day, month, year, input_toll, exit_toll;
    float price;
    int filters[MAX_FILTERS];
    int filters_size = 0;
    int results_list_size = 0;

    printf("--Search Trips--\n\n"
           "-Filters-\n"
           "1.Client ID(Vehicle)\n"
           "2.Day\n"
           "3.Month\n"
           "4.Year\n"
           "5.Input toll\n"
           "6.Exit toll\n"
           "7.Price\n"
           "0.Stop filters\n"
           "Note : You only can choose 3 filters(max) to do the search.\n"
    );
    do {// here the filters (3-max) are chosen until 0 is clicked
        readInt(&choice, 0, 7, "Pick a filter : ");
        if (choice != 0) {
            filters[filters_size] = choice;
            filters_size++;
        }
    } while (choice != 0 && filters_size < MAX_FILTERS);

    for (int i = 0; i < filters_size; i++) {//Verify if exists equals filters
        for (int j = i; j < filters_size; j++) {
            if (filters[i] == filters[j+1]) {
                printf("Cannot choose the same filter, try again\n");
                search_trip();
            }
        }
    }

    struct Trip results_list[trip_list_size];
    for (int i = 0; i < trip_list_size; i++) {
        results_list[i] = trips_list[i];
        // copy the saved trips to the new array results_list
    }
    results_list_size = trip_list_size;

    for (int i = 0; i < filters_size; i++) {

        switch (filters[i]) {

            case 1:
                printf("Client ID : ");
                scanf("%d", &input_id);
                id_search(input_id, results_list, &results_list_size);
                break;
            case 2:
                printf("Day : ");
                scanf("%d", &day);
                day_search(day, results_list, &results_list_size);
                break;
            case 3:
                printf("Month : \n");
                scanf("%d", &month);
                month_search(month, results_list, &results_list_size);
                break;
            case 4:
                printf("Year : \n");
                scanf("%d", &year);
                year_search(year, results_list, &results_list_size);
                break;
            case 5:
                printf("Input toll : \n");
                scanf("%d", &input_toll);
                input_toll_search(input_toll, results_list, &results_list_size);
                break;
            case 6:
                printf("Exit toll : \n");
                scanf("%d", &exit_toll);
                exit_toll_search(exit_toll, results_list, &results_list_size);
                break;
            case 7:
                printf("Price : \n");
                scanf("%f", &price);
                price_search(price, results_list, &results_list_size);
                break;
            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    }
    print_results(results_list, results_list_size);
    trip_management();
}

/**
 * Prints the results of the given filters
 * @param results_list
 * @param results_list_size
 */
void print_results(struct Trip *results_list, int results_list_size) {

    for (int i = 0; i < results_list_size; i++) {

        if (i == 0) {
            printf("Client_ID   Input-Exit      Date       Hour        Price\n");
        }
        printf("   %d          %d-%d       %d/%d/%d   %d:%d:%d \t %f\n",
               results_list[i].client_id,
               results_list[i].choice_x,
               results_list[i].choice_y,
               results_list[i].date.tm_mday,
               results_list[i].date.tm_mon + 1,
               results_list[i].date.tm_year + 1900,
               results_list[i].date.tm_hour,
               results_list[i].date.tm_min,
               results_list[i].date.tm_sec,
               results_list[i].trip_cost);
    }
}

/**
 * Filter the results
 * @param id
 * @param results_list
 * @param results_list_size
 */
void id_search(int id, struct Trip *results_list, int *results_list_size) {
    for (int i = 0; i < *results_list_size; i++) {
        if (id != results_list[i].client_id) {
            for (int j = i; j < *results_list_size; j++) {
                results_list[j] = results_list[j + 1];
            }
            i--;
            *results_list_size -= 1;
        }
    }
}

/**
 * Filter the results
 * @param day
 * @param results_list
 * @param results_list_size
 */
void day_search(int day, struct Trip *results_list, int *results_list_size) {
    for (int i = 0; i < *results_list_size; i++) {
        if (day != results_list[i].date.tm_mday) {
            for (int j = i; j < *results_list_size; j++) {
                results_list[j] = results_list[j + 1];
            }
            i--;
            *results_list_size -= 1;
        }
    }
}

/**
 * Filter the results
 * @param month
 * @param results_list
 * @param results_list_size
 */
void month_search(int month, struct Trip *results_list, int *results_list_size) {
    for (int i = 0; i < *results_list_size; i++) {
        if (month != results_list[i].date.tm_mon + 1) {
            for (int j = i; j < *results_list_size; j++) {
                results_list[j] = results_list[j + 1];
            }
            i--;
            *results_list_size -= 1;
        }
    }
}

/**
 * Filter the results
 * @param year
 * @param results_list
 * @param results_list_size
 */
void year_search(int year, struct Trip *results_list, int *results_list_size) {
    for (int i = 0; i < *results_list_size; i++) {
        if (year != results_list[i].date.tm_year + 1900) {
            for (int j = i; j < *results_list_size; j++) {
                results_list[j] = results_list[j + 1];
            }
            i--;
            *results_list_size -= 1;
        }
    }
}

/**
  * @brief Search for registered trip (input toll)
  * The given id will have to be equal to one registered in the trips
  * @param input_toll - input port provided when choosing filters
*/
void input_toll_search(int input_toll, struct Trip *results_list, int *results_list_size) {
    for (int i = 0; i < *results_list_size; i++) {
        if (input_toll != results_list[i].choice_x) {
            for (int j = i; j < *results_list_size; j++) {
                results_list[j] = results_list[j + 1];
            }
            i--;
            *results_list_size -= 1;
        }
    }
}

/**
  * @brief Search for travel (exit toll)
  * The given id will have to be equal to one registered in the trips
  * @param exit_toll - output port provided when choosing filters
 */
void exit_toll_search(int exit_toll, struct Trip *results_list, int *results_list_size) {
    for (int i = 0; i < *results_list_size; i++) {
        if (exit_toll != results_list[i].choice_y) {
            for (int j = i; j < *results_list_size; j++) {
                results_list[j] = results_list[j + 1];
            }
            i--;
            *results_list_size -= 1;
        }
    }
}

/**
  * @brief Search for registered travel (price of the trip)
  * The given id will have to be equal to one registered in the trips
  * @param price - price provided when choosing filters
 */
void price_search(float price, struct Trip *results_list, int *results_list_size) {
    for (int i = 0; i < *results_list_size; i++) {
        if (price != results_list[i].trip_cost) {
            for (int j = i; j < *results_list_size; j++) {
                results_list[j] = results_list[j + 1];
            }
            i--;
            *results_list_size -= 1;
        }
    }
}

/**
  * @brief pricing management
  * See current rate card
  * Edit the price list
  * Previous menu
  * Quit the program
 */
void price_management() {
    int choice;
    do {
        printf("\n---Price Management---\n\n");
        printf("1. Show Prices\n");
        printf("2. Edit Prices\n");
        printf("3. Previous Menu\n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");
        switch (choice) {

            case 1:
                system("clear");
                show_prices();
                break;
            case 2:
                system("clear");
                edit_prices();
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
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 3);
}

/**
  * @brief Distance Management
  * Is the distance matrix filled, isDistance? true (Param)
  * Shows matrix on screen
  * You are prompted to choose the distance to be edited by the x and y axes
  * If the choices of x and y are equal, it is not allowed to edit, and it is returned to show the matrix in the screen
  * If they are different choices you are asked to enter a number between 0-100 as a new distance
  * The new distance is written in the matrix replacing the old one
  * Displays matrix with updated distances
 */
void distance_management() {

    int choice_x, choice_y;
    float new_distance;

    fill_matrix(distance_matrix_list, "../Distances.txt", true);
    printf("\n---Distance Management---\n\n");
    show_distances();
    printf("Enter the distance to edit:\n");
    readInt(&choice_x, 1, NUM_PORTAGENS, "Choose between 1-5:\nX:\n");
    readInt(&choice_y, 1, NUM_PORTAGENS, "Choose between 1-5:\nY:\n");

    if (choice_x == choice_y) {
        printf("Cannot edit this distance.\n");
        printf("Please try another one.\n");
        distance_management();
    } else {
        printf("Enter the new distance:\n");
        readFloat(&new_distance, 0, 100, "Choose between 0-100: ");
        distance_matrix_list[(choice_x - 1) * NUM_PORTAGENS + (choice_y - 1)].distance = new_distance;
        write_matrix(distance_matrix_list, "../Distances.txt", false);
        system("clear");
        show_distances();
    }
}

/**
  * @brief User Menu
  * Customer management
  * Travel management
  * Management of prices
  * Travel management
  * Generation of invoices
  * Previous menu
  * Quit the program
 */

void user_menu() {

    int choice;
    do {
        printf("---User Area---\n\n");
        printf("1. User Management\n");
        printf("2. Trip Management\n");
        printf("3. Price Management\n");
        printf("4. Distance Management\n");
        printf("5. Invoice Generation\n");
        printf("6. Previous Menu\n");
        printf("7. Exit\n");
        readInt(&choice, 1, 7, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                user_management();
                break;
            case 2:
                system("clear");
                trip_management();
                break;
            case 3:
                system("clear");
                price_management();
                break;
            case 4:
                system("clear");
                distance_management();
                break;
            case 5:
                system("clear");
                extracts_page();
                break;
            case 6:
                system("clear");
                break;
            case 7:
                printf("\nSee you soon! ;\051");
                free(clients_list);
                free(trips_list);
                exit(0);
            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 6);
}

/**
* @brief Edit tabulated prices
  * Is the matrix of prices filled, isDistance? false (Param)
  * Shows matrix on screen
  * You are asked to choose the price to be edited by the axes x and y
  * If the choices of x and y are equal, it is not allowed to edit,
    and it is returned to show the matrix in the screen
  * If they are different choices you are asked to enter a number between 0-100 as new price
  * The new price is written in the matrix replacing the old one
  * Displays the matrix with updated prices
 */
void edit_prices() {

    int choice_x, choice_y;
    float new_price;

    fill_matrix(price_matrix_list, "../Prices.txt", false);
    show_prices();
    printf("Enter the price to edit:\n");
    readInt(&choice_x, 1, NUM_PORTAGENS, "Choose between 1-5:\nX:\n");
    readInt(&choice_y, 1, NUM_PORTAGENS, "Choose between 1-5:\nY:\n");

    if (choice_x == choice_y) {
        printf("Cannot edit this price.\n");
        printf("Please try another one.\n");
        edit_prices();
    } else {
        printf("Enter the new price:\n");
        readFloat(&new_price, 0, 100, "Choose between 0-100: ");
        price_matrix_list[(choice_x - 1) * NUM_PORTAGENS + (choice_y - 1)].price = new_price;
        write_matrix(price_matrix_list, "../Prices.txt", true);
        system("clear");
        show_prices();
    }
}

/**
  * Edit customer
  * Shows the fields to be edited
  * The field to be edited is requested and if successful it is written in the file
 */
void edit_client() {

    int choice, flag;
    char name_edited[20], edit_NIF[10], edit_CC[9],
            edit_NIB[22], edit_street[40], edit_manufacturer[12], edit_model[12], edit_regist[10];

    client_info();

    printf("\n--Edit Fields--\n\n"

           "1.Name\n"
           "2.NIF\n"
           "3.CC\n"
           "4.NIB\n"
           "5.Street\n"
           "6.Manufacturer\n"
           "7.Model\n"
           "8.Registration\n"
           "0.Exit\n"
    );
    readInt(&choice, 0, 8, "Pick a field : ");

    switch (choice) {

        case 0:
            system("clear");
            break;

        case 1:

            readString(name_edited, 20, "Enter new client name: ");
            readInt(&flag, 0, 1, "You want save the information? Yes press 1, No press 0");

            if (flag == 1) {
                strcpy(clients_list[current_client_id - 1].name, name_edited);
                write_client_file();
                printf("Successfully edited!");
                edit_client();
            } else {
                user_management();
            }
            break;
        case 2:
            readString(edit_NIF, 10, "Enter new NIF : ");
            readInt(&flag, 0, 1, "You want save the information? Yes press 1, No press 0");

            if (flag == 1) {
                strcpy(clients_list[current_client_id - 1].NIF, edit_NIF);
                printf("Successfully edited!");
                edit_client();
            } else {
                user_management();
            }
            break;
        case 3:
            readString(edit_CC, 9, "Enter new CC : ");
            readInt(&flag, 0, 1, "You want save the information? Yes press 1, No press 0");

            if (flag == 1) {
                strcpy(clients_list[current_client_id - 1].CC, edit_CC);
                write_client_file();
                printf("Successfully edited!");
                edit_client();
            } else {
                user_management();
            }
            break;
        case 4:
            readString(edit_NIB, 22, "Enter new NIB : ");
            readInt(&flag, 0, 1, "You want save the information? Yes press 1, No press 0");

            if (flag == 1) {
                strcpy(clients_list[current_client_id - 1].NIB, edit_NIB);
                write_client_file();
                printf("Successfully edited!");
                edit_client();
            } else {
                user_management();
            }
            break;
        case 5:
            readString(edit_street, 40, "Enter new street: ");
            readInt(&flag, 0, 1, "You want save the information? Yes press 1, No press 0");

            if (flag == 1) {
                strcpy(clients_list[current_client_id - 1].street, edit_street);
                write_client_file();
                printf("Successfully edited!");
                edit_client();
            } else {
                user_management();
            }
            break;
        case 6:
            readString(edit_manufacturer, 12, "Enter new manufacturer : ");
            readInt(&flag, 0, 1, "You want save the information? Yes press 1, No press 0");

            if (flag == 1) {
                strcpy(clients_list[current_client_id - 1].vehicle.manufacturer,
                       edit_manufacturer);
                write_client_file();
                printf("Successfully edited!");
                edit_client();
            } else {
                user_management();
            }
            break;
        case 7:
            readString(edit_model, 12, "Enter new model : ");
            readInt(&flag, 0, 1, "You want save the information? Yes press 1, No press 0");

            if (flag == 1) {
                strcpy(clients_list[current_client_id - 1].vehicle.model,
                       edit_model);
                write_client_file();
                printf("Successfully edited!");
                edit_client();
            } else {
                user_management();
            }
        case 8:
            readString(edit_regist, 10, "Enter new registration : ");
            readInt(&flag, 0, 1, "You want save the information? Yes press 1, No press 0");

            if (flag == 1) {
                strcpy(clients_list[current_client_id - 1].vehicle.registration,
                       edit_regist);
                write_client_file();
                printf("Successfully edited!");
                edit_client();
            } else {
                user_management();
            }
        default:
            printf("Wrong choice. Try again\n");
            break;
    }
}

/**
  * @brief Search for customer
  * Displays customer information if your id is equal to a customer list id
*/
void search_user() {

    unsigned int id;
    int results = 0;

    printf("--Search Client--\n\n");

    do {
        printf("Tell me the ID you want to search : ");
        printf("\n*Press 0 to exit*\n");
        scanf("%d", &id);

        for (int i = 0; i < client_list_size; i++) {

            if (clients_list[i].ID == id) {
                printf("--Client Info--\n\n");
                printf("ID : %d\n", clients_list[i].ID);
                printf("Name : %s\n", clients_list[i].name);
                printf("NIF : %s\n", clients_list[i].NIF);
                printf("CC : %s\n", clients_list[i].CC);
                printf("NIB : %s\n", clients_list[i].NIB);
                printf("Street : %s\n", clients_list[i].street);
                results++;
            }
        }
        cleanInputBuffer();
        if (results == 0) {
            printf("\n** 404 - Client not found **\n");
        }

    } while (id != 0);
}

/**
  * @brief Erase data from a registered client
  * Shows current customers
  * You are prompted for an id to be deleted
  * This id is searched and deleted from the system if it is found
  * Print on screen the current list of updated clients
 */
void delete_client_data() {

    int delete_id, results = 0;

    printf("--Registered Clients--\n\n");
    print_clients();

    printf("Choose the client ID who want to delete : ");
    scanf("%d", &delete_id);

    for (int i = 0; i < client_list_size; i++) {
        if (clients_list[i].ID == delete_id) {
            clients_list[i] = clients_list[i + 1];
            results++;
        }
    }
    if (results == 0) {
        printf("\n** 404 - Client not found **\n");
    } else {
        client_list_size--;
        write_client_file();
        printf("--Clients after delete--\n\n");
        print_clients();
    }
    delete_trips(delete_id);
}

/**
  * Prints existing clients in the application
 */
void print_clients() {

    for (int i = 0; i < client_list_size; i++) {

        if (i == 0) {
            printf("ID        Name       NIF       CC        NIB         Street      Manufacturer"
                   "   Model     Registration\n");
        }
        printf("%d   %s   %s   %s   %s   %s   %s   %s   %s   %d\n",
               clients_list[i].ID,
               clients_list[i].name,
               clients_list[i].NIF,
               clients_list[i].CC,
               clients_list[i].NIB,
               clients_list[i].street,
               clients_list[i].vehicle.manufacturer,
               clients_list[i].vehicle.model,
               clients_list[i].vehicle.registration,
               clients_list[i].VVPoints);
    }
}

/**
 * Clears the trips of the selected customer
 * @param delete_id
 */
void delete_trips(int delete_id) {

    for (int i = 0; i < trip_list_size; i++) {
        if (trips_list[i].client_id == delete_id) {
            for (int j = i; j < trip_list_size; j++) {
                trips_list[j] = trips_list[j + 1];
            }
            i--;
            trip_list_size--;
        }
    }
    write_trip_file();
}
