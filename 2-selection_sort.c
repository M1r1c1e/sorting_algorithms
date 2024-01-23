#include "sort.h"

/**
 * selection_sort - Sorting an array of integers in ascending order with
 *                  the Selection sort algorithm.
 *
 * @array: unsorted array
 * @size: total num of elem in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t unsorted_idx, sorted_idx, min_val;
	int temp;

	/* If array is null or less than 2 it is considered to be sorted */
	if (array == NULL || size < 2)
		return;

	/* Selection of the minimum element from the unsorted portion of the array */
	/* during each iteration of the Selection Sort algorithm */
	for (unsorted_idx = 0; unsorted_idx < size - 1; ++unsorted_idx)
	{
		min_val = unsorted_idx;

		for (sorted_idx = unsorted_idx + 1; sorted_idx < size; ++sorted_idx)
		{
			if (array[sorted_idx] < array[min_val])
				min_val = sorted_idx;
		}

		if (min_val != unsorted_idx)
		{
			/* Swap array[unsorted_idx] and array[min_val] */
			temp = array[unsorted_idx];
			array[unsorted_idx] = array[min_val];
			array[min_val] = temp;

			/* After each swap, print the array */
			print_array(array, size);
		}
	}
}

