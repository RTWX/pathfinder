#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, int indx, int len) {
    if (sizeof(s1) > sizeof(s2)) {
        return 1;
    }
    if (sizeof(s1) < sizeof(s2)) {
        return -1;
    }
    for (int i = indx; s1[i] != 0 && s2[i] != 0 && i < indx + len; i++) {
        if (s1[i] < s2[i]) {
            return -1;
        }
        else if (s1[i] > s2[i]) {
            return 1;
        }
    }
    return 0;
}

