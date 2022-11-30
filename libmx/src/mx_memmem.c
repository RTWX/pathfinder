#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    char *it1 = (char *)big;
    char *it2 = (char *)little;
    
    for (int i = mx_get_substr_index(big, little); i < (int)big_len && i != -1; i++) {
        bool b = true;
        if (it1[i] == it2[0] ) {
            for (int j = 0; j < (int)little_len; j++) {
                if ( it1[i + j] != it2[j] ) {
                    b = false;
                    break;
                }
            }
            if ( b ) 
                return (it1 + i);
        }
    }
    return NULL;
}


