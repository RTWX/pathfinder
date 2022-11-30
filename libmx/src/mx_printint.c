#include "../inc/libmx.h"

void mx_printint(int n) {
    long num = n;
    if (num == 0) {
        int x = 48;
        write(1, &x, 1);
    }
    if (num < 0) {
        int x = 45;
        write(1, &x, 1);
        num *= -1;
    }
    char cint[10] = {0};
    for(int i = 9; num > 0 && i >= 0; i--) {
        char c = (num % 10) + '0';
        num = num / 10;
        cint[i] = c;
    }
    for (int i = 0; i < 10; i++) {
        if (cint[i] != '\0') {
            write(1, &(cint[i]), 1);
        }
    }
}

