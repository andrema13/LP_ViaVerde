#include <stdio.h>
#include <stdlib.h>
#include "Utilizador.h"
#include "API_Leitura.h"
#include "Utils.h"
#include "Cliente.h"
#include "Viagem.h"
#include "Data.h"

/**
 * Array de resultados do tipo struct Resultado
 */
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
                //edit_client();
                //editar utili
                break;
            case 3:
                system("clear");
                delete_client();
                //remover utili
                break;
            case 4:
                system("clear");
                //search_user();
                //pesquisar utili
                break;
            case 5:
                system("clear");
                break;
            case 6:
                printf("\nSee you soon! ;\051");
                free(clients_list);
                free(trips_list);
                exit(0);//sair
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 5);
}

/**
 * @brief Gestao de viagens
 * Adicionar uma nova viagem
 * Pesquisar por viagens ja efetuadas
 * Menu anterior
 * Sair do programa
 */
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
 * @brief Pesquisa de viagens
 * É possivel pesquisar por diferentes filtros bem como utilizar a combinaçao de dois filtros
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
    do {//aqui sao escolhidos os filtros(3-max) enquanto nao for clicado o 0
        readInt(&choice, 0, 7, "Pick a filter : ");
        if (choice != 0) {
            filters[filters_size] = choice;
            filters_size++;
        }
    } while (choice != 0 && filters_size < MAX_FILTERS);

    struct Trip results_list[trip_list_size];
    for (int i = 0; i < trip_list_size; i++) {
        results_list[i] = trips_list[i];
        //copia as viagens resgistadas para o novo array results_list
        printf("%d %f \n", results_list[i].client_id, results_list[i].distance);
    }
    results_list_size = trip_list_size;

    for (int i = 0; i < filters_size; i++) {

        switch (filters[i]) {

            case 1:
                system("clear");
                printf("Cliente ID : ");
                scanf("%d", &input_id);
                id_search(input_id, results_list, &results_list_size);
                break;
            case 2:
                system("clear");
                printf("Day : ");
                scanf("%d", &day);
                day_search(day, results_list, results_list_size);
                break;
            case 3:
                system("clear");
                printf("Month : \n");
                scanf("%d", &month);
               // month_search(month, results_list, results_list_size);
                break;
            case 4:
                system("clear");
                printf("Year : \n");
                scanf("%d", &year);
               // year_search(year, results_list, results_list_size);
                break;
            case 5:
                system("clear");
                printf("Input toll : \n");
                scanf("%d", &input_toll);
                //input_toll_search(input_toll, results_list, results_list_size);
                break;
            case 6:
                system("clear");
                printf("Exit toll : \n");
                scanf("%d", &exit_toll);
                //exit_toll_search(exit_toll, results_list, results_list_size);
                break;
            case 7:
                system("clear");
                printf("Price : \n");
                scanf("%f", &price);
                //price_search(price, results_list, results_list_size);
                break;
            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    }
}

