#include "sort.h"

/**
 * shell_sort - sort an array using Shell Sort (Knuth)
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;
	int temp;

	for (interval = 0; interval < size;)
		interval = 3 * interval + 1;

	for (interval /= 3; interval; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}
		print_array(array, size);
	}
}

