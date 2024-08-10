#include <stdio.h>
#include <stdlib.h>

#include "grid.h"
#include "cell.h"

grid create_grid(int dim_x, int dim_y)
{
    grid grid;
    grid.dim_x = dim_x;
    grid.dim_y = dim_y;
    grid.grid_array = (int*)calloc(dim_x * dim_y, sizeof(cell_data));

    return grid;
}

void insert_cell(grid* grid, int value, int x, int y)
{
    grid->grid_array[y * grid->dim_y + x] = value;
}

cell_data get_cell(grid* grid, int x, int y)
{
    return grid->grid_array[x + y * grid->dim_y];
}

void print_grid(grid* grid)
{
    printf("Print Grid(%d,%d)\n\n", grid->dim_x, grid->dim_y);
    
    int dim_y = grid->dim_y;
    int dim_x = grid->dim_x;
    
    for (int y = 0; y < dim_y; y++){
        for (int x = 0; x < dim_x; x++){
            printf("%d ", get_cell(grid, x, y));
        }
        printf("\n");
    }
}