#include <stdio.h>
#include <Windows.h>
#include "grid.h"

int main(void)
{
    grid ngrid = create_grid(10, 10);
    insert_cell(&ngrid, 1, 3, 3);
    insert_cell(&ngrid, 1, 1, 3);
    insert_cell(&ngrid, 1, 2, 1);
    print_grid(&ngrid);

    free(ngrid.grid_array);

    return 0;
}