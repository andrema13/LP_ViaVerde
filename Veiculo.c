#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Veiculo.h"
#include "API_Leitura.h"

void registar_veiculo(){

    struct Cliente cliente1;
    int c;
    FILE *file;

    printf("\nIntroduza as informaçoes do seu veiculo:\n ");
    readString(cliente1.veiculo.marca,12, "Marca: ");
    readString(cliente1.veiculo.modelo,12, "Modelo: ");
    readString(cliente1.veiculo.matricula,10, "Matricula: ");
    cliente1.pontosVV = 0;
    file = fopen("../info_cliente.txt", "a");

    fprintf(file,"%s,%s,%s,%d;\n", cliente1.veiculo.marca, cliente1.veiculo.modelo,
            cliente1.veiculo.matricula,cliente1.pontosVV);
    if (file) {
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
    }
}
