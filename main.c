#include <stdio.h>
#include "grid.h"

int main(void)
{
    struct grid ngrid = create_grid(10, 10);
    insert_cell(&ngrid, 1, 3, 3);
    insert_cell(&ngrid, 1, 1, 3);
    insert_cell(&ngrid, 1, 2, 1);
    print_grid(&ngrid);

    return 0;
}