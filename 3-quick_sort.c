#include "sort.h"
#include <stdlib.h>

size_t partition(int arr[], size_t low, size_t high) {
    int pivot;
	size_t i, j;

	i = low - 1;
	pivot = arr[high];

    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
			swap_array(arr + i, arr + j);
        }
    }
	swap_array(arr + i + 1, arr + high);

    return (i + 1);
}

/**
 * quick_sort - sort an integer array using Quick Sort
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    int *stack, top;
    int low, high, pivotIndex;

	stack = malloc(size*sizeof(int));
	top = -1;

    stack[++top] = 0;
    stack[++top] = size - 1;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        pivotIndex = partition(array, low, high);

        if (pivotIndex - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivotIndex - 1;
        }

        if (pivotIndex + 1 < high) {
            stack[++top] = pivotIndex + 1;
            stack[++top] = high;
        }
		print_array(array, size);
    }

	free(stack);
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
