#include "../inc/pathfinder.h"

int **mx_find_algoritm(int **adjacency_matrix, int **min_path, int dest, int size) {

    int min_path_last = min_path[0][0];
    int mpi = 0;
    for ( ; mpi < size && min_path[0][mpi] != -1; mpi++) // last island
        min_path_last = min_path[0][mpi];

    int start = min_path_last;
    if ( start < size ) { //

        int mp_len = 0;
        for ( ; min_path[mp_len] != NULL; mp_len++) {  }

        int **min_path_temp = (int **)malloc( sizeof(int *) * (mp_len + 1) ); // need to be freed

        for (int ix = 0; ix < mp_len; ix++)
            min_path_temp[ix] = (int *)malloc( sizeof(int ) * size);
        min_path_temp[mp_len] = NULL;

        for (int ix = 0; ix < mp_len; ix++)
            for (int i = 0; i < size; i++)
                min_path_temp[ix][i] = min_path[ix][i];

        int **min_path_next;

        for (int node = 0; node < size; node++) { // 1 horisontal line 

            bool b = true; // 
            for (int i = 0; i < size; i++) {
                if (min_path[0][i] == node) {
                    b = false;
                    break;
                }
            }

            if ( b && adjacency_matrix[start][node] > 0 ) { 

                if (node == dest) {

                    min_path_next = (int **)malloc(sizeof(int *) * 2);
                    min_path_next[0] = (int *)malloc( sizeof(int ) * size);
                    min_path_next[1] = NULL;
                    for (int i = 0; i < size; i++)
                        min_path_next[0][i] = min_path[0][i];
                    
                    for (int i = 0; i < size; i++)
                        if ( min_path_next[0][i] == -1 ) {
                            min_path_next[0][i] = node;
                            break;
                        }
                }
                else {
                    min_path_next = (int **)malloc(sizeof(int *) * 2);
                    min_path_next[0] = (int *)malloc( sizeof(int ) * size);
                    min_path_next[1] = NULL;
                    for (int i = 0; i < size; i++)
                        min_path_next[0][i] = min_path[0][i];
                    
                    for (int i = 0; i < size; i++)
                        if ( min_path_next[0][i] == -1 ) {
                            min_path_next[0][i] = node;
                            break;
                        }
                    min_path_next = mx_find_algoritm(adjacency_matrix, min_path_next, dest, size);
                }
                int last1 = min_path_next[0][0];
                int i_cnt = 0;
                for ( int i = 0; i < size - 1 && min_path_next[0][i + 1] != -1; i++) { 

                    last1 = min_path_next[0][i + 1];
                    i_cnt += adjacency_matrix[ min_path_next[0][i] ][ min_path_next[0][i+1] ];
                } // cnt 
                min_path_last = min_path_temp[0][0];
                mpi = 0;
                for ( int i = 0; i < size - 1 && min_path_temp[0][i + 1] != -1; i++) {

                    min_path_last = min_path_temp[0][i + 1];
                    mpi += adjacency_matrix[ min_path_temp[0][i] ][ min_path_temp[0][i+1] ];
                }
                if (last1 == dest && min_path_last != dest) {

                    for (int i = 0; min_path_temp[i] != NULL; i++)
                        free( min_path_temp[i] );
                    free(min_path_temp);
                    min_path_temp = min_path_next;
                }
                else if (last1 == dest && min_path_last == dest && i_cnt < mpi) {

                    for (int i = 0; min_path_temp[i] != NULL; i++)
                        free( min_path_temp[i] );
                    free(min_path_temp);
                    min_path_temp = min_path_next;
                }
                else if (last1 == dest && min_path_last == dest && i_cnt == mpi) {

                    // bool b2 = false;
                    // for (int i = 0; i < size; i++) // mpn != mp
                    //     if ( min_path_next[0][i] != min_path_temp[0][i] ) 
                    //         b2 = true;
                    
                    int mp_cnt = 0;
                    for ( ; min_path_temp[mp_cnt] != NULL; mp_cnt++) {  }
                    int mpn_cnt = 0;
                    for ( ; min_path_next[mpn_cnt] != NULL; mpn_cnt++) {  }

                    int **temp = (int **)malloc( sizeof(int *) * (mp_cnt + mpn_cnt + 1) );
                    int  j = 0;
                    for (int i = 0; min_path_temp[i] != NULL; i++) {
                        temp[j] = min_path_temp[i];
                        j++;
                    }
                    for (int i = 0; min_path_next[i] != NULL; i++){
                        temp[j] = min_path_next[i];
                        j++;
                    }
                    temp[mp_cnt + mpn_cnt] = NULL;

                    free(min_path_next);
                    free(min_path_temp);
                    min_path_temp = temp;
                }
                else if (min_path_next != NULL) {

                    for (int i = 0; min_path_next[i] != NULL; i++)
                        free( min_path_next[i] );
                    free(min_path_next);
                }
                
            }
        }
        for (int i = 0; min_path[i] != NULL; i++)
            free( min_path[i] );
        free(min_path);
        min_path = min_path_temp;
    }
    return min_path;
}


