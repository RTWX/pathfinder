#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (mx_strlen(needle) == 0) {

        return (char *)(haystack + 0);
    }
    if (mx_get_substr_index(haystack, needle) >= 0) 
        return (char *)(haystack + mx_get_substr_index(haystack, needle) );

    return NULL;
}


