#include "Headers.h"

void main_menu() {

    int choice;
    do {
        printf("---Welcome to Via Verde---\n\n");
        printf("1. Client\n");
        printf("2. User\n");
        printf("3. Exit\n");
        readInt(&choice, 1, 3, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                client_menu();
                break;
            case 2:
                system("clear");
                user_screen();
                break;
            case 3: // Exit
                printf("\nSee you soon! ;\051");
                exit(0);
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 3);
}

int main() {

    main_menu();

    struct lanco matrix[NUM_PORTAGENS * NUM_PORTAGENS];

    preencheMatriz(matrix, "../Precos.txt", false);

    int i, j;

    for(i=0; i < NUM_PORTAGENS; i++) {
        for (j = 0; j < NUM_PORTAGENS; j++) {
            printf("%f, ", matrix[i * NUM_PORTAGENS + j].preco);
        }
        printf("\n");
    }

    printf("\n\n");
    preencheMatriz(matrix, "../Distancias.txt", true);

    for(i=0; i<NUM_PORTAGENS; i++) {
        for (j = 0; j < NUM_PORTAGENS; j++) {
            printf("%f, ", matrix[i * NUM_PORTAGENS + j].dist);
        }
        printf("\n");
    }

    matrix[1].preco = 1.0;
    write_matrix(matrix, "../Precos.txt");

    return 0;
}