#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorting a doubly linked list of integers in ascending order
 *                       using the insertion sort algorithm.
 *
 * @list: Pointing to doubly linked list head
 */
void insertion_sort_list(listint_t **list)
{
	/* Initialization of variables */
	listint_t *iterated_node, *moving_node;

	iterated_node = (*list)->next;

	/* If list has one or two elements or is empty, exit the program */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (iterated_node != NULL)
	{
		moving_node = iterated_node;
		while (moving_node->prev != NULL && moving_node->n < moving_node->prev->n)
		{
			/* Swapping the nodes */
			if (moving_node->next != NULL)
				moving_node->next->prev = moving_node->prev;
			moving_node->prev->next = moving_node->next;
			moving_node->next = moving_node->prev;
			moving_node->prev = moving_node->prev->prev;
			moving_node->next->prev = moving_node;

			if (moving_node->prev != NULL)
				moving_node->prev->next = moving_node;
			else
				*list = moving_node;

			/* Printing the list of swapped iterated node */
			print_list(*list);
		}
		iterated_node = iterated_node->next;
	}
}

