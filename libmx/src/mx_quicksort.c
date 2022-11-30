#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL)
        return -1;
    int cnt = 0;
    int mid = (double)((right - left) / 2)  + left;
    //mx_printint(mid);
    for (int i = left; i < right; i++)                       
        if ( mx_strlen(arr[i]) >= mx_strlen(arr[mid]) )           
            for (int j = right; j > i; j--)             
                if ( mx_strlen(arr[j]) < mx_strlen(arr[mid]) ) {
                    char *temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    i = left;
                    cnt++;
                    break;
                }
    if (mid - left > 0 ) 
        cnt += mx_quicksort(arr, left, mid);
    if (right - mid > 0 )
        cnt += mx_quicksort(arr, mid + 1, right);
    return cnt;
}


