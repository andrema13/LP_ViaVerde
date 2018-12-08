#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

void ler_ficheiro() {

    int c;
    FILE *file;
    file = fopen("../test.txt", "r");
    if (file) {
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
    }
}

void registar_cliente() {
   //reg_cliente reg_cliente1;
    //scanf("%c", reg_cliente1.nome);
}