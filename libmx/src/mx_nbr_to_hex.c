#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char chex[31] = {0};
    for(int i = 30; nbr > 0 && i >= 0; i--) {
        unsigned long num = nbr % 16;
        nbr = nbr / 16;
        char chr = ' ';
        if (num == 10) {
            chr = 'a';
        }
        else if (num == 11) {
            chr = 'b';
        }
        else if (num == 12) {
            chr = 'c';
        }
        else if (num == 13) {
            chr = 'd';
        }
        else if (num == 14) {
            chr = 'e';
        }
        else if (num == 15) {
            chr = 'f';
        }
        else {
            chr = num + '0';
        }
        chex[i] = chr;
    }
    int size = 0;
    for (int i = 0; i < 31; i++) {
        if (chex[i] != 0) {
            size++;
        }
    }
    char *hex = malloc( ( size * sizeof(char) ) + 1);
    int j = 0;
    for (int i = 0; i < 31; i++) {
        if (chex[i] != 0) {
            hex[j] = chex[i];
            j++;
        }
    }
    hex[j] = '\0';
    return hex;
}

