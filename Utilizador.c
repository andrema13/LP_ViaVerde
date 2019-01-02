#include <stdio.h>
#include <stdlib.h>
#include "Utilizador.h"
#include "API_Leitura.h"
#include "Utils.h"
#include "Cliente.h"
#include "Viagem.h"
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
                exit(0);//sair
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
                exit(0);
            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 3);
}

void search_trip() {

    int choice_1, choice_2, choice_3, input_id,
            day, month, year,
            input_toll, exit_toll, total_filters, max_filters = 3;
    float price;

    do {

        printf("--Search Trips--\n\n"
               "-Filters-\n"
               "1.Client ID(Vehicle)\n"
               "2.Day\n"
               "3.Month\n"
               "4.Year\n"
               "5.Input toll\n"
               "6.Exit toll\n"
               "7.Price\n"
               "0.No more filters\n"
               "Note : You only can choose 3 filters(max) to do the search.\n"
        );

        readInt(&choice_1, 1, 7, "Tell me your 1st option :");

        switch (choice_1) {
            case 0:
                system("clear");
                break;

            case 1:
                system("clear");
                printf("Client ID: \n");
                scanf("%d", &input_id);
                id_search(input_id);
                max_filters--;
                break;
            case 2:
                system("clear");
                printf("Day : \n");
                scanf("%d", &day);
                day_search(day);
                max_filters--;
                break;
            case 3:
                system("clear");
                printf("Month : \n");
                scanf("%d", &month);
                month_search(month);
                max_filters--;
                break;
            case 4:
                system("clear");
                printf("Year : \n");
                scanf("%d", &year);
                year_search(year);
                max_filters--;
                break;

            case 5:
                system("clear");
                printf("Input toll : \n");
                scanf("%d", &input_toll);
                input_toll_search(input_toll);
                max_filters--;
                break;
            case 6:
                system("clear");
                printf("Exit toll : \n");
                scanf("%d", &exit_toll);
                exit_toll_search(exit_toll);
                max_filters--;
                break;
            case 7:
                system("clear");
                printf("Price : \n");
                scanf("%f", &price);
                price_search(price);
                max_filters--;
                break;
            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (max_filters > 0);

}

void id_search(int id) {

    int results = 0;

    for (int i = 0; i < trip_list_size; i++) {
        if (id == trips_list[i].client_id) {
            if (results == 0) {
                printf("-Results- \n\n");
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
            results++;
        }
    }
    if (results == 0) {
        printf("\n** 404 - No results **\n");
    }
}

void day_search(int day) {
    int results = 0;

    for (int i = 0; i < trip_list_size; i++) {
        if (day == trips_list[i].date.tm_mday) {
            if (results == 0) {
                printf("-Results- \n\n");
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
            results++;
        }
    }
    if (results == 0) {
        printf("\n** 404 - No results **\n");
    }
}

void month_search(int month){
    int results = 0;

    for (int i = 0; i < trip_list_size; i++) {
        if (month == trips_list[i].date.tm_mon + 1) {
            if (results == 0) {
                printf("-Results- \n\n");
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
            results++;
        }
    }
    if (results == 0) {
        printf("\n** 404 - No results **\n");
    }
}

void year_search(int year){

    int results = 0;

    for (int i = 0; i < trip_list_size; i++) {
        if (year == trips_list[i].date.tm_year + 1900) {
            if (results == 0) {
                printf("-Results- \n\n");
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
            results++;
        }
    }
    if (results == 0) {
        printf("\n** 404 - No results **\n");
    }
}

void input_toll_search(int in_toll) {
    int results = 0;

    for (int i = 0; i < trip_list_size; i++) {
        if (in_toll == trips_list[i].choice_x) {
            if (results == 0) {
                printf("-Results- \n\n");
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
            results++;
        }
    }
    if (results == 0) {
        printf("\n** 404 - No results **\n");
    }
}

void exit_toll_search(int out_toll) {
    int results = 0;

    for (int i = 0; i < trip_list_size; i++) {
        if (out_toll == trips_list[i].choice_y) {
            if (results == 0) {
                printf("-Results- \n\n");
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
            results++;
        }
    }
    if (results == 0) {
        printf("\n** 404 - No results **\n");
    }
}

void price_search(float price) {
    int results = 0;

    for (int i = 0; i < trip_list_size; i++) {
        if (price == trips_list[i].trip_cost) {
            if (results == 0) {
                printf("-Results- \n\n");
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
            results++;
        }
    }
    if (results == 0) {
        printf("\n** 404 - No results **\n");
    }
}

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

int delete_client() {

    FILE *fileptr1, *fileptr2;
    char ch;
    int delete_id, temp = 1, cont = delete_id;

    //open file in read mode
    fileptr1 = fopen("../info_cliente.txt", "r");
    ch = getc(fileptr1);
    while (ch != EOF) {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);
    printf(" \n Enter client's ID to be deleted:");
    scanf("%d", &delete_id);
    //open new file in write mode
    fileptr2 = fopen("replica.txt", "w");
    ch = getc(fileptr1);
    while (ch != EOF) {
        ch = getc(fileptr1);
        if (ch == '\n') {
            temp++;
        }
        //except the line to be deleted
        if (temp < delete_id) {
            //copy all lines in file replica.c
            putc(ch, fileptr2);
        }
        if (temp > delete_id) {
            // copiar tudo menos id
            // id = contador
        }
        if (temp == delete_id) {
            temp++;
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove("../info_cliente.txt");
    //rename the file replica.txt to original name
    rename("replica.txt", "../info_cliente.txt");
    printf("\n Client sucessfully deleted. There's the updated list of clients. \n");
    fileptr1 = fopen("../info_cliente.txt", "r");
    ch = getc(fileptr1);
    while (ch != EOF) {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    return 0;
}

int edit_client() {

    FILE *fileptr1, *fileptr2;
    char ch;
    int edit_id, temp = 1, cont = edit_id;

    //open file in read mode
    fileptr1 = fopen("../info_cliente.txt", "r");
    ch = getc(fileptr1);
    while (ch != EOF) {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);
    printf(" \n Enter client's ID to be edited:");
    scanf("%d", &edit_id);
    //open new file in write mode
    fileptr2 = fopen("replica.txt", "w");
    ch = getc(fileptr1);
    while (ch != EOF) {
        ch = getc(fileptr1);
        if (ch == '\n') {
            temp++;
        }
        //except the line to be deleted
        if (temp != edit_id) {
            //copy all lines in file replica.c
            putc(ch, fileptr2);
        }
        if (temp = edit_id) {
            // copiar ID , voltar a pedir o resto
            // PEDIR TUDO OU PERGUNTAR O QUE QUER EDITAR?!!?!?!?!??
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove("../info_cliente.txt");
    //rename the file replica.txt to original name
    rename("replica.txt", "../info_cliente.txt");
    printf("\n Client sucessfully edited. There's the updated list of clients. \n");
    fileptr1 = fopen("../info_cliente.txt", "r");
    ch = getc(fileptr1);
    while (ch != EOF) {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    return 0;
}

/*int search_user() {
    int search_id;
    char ch;
    FILE *fileptr1;
    printf("What's the ID you want to search?");
    scanf("%d", &search_id);
    fileptr1 = fopen("../info_cliente.txt", "r");
    ch = getc(fileptr1);
    while (ch < search_id) {
        ch++;
    }
    if ( ch == search_id ){
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    return 0;
}*/
