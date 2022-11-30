#ifndef PATHFINDER
#define PATHFINDER

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>

void mx_printpath(char **path_arr, char **route_arr, int *distance_arr, int size);
int mx_readfile(char *filename, char ***varr, int ***parr);
void mx_pathfinder(char **varr, int **parr, int size);
int **mx_find_algoritm(int **adjacency_matrix, int **min_path, int dest, int size);

#endif


