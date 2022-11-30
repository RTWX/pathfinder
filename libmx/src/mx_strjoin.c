#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 != NULL)
        return mx_strdup(s2);
    else if (s2 == NULL && s1 != NULL)
        return mx_strdup(s1);
    else if (s2 == NULL && s1 == NULL)
        return NULL;
    //int cstr_len = mx_strlen(s1) + mx_strlen(s2);
    char *cstr = (char *)malloc( (mx_strlen(s1) + mx_strlen(s2) + 1) * sizeof(char) );
    if (cstr == NULL)
        return NULL;
    mx_strncpy(cstr, s1, mx_strlen(s1));
    mx_strncpy(cstr + mx_strlen(s1), s2, mx_strlen(s2));
    return cstr;
}

