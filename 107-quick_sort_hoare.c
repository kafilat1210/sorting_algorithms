#include "sort.h"

/**
 * hoare_partition - Partitions an array using the Hoare scheme
 * @array: The array to be partitioned
 * @size: The size of the array
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * Return: The final partition index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j, temp;

	pivot = array[high]; /* The pivot is the last element */
	i = low - 1; /* i starts from the left */
	j = high + 1; /* j starts from the right */

	while (1)
	{
		/* Find the first element greater than or equal to the pivot */
		do {
			i++;
		} while (array[i] < pivot);

		/* Find the first element smaller than or equal to the pivot */
		do {
			j--;
		} while (array[j] > pivot);

		/* If i and j cross, return j as the partition index */
		if (i >= j)
			return (j);

		/* Otherwise, swap the elements at i and j */
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size); /* Print the array after swapping */
	}
}

/**
 * quick_sort_hoare_rec - Recursively sorts a partition of an array
 * @array: The array to be sorted
 * @size: The size of the array
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 */
void quick_sort_hoare_rec(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		/* Partition the array and get the partition index */
		p = hoare_partition(array, size, low, high);

		/* Sort the left partition */
		quick_sort_hoare_rec(array, size, low, p - 1);

		/* Sort the right partition */
		quick_sort_hoare_rec(array, size, p + 1, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with the Hoare partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Call the recursive function with the entire array */
	quick_sort_hoare_rec(array, size, 0, size - 1);
}
