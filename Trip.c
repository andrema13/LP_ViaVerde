#include "Trip.h"
#include "time.h"
#include "Utils.h"
#include "User.h"
#include "API_Read.h"
#include "Data.h"

/**
  * @brief Add trip
  * Function that adds a trip and records the time, date and points earned with it.
  * You are requested to choose a trip between x and y
  * A price is assigned to that choice and to its distance made
  * If the price of the trip is 0 then we are going to the same destination or it is not possible to travel in the
  * between x and y data.
  * If a successful trip is made then the customer id, the input portico,
  * the departure port, the date, the time, the cost of the trip, the distance made and the conversion is made
  * of travel cost to int and this value is assigned to points earned with the trip
  * The trip is added to the travel array and the position for the next trip is incremented
  * Write in the clients file to update the points
  * Write in the travel file the trip recorded
  * Displays travel trip data
 */
void add_trip() {

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int choice_x, choice_y;
    float trip_cost, total_distance;
    struct Trip trip;

    fill_matrix(price_matrix_list, "../Prices.txt", false);
    fill_matrix(distance_matrix_list, "../Distances.txt", true);
    show_prices();
    printf("Enter where you want to go:\n");
    readInt(&choice_x, 1, NUM_PORTAGENS, "Choose between 1-5:\nX:");
    readInt(&choice_y, 1, NUM_PORTAGENS, "Choose between 1-5:\nY:");
    trip_cost = price_matrix_list[(choice_x - 1) * NUM_PORTAGENS + (choice_y - 1)].price;
    total_distance = distance_matrix_list[(choice_x - 1) * NUM_PORTAGENS + (choice_y - 1)].distance;

    if (trip_cost == 0) {/* check if the price is = 0 and also check
                                     if we are going to the same destination, since the price is also 0 */
        printf("\nThis trip is not valid!\n");
        printf("Please try another one.\n");
        add_trip();
    } else {
        trip.client_id = current_client_id;
        trip.choice_x = choice_x;
        trip.choice_y = choice_y;
        trip.date = tm;
        trip.trip_cost = trip_cost;
        trip.distance = total_distance;// sum distance traveled by this client
        clients_list[current_client_id - 1].VVPoints = (int) trip_cost;// convert to int and sum the points
        trips_list[trip_list_size++] = trip;
        write_client_file();// to update in the client file the points
        write_trip_file();

        printf("Success! Trip registered.\n");
        printf("Price: %f\n", trip_cost);
        printf("Time: %d-%d-%d %d:%d:%d\n", tm.tm_mday,
               tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("Earned Points: %d\n", (int) trip_cost);
    }
}

/**
  * @brief Shows the distances matrix on the screen
  * Print the miles made in total by the selected client // to update in the client file the points
 */
void show_distance() {
    printf("--Total Distance--\n\n");
    float add_distance = 0;

    for (int i = 0; i < trip_list_size; i++) {
        if (current_client_id == trips_list[i].client_id) {
            add_distance += trips_list[i].distance;
        }
    }
    printf("You already have made %f km's in ViaVerde!\n", add_distance);
}

/**
  * @brief Registered trip history
  * Prints trips registered by the current customer
  * A message is also printed if there are no trips registered yet
 */
void trip_history() {

    int i;
    int trip_count = 1;
    printf("--Trip History--\n\n");

    for (i = 0; i < trip_list_size; i++) {

        if (current_client_id == trips_list[i].client_id) {
            printf("** Trip nº%d **\n", trip_count++);
            printf("Input Toll : %d\n", trips_list[i].choice_x);
            printf("Exit Toll : %d\n", trips_list[i].choice_y);
            printf("Date : %d/%d/%d\n",
                   trips_list[i].date.tm_mday,
                   trips_list[i].date.tm_mon + 1,
                   trips_list[i].date.tm_year + 1900);
            printf("Hour: %d:%d:%d\n",
                   trips_list[i].date.tm_hour,
                   trips_list[i].date.tm_min,
                   trips_list[i].date.tm_sec);
            printf("Cost : %f€\n\n", trips_list[i].trip_cost);
        }
    }
    if (trip_count == 1) {// arriving here and given that if there are no trips registered
           // the trip count will be 1 so there are no trips yet
        printf("No trips registered yet!\n");
    }
}

/**
  * @brief Extract generated
  * A month and a specific year is requested
  * It is checked if there is travel of the current client
  * Search by month and year data
  * The header of the results is printed
  * If no trips are found a message is printed
  * At the end, the total price of the trips found is also printed
 */
void extracts_page() {

    int month, year, get_year = trips_list->date.tm_year + 1900, results = 0;
    float total_price = 0;

    printf("--Extract Page--\n\n");
    printf("Tell me the month : ");
    readInt(&month, 1, 12, "Between 1-12 : ");
    readInt(&year, 1900, get_year, "Tell me the year : ");

    for (int i = 0; i < trip_list_size; i++) {

        if (current_client_id == trips_list[i].client_id && 
            trips_list[i].date.tm_mon + 1 == month &&      
            trips_list[i].date.tm_year + 1900 == year) {

            if (results == 0) {
                printf("*** Extract %d/%d ***\n\n", month, year);
                printf("Client ID  Input-Exit      Date       Hour        Price\n");
            }
            printf("   %d          %d-%d       %d/%d/%d   %d:%d:%d \t %f\n",
                   trips_list[i].client_id,
                   trips_list[i].choice_x,
                   trips_list[i].choice_y,
                   trips_list[i].date.tm_mday,
                   trips_list[i].date.tm_mon + 1,
                   trips_list[i].date.tm_year + 1900,
                   trips_list[i].date.tm_hour,
                   trips_list[i].date.tm_min,
                   trips_list[i].date.tm_sec,
                   trips_list[i].trip_cost);
            total_price += trips_list[i].trip_cost;
            results++;
        }
    }
    if (results == 0) {
        printf("\n** 404 - Extract not found **\n");
    } else {
        printf("\n                                         Total: %f€\n\n", total_price);
    }
}
