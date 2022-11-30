#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    long atoi = 0;
    int sign = 1;
    int i = 0;
    if (str[0] == '-' || str[0] == '+') {
        if (str[0] == '-') 
            sign = -1;
        i++;
    }
    for ( ; str[i] != 0 ; i++) {
        if ( mx_isdigit( str[i] ) == 1 ) {
            if (atoi != 0) 
                atoi *= 10;
            atoi += str[i] - '0';
        }
        else 
            break;
    }
    return (int)(atoi * sign);
}

