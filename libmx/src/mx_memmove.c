#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *it1 = dst;
    char *it2 = (char *)src;
    char *it3 = (char *)malloc(len);

    for (int i = 0; i < (int)len; i++)
        it3[i] = it2[i];
    
    for (int i = 0; i < (int)len; i++)
        it1[i] = it3[i];
    
    free(it3);
    return dst;
}



