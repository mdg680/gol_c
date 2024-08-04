#ifndef GRID_H_
#define GRID_H_

#include <stdbool.h>

typedef struct grid
{
    /* data */
    int dim_x;
    int dim_y;
    int* grid_array;
} grid;


struct grid create_grid(int dim_x, int dim_y);
void print_grid(struct grid grid);
//void populate_random(grid grid);

#endif