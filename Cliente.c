#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Veiculo.h"
#include "API_Leitura.h"

void ecra_cliente() {

    int choice;
    do {
        printf("---Área Cliente---\n\n");
        printf("1. Cliente\n");
        printf("2. Veiculo\n");
        printf("3. Viagens\n");
        printf("4. Extratos\n");
        printf("5. Pontos\n");
        printf("6. Menu Anterior\n");
        printf("7. Sair\n");
        readInt(&choice, 1, 7, "Escolha uma opção: ");

        switch (choice) {
            case 1:
                //system("clear");
                // aqui o cliente podera ver o  registo dos seus dados pessoais
                break;
            case 2:
                printf("Veiculo");
                // aqui o cliente podera ver o registo do seu carro(s)
                break;
            case 3:
                system("clear");
                printf("Viagens");
                break;
            case 4:
                system("clear");
                printf("Extratos");
                break;
            case 5:
                system("clear");
                printf("Pontos");
                break;
            case 6:
                system("clear");
                break;//menu anterior
            case 7:
                printf("\nAté á proxima ;\051");
                exit(0);
            default:
                printf("Escolha errada. Tente novamente\n");
                break;
        }
    } while (choice != 6);
}

void menu_cliente() {

    int choice;
    int id = 1;
    do {
        printf("\n---Menu Inicial---\n\n");
        printf("1. Login\n");
        printf("2. Registar Novo Cliente\n");
        printf("3. Menu Anterior\n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Escolha uma opção: ");

        switch (choice) {
            case 1:
                system("clear");
                ecra_cliente();
                break; // Login
            case 2:
                system("clear");
                printf("\nRegistar novo cliente\n");
                criar_cliente(id);
                printf("\nRegistado com sucesso!\n");
                id++;
                break;
            case 3:
                system("clear");//menu anterior
                break;
            case 4:
                printf("\nAté á proxima ;\051");
                exit(0);//sair da aplicacao

            default:
                printf("Escolha errada. Tente novamente\n");
                break;
        }
    } while (choice != 3);
}
void criar_cliente(int id) {

    struct Cliente cliente1;
    int c;
    FILE *file;

    readString(cliente1.nome,20, "Nome: ");
    readString(cliente1.nif,10,"NIF: ");
    readString(cliente1.cc,9, "CC: ");
    readString(cliente1.NIB,22, "NIB: ");
    readString(cliente1.morada,20, "Morada: ");
    file = fopen("../info_cliente.txt", "a");

    fprintf(file,"%d,%s,%s,%s,%s,%s", id,cliente1.nome, cliente1.nif, cliente1.cc, cliente1.NIB, cliente1.morada);
    if (file) {
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
    }
    registar_veiculo();
}
