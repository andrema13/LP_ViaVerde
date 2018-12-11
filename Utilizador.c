#include <stdio.h>
#include <stdlib.h>
#include "Utilizador.h"
#include "API_Leitura.h"

void gestao_utiizadores() {

    int choice;
    do {
        printf("---Gestao de Utilizadores---\n\n");
        printf("1. Criar Utilizador\n");
        printf("2. Editar Utilizador\n");
        printf("3. Remover Utilizador\n");
        printf("4. Pesquisar\\listar Utilizador\n");
        printf("5. Menu Anterior\n");
        printf("6. Sair\n");
        readInt(&choice, 1, 6, "Escolha uma opção: ");
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
                printf("\nAté á proxima ;\051");
                exit(0);//sair
            default:
                printf("Escolha errada. Tente novamente\n");
                break;
            }
        } while (choice != 5);
}

void ecra_utilizador() {

    int choice;
    do {
        printf("---Área do Utilizador---\n\n");
        printf("1. Gestão de Utilizador\n");
        printf("2. Gestão de Viagens\n");
        printf("3. Gestão de Preços\n");
        printf("4. Gestão de Faturas\n");
        printf("5. Persistencia de Dados\n");
        printf("6. Menu Anterior\n");
        printf("7. Sair\n");
        readInt(&choice, 1, 7, "Escolha uma opção: ");

        switch (choice) {
            case 1:
                system("clear");
                gestao_utiizadores();
                break;
            case 2:
                system("clear");
                printf("gestao viagens");
                break;
            case 3:
                system("clear");
                printf("gestao de preços");
                break;
            case 4:
                system("clear");
                printf("gestao faturas");
                break;
            case 5:
                system("clear");
                printf("persistencia dados");
                break;
            case 6:
                system("clear");
                break;
            case 7:
                printf("\nAté á proxima ;\051");
                exit(0);//sair
            default:
                printf("Escolha errada. Tente novamente\n");
                break;
        }
    } while (choice != 6);
}
