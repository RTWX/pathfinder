#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    int size = 0;
    for ( ; s1[size] != 0 ; ) {
        size++;
    }
    char *dub = mx_strnew(size + 1);
    if (dub != NULL)  {
        dub = mx_strcpy(dub, s1);
    }
    return dub;
}

