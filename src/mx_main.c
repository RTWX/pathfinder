#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    } 
    else {
        // 1D array of islands names in FIFO 
        char **varr = NULL; 
        // adjacency matrix with bridges lenghts
        int **parr = NULL; 

        int islands_count = mx_readfile((char *)argv[1], &varr, &parr);

        mx_pathfinder(varr, parr, islands_count);

        for (int i2 = 0; i2 < islands_count ; i2++ ) {
            free(varr[i2]);
        }
        free(varr);
        for (int i2 = 0; i2 < islands_count ; i2++ ) {
            free(parr[i2]);
        }
        free(parr);
    }
    return 0;
}


