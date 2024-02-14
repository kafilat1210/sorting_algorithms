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

/* Prototype of bubble sort function */
void bubble_sort(int *array, size_t size);

#endif /* SORT_H */