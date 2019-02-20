#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "Utils.h"

struct Lanco price_matrix_list[NUM_PORTAGENS * NUM_PORTAGENS];
struct Lanco distance_matrix_list[NUM_PORTAGENS * NUM_PORTAGENS];

int client_list_size = 0, trip_list_size = 0;
int client_list_max_size = LIST_SIZE;
int trip_list_max_size = TRIP_SIZE;

/**
 * @brief Read the registered clients file
  * The file is opened in read mode
  * Verified if it really does not exist if an error occurs
  * Declared the indicated structure and while not reaching the end of the file is read the information
  * by the corresponding fields
  * Memory is allocated for the stipulated limit (10) and
  * if necessary is allocated a further 10 in this case
  * If no reallocation exists, an error message is printed
  * If successful, the memory space is then reallocated
  * The client is added to the client list and the value of the array is incremented.
  * The value of the array size of the clients is assigned to the variable client_list_size
  * The file is closed by the end.
 **/
void read_client_file() {

    struct Client *clients_list = NULL;
    struct Client *temp = NULL;

    clients_list = (struct Client *) malloc(client_list_max_size * sizeof(struct Client));

    FILE *file;
    int i = 0;
    file = fopen("../client_info.txt", "r");

    if (file == NULL) {
        perror("Error: ");
    } else {
        struct Client client;

        while (fscanf(file, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d",
                      &client.ID, client.name, client.NIF,
                      client.CC, client.NIB, client.street,
                      client.vehicle.manufacturer, client.vehicle.model,
                      client.vehicle.registration,
                      &client.VVPoints
        ) != EOF) {

            if (i + 1 > client_list_max_size) {
                temp = (struct Client *) realloc(clients_list,
                                                 client_list_max_size * sizeof(struct Client) +
                                                 LIST_SIZE * sizeof(struct Client));

                if (temp == NULL) {

                    printf("Memory Allocation failed!");
                    break;
                } else {
                    clients_list = temp;
                    client_list_max_size += LIST_SIZE;
                }
            }

            clients_list[i] = client;
            i++;
        }
    }
    client_list_size = i;

    fclose(file);
}
/**
 * @brief Writing to clients file
 * The client file is opened in write mode
 * The information of the customer and the respective vehicle are then written for each field separated by commas
 * Until you reach the end of the file, write the information
 * The file is closed
 */
void write_client_file() {

    int i, c;
    FILE *file;

    file = fopen("../client_info.txt", "w");//Creates an empty file for writing.
    // If a file with the same name already exists,
    // its content is erased and the file is considered as a new empty file.

    for (i = 0; i < client_list_size; i++) {

        fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%d\n",
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
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
    fclose(file);
}

/**
 * @brief Reading of registered trip file
  * The file is opened in read mode
  * Verified if it really does not exist if an error occurs
  * Declared the indicated structure and while not reaching the end of the file is read the information
  * by the corresponding fields
  * Memory is allocated for the stipulated limit (100) and if necessary is allocated another 100 in this case
  * If no reallocation exists, an error message is printed
  * If successful, the memory space is then reallocated
  * The trip is added to the travel list and the value of the array is incremented.
  * The trip array size value is assigned to the trip_list_size variable
  * The file is closed by the end.
 */
void read_trip_file() {

    struct Trip *trips_list = NULL;
    struct Trip *trip_temp = NULL;

    trips_list = (struct Trip *) malloc(trip_list_max_size * sizeof(struct Trip));

    FILE *file;
    int i = 0;
    file = fopen("../trip_registration.txt", "r");
    if (file == NULL) {
        perror("Error: ");
    } else {
        struct Trip trip;

        while (fscanf(file, "%d,%d,%d,%d/%d/%d,%d:%d:%d,%f,%f",
                      &trip.client_id,
                      &trip.choice_x,
                      &trip.choice_y,
                      &trip.date.tm_mday,
                      &trip.date.tm_mon,
                      &trip.date.tm_year,
                      &trip.date.tm_hour,
                      &trip.date.tm_min,
                      &trip.date.tm_sec,
                      &trip.distance,
                      &trip.trip_cost
        ) != EOF) {
            if (i + 1 > trip_list_max_size) {
                trip_temp = (struct Trip *) realloc(trips_list,
                                                    trip_list_max_size * sizeof(struct Trip) +
                                                    TRIP_SIZE * sizeof(struct Trip));

                if (trip_temp == NULL) {

                    printf("Memory failed!");
                    break;
                } else {
                    trips_list = trip_temp;
                    trip_list_max_size += TRIP_SIZE;
                }
            }
            trips_list[i] = trip;
            i++;
        }
    }
    trip_list_size = i;

    fclose(file);
}

/**
 * @brief Writing in the trip file
  * The client file is opened in write mode
  * Customer trips are then written for each field separated by commas
  * Until you reach the end of the file, write the information
  * The file is closed
 */
void write_trip_file() {

    int i, c;
    FILE *file;

    file = fopen("../trip_registration.txt", "w");//Creates an empty file for writing.
    // If a file with the same name already exists,
    // its content is erased and the file is considered as a new empty file.

    for (i = 0; i < trip_list_size; i++) {

        fprintf(file, "%d,%d,%d,%d/%d/%d,%d:%d:%d,%f,%f\n",
                trips_list[i].client_id,
                trips_list[i].choice_x,
                trips_list[i].choice_y,
                trips_list[i].date.tm_mday,
                trips_list[i].date.tm_mon,//plus +1
                trips_list[i].date.tm_year,//plus +1900
                trips_list[i].date.tm_hour,
                trips_list[i].date.tm_min,
                trips_list[i].date.tm_sec,
                trips_list[i].distance,
                trips_list[i].trip_cost);
    }
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
    fclose(file);
}

/**
 * @brief Shows the price matrix on the screen
  * Fills the price matrix and false is relative to the isDistance parameter
  * The matrix and its caption at the bottom and its header are then printed on the screen.
 */
void show_prices() {

    fill_matrix(price_matrix_list, "../Prices.txt", false);
    int i, j;

    printf("---Prices---\n\n");
    printf("X/Y     1           2           3           4          5\n");

    for (i = 0; i < NUM_PORTAGENS; i++) {
        printf("%d\t", i + 1);

        for (j = 0; j < NUM_PORTAGENS; j++) {
            printf("%f\t ", price_matrix_list[i * NUM_PORTAGENS + j].price);
        }
        printf("\n");
    }
    printf("-Legend-\n1-Braga  2-Porto  3-Coimbra  4-Lisboa  5-Algarve\n");
}

/**
  * @brief Shows the distance matrix on the screen
  * Fills the distance matrix and true is relative to the isDistance parameter
  * The matrix and its caption at the bottom and its header are then printed on the screen.
 */
void show_distances() {

    fill_matrix(distance_matrix_list, "../Distances.txt", true);
    int i, j;

    printf("---Distances---\n\n");
    printf("X/Y     1           2           3           4          5\n");

    for (i = 0; i < NUM_PORTAGENS; i++) {
        printf("%d\t", i + 1);

        for (j = 0; j < NUM_PORTAGENS; j++) {
            printf("%f\t ", distance_matrix_list[i * NUM_PORTAGENS + j].distance);
        }
        printf("\n");
    }
    printf("-Legend-\n1-Braga  2-Porto  3-Coimbra  4-Lisboa  5-Algarve\n");
}

