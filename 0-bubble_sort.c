#include "sort.h"
#include <stdio.h>


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
				swap_array(array, j, j + 1);
				swapped = 1;
				print_array(array,  size);
			}
		}
		if (!swapped)
			break;
	}
}

/**
 * swap_array - swap two elements in an integer array
 * @array: array to swap items in
 * @i: first index
 * @j: second index
 * */
void swap_array(int *array, size_t i, size_t j)
{
	int tmp;
	
	tmp = array[j];
	array[j] = array[i];
	array[i] = tmp;
}
