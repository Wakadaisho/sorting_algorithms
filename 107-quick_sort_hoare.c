#include "sort.h"

/**
 * partition - partition array using Hoare scheme on last element
 * @array: array to partition
 * @size: size of the array
 * @low: lowest index in parition
 * @high: largest index in partiton
 * Return: index of the pivot once moved to correct position
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[low];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_array(array + i, array + j);
		print_array(array, size);
	}
}

/**
 * quick_sort_r - quick sort recursively
 * @array: original array to sort
 * @size: size of the array
 * @low: lowest index in parition
 * @high: largest index in partiton
 */
void quick_sort_r(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high || size < 2 || array == NULL)
	{
		pivot = partition(array, size, low, high);
		quick_sort_r(array, size, low, pivot);
		quick_sort_r(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort_hoare - sort an integer array using Quick Sort (Hoare)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_r(array, size, 0, (int)size - 1);
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
