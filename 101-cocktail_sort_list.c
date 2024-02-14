#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: The pointer to the pointer of the list
 * @node1: The first node to be swapped
 * @node2: The second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*list = node2;

	if (next != NULL)
		next->prev = node1;

	node2->prev = prev;
	node2->next = node1;
	node1->prev = node2;
	node1->next = next;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: The pointer to the pointer of the list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped)
	{
		swapped = 0;
		/* Traverse the list from left to right */
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				/* Swap the nodes */
				swap_nodes(list, current, current->next);
				/* Print the list after each swap */
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		/* Traverse the list from right to left */
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
