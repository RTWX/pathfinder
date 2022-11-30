#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    
    if (pow == 0) {
        return 1;
    }
    double np = n;
    
    for (unsigned int i = 1; i < pow; i++) {
        np = np * n;
    }
    return np;
}







