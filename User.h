#ifndef UTILIZADOR_H
#define UTILIZADOR_H

#include "time.h"
#include "Data.h"

#define MAX_FILTERS 3

void user_menu();

void user_management();

void trip_management();

void price_management();

void distance_management();

void edit_prices();

void delete_client_data();

void edit_client();

void search_trip();

void id_search(int id, struct Trip *results_list, int *results_list_size);

void day_search(int day, struct Trip *results_list, int *results_list_size);

void input_toll_search(int input_toll, struct Trip *results_list, int *results_list_size);

void exit_toll_search(int exit_toll, struct Trip *results_list, int *results_list_size);

void price_search(float price, struct Trip *results_list, int *results_list_size);

void month_search(int month, struct Trip *results_list, int *results_list_size);

void year_search(int year, struct Trip *results_list, int *results_list_size);

void print_results(struct Trip *results_list, int results_list_size);

void search_user();

void print_clients();

void delete_trips(int delete_id);


#endif