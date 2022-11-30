#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {

    if (size == 0) {
        free(ptr);
        ptr = NULL;
        return NULL;
    }
    void *nptr = malloc(size);

    if (ptr != NULL)
        mx_memcpy(nptr, ptr, mx_strlen(ptr) );
        
    ptr = nptr;

    return ptr;
}


