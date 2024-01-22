#include "sort.h"
#include <stddef.h>

/**
 * bubble_sort - a function that sorts elem by swapping adjacent elem
 * @array: integers that have to be arranged
 * @size: the total number of integers in the array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t out_idx, iner_idx;

	/* this checks if the array has just one element or it's empty */
	if (size < 2)
		return;

	/* iterating through the unsorted elements to fix them */
	for (out_idx = 0; out_idx < size - 1; ++out_idx)
	{
		for (iner_idx = 0; iner_idx < size - out_idx - 1; ++iner_idx)
		{
			if (array[iner_idx] > array[iner_idx + 1])
			{
				/* Swapping adjacent inner index if order is wrong */
				temp = array[iner_idx];
				array[iner_idx] = array[iner_idx + 1];
				array[iner_idx + 1] = temp;

				/* function to print swapped array */
				print_array(array, size);
			}
		}
	}
}

