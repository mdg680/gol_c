#ifndef GRID_H_
#define GRID_H_

struct grid
{
    /* data */
    int dim_x;
    int dim_y;
    int* grid_array;
};


struct grid create_grid(int dim_x, int dim_y);
void print_grid(struct grid* grid);
void populate_grid_random(struct grid*);
void insert_cell(struct grid*, int, int, int);

#endif