#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - Find max value in an array
 * @array: Array of int
 * @size: Array's size
 * Return: Max value in the array
 */
int get_max(int *array, size_t size)
{
	int max_val;
	size_t i;

	if (array == NULL || size == 0)
		return (0);

	max_val = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}
	return (max_val);
}

/**
 * counting_sort_for_radix - sort an array of int by exp
 * @array: Array who sorted
 * @size: Array's size
 * @exp: Exp for define the numbers comparated
 */
void counting_sort_for_radix(int *array, size_t size, int exp)
{
	int *output_array = NULL;
	int count[10] = {0};
	size_t i;
	int digit;

	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		digit = (array[i] / exp) % 10;
		output_array[count[digit] - 1] = array[i];
		count[digit]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(output_array);
}

/**
 * radix_sort - Sort an array of int in order
 * @array: array who sorted
 * @size: array's size
 */

void radix_sort(int *array, size_t size)
{
	int max_val;
	int exp;

	if (array == NULL || size < 2)
		return;

	max_val = get_max(array, size);

	for (exp = 1; max_val / exp > 0; exp *= 10)
	{
		counting_sort_for_radix(array, size, exp);
		print_array(array, size);
	}
}
