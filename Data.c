#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "Utils.h"
/**
 * Tamanho maximo que é alocado de memoria em nº de clientes
 */
int client_list_max_size = LIST_SIZE;
/**
 * Apontador para a lista de clientes
 */
struct Client *clients_list = NULL;
/**
 * Apontador para uma variavel temporaria do tipo struct
 */
struct Client *temp = NULL;
/**
 * Matriz dos preços que é uma matriz global com o numero de portagens atual(pode ser mudado)
 */
struct Lanco price_matrix_list[NUM_PORTAGENS * NUM_PORTAGENS];
/**
 * Matriz das distancias que é uma matriz global com o numero de portagens atual(pode ser mudado)
 */
struct Lanco distance_matrix_list[NUM_PORTAGENS * NUM_PORTAGENS];
/**
 * Matriz das viagens
 */
struct Trip trips_list[100];
/**
 * Variaveis globais que irao conter o tamanho do array dos cliente e das viagens, respetivamente.
 */
int client_list_size = 0, trip_list_size = 0;
/**
 * @brief Leitura do ficheiro dos clientes registados
 * É aberto o ficheiro
 * Verificado se ele realmente exite senao ocorre um erro
 * Declarado a estrutura indicada e enquanto nao chegar ao fim do ficheiro é lido as informaçoes
 * pelos campos correspondentes
 * É alocado memoria para o limite estipulado(10) e se for necessario é alocado mais 10 neste caso
 * Se nao chegar a existir realocaçao é imprimido uma mensagem de erro
 * Se for bem sucedido é entao realocado o espaço de memoria
 * O cliente é adicionado á lista de clientes e é incrementado o valor do array
 * É atribuido o valor do tamanho do array dos clientes á variavel client_list_size
 * É fechado por fim o ficheiro.
 */
void read_client_file() {

    FILE *file;
    int i = 0;
    file = fopen("../info_cliente.txt", "r");

    if (file == NULL) {
        perror("Error: ");
    } else {
        struct Client client;
        //TODO tratar das virgulas no input
        while (fscanf(file, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d",
                      &client.ID, client.name, client.NIF,
                      client.CC, client.NIB, client.street,
                      client.vehicle.manufacturer, client.vehicle.model,
                      client.vehicle.registration,
                      &client.VVPoints
        ) != EOF) {

            if (i + 1 > client_list_max_size) {//memoria dinamica, limite 10, soma mais 10
                temp = (struct Client *) realloc(clients_list,//se necessario
                        client_list_max_size * sizeof(struct Client) +
                                LIST_SIZE * sizeof(struct Client));

                if (temp == NULL) {

                    printf("Memory failed!");
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
 * 
 */
void write_client_file() {

    int i, c;
    FILE *file;

    file = fopen("../info_cliente.txt",
                 "w");//Creates an empty file for writing. If a file with the same name already exists,
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

int count_file_line_numbers() {

    int lines = 0;
    int ch; //char que define se tem palavras ou EOF
    FILE *file;
    file = fopen("../info_cliente.txt", "r");

    if (file == NULL) {
        perror("Error: ");
        return lines;
    }

    while (!feof(file)) {
        ch = fgetc(file);
        if (ch == '\n') {
            lines++;
        }
    }

    fclose(file);
    return lines;
}

void read_trip_file() {

    FILE *file;
    int i = 0;
    file = fopen("../travel_registration.txt", "r");
    if (file == NULL) {
        perror("Error: ");
    } else {
        struct Trip trip;
        //TODO tratar das virgulas no input
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
            trips_list[i] = trip;
            i++;
        }
    }
    trip_list_size = i;

    fclose(file);
}

void write_trip_file() {

    int i, c;
    FILE *file;

    file = fopen("../travel_registration.txt", "w");//Creates an empty file for writing.
    // If a file with the same name already exists,
    // its content is erased and the file is considered as a new empty file.

    for (i = 0; i < trip_list_size; i++) {

        fprintf(file, "%d,%d,%d,%d/%d/%d,%d:%d:%d,%f,%f\n",
                trips_list[i].client_id,
                trips_list[i].choice_x,
                trips_list[i].choice_y,
                trips_list[i].date.tm_mday,
                trips_list[i].date.tm_mon,//somar +1
                trips_list[i].date.tm_year,//somar +1900
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

void show_prices() {

    fill_matrix(price_matrix_list, "../Precos.txt", false);
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
    printf("-Legenda-\n1-Braga  2-Porto  3-Coimbra  4-Lisboa  5-Algarve\n");
}

void show_distances(){

    fill_matrix(distance_matrix_list, "../Distancias.txt", true);
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
    printf("-Legenda-\n1-Braga  2-Porto  3-Coimbra  4-Lisboa  5-Algarve\n");
}

