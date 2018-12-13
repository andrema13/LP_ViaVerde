#include "Headers.h"
/*
void main_menu() {

    int choice;
    do {
        printf("---Bem Vindo à Via Verde---\n\n");
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
                printf("\nAté à próxima! ;\051");
                exit(0);
            default:
                printf("Escolha errada. Tente novamente.\n");
                break;
        }
    } while (choice != 3);
}*/

#include "Utils.h"

int main() {
    //main_menu();

    struct lanco matrix[5 * 5];

    preencheMatriz(matrix, "../Precos.txt", false);

    int i, j;

    for(i=0; i<5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%f, ", matrix[i * NUM_PORTAGENS + j].preco);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
    preencheMatriz(matrix, "../Distancias.txt", true);

    for(i=0; i<5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%f, ", matrix[i * NUM_PORTAGENS + j].dist);
        }
        printf("\n");
    }

    matrix[1].preco = 1.0;
    escreveMatriz(matrix, "../Precos.txt");

    return 0;
}