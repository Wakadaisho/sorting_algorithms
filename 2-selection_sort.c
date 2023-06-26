#include "sort.h"

/**
 * selection_sort - sort an integer array using Selection Sort
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap_array(array + i, array + min);
			print_array(array,  size);
		}
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
