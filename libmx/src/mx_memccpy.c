#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *it1 = dst;
    char *it2 = (char *)src;
    for (int i = 0; i < (int)n; i++) {
        *it1 = *it2;
        if (*it2 == c) {
            it1++;
            return it1;
        }
        it1++;
        it2++;
    }
    return NULL;
}


