#ifndef UTILS_H
#define UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PORTAGENS 5

struct Lanco {
    float price, distance;
};

bool fill_matrix(struct Lanco *f, char *file, bool is_distance);

bool write_matrix(struct Lanco *f, char *file, bool is_price);

#ifdef __cplusplus
}
#endif

#endif /* UTILS_H */

