#ifndef VEICULO_H
#define VEICULO_H
#include <string.h>

void register_vehicle();

struct Vehicle {

    char registration[10];
    char manufacturer[12];
    char model[12];
   
};
#endif