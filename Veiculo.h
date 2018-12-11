#ifndef VEICULO_H
#define VEICULO_H
#include <string.h>

void registar_veiculo();

struct Veiculo {

    char matricula[10];
    char marca[12];
    char modelo[12];
   
};
#endif