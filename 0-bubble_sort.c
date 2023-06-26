#include "sort.h"

/**
 * bubble_sort - sort an integer array using Bubble Sort
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_array(array + j, array + j + 1);
				swapped = 1;
				print_array(array,  size);
			}
		}
		if (!swapped)
			break;
	}
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
