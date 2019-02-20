#include <stdio.h>
#include <stdlib.h>
#include "API_Read.h"
#include "Client.h"
#include "User.h"
#include "Data.h"
#include "Trip.h"

/**
  * @brief Application start menu
  * Menu with the choice for the client or user part, or the program exit
  * In option 2 it is checked if there are clients only if a message is said saying that they do not exist
  * clients and the initial menu is shown again.
  * If clients exist then it is verified if the given id exists in registered clients
 */
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
                if (client_list_size == 0) {//if no clients
                    printf("\nNo clients yet!\n");

                } else {
                    id_verification(main_menu, user_menu);
                    //verify id is equal to registered's id
                }
                break;
            case 3:
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
  * @brief Main function
  * Performs the functions required to execute the program
  * The customer file is read
  * The travel file is read
  * @return 0 if success
 */
int main() {

    read_client_file();
    read_trip_file();
    main_menu();

    return 0;
}