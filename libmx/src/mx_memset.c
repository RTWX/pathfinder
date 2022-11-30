#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {

    char *it = b;

    for (int i = 0; i < (int)len; i++) {
        
        *it = c;
        it++;
    }
    return b;
}


