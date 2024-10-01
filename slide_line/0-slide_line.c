#include "slide_line.h"



/**
 * slide_line - slides line to the left or to the right
 * @line: list of int
 * @size: size of list
 * @direction: direction to slide
 * Return: 1 if successful or 0 if fails
 */

int slide_line(int *line, size_t size, int direction)
{
	if (!line || !size)
		return (0);
	if (direction == 76)
		to_the_left(line, size);
	else if (direction == 82)
		to_the_right(line, size);
	else
		return (0);
	return (1);
}

/**
 * to_the_left - pushes line to the left
 * @line: list of int
 * @size: size of list
 */
void to_the_left(int *line, size_t size)
{
	size_t index1, index2;

	for (index1 = 0; index1 < size; index1++)
	{
		for (index2 = index1 + 1; index2 < size; index2++)
		{
			if (line[index1] == 0 && line[index2] != 0)
			{
				line[index1] = line[index2];
				line[index2] = 0;
				index1--;
				break;
			}
			if (line[index1] == line[index2] && line[index1] != 0)
			{
				line[index1] *= 2;
				line[index2] = 0;
				break;
			}
			else if (line[index2] != 0 && line[index1 + 1] == 0)
			{
				line[index1 + 1] = line[index2];
				line[index2] = 0;
				break;
			}
		}
	}
}

/**
 * to_the_right - pushes line to the right
 * @line: list of int
 * @size: size of list
 */
void to_the_right(int *line, size_t size)
{
	size_t index1, index2;

	for (index1 = 1; index1 <= size; index1++)
	{
		for (index2 = index1 + 1; index2 <= size; index2++)
		{
			if (line[size - index1] == 0 && line[size - index2] != 0)
			{
				line[size - index1] = line[size - index2];
				line[size - index2] = 0;
				index1--;
				break;
			}
			if (line[size - index1] == line[size - index2] && line[size - index1] != 0)
			{
				line[size - index1] *= 2;
				line[size - index2] = 0;
				break;
			}
			else if (line[size - index2] != 0 && line[size - (index1 + 1)] == 0)
			{
				line[size - (index1 + 1)] = line[size - index2];
				line[size - index2] = 0;
				break;
			}
		}
	}
}

