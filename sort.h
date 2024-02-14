#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/* Data structure for doubly linked list */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prototypes of print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
/* Prototype of bubble sort function */
void bubble_sort(int *array, size_t size);

/*prototypes for quick-sort functions */
int partition(int *array, int low, int high, size_t size);
void quick_sort_helper(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
/* sort algo*/
void shell_sort(int *array, size_t size);
/* Cocktail shaker sort */
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);

#endif /* SORT_H */
