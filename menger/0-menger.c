#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: The level of the Menger Sponge to draw
 *
 * Description: If level < 0, does nothing.
 * Calculates coordinates based on powers of 3.
 * A position (row, col) is empty if, at any step of dividing by 3,
 * the remainder of both row and col is 1 (the center of a 3x3 block).
 */
void menger(int level)
{
	int row, col, size, r, c;
	char symbol;

	if (level < 0)
		return;

	/* Calculate the size of the square: 3^level */
	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			/* Default assumption: we print a block */
			symbol = '#';
			r = row;
			c = col;

			/*
			 * Check recursively if this coordinate falls into a 'hole'.
			 * A hole exists if row % 3 == 1 and col % 3 == 1
			 * at any scale level.
			 */
			while (r > 0 || c > 0)
			{
				if (r % 3 == 1 && c % 3 == 1)
				{
					symbol = ' ';
					break;
				}
				r /= 3;
				c /= 3;
			}
			putchar(symbol);
		}
		putchar('\n');
	}
}
