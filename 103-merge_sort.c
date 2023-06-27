#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_arrays - merge two arrays with elements sorted in ascending ordr
 * @array: original array
 * @left: left half of @array
 * @l_size: length of @left
 * @right: right half of @array
 * @r_size: length of @right
 */
void merge_arrays(int *array, int *left, size_t l_size,
				  int *right, size_t r_size)
{
	size_t i, j, k;

	printf("Merging...\n");

	printf("[left]: ");
	print_array(left, l_size);

	printf("[right]: ");
	print_array(right, r_size);

	for (i = j = k = 0; i < l_size && j < r_size; k++)
		array[k] = left[i] <= right[j] ? left[i++] : right[j++];

	while (i < l_size)
		array[k++] = left[i++];

	while (j < r_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, k);
}

/**
 * merge_sort - sort an array using Merge Sort
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i, j, l_size, r_size;
	int *left, *right;

	if (size < 2)
		return;

	l_size = size / 2;
	r_size = size - l_size;

	left = (int *) malloc(l_size * sizeof(int));
	right = (int *) malloc(r_size * sizeof(int));

	for (i = j = 0; i < l_size;)
		left[j++] = array[i++];

	for (j = 0; j < r_size;)
		right[j++] = array[i++];

	merge_sort(left, l_size);
	merge_sort(right, r_size);
	merge_arrays(array, left, l_size, right, r_size);
	free(left);
	free(right);
}
