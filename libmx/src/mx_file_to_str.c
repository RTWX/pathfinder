#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int sfile = open(file, O_RDONLY);
    if (sfile < 0)
        return NULL;
    char c;
    int strLenght = 0;
    for (int err = 2; err > 0; ) {
        err = read(sfile, (void *)&c, 1);
        if (err != 2)
            strLenght++;
        if (err == -1)
            return NULL;
    }
    close(sfile);
    sfile = open(file, O_RDONLY);
    if (sfile < 0 || strLenght == 0)
        return NULL;
    char *str = mx_strnew( (strLenght + 1) * sizeof(char) );
    int err = 2;
    for (int i = 0; err > 0; i++) 
        err = read(sfile, (void *)&str[i], 1);
    str[strLenght] = '\0';
    if (err == -1) {
        free(str);
        return NULL;
    }
    close(sfile);
    return str;
}

