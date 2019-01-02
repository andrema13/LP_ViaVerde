#ifndef UTILIZADOR_H
#define UTILIZADOR_H
#include "time.h"

void user_menu();
void user_management();
void trip_management();
void price_management();
void distance_management();
void edit_prices();
int delete_client();
void search_trip();
void id_search(int id);
void day_search(int day);
void input_toll_search(int in_toll);
void exit_toll_search(int out_toll);
void price_search(float price);
void month_search(int month);
void year_search(int year);
void print_results(int print_id);

struct Results {
    int client_id;
    struct tm date;
    int choice_x;
    int choice_y;
    float trip_cost;
};
struct Results results_list[100];

#endif