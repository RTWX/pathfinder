#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *it1 = (char *)s1;
    char *it2 = (char *)s2;

    for (int i = 0; i < (int)n ; i++) {
        
        if (*it1 != *it2)
            return *it1 - *it2;
        
        it1++;
        it2++;
    }
    return 0;
}


