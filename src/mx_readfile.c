#include "../libmx/inc/libmx.h"
#include <stdio.h>

int mx_readfile(char *filename, char ***varr, int ***parr) {

    int fd = open(filename, O_RDONLY, 777);
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(-2);
    }
    signed char c = -1;
    int readcnt = read(fd, &c, 1);
    if (readcnt == 0) {
        close(fd);
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(-3);
    }
    char *islands_cnt = mx_strnew(10);
    int it = 0;
    while (readcnt > 0 && c > 0) { // read first line
        if (c == '\n') {
            islands_cnt[it] = '\0';
            it++;
            c = -1;
        }
        else if (mx_isdigit(c)) {
            islands_cnt[it] = c;
            it++;
        }
        else if ( !mx_isdigit(c) ) {
            mx_printerr("error: line 1 is not valid\n");
            mx_strdel(&islands_cnt);
            exit(-4);
        }
        if (c >= 0)
            readcnt = read(fd, &c, 1);
    }
    if ( mx_atoi(islands_cnt) <= 1 ) {
        mx_printerr("error: line 1 is not valid\n");
        mx_strdel(&islands_cnt);
        exit(-4);
    }
    int islands_count = mx_atoi(islands_cnt);
    mx_strdel(&islands_cnt);
    // initialise arrays
    (*varr) = (char **)malloc( sizeof(char *) * (islands_count + 1) ); // need to be freed
    for (int i3 = 0; i3 < islands_count + 1; i3++)
        (*varr)[i3] = NULL;

    (*parr) = (int **)malloc( sizeof(int *) * islands_count );
    for (int i = 0; i < islands_count; i++)
        (*parr)[i] = (int *)malloc( sizeof(int) * islands_count );

    for (int i2 = 0; i2 < islands_count; i2++)
        for (int i3 = 0; i3 < islands_count; i3++)
            (*parr)[i2][i3] = 0;

    long bridges_lenght_sum = 0;
    int line_cnt = 2;
    while (readcnt > 0) { // read line
        int readcnt = read(fd, &c, 1);
        if (readcnt == 0) { // if EOF
            close(fd);
            break;
        }
        //int str_cnt = 0;
        char *island1 = mx_strnew(10);
        it = 0;
        while (readcnt > 0 && c > 0) { // read first island
            if (it % 10 > 8) {
                char *temp = mx_strndup(island1, it + 10);
                mx_strdel(&island1);
                island1 = temp;
            }
            if (c == '-') {
                //str_cnt++;
                island1[it] = '\0';
                it++;
                c = -1;
            }
            else if (mx_isalpha(c)) {
                island1[it] = c;
                it++;
            }
            else if (!mx_isalpha(c)) {
                mx_strdel(&island1);
                { // free varr & parr
                    for (int i2 = 0; i2 < islands_count ; i2++ ) {
                        free( (*varr)[i2]);
                    }
                    free( (*varr) );
                    for (int i2 = 0; i2 < islands_count ; i2++ ) {
                        free( (*parr)[i2]);
                    }
                    free( (*parr) );
                }
                mx_printerr("error: line ");
                char *itoa = mx_itoa(line_cnt);
                mx_printerr( itoa );
                free(itoa);
                mx_printerr(" is not valid\n");
                exit(-5);
            }
            if (c >= 0)
                readcnt = read(fd, &c, 1);
        }
        //str_cnt = 0;
        readcnt = read(fd, &c, 1);
        char *island2 = mx_strnew(10);
        it = 0;
        while (readcnt > 0 && c > 0) { // read second island

            if (it % 10 > 8) {
                char *temp = mx_strndup(island2, it + 10);
                mx_strdel(&island2);
                island2 = temp;
            }
            if (c == ',') {
                island2[it] = '\0';
                it++;
                c = -1;
            }
            else if (mx_isalpha(c)) {
                island2[it] = c;
                it++;
            }
            else if (!mx_isalpha(c)) {
                mx_strdel(&island1);
                mx_strdel(&island2);
                { // free varr & parr
                    for (int i2 = 0; i2 < islands_count ; i2++ ) {
                        free((*varr)[i2]);
                    }
                    free( (*varr) );
                    for (int i2 = 0; i2 < islands_count ; i2++ ) {
                        free((*parr)[i2]);
                    }
                    free( (*parr) );
                }
                mx_printerr("error: line ");
                char *itoa = mx_itoa(line_cnt);
                mx_printerr( itoa );
                free(itoa);
                mx_printerr(" is not valid\n");
                exit(-5);
            }
            if (c >= 0)
                readcnt = read(fd, &c, 1);
        }
        readcnt = read(fd, &c, 1);
        char *distance = mx_strnew(10);
        it = 0;
        while (readcnt > 0 && c > 0) { // read lenght
            if (c == '\n') {
                distance[it] = '\0';
                it++;
                c = -1;
            }
            else if (mx_isdigit(c)) {
                distance[it] = c;
                it++;
            }
            else if (!mx_isdigit(c)) {
                mx_strdel(&island1);
                mx_strdel(&island2);
                mx_strdel(&distance);
                { // free varr & parr
                    for (int i2 = 0; i2 < islands_count ; i2++ ) {
                        free( (*varr)[i2] );
                    }
                    free( (*varr) );
                    for (int i2 = 0; i2 < islands_count ; i2++ ) {
                        free( (*parr)[i2] );
                    }
                    free( (*parr) );
                }
                mx_printerr("error: line ");
                char *itoa = mx_itoa(line_cnt);
                mx_printerr( itoa );
                free(itoa);
                mx_printerr(" is not valid\n");
                exit(-5);
            }
            if (c >= 0)
                readcnt = read(fd, &c, 1);
        }
        bridges_lenght_sum += mx_atoi(distance);
        
        if (mx_strcmp(island1, island2) == 0) { // if loop bridge
            mx_strdel(&island1);
            mx_strdel(&island2);
            mx_strdel(&distance);
            { // free varr & parr
                for (int i2 = 0; i2 < islands_count ; i2++ ) {
                    free( (*varr)[i2]);
                }
                free( (*varr) );
                for (int i2 = 0; i2 < islands_count ; i2++ ) {
                    free( (*parr)[i2]);
                }
                free( (*parr) );
            }
            mx_printerr("error: line ");
            char *itoa = mx_itoa(line_cnt);
            mx_printerr( itoa );
            free(itoa);
            mx_printerr(" is not valid\n");
            exit(-5);
        }
        int x1 = 0;
        int i2 = 0;
        for (; i2 < islands_count; i2++) { // check if island1 already exists
            if ( (*varr)[i2] == NULL) {
                (*varr)[i2] = island1;
                x1 = 2;
                break;
            }
            else if (mx_strcmp( (*varr)[i2], island1) == 0) {
                x1 = 1;
                break;
            }
        }
        if (x1 != 2) {
            mx_strdel(&island1);
            island1 = NULL;
        }
        if (x1 == 0) { //
            mx_strdel(&distance);
            if (island2 != NULL)
                mx_strdel(&island2);
            { // free varr & parr
                for (int i2 = 0; i2 < islands_count ; i2++ ) {
                    free( (*varr)[i2]);
                }
                free( (*varr) );
                for (int i2 = 0; i2 < islands_count ; i2++ ) {
                    free( (*parr)[i2]);
                }
                free( (*parr) );
            }
            mx_printerr("error: invalid number of islands\n");
            exit(-6);
        }
        x1 = 0;
        int i3 = 0;
        for (; i3 < islands_count; i3++) { // check if island2 already exists

            if ( (*varr)[i3] == NULL ) {
                (*varr)[i3] = island2;
                x1 = 2;
                break;
            }
            else if (mx_strcmp( (*varr)[i3], island2) == 0) {
                x1 = 1;
                break;
            }
        }
        if (x1 != 2) {
            mx_strdel(&island2);
            island2 = NULL;
        }
        if ( x1 == 0 ) { 
            mx_strdel(&distance);
            if (island1 != NULL)
                mx_strdel(&island1);
            { // free varr & parr
                for (int i2 = 0; i2 < islands_count ; i2++ ) {
                    free( (*varr)[i2]);
                }
                free( (*varr) );
                for (int i2 = 0; i2 < islands_count ; i2++ ) {
                    free( (*parr)[i2]);
                }
                free( (*parr) );
            }
            mx_printerr("error: invalid number of islands\n");
            exit(-6);
        }
        if ( (*parr)[i2][i3] != 0 ) {
            mx_strdel(&distance);
            if (island1 != NULL)
                mx_strdel(&island1);
            if (island2 != NULL)
                mx_strdel(&island2);
            { // free varr & parr
                for (int i2 = 0; i2 < islands_count ; i2++ ) {
                    free( (*varr)[i2]);
                }
                free( (*varr) );
                for (int i2 = 0; i2 < islands_count ; i2++ ) {
                    free( (*parr)[i2]);
                }
                free( (*parr) );
            }
            mx_printerr("error: duplicate bridges\n");
            exit(-7);
        }
        else {
            (*parr)[i2][i3] = mx_atoi(distance);
            (*parr)[i3][i2] = mx_atoi(distance);
            mx_strdel(&distance);
        }
        line_cnt++;
    }
    if (bridges_lenght_sum > (long)__INT_MAX__) {
        { // free varr & parr
            for (int i2 = 0; i2 < islands_count ; i2++ ) {
                free( (*varr)[i2]);
            }
            free( (*varr) );
            for (int i2 = 0; i2 < islands_count ; i2++ ) {
                free( (*parr)[i2]);
            }
            free( (*parr) );
        }
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(-8);
    }
    close(fd);
    return islands_count;
}



