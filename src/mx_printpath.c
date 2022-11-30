#include "../libmx/inc/libmx.h"

void mx_printpath(char **path_arr, char **route_arr, int *distance_arr, int size) {
    mx_printstr("========================================");
    mx_printstr("\nPath: ");
    for (int i = 0; i < 2; i++) {
        mx_printstr( path_arr[i] );
        if ( i + 1 < 2 ) 
            mx_printstr(" -> ");
    }
    mx_printstr("\nRoute: ");
    for (int i = 0; i < size; i++) {
        mx_printstr( route_arr[i] );
        if ( i + 1 < size ) 
            mx_printstr(" -> ");
    }
    mx_printstr("\nDistance: ");
    int i = 0;
    for ( ; i + 1 < size; i++) {
        mx_printint( distance_arr[i] );
        if ( i + 2 < size ) 
            mx_printstr(" + ");
    }
    if (i > 1) {
        mx_printstr(" = ");
        mx_printint( distance_arr[i] );
    }
    mx_printstr("\n========================================\n");
}


