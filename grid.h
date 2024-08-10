#ifndef GRID_H_
#define GRID_H_

typedef struct
{
    int dim_x;
    int dim_y;
    int* grid_array;
} grid;


grid create_grid(int dim_x, int dim_y);
void print_grid(grid* grid);
void populate_grid_random(grid*);
void insert_cell(grid*, int, int, int);

#endif