#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - spread array elements to individual buckets
 *					then sort
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t max, i;
	int *counting_array, *sorted_asc;

	max = 0;
	for (i = 0; i < size; i++)
		if ((size_t) array[i] > max)
			max = array[i];

	counting_array = (int *)malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	for (i = 0; i <= max; i++)
		counting_array[i] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]] += 1;

	for (i = 1; i <= max; i++)
		counting_array[i] += counting_array[i - 1];

	print_array(counting_array, max + 1);

	sorted_asc = (int *) malloc(size * sizeof(int));
	if (sorted_asc == NULL)
	{
		free(counting_array);
		return;
	}
	for (i = size - 1;; i--)
	{
		sorted_asc[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]] -= 1;
		if (i == 0)
			break;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_asc[i];

	free(counting_array);
	free(sorted_asc);
}
