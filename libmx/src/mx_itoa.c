#include "../inc/libmx.h"

static int mx_num_count(int number) {
    long num = number;
    int cnt = 0;
    if (num < 0) {
        cnt++;
        num *= -1;
    }
    for ( ; num != 0; cnt++) {
        num /= 10;
    }
    return cnt;
}
char *mx_itoa(int number) {
    if (number == 0) {
        char *str2 = (char *)malloc( 2 * sizeof(char) );
        str2[0] = '0';
        str2[1] = '\0';
        return str2;
    }
    long num = number;
    number = mx_num_count(number) + 1;
    char *str = (char *)malloc( number * sizeof(char) );
    int i = 0;
    if (num < 0) {
        num *= -1;
        str[0] = '-';
    }
    for (i = number - 2; i >= 0 ; i--) {
        if (num > 0) {
            str[i] = (num % 10) + '0';
            num /= 10;
        }
    }
    str[number - 1] = '\0';
    return str;
}

