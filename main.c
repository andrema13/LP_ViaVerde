#include "Headers.h"

void ecra_utilizador() {

    int choice;
    do {
        printf("---Área do Utilizador---\n\n");
        printf("1. Gestão de Utilizador\n");
        printf("2. Gestão de Viagens\n");
        printf("3. Gestão de Pre�os\n");
        printf("4. Gestão de Faturas\n");
        printf("5. Persistencia de Dados\n");
        printf("6. Menu Anterior\n");
        printf("7. Sair\n");
        readInt(&choice, 1, 7, "Escolha uma opção: ");

        switch (choice) {
            case 1:
                system("clear");
                printf("Gestao utili");
                break;
            case 2:
                system("clear");
                printf("gestao viagens");
                break;
            case 3:
                system("clear");
                printf("gestao de pre�os");
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
                break;
            default:
                printf("Escolha errada. Tente novamente\n");
                break;
        }
    } while (choice != 6);
}

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
               //cliente
                registar_cliente();
                break;
            case 2:
                printf("Veiculo");
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
                break;
            default:
                printf("Escolha errada. Tente novamente\n");
                break;
        }
    } while (choice != 6); 
}

void menu_cliente() {

    int choice;
    do {
        printf("---Menu Inicial---\n\n");
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
                printf("Registar novo cliente\n");
                 registar_cliente();// Registar
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

void main_menu() {

    int choice;
    do {
        printf("---Bem Vindo � Via Verde---\n\n");
        printf("1. Cliente\n");
        printf("2. Utilizador\n");
        printf("3. Exit\n");
        readInt(&choice, 1, 3, "Escolha uma opção: ");

        switch (choice) {
            case 1:
                system("clear");
                menu_cliente();
                break;
            case 2: // Utilizador
                system("clear");
                ecra_utilizador();
                break;
            case 3: // Exit
                printf("\nAté á proxima ;\051");
                exit(0);
                break;
            default:
                printf("Escolha errada. Tente novamente\n");
                break;
        }
    } while (choice != 3);
}

int main() {
    //main_menu();

    ler_ficheiro();

    return 0;
}