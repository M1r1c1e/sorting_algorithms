#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorting a doubly linked list
 * of integers in ascending order with Insertion sort algorithm.
 *
 * @list: Pointing to the doubly linked list head
 */
void insertion_sort_list(listint_t **list);
void insertion_sort_list(listint_t **list)
{
	listint_t *iterate_node = (*list)->next;

	/* is empty or has one or two nodes; if condition is true */
	/* exit program because sorting will not be needed */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* initializing pointers: iterating node iterates*/
	/* from second node through end of list */
	/* moving node is the node that needs to be moved for sorting to take place */

	while (iterate_node != NULL)
	{
		listint_t *moving_node = iterate_node;

		/* sorting process */
		while (moving_node->prev != NULL && moving_node->n < moving_node->prev->n)
		{
			listint_t *prev_node = moving_node->prev;
			listint_t *next_node = moving_node->next;

			/* swapping nodes */
			if (prev_node != NULL)
				prev_node->next = next_node;
			else
				*list = next_node;

			if (next_node != NULL)
				next_node->prev = prev_node;

			moving_node->next = prev_node;
			moving_node->prev = prev_node != NULL ? prev_node->prev : NULL;

			if (prev_node != NULL)
				prev_node->prev = moving_node;

			/* Print the moving node after swapping */
			print_list(*list);
		}

		iterate_node = iterate_node->next;
	}
}

