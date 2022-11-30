#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *it1 = dst;
    char *it2 = (char *)src;
    for (int i = 0; i < (int)n; i++) {
        *it1 = *it2;
        it1++;
        it2++;
    }
    return dst;
}



