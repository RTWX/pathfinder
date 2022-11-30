#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_pathfinder(char **varr, int **parr, int size) {

    int **carr = (int **)malloc( sizeof(int *) * size );
    for (int i = 0; i < size; i++ )
        carr[i] = (int *)malloc( sizeof(int) * size );

    for (int i2 = 0; i2 < size; i2++ ) 
        for (int i3 = 0; i3 < size; i3++ )
            if ( i2 != i3 )
                carr[i2][i3] = 0;
            else
                carr[i2][i3] = 1;

    int island1 = 0;
    for ( ; island1 < size; island1++ ) {

        int island2 = 0;
        for ( ; island2 < size; island2++ ) {

            if ( carr[island1][island2] == 0 ) {

                int **start_path = (int **)malloc( sizeof(int *) * 2); // need to be freed
                start_path[0] = (int *)malloc( sizeof(int ) * size);
                start_path[1] = NULL;

                for (int i = 0; i < size; i++)
                    start_path[0][i] = -1;
                start_path[0][0] = island1;

                int **path = mx_find_algoritm(parr, start_path, island2, size );

                for (int ix = 0; path[ix] != NULL; ix++) {

                    int lenght = 0;
                    for ( ; lenght < size && path != NULL && path[ix][lenght] != -1 ; lenght++) {  }

                    if (lenght >= 2) {

                        char **path_arr = (char **)malloc( sizeof(char *) * 2);
                        path_arr[0] = mx_strdup( varr[island1] );
                        path_arr[1] = mx_strdup( varr[island2] );

                        char **route_arr = (char **)malloc( sizeof(char *) * lenght );
                        int i = 0;
                        for ( ; i < lenght ; i++ ) {

                            if (path[ix][i] != -1)
                                route_arr[i] = mx_strdup( varr[path[ix][i]] );
                            else
                                route_arr[i] = NULL;
                        }
                        int *distance_arr = (int *)malloc( sizeof(int) * lenght );
                        i = 0;
                        int i2 = 0;
                        for ( ; i2 + 1 < lenght && path[ix][i2 + 1] != -1 ; i2++ ) {

                            distance_arr[i2] = parr[ path[ix][i2] ][ path[ix][i2+1] ];
                            i += distance_arr[i2];
                        }
                        if (i2 > 1)
                            distance_arr[i2] = i;

                        carr[ path[ix][0] ][ path[ix][lenght-1] ] = 1;
                        carr[ path[ix][lenght-1] ][ path[ix][0] ] = 1;

                        mx_printpath( path_arr, route_arr, distance_arr, lenght );

                        for ( int i = 0; i < 2  ; i++ ) 
                            free( path_arr[i] );
                        free(path_arr);

                        for ( int i = 0; i < lenght && route_arr[i] != NULL ; i++ ) 
                            free( route_arr[i] );
                        free(route_arr);
                        free(distance_arr);
                    }
                }
                for (int i2 = 0; path[i2] != NULL; i2++ ) {
                    free(path[i2]);
                }
                free(path);
            }
        }
    }
    for (int i2 = 0; i2 < size ; i2++ ) {
        free(carr[i2]);
    }
    free(carr);
}


