#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int len = mx_strlen(s1);
    
    for (int i = 0; s2[i] != 0; i++) {
        s1[len] = s2[i];
        len++;
    }
    s1[len] = '\0';
    return s1;
}

