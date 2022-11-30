#include "../inc/libmx.h"

int mx_isdigit(int n) {
    if ( n >= 48 && n <= 57 ) {
        return 1;
    }
    return 0;
}



