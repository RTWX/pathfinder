#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0)
        return -2;
    mx_strdel(lineptr);
    //int buf_cnt = 0;
    int strcnt = 0;
    char *buf = malloc( buf_size );
    bool b = true;
    while (b) {
        if (read(fd, (void *)buf, buf_size) == 0)
            return -1;
        //buf_cnt += buf_size;
        int j = strcnt;
        int i = 0;
        for ( ; i < (int)buf_size; i++) {
            if (buf[i] != delim)
                strcnt++;
            else if (buf[i] == delim){
                b = false;
                break;
            }
        }
        if (lineptr != NULL && *lineptr != NULL) {
            char *s = mx_strnew(strcnt);
            mx_strcpy( s, *lineptr);
            mx_strdel(lineptr);
            *lineptr = s;
        }
        for (int n = 0; j < strcnt && n < (int)buf_size; n++, j++)
            (*lineptr)[j] = buf[n];
    }
    mx_strdel(&buf);
    return strcnt;
}


