#include "sort.h"
#include <stdio.h>

#define ASC 1
#define DESC 0

/**
 * bitonic_merge - merge sorted bitonic arrays
 * @array: array to sort
 * @low: the starting index
 * @count: number of elements in the array split
 * @order: ascending (1) or descending (0) order
 * @iteration: current depth of the recursion
 */
void bitonic_merge(int *array, size_t low, size_t count,
				   int order, int iteration)
{
	size_t k, i, swapped = 0;

	if (count <= 1)
	{
		return;
	}

	k = count / 2;


	for (i = low; i < low + k; i++)
	{
		if (order == (array[i] > array[i + k]))
		{
			swap_array(array + i, array + i + k);
			swapped = 1;
		}
	}

	if (swapped)
	{
		printf("Result [%lu/%lu] (%s)\n",
		 count, count << iteration, order ? "UP" : "DOWN");
		print_array(array, count);
	}

	bitonic_merge(array, low, k, order, iteration + 1);
	bitonic_merge(array, low + k, k, order, iteration + 1);

}
/**
 * bitonic_sort_r - recursively sort an array bitonically
 * @array: array to sort
 * @low: the starting index
 * @count: number of elements in the array split
 * @order: ascending (1) or descending (0) order
 * @iteration: current depth of the recursion
 */
void bitonic_sort_r(int *array, size_t low, size_t count,
					int order, int iteration)
{
	size_t k;

	if (count <= 1)
		return;

	k = count / 2;

	printf("Merging [%lu/%lu] (%s)\n",
		count, count << iteration, order ? "UP" : "DOWN");
	print_array(array, count);
	bitonic_sort_r(array, low, k, ASC, iteration + 1);
	bitonic_sort_r(array, low + k, k, DESC, iteration + 1);
	bitonic_merge(array, low, count, order, iteration);
}

/**
 * bitonic_sort - sort an linked list using Bitonic Sort
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	size_t k, iteration = 0;

	if (size <= 1 || array == NULL)
		return;

	k = size / 2;

	printf("Merging [%lu/%lu] (%s)\n",
		size, size << iteration, size ? "UP" : "DOWN");
	print_array(array, size);
	bitonic_sort_r(array, 0, k, ASC, iteration + 1);
	bitonic_sort_r(array, 0 + k, k, DESC, iteration + 1);
	bitonic_merge(array, 0, size, ASC, iteration);
}

/**
 * swap_array - swap two elements values in memory
 * @i: first integer
 * @j: second integer
 */
void swap_array(int *i, int *j)
{
	int tmp;

	tmp = *j;
	*j = *i;
	*i = tmp;
}
