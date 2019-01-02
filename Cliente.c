#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "API_Leitura.h"
#include "API_Utils.h"
#include "Utils.h"
#include "Utilizador.h"
#include "Data.h"
#include "Viagem.h"
/**
 *@brief Mostra as informaçoes do cliente caso o seu id seja igual a um id da lista de clientes
 */
void client_info() {

    for (int i = 0; i < client_list_size; i++) {
        if (current_client_id == clients_list[i].ID) {
            printf("--Client Info--\n\n");
            printf("ID : %d\n", clients_list[i].ID);
            printf("Name : %s\n", clients_list[i].name);
            printf("NIF : %s\n", clients_list[i].NIF);
            printf("CC : %s\n", clients_list[i].CC);
            printf("NIB : %s\n", clients_list[i].NIB);
            printf("Street : %s\n", clients_list[i].street);
        }
    }
}
/**
 * @brief Mostra as informaçoes do veiculo asssociado ao cliente,
 * caso o id do cliente seja igual a um id da lista de clientes
 */
void vehicle_info() {

    for (int i = 0; i < client_list_size; i++) {
        if (current_client_id == clients_list[i].ID) {
            printf("--Vehicle Info--\n\n");
            printf("Manufacturer : %s\n", clients_list[i].vehicle.manufacturer);
            printf("Model : %s\n", clients_list[i].vehicle.model);
            printf("Registration : %s\n", clients_list[i].vehicle.registration);
        }
    }

}// ver info carro ( penso que seja uma funcionalidade p/relatorio)
/**
 * @brief Nesta funçao temos um menu em que é possivel  :
 * Adicionar uma nova viagem ao cliente atual
 * Ver o historico de viagens do cliente que esta no programa atualmente
 * Ver o total de km's percorrido pelo cliente em toda a sua utilizaçao da Via Verde
 * Voltar ao menu anterior
 * Sair do programa
 */
