#include "Viagem.h"
#include "time.h"
#include "Utils.h"
#include "Utilizador.h"
#include "API_Leitura.h"
#include "Data.h"

/**
 * @brief Adicionar uma viagem
 * Funçao que adiciona uma viagem e regista a hora , a data e os pontos ganhos com a mesma.
 * É pedido para escolher uma viagem entre x e y
 * É atribuido um preço a essa escolha e a respetiva distancia efetuada
 * Se o preço da viagem for 0 entao entao estamos a ir para o mesmo destino ou nao é possivel viajar no
 * entre x e y dados.
 * Se for efetuada uma viagem com sucesso entao é registado o id do cliente, o portico de entrada,
 * o portico de saida, a data, a hora, o custo da viagem, a distancia efetuada e  é feita a conversao
 * do custo da viagem para int e é atribuido esse valor aos pontos ganhos com a viagem
 * A viagem é adicionada ao array das viagens e é encrementada a posiçao para a proxima viagem
 * Escreve no ficheiro dos clientes para atualizar os pontos
 * Escreve no ficheiro das viagens a viagem registada
 * Mostra os dados do resgisto da viagem
 */
void add_trip() {

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int choice_x, choice_y;
    float trip_cost, total_distance;
    struct Trip trip;

    fill_matrix(price_matrix_list, "../Precos.txt", false);
    fill_matrix(distance_matrix_list, "../Distancias.txt", true);
    show_prices();
    printf("Enter where you want to go:\n");
    readInt(&choice_x, 1, NUM_PORTAGENS, "Choose between 1-5:\nX:");
    readInt(&choice_y, 1, NUM_PORTAGENS, "Choose between 1-5:\nY:");
    trip_cost = price_matrix_list[(choice_x - 1) * NUM_PORTAGENS + (choice_y - 1)].price;
    total_distance = distance_matrix_list[(choice_x - 1) * NUM_PORTAGENS + (choice_y - 1)].distance;

    if (trip_cost == 0) {/*verifica se o preço é = 0 e tambem verifica
                            se estamos a ir para o mesmo destino, ja que o preco tambem é 0*/
        printf("\nThis trip is not valid!\n");
        printf("Please try another one.\n");
        add_trip();
    } else {
        trip.client_id = current_client_id;
        trip.choice_x = choice_x;
        trip.choice_y = choice_y;
        trip.date = tm;
        trip.trip_cost = trip_cost;
        trip.distance = total_distance;//soma a distancia percorrida por este cliente
        clients_list[current_client_id - 1].VVPoints = (int) trip_cost;//converte para int e soma os pontos
        trips_list[trip_list_size++] = trip;
        write_client_file();//para atualizar no ficheiro do cliente os pontos
        write_trip_file();

        printf("Success! Trip registered.\n");
        printf("Price: %f\n", trip_cost);
        printf("Time: %d-%d-%d %d:%d:%d\n", tm.tm_mday,
               tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("Earned Points: %d\n", (int) trip_cost);
    }
}

/**
 * @brief Mostra a matriz das distancias no ecra
 * Imprime os km's efetuados no total pelo cliente seleccionado
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
 * @brief Historico das viagens registadas
 * Imprime as viagens registadas pelo cliente atual
 * É imprimido tambem uma mensagem caso nao existam viagens registadas ainda
 */
void trip_history() {

    int i;
    int trip_count = 1;
    printf("--Trip History--\n\n");

    for (i = 0; i < trip_list_size; i++) {

        if (current_client_id == trips_list[i].client_id) {
            printf("** Trip nº%d **\n", trip_count++);//mostra o numero de viagens ordenado p/cliente
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
    if (trip_count == 1) {//chegando aqui e dado que se nao houver viagens registadas
        //o trip count sera 1 portanto nao existem viagens ainda
        printf("No trips registered yet!\n");
    }
}

/**
 * @brief Extracto gerado
 * É pedido um mes e um ano especifico
 * É verificado se existe viagens do cliente atual
 * Pesquisa pelo mes e o ano dados
 * É imprimido o cabeçalho dos resultados encontrados
 * Se nao forem encontradas viagens é imprimido uma mensagem
 * No final é tambem imprimido o preço total das viagens encontradas
 */
void extracts_page() {

    int month, year, get_year = trips_list->date.tm_year + 1900, results = 0;
    float total_price = 0;

    printf("--Extract Page--\n\n");
    printf("Tell me the month : ");
    readInt(&month, 1, 12, "Between 1-12 : ");
    readInt(&year, 1900, get_year, "Tell me the year : ");

    for (int i = 0; i < trip_list_size; i++) {

        if (current_client_id == trips_list[i].client_id && //verifica o id do cliente
            trips_list[i].date.tm_mon + 1 == month &&      // pesquisa pelo mes e ano
            trips_list[i].date.tm_year + 1900 == year) {

            system("clear");
            if (results == 0) {//apenas para imprimir o cabeçalho uma vez
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
