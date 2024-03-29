#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The pointer to the pointer of the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		next = current->next;
		while (prev != NULL && current->n < prev->n)
		{
			/* Swap the nodes */
			prev->next = next;
			if (next != NULL)
				next->prev = prev;
			current->prev = prev->prev;
			current->next = prev;
			prev->prev = current;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			/* Print the list after each swap */
			print_list(*list);
			/* Update the pointers */
			prev = current->prev;
			next = current->next;
		}
		current = next;
	}
}
