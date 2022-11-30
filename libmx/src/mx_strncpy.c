#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int zero = 0;
    for (int i = 0; i < len /*&& dst[i] != 0*/; i++) {
        if (src[i] == 0 ) {
            zero = 1;
        }
        if (zero) {
            dst[i] = '\0';
            break;
        }
        else {
            dst[i] = src[i];
        }
    }
    return dst;
}

