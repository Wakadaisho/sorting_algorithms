#include "sort.h"

/**
 * partition - partition array using Lomuto scheme on last element
 * @array: array to partition
 * @size: size of the whole array
 * @low: lowest index in parition
 * @high: largest index in partiton
 * Return: index of the pivot once moved to correct position
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	i = low - 1;
	pivot = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_array(array + i, array + j);
		}
	}
	swap_array(array + i + 1, array + high);
	print_array(array, size);
	return (i + 1);
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
		quick_sort_r(array, size, low, pivot - 1);
		quick_sort_r(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - sort an integer array using Quick Sort (Lomuto)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
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
