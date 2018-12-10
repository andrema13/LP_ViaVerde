#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Veiculo.h"

void ler_ficheiro() {

    struct Cliente cliente1;
    int c;
    FILE *file;

    printf("Nome: "); scanf(" %s", cliente1.nome);
    printf("NIF: "); scanf(" %d", &cliente1.nif);
    printf("CC: "); scanf(" %d", &cliente1.cc);
    printf("NIB: "); scanf(" %d", &cliente1.NIB);
    printf("Morada: "); scanf(" %s", cliente1.morada);
    cliente1.pontosVV = 0;
    file = fopen("../test.txt", "a");

    fprintf(file,"%s\t%d\t%d\t%d\t%s\t%d\n", cliente1.nome, cliente1.nif, cliente1.cc, cliente1.NIB,
            cliente1.morada, cliente1.pontosVV);
    if (file) {
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
    }
}
