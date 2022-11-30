#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) 
        return -1;
    int counted = 0;
    int count = 0;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] != c) {
            if (!counted) {
                count++;
                counted = 1;
            }
        }
        else if (str[i] == c) {
            counted = 0;
        }
    }
    return count;
}

