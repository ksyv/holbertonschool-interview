#include "sort.h"

/**
 * merge_sub - Merges two subarrays of integers.
 * @sub: The original array to store merged elements.
 * @tmp: The working buffer.
 * @left: Pointer to the left subarray.
 * @l_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @r_size: Size of the right subarray.
 */
void merge_sub(int *sub, int *tmp, int *left, size_t l_size,
	       int *right, size_t r_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, l_size);
	printf("[right]: ");
	print_array(right, r_size);

	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
			tmp[k++] = left[i++];
		else
			tmp[k++] = right[j++];
	}
	while (i < l_size)
		tmp[k++] = left[i++];
	while (j < r_size)
		tmp[k++] = right[j++];

	for (i = 0; i < l_size + r_size; i++)
		sub[i] = tmp[i];

	printf("[Done]: ");
	print_array(sub, l_size + r_size);
}

/**
 * recursive_merge - Top-down recursive merge sort logic.
 * @array: The subarray to sort.
 * @tmp: The working buffer.
 * @size: Size of the current subarray.
 */
void recursive_merge(int *array, int *tmp, size_t size)
{
	size_t mid;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;
	left = array;
	right = array + mid;

	recursive_merge(left, tmp, mid);
	recursive_merge(right, tmp, size - mid);
	merge_sub(array, tmp, left, mid, right, size - mid);
}

/**
 * merge_sort - Sorts an array using Top-down Merge Sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	recursive_merge(array, tmp, size);
	free(tmp);
}
