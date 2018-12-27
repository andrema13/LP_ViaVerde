#include "Viagem.h"
#include "time.h"
#include "Utils.h"
#include "Utilizador.h"
#include "API_Leitura.h"
#include "Data.h"


void add_trip() {

    struct lanco matrix[NUM_PORTAGENS * NUM_PORTAGENS];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int choice_x, choice_y;
    float travel_cost;
    struct Trip trip;

    fill_matrix(matrix, "../Precos.txt", false);
    show_prices();
    printf("Enter where you want to go:\n");
    readInt(&choice_x, 1, NUM_PORTAGENS, "Choose between 1-5:\nX:");
    readInt(&choice_y, 1, NUM_PORTAGENS, "Choose between 1-5:\nY:");
    travel_cost = matrix[(choice_x - 1) * NUM_PORTAGENS + (choice_y - 1)].price;

    if (travel_cost == 0) {/*verifica se o preço é = 0 e tambem verifica
                            se estamos a ir para o mesmo destino, ja que o preco tambem é 0*/
        printf("\nThis trip is not valid!\n");
        printf("Please try another one.\n");
        add_trip();
    } else {
        trip.client_id = current_client_id;
        trip.choice_x = choice_x;
        trip.choice_y = choice_y;
        trip.date = tm;
        trip.travel_cost = travel_cost;
        trips_list[trip_list_size++] = trip;
        write_trip_file();

        printf("Success! Trip registered.\n");
        printf("Price: %f\n", travel_cost);
        printf("time: %d-%d-%d %d:%d:%d\n", tm.tm_mday,
               tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    }
}

void trip_history() {

    int i;
    printf("--Trip History--\n\n");
    for (i = 0; i < trip_list_size; i++) {

        if (current_client_id == trips_list[i].client_id) {
            printf("** Trip nº%d **\n", i + 1);//adiciona-se o 1 para nao existir a viagem 0
            printf("Input Toll : %d\n", trips_list[i].choice_x);
            printf("Exit Toll : %d\n", trips_list[i].choice_y);
            printf("Date : %d/%d/%d\n",
                   trips_list[i].date.tm_mday,
                   trips_list[i].date.tm_mon,
                   trips_list[i].date.tm_year);
            printf("Hour: %d:%d:%d\n",
                   trips_list[i].date.tm_hour,
                   trips_list[i].date.tm_min,
                   trips_list[i].date.tm_sec);
            printf("Cost : %f€\n", trips_list[i].travel_cost);
        }
    }
}