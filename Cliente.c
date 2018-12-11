#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Veiculo.h"
#include "API_Leitura.h"

void criar_cliente() {

    struct Cliente cliente1;
    int c;
    FILE *file;

    readString(cliente1.nome,20, "Nome: ");
    readString(cliente1.nif,10,"NIF: ");
    readString(cliente1.cc,9, "CC: ");
    readString(cliente1.NIB,22, "NIB: ");
    readString(cliente1.morada,20, "Morada: ");
    cliente1.pontosVV = 0;
    file = fopen("../info_cliente.txt", "a");

    fprintf(file,"%s\t%s\t%s\t%s\t%s\t%d\t", cliente1.nome, cliente1.nif, cliente1.cc, cliente1.NIB,
            cliente1.morada, cliente1.pontosVV);
    if (file) {
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
    }
    registar_veiculo();
}
