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
void merge(int *array, int *left, int *right, size_t size);
void merge_sort(int *array, size_t size);
void swap(int *array, int i, int j, size_t size);
void sift_down(int *array, int start, int end, size_t size);
void heapify(int *array, size_t size);
void radix_sort(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
int get_max(int *array, size_t size);
void bitonic_compare(int *array, size_t size, size_t i, size_t j, int dir);
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int dir);
void bitonic_sort_rec(int *array, size_t size, size_t low,
		size_t count, int dir);
void bitonic_sort(int *array, size_t size);


void heap_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void quick_sort_hoare_rec(int *array, size_t size, int low, int high);
int hoare_partition(int *array, size_t size, int low, int high);

#endif /* SORT_H */
