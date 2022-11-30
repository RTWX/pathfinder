#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) { 
    if (arr == NULL)
        return -1;
    int quit = 0;
    int cnt = 0;
    while (!quit) {
        quit = 1;
        for (int i = 0; i < size - 1; i++) {
            if ( mx_strcmp(arr[i], arr[i+1] ) > 0 ) {
                char *c = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = c;
                quit = 0;
                cnt++;
            }
        }
    }
    return cnt;
}




