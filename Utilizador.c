#include <stdio.h>
#include <stdlib.h>
#include "Utilizador.h"
#include "API_Leitura.h"

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
                //criar utili.
                break;
            case 2:
                system("clear");
                //editar utili
                break;
            case 3:
                system("clear");
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
void travel_management(){
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
void price_management(){
    int choice;
    do {
        printf("---Price Management---\n\n");
        printf("1. Edit Prices\n");
        printf("2. Previous Menu\n");
        printf("3. Exit\n");
        readInt(&choice, 1, 3, "Choose an option: ");
        switch (choice) {
            case 1:
                system("clear");
                //editar preços
                break;
            case 2:
                system("clear");//menu anterior
                break;
            case 3:
                printf("\nSee you soon! ;\051");
                exit(0);//sair
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 2);
}
void invoice_generation(){
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
        printf("5. Data Persistence\n");
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
                printf("persistencia dados");
                break;
            case 6:
                system("clear");
                break;
            case 7:
                printf("\nSee you soon! ;\051");
                exit(0);//sair
            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 6);
}
