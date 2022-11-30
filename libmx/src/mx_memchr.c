#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    char *it1 = (char *)s;

    for (int i = 0; i < (int)n; i++) {
        if ( *it1 == c ) {
            return it1;
        }
        it1++;
    }
    return NULL;
}


