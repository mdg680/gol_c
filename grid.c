#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

struct grid create_grid(int dim_x, int dim_y)
{
    struct grid grid;
    grid.dim_x = dim_x;
    grid.dim_y = dim_y;
    grid.grid_array = (int*)malloc(dim_x * dim_y * sizeof(int));
    
    return grid;
}

void print_grid(struct grid grid)
{
    printf("Print Grid(%d,%d)\n", grid.dim_x, grid.dim_y);

    // for (int n = 0; n < grid.dim_x * grid.dim_y; n++) {
    //     printf("%d", grid.grid_array[n]);
    // }
    printf("\n");
    for (int y = 0; y < grid.dim_y; y++){
        for (int x = 0; x < grid.dim_x; x++){
            printf("%d ", grid.grid_array[x + y*x]);
        }
        printf("\n");
    }
}