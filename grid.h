#ifndef GRID_H_
#define GRID_H_


typedef struct
{
    int dim_x;
    int dim_y;
    int* grid_array;
} grid;


grid create_grid(int, int);
void print_grid(grid*);
void insert_cell(grid*, int, int, int);
int get_cell(grid*, int, int);

#endif