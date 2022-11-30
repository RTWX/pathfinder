#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    int str_size = size;
    if (str_size < 0) {
        return NULL;
    }
    if (str_size == 0) {
        str_size = 1;
    }
    char *c = (char *)malloc(  (str_size + 1) * sizeof(char)  );

    if (c != NULL) {
        for (int i = 0; i <= str_size; i++) {
            c[i] = '\0';
        }
    }
    return c;
}

