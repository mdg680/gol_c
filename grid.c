#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"

struct grid create_grid(int dim_x, int dim_y)
{
    struct grid grid;
    grid.dim_x = dim_x;
    grid.dim_y = dim_y;
    grid.grid_array = (int*)malloc(dim_x * dim_y * sizeof(int));

    return grid;
}

void populate_grid_random(struct grid* grid)
{
    // TODO
}

void insert_cell(struct grid* grid, int value, int x, int y)
{
    grid->grid_array[y*grid->dim_y + x] = value;
}

void print_grid(struct grid* grid)
{
    printf("Print Grid(%d,%d)\n\n", grid->dim_x, grid->dim_y);
    for (int y = 0; y < grid->dim_y; y++){
        for (int x = 0; x < grid->dim_x; x++){
            printf("%d ", grid->grid_array[x + y*grid->dim_y]);
        }
        printf("\n");
    }
}