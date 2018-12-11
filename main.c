#include "Headers.h"

void main_menu() {

    int choice;
    do {
        printf("---Bem Vindo á Via Verde---\n\n");
        printf("1. Cliente\n");
        printf("2. Utilizador\n");
        printf("3. Exit\n");
        readInt(&choice, 1, 3, "Escolha uma opção: ");

        switch (choice) {
            case 1:
                system("clear");
                menu_cliente();
                break;
            case 2:
                system("clear");
                ecra_utilizador();
                break;
            case 3: // Exit
                printf("\nAté á proxima ;\051");
                exit(0);
            default:
                printf("Escolha errada. Tente novamente\n");
                break;
        }
    } while (choice != 3);
}

int main() {
    main_menu();
    return 0;
}