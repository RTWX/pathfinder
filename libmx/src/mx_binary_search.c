#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) { 
    if (arr == NULL || s == NULL){
        *count = 0;
        return -1;
    }
    int indx = 0;
    int mid = (*count + size ) / 2;
    int mid2 = (*count + size ) % 2;
    if (mid2 == 0)
        mid--;
    if (mx_strcmp(s, arr[mid] ) == 0 ) {
        *count = 1;
        return mid;
    }
    if ( mx_strcmp(s, arr[mid] ) > 0 && mid+1 != size) {
        *count = mid + 1;
        indx = mx_binary_search(arr, size, s, count );
        if ( indx >= 0 ) { 
            *count += 1;
            return indx;
        }
    }
    else if ( mx_strcmp(s, arr[mid] ) < 0 && *count != mid) {
        indx = mx_binary_search(arr, mid, s, count);
        if ( indx >= 0 ) { 
            *count += 1;
            return indx;
        }
    }
    *count = 0;
    return -1;
}




