#include <stdio.h>
#include <stdlib.h>
#include "API_Leitura.h"
#include "Cliente.h"
#include "Utilizador.h"
#include "Data.h"
#include "Viagem.h"

/**
 * @brief Menu incial da aplicaçao
 * Menu com a escolha para a parte do cliente ou do utilizador, ou da saida do programa
 * Na opçao 2 é verificado se existem clientes senao é imprimido uma mensagem a dizer que nao existem
 * clientes e é voltado a ser mostrado o menu inicial.
 * Se existir clientes é entao verificado se o id dado existe nos clientes registados
 */
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
                if (client_list_size == 0) {//se nao existir clientes
                    printf("\nNo clients yet!\n");
                    main_menu();
                } else {
                    id_verification(main_menu, user_menu);
                    //verifica se o id dado existe nos clientes registados
                }
                break;
            case 3:
                printf("\nSee you soon! ;\051");
                exit(0);
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 3);
}
/**
 *@brief Funçao main
 * Executa as funçoes necessarias á execuçao do programa
 * É alocado memoria para a lista dos clientes
 * É lido o ficheiro dos clientes
 * É lido o ficheiro das viagens
 * @return 0 em caso de sucesso
 */
int main() {
//
//    FILE *file;
//    file = fopen("../info_cliente.txt", "w");
//    if (file == NULL) {
//        perror("Error: ");
//    }
//    fclose(file);

    clients_list = (struct Client*) malloc(client_list_max_size * sizeof(struct Client));
    trips_list = (struct Trip*) malloc(trip_list_max_size * sizeof(struct Trip));

    read_client_file();
    read_trip_file();
    main_menu();


    return 0;
}