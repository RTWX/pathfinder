#include "../inc/libmx.h"

void mx_printchar(int c) {
    write(1, &c, 1);
}

