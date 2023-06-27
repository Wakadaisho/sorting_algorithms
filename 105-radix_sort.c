#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - sort an linked list using Radix Sort
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max, place;
	int *buckets, *output;

	if (size <= 1 || array == NULL)
		return;

	buckets = malloc(10 * sizeof(int));
	output = malloc(size * sizeof(int));

	for (max = *array, i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (place = 1; max / place; place *= 10)
	{
		for (i = 0; i < size; i++)
			output[i] = 0;
		for (i = 0; i < 10; i++)
			buckets[i] = 0;
		for (i = 0; i < size; i++)
			buckets[(array[i] / place) % 10] += 1;
		for (i = 1; i < 10; i++)
			buckets[i] += buckets[i - 1];
		for (i = size - 1; i <= size; i--)
		{
			output[buckets[(array[i] / place) % 10] - 1] = array[i];
			buckets[(array[i] / place) % 10]--;
		}
		for (i = 0; i < size; i++)
			array[i] = output[i];
		print_array(array, size);
	}
	free(output);
	free(buckets);
}
