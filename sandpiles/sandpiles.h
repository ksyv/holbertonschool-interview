#ifndef __sandpiles__
#define __sandpiles__
/*Library*/
#include <stdio.h>
#include <stdlib.h>
/*prototype*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int grid_is_stable(int grid[3][3]);
void print_this_grid(int grid[3][3]);
void leave_the_big_piles(int grid[3][3]);

#endif