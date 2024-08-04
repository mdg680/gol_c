#include <stdio.h>
#include "grid.h"

int main(void)
{
    printf("run");

    struct grid ngrid = create_grid(40, 30);
    print_grid(ngrid);
}