void trip_info() {

    int choice;
    do {
        printf("---Trips---\n\n");
        printf("1. Add trip\n");
        printf("2. Trip history\n");//funcionalidade nova
        printf("3. Total Distance\n");//funcionalidade nova
        printf("4. Previous Menu \n");
        printf("5. Exit\n");
        readInt(&choice, 1, 5, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                add_trip();
                break;
            case 2:
                system("clear");
                trip_history();
                break;
            case 3:
                system("clear");
                show_distance();
                break;
            case 4:
                system("clear");
                break;
            case 5:
                printf("\nSee you soon! ;\051");
                exit(0);
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 4);
}
/**
 * @brief Verificar os extratos disponiveis para o cliente que esta no programa atualmente
 * Voltar ao menu anterior
 * Sair do programa
 */
void extracts_info() {

    int choice;
    do {
        printf("--Extracts--\n\n");
        printf("1. See extract  \n");
        printf("2. Previous Menu\n");
        printf("3. Exit\n");
        readInt(&choice, 1, 3, "Choose an option: ");

        switch (choice) {

            case 1:
                system("clear");
                extracts_page();
                break;
            case 2:
                system("clear");//menu anterior
                break;
            case 3:
                printf("\nSee you soon! ;\051");
                exit(0);

            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 2);
}
/**
 * Faz o somatorio dos pontos obtidos das viagens efetuadas pelo cliente atual
 * Verifica o total de pontos acumulado pelo cliente atual
 * @return o numero de pontos atual do cliente
 */
int points_info() {

    int total_points = 0;
    for (int i = 0; i < trip_list_size; i++) {
        if (current_client_id == trips_list[i].client_id) {
            total_points += (int) trips_list[i].trip_cost;
        }
    }
    printf("--Points Info--\n\n");
    printf("Points : %d\n", total_points);

    return total_points;
}// ver info pontos ( penso que seja uma funcionalidade p/relatorio)
/**
 * @brief Trata-se do menu inicial do cliente assim que efetua o respetivo login, pelo que podera ver:
 * Os seus dados pessoais registados
 * Os dados do seu veiculo associado
 * Entrar no menu de viagens, pelo que podera adicionar viagens e verificar o seu historico
 * Gerar um extrato das viagens ja efetuadas
 * Verificar os seus pontos acumulados
 * Voltar ao menu anterior(menu do cliente)
 * Sair do programa
 */
void customer_area() {

    int choice;
    do {
        printf("---Customer area---\n\n");
        printf("1. Costumer Data\n");
        printf("2. Vehicle Data\n");
        printf("3. Trips\n");
        printf("4. Extracts\n");
        printf("5. Points\n");
        printf("6. Previous Menu\n");
        printf("7. Exit\n");
        readInt(&choice, 1, 7, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                client_info();
                break;
            case 2:
                system("clear");
                vehicle_info();
                break;
            case 3:
                system("clear");
                trip_info();
                break;
            case 4:
                system("clear");
                extracts_info();
                break;
            case 5:
                system("clear");
                points_info();
                break;
            case 6:
                system("clear");
                client_menu();
                break;
            case 7:
                printf("\nSee you soon! ;\051");
                exit(0);
            default:
                printf("Wrong choice. Try Again\n");
                break;
        }
    } while (choice != 6);
}
/**
 * @brief Menu da parte do cliente
 * Entrar na sua conta atraves do id indicado
 * Registar um novo cliente
 * Voltar ao menu anterior(ecra inicial)
 * Sair do programa
 */
void client_menu() {

    int choice;
    do {
        printf("---Client Menu---\n\n");
        printf("1. Enter to your account\n");
        printf("2. Register new client\n");
        printf("3. Previous Menu\n");
        printf("4. Exit\n");
        readInt(&choice, 1, 4, "Choose an option: ");

        switch (choice) {
            case 1:
                system("clear");
                if (client_list_size == 0) {//se nao existir clientes
                    printf("\nNo clients yet!\n");
                    client_menu();
                } else {
                    id_verification(client_menu, customer_area);
                    //verifica se o id dado existe nos clientes registados
                }
                break;

            case 2:
                system("clear");
                printf("\nEnter your data: \n");
                new_client();
                printf("\nRegistered successfully!\n");
                break;
            case 3:
                system("clear");
                break;
            case 4:
                printf("\nSee you soon! ;\051");
                exit(0);

            default:
                printf("Wrong choice. Try again\n");
                break;
        }
    } while (choice != 3);
}
/**
 * @brief Trata-se de uma funçao que verifica se o id dado existe nos clientes ja registados, se nao existir,
 * será pedido um novo id
 * @param f - Apontador que espera uma funçao sem argumentos e sem return
 * @param e - Apontador que espera uma funçao sem argumenos e sem return
 * Será primeiramente imprimido os clientes já registados
 * Será posteriormente pedido um id ao utilizador
 * É verificado se o id corresponde aos id ja registados no programa
 * Se exitir o utilizador entra na sua conta (cliente/Utilizador)
 * Se nao corresponder , imprime uma mensagem e é pedido um novo id
 * É tambem efetuada a respetiva limpeza do input para que seja efetuado uma nova tentativa de login
 */
void id_verification(void (*f)(void), void (*e)(void)) {//para passar duas funçoes sem argumentos

    printf("--Registered Clients--\n");
    for (int i = 0; i < client_list_size; i++) {//mostra os clientes id/nome
        printf("Id: %d - Name: %s\n", clients_list[i].ID, clients_list[i].name);
    }

    printf("\n--Tell me your ID--\n");
    current_client_id = 0;
    scanf(" %d", &current_client_id);

    for (int i = 0; i < client_list_size; i++) {//verifica se exite o id
        if (current_client_id == clients_list[i].ID) {
            system("clear");
            (*e)();
            return;
        }
    }//se chega aqui entao nao existe o id , logo volta a pedir um novo id
    printf("** 404 - Client not found **\n");
    system("clear");
    cleanInputBuffer();//limpa o input anterior e espera um novo scanf
    id_verification((*f), (*e));
}
/**
 * @brief Registo de um novo cliente
 * É atribuido um id unico , caso ainda nao exista clientes o id atribuido a este novo
 * registo sera 1 . Se já existir clientes, é verificado o ultimo cliente(posiçao que ocupa no array)
 * e é adicionado 1.
 * É pedido informaçoes para ser registado um novo cliente, tais como:
 * Nome, NIF, Cartao de Cidadão, NIB, Rua, Marca do veiculo, Modelo e a matricula do veiculo .
 * É atribuido os pontos correspondentes pelo que começará em 0 , no caso de um novo cliente .
 * É entao inserido no array dos clientes o novo cliente com as informaçoes dadas e é incrmentado
 * uma posicao para o proximo cliente a ser registado
 * write_cliente_file() é a funçao responsavel por escrever no ficheiro dos cliente o seu registo
 * É ainda mostrado no ecrã o id atribuido a este novo cliente
 */
void new_client() {

    struct Client client;

    if (client_list_size == 0) {
        client.ID = 1;
    } else {
        client.ID = clients_list[client_list_size - 1].ID + 1;//incrementa id do cliente
    }

    readString(client.name, 20, "Name: ");//Pede informaçoes pessoais ao utilizador
    readString(client.NIF, 9, "NIF: ");
    readString(client.CC, 8, "CC: ");
    readString(client.NIB, 20, "NIB: ");
    readString(client.street, 40, "Street: ");
    printf("\nEnter your vehicle information: \n ");
    readString(client.vehicle.manufacturer, 12, "Manufacturer: ");
    readString(client.vehicle.model, 12, "Model: ");
    readString(client.vehicle.registration, 10, "Registration: ");
    client.VVPoints = points_info();

    clients_list[client_list_size++] = client;
    write_client_file();
    printf("Your ID is: %d", client.ID);
}
