#include <stdio.h>
#include <stdlib.h>
#include "Utilizador.h"
#include "API_Leitura.h"
#include "Utils.h"
#include "Cliente.h"

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
                client_id();
                new_client();
                printf("\nRegistered successfully!\n");
                break;
            case 2:
                system("clear");
                //editar utili
                break;
            case 3:
                system("clear");
                delete_client();
                //remover utili
                break;
            case 4:
                system("clear");
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

void travel_management() {
    int choice;
    do {
        printf("---Travel Management---\n\n");
        printf("1. Add travel\n");
        printf("2. Search travel\n");
        printf("3. Previous Menu\n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");
        switch (choice) {
            case 1:
                system("clear");
                //acrescentar viagens( ver enunciado)
                break;
            case 2:
                system("clear");
                //pesquisar por viagens de varios modos
                break;
            case 3:
                system("clear");
                break;
            case 4:
                printf("\nSee you soon!;\051");
                exit(0);//sair
            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 3);
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

void invoice_generation() {

    int choice;
    do {
        printf("---Invoice Generation---\n\n");
        printf("1. Invoice Generation\n");
        printf("2. Invoice Search\n");// nova funcionalidade (relatorio)
        printf("3. Previous Menu\n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");
        switch (choice) {
            case 1:
                system("clear");
                //gerar fatura para um utiliz especifico num dado mes
                break;
            case 2:
                system("clear");
                //Pesquisar por faturas anteriores
            case 3:
                system("clear");//menu anterior
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

void user_screen() {

    int choice;
    do {
        printf("---User Area---\n\n");
        printf("1. User Management\n");
        printf("2. Travel Management\n");
        printf("3. Price Management\n");
        printf("4. Invoice Generation\n");
        printf("5. Previous Menu\n");
        printf("6. Exit\n");
        readInt(&choice, 1, 6, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                user_management();
                break;
            case 2:
                system("clear");
                travel_management();
                break;
            case 3:
                system("clear");
                price_management();
                break;
            case 4:
                system("clear");
                invoice_generation();
                break;
            case 5:
                system("clear");
                break;
            case 6:
                printf("\nSee you soon! ;\051");
                exit(0);
            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 5);
}

void edit_prices() {

    struct lanco matrix[NUM_PORTAGENS * NUM_PORTAGENS];
    int choice_x, choice_y;
    float new_price;

    fill_matrix(matrix, "../Precos.txt", false);
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
        readFloat(&new_price, 1, 100, "Choose between 1-100: ");
        matrix[(choice_x - 1) * NUM_PORTAGENS + (choice_y - 1)].price = new_price;
        write_matrix(matrix, "../Precos.txt");
        system("clear");
        show_prices();
    }
}


void show_prices() {

    //TODO meter a matriz em memoria para toda a aplicaçao
    struct lanco matrix[NUM_PORTAGENS * NUM_PORTAGENS];
    fill_matrix(matrix, "../Precos.txt", false);
    int i, j, num = 1;

    printf("---Prices---\n\n");
    printf("Y/X\t1\t2\t3\t4\t5\n");

    for (i = 0; i < NUM_PORTAGENS; i++) {
        printf("%d\t", num);
        num++;
        for (j = 0; j < NUM_PORTAGENS; j++) {
            printf("%f\t ", matrix[i * NUM_PORTAGENS + j].price);
        }
        printf("\n");
    }
    printf("-Legenda-\n1-Braga  2-Porto  3-Coimbra  4-Lisboa  5-Algarve\n");
}

int delete_client() {
    FILE *fileptr1, *fileptr2;
    char ch;
    int delete_id, temp = 1;

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
        if (temp != delete_id) {
            //copy all lines in file replica.c
            putc(ch, fileptr2);
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