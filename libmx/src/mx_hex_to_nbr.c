#include "../inc/libmx.h"

int mx_hex_number(char hexn) {
    switch (hexn) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': return 10;
        case 'A': return 10;
        case 'b': return 11;
        case 'B': return 11;
        case 'c': return 12;
        case 'C': return 12;
        case 'd': return 13;
        case 'D': return 13;
        case 'e': return 14;
        case 'E': return 14;
        case 'f': return 15;
        case 'F': return 15;
    }
    return -1;
}
unsigned long mx_hex_to_nbr(const char* hex) {
    unsigned long nbr = 0;
    for(int i = 0; hex[i] != 0; i++) {
        if ( ( hex[i] >= '0' && hex[i] <= '9' )
                || ( hex[i] >= 'A' && hex[i] <= 'F' )
                || ( hex[i] >= 'a' && hex[i] <= 'f' ) ) {
            nbr *= 16;
            nbr += mx_hex_number(hex[i]);
        }
    }
    return nbr;
}