void print_results(struct Trip results_list[], int results_list_size) {

    for (int i = 0; i < results_list_size; i++) {

        if (i == 0) {
            printf("Client ID  Input-Exit      Date       Hour        Price\n");
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
 * @brief Pesquisa pelas viagens registadas ( client ID)
 * O id fornecido terá de ser igual a um dos registados nas viagens
 * @param id - id fornecido na escolha dos filtros
 */
void id_search(int id, struct Trip *results_list, int *results_list_size) {

    struct Trip temp_list[*results_list_size];
    int temp_list_size = 0;

    for (int i = 0; i < *results_list_size ; i++) {
        printf("%d %f \n", results_list[i].client_id, results_list[i].distance);
        if (id == results_list[i].client_id) {
            temp_list[temp_list_size] = results_list[i];
            temp_list_size++;
        }
    }

    // falta corrigir isto
    *results_list = *temp_list;
    *results_list_size = temp_list_size;

    print_results(results_list, *results_list_size);
}

/**
 * @brief Pesquisa pelas viagens registadas (dia)
 * O id fornecido terá de ser igual a um dos registados nas viagens
 * @param day - dia fornecido na escolha dos filtros
 */
void day_search(int day, struct Trip results_list[], int results_list_size) {

    for (int i = 0; i <= results_list_size - 1; i++) {

        if (day != results_list[i].date.tm_mday) {

            results_list[i] = results_list[i + 1];
            results_list_size--;
            i--;
        }
    }
    if (results_list[results_list_size - 1].date.tm_mday != day) {
        printf("\n** 404 - Trip not found **\n");
    }
    print_results(results_list, results_list_size);
}

/**
 * @brief Pesquisa pelas viagens registadas (mes)
 * O id fornecido terá de ser igual a um dos registados nas viagens
 * @param month - mes fornecido na escolha dos filtros
 */
void month_search(int month, struct Trip results_list[], int results_list_size) {

    for (int i = 0; i <= results_list_size - 1; i++) {

        if (month != results_list[i].date.tm_mon) {

            results_list[i] = results_list[i + 1];
            results_list_size--;
            i--;
        }
    }
    if (results_list[results_list_size - 1].date.tm_mon != month) {
        printf("\n** 404 - Trip not found **\n");
    }
    print_results(results_list, results_list_size);
}

/**
 * @brief Pesquisa pelas viagens registadas (ano)
 * O id fornecido terá de ser igual a um dos registados nas viagens
 * @param year - ano fornecido na escolha dos filtros
 */
void year_search(int year, struct Trip results_list[], int results_list_size) {

    for (int i = 0; i <= results_list_size - 1; i++) {

        if (year != results_list[i].date.tm_year) {

            results_list[i] = results_list[i + 1];
            results_list_size--;
            i--;
        }
    }
    if (results_list[results_list_size - 1].date.tm_year != year) {
        printf("\n** 404 - Trip not found **\n");
    }
    print_results(results_list, results_list_size);
}

/**
 * @brief Pesquisa pelas viagens registadas (portico de entrada)
 * O id fornecido terá de ser igual a um dos registados nas viagens
 * @param in_toll - portico de entrada fornecido na escolha dos filtros
 */
void input_toll_search(int input_toll, struct Trip results_list[], int results_list_size) {

    for (int i = 0; i <= results_list_size - 1; i++) {

        if (input_toll != results_list[i].choice_x) {

            results_list[i] = results_list[i + 1];
            results_list_size--;
            i--;
        }
    }
    if (results_list[results_list_size - 1].choice_x != input_toll) {
        printf("\n** 404 - Trip not found **\n");
    }
    print_results(results_list, results_list_size);
}

/**
 * @brief Pesquisa pelas viagens registadas (portico de saida)
 * O id fornecido terá de ser igual a um dos registados nas viagens
 * @param out_toll - portico de saida fornecido na escolha dos filtros
 */
void exit_toll_search(int exit_toll, struct Trip results_list[], int results_list_size) {

    for (int i = 0; i <= results_list_size - 1; i++) {

        if (exit_toll != results_list[i].choice_y) {

            results_list[i] = results_list[i + 1];
            results_list_size--;
            i--;
        }
    }
    if (results_list[results_list_size - 1].choice_y != exit_toll) {
        printf("\n** 404 - Trip not found **\n");
    }
    print_results(results_list, results_list_size);
}

/**
 * @brief Pesquisa pelas viagens registadas (preço da viagem)
 * O id fornecido terá de ser igual a um dos registados nas viagens
 * @param price - preço fornecido na escolha dos filtros
 */
void price_search(float price, struct Trip results_list[], int results_list_size) {

    for (int i = 0; i <= results_list_size - 1; i++) {

        if (price != results_list[i].trip_cost) {

            results_list[i] = results_list[i + 1];
            results_list_size--;
            i--;
        }
    }
    if (results_list[results_list_size - 1].trip_cost != price) {
        printf("\n** 404 - Trip not found **\n");
    }
    print_results(results_list, results_list_size);
}

/**
 * @brief Gestao de preços
 * Ver a tabela de preços atual
 * Editar a tabela de preços
 * Menu anterior
 * Sair do programa
 */
void price_management() {
    int choice;
    do {
        printf("\n---Price Management---\n\n");
        printf("1. Show Prices\n");//funcionalidade nova(relatorio)
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
                system("clear");//menu anterior
                edit_prices();
                break;
            case 3:
                system("clear");
                break;
            case 4:
                printf("\nSee you soon! ;\051");
                exit(0);//sair
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 3);
}

/**
 * @brief Gestao da distancia
 * É preenchido a matriz da distancia, isDistance? true(Param)
 * Mostra a matriz no ecra
 * É pedido para escolher qual a distancia a ser editado pelos eixos x e y
 * Se as escolhas de x e y forem iguais nao é permitido editar, e é voltado a mostrar a matriz no ecra
 * Se forem escolhas diferentes é pedido para introduzir um numero entre 0-100 como nova distancia
 * É escrito na matriz a nova distancia substituindo a antiga
 * Volta a mostrar a matriz com as distancias atualizadas
 */
void distance_management() {

    int choice_x, choice_y;
    float new_distance;

    fill_matrix(distance_matrix_list, "../Distancias.txt", true);
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
        write_matrix(distance_matrix_list, "../Distancias.txt", false);
        system("clear");
        show_distances();
    }
}

/**
 * @brief Menu do utlizador
 * Gestao dos clientes
 * Gestao das viagens
 * Gestao dos preços
 * Gestao das viagens
 * Geraçao de faturas
 * Menu anterior
 * Sair do programa
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
                //free(*__alloc_align())
                exit(0);
            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 6);
}

/**
 * @brief Editar os preços tabelados
 * É preenchido a matriz dos preços , isDistance? false(Param)
 * Mostra a matriz no ecra
 * É pedido para escolher qual o preço a ser editado pelos eixos x e y
 * Se as escolhas de x e y forem iguais nao é permitido editar, e é voltado a mostrar a matriz no ecra
 * Se forem escolhas diferentes é pedido para introduzir um numero entre 0-100 como novo preço
 * É escrito na matriz o novo preço substituindo o antigo
 * Volta a mostrar a matriz com os preços atualizados
 */
void edit_prices() {

    int choice_x, choice_y;
    float new_price;

    fill_matrix(price_matrix_list, "../Precos.txt", false);
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
        write_matrix(price_matrix_list, "../Precos.txt", true);
        system("clear");
        show_prices();
    }
}

/**
 * @brief Apagar um cliente registado
 * (completar)
 * @return 0
 */

int editClient() {


    struct Client client;
    int edit_id = -1, choice, NIF_edited, CC_ed, NIB_ed;
    char nameEdited[20], streetEdited;
    int changed = 0;
    printf(" \n Enter client's ID to be edited:");
    scanf("%d", &edit_id);


    if (edit_id != -1 && edit_id < client_list_size) {// valida o id introduzido
        client = clients_list[edit_id - 1];
        do {
            printf("ID - %d", client.ID); // TODO: testar isto!
            printf("1 - Name - %c", client.name); // TODO: testar isto!
            printf("2 - NIF - %d", client.NIF); // TODO: testar isto!
            printf("3 - CC - %d", client.CC); // TODO: testar isto!
            printf("4 - NIB - %d", client.NIB); // TODO: testar isto!
            printf("5 - Street - %c", client.street); // TODO: testar isto!
            printf("6 - Vehicle - %s", client.vehicle); // TODO: testar isto!
            printf("7 - Sair"); // TODO: testar isto!
            printf(" \n Enter the option to be edited:");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    system("clear");
                    readString(&nameEdited, 20, "Enter new client name: ");
                    int flag = 0;
                    //fazer ciclo
                    printf("You want save the information? Yes press 1, No press 0");
                    scanf("%d", &flag);
                    if(flag == 1){
                        strcpy(client.name, &nameEdited); //copia o conjunto de caracteres.   -> client.name = &nameEdited;
                        changed = 1;
                    }
                    break;
                case 2:
                    printf("\nEnter new client NIF: \n");
                    scanf("%c", &NIF_edited);
                    readString(&NIF_edited, 10, "Enter new client NIF: ");
                    int flag = 0;
                    //fazer ciclo
                    printf("You want save the information? Yes press 1, No press 0");
                    scanf("%d", &flag);
                    if(flag == 1){
                        strcpy(client.NIF, &NIF_edited); //copia o conjunto de caracteres.   -> client.name = &nameEdited;
                        changed = 1;
                    }
                    break;
                case 3:
                    printf("\nEnter new client CC: \n");
                    scanf("%c", &CC_ed);
                    readString(&CC_ed, 9, "Enter new client CC number: ");
                    int flag = 0;
                    //fazer ciclo
                    printf("You want save the information? Yes press 1, No press 0");
                    scanf("%d", &flag);
                    if(flag == 1){
                        strcpy(client.CC, &CC_ed); //copia o conjunto de caracteres.
                        changed = 1;
                    }

                    break;
                case 4:
                    printf("\nEnter new client NIB: \n");
                    scanf("%c", &NIB_ed);
                    readString(&NIB_ed, 22, "Enter new client NIB: ");
                    int flag = 0;
                    //fazer ciclo
                    printf("You want save the information? Yes press 1, No press 0");
                    scanf("%d", &flag);
                    if(flag == 1){
                        strcpy(client.NIB, &NIB_ed); //copia o conjunto de caracteres.
                        changed = 1;
                    }
                    break;
                case 5:
                    printf("\nEnter new client Street: \n");
                    scanf("%c", &streetEdited);
                    readString(&streetEdited, 40, "Enter new street: ");
                    printf("You want save the information? Yes press 1, No press 0");
                    scanf("%d", &flag);
                    if(flag == 1){
                        strcpy(client.street, &streetEdited); //copia o conjunto de caracteres.
                        changed = 1;
                    }
                    break;
                case 6:
                    printf("\nEnter new client vehicle: \n");
                    vehicleInfoById(edit_id);
                    //scanf("%c", &NIF_edited); Chamar função para editar veiculo
                    break;
                default:
                    break;
            }
        } while (choice != 7);

        if(changed == 1){ //Se for alterado ele atualiza! caso contrario fica como está.
            clients_list[edit_id] = client;
            printf("Edited with success! ");
        }

    } else {
        printf("Id not valid! \n");
    }

    return 0;
}
/**
*@brief Mostra as informaçoes do cliente caso o seu id seja igual a um id da lista de clientes
*/
void clientInfoById(int id) {
    if (id >= 1 && id < client_list_size) {
        printf("--Client Info--\n\n");
        printf("ID : %d\n", clients_list[id].ID);
        printf("Name : %s\n", clients_list[id].name);
        printf("NIF : %s\n", clients_list[id].NIF);
        printf("CC : %s\n", clients_list[id].CC);
        printf("NIB : %s\n", clients_list[id].NIB);
        printf("Street : %s\n", clients_list[id].street);
    }
}
void vehicleInfoById(int id) {
    if (id > -1 && id < client_list_size) {
        printf("--Vehicle Info--\n\n");
        printf("Manufacturer : %s\n", clients_list[id].vehicle.manufacturer);
        printf("Model : %s\n", clients_list[id].vehicle.model);
        printf("Registration : %s\n", clients_list[id].vehicle.registration);
    }
}

int searchUser() {
    int id = 0;
    readInt(id, 1, client_list_size, "What's the ID you want to search?");
    clientInfoById(id);
    return 0;
}