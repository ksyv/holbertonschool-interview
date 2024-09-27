#include "sandpiles.h"

/**
  * sandpiles_sum - add 2 grid of sandpiles
  * @grid1: first grid
  * @grid2: sec grid
  */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int indexLine, indexColumn = 0;

	for (indexLine = 0; indexLine < 3; indexLine++)
	{
		for (indexColumn = 0; indexColumn < 3; indexColumn++)
		{
			grid1[indexLine][indexColumn] += grid2[indexLine][indexColumn];
		}
	}
	while (grid_is_stable(grid1) == 0)
	{
		printf("=\n");
		print_this_grid(grid1);
		leave_the_big_piles(grid1);
	}
}

/**
  * grid_is_stable - verify if the grid is stable
  * No sandpile is upper than 3
  * @grid: the grid analised
  *
  * Return: 1 if it's stable, 0 if not
  */
int grid_is_stable(int grid[3][3])
{
	int indexLine, indexColumn = 0;

	for (indexLine = 0; indexLine < 3; indexLine++)
	{
		for (indexColumn = 0; indexColumn < 3; indexColumn++)
		{
			if (grid[indexLine][indexColumn] > 3)
				return (0);
		}
	}

	return (1);
}

/**
  * print_this_grid - print the actual grid
  * of integers using binary search.
  * @grid: the grid who's print
  */
void print_this_grid(int grid[3][3])
{
	int indexLine, indexColumn;

	for (indexLine = 0; indexLine < 3; indexLine++)
	{
		for (indexColumn = 0; indexColumn < 3; indexColumn++)
		{
			if (indexColumn)
				printf(" ");
			printf("%d", grid[indexLine][indexColumn]);
		}
		printf("\n");
	}
}

/**
  * leave_the_big_piles - leave the sandpiles who's upper than 3
  * @grid: the grid of sandpiles
  *
  * Return: -1 if value is not found, first index if it's found
  */
void leave_the_big_piles(int grid[3][3])
{
	int indexLine, indexColumn = 0;
	int temporary_grid[3][3] = {0};

	for (indexLine = 0; indexLine < 3; indexLine++)
	{
		for (indexColumn = 0; indexColumn < 3; indexColumn++)
		{
			if (grid[indexLine][indexColumn] > 3)
			{
				temporary_grid[indexLine][indexColumn] -= 4;
				if ((indexLine - 1) >= 0)
				{
					temporary_grid[indexLine - 1][indexColumn] += 1;
				}
				if ((indexLine + 1) < 3)
				{
					temporary_grid[indexLine + 1][indexColumn] += 1;
				}
				if ((indexColumn - 1) >= 0)
				{
					temporary_grid[indexLine][indexColumn - 1] += 1;
				}
				if ((indexColumn + 1) < 3)
				{
					temporary_grid[indexLine][indexColumn + 1] += 1;
				}
			}
		}
	}
	for (indexLine = 0; indexLine < 3; indexLine++)
	{
		for (indexColumn = 0; indexColumn < 3; indexColumn++)
			grid[indexLine][indexColumn] += temporary_grid[indexLine][indexColumn];
	}
}
