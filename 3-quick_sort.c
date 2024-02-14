#include "sort.h"

/**
 * partition - Partitions an array using the Lomuto scheme
 * @array: The array to be partitioned
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the array
 * Return: The final index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high]; /* The pivot is the last element */
	i = low - 1; /* The index of the smaller element */

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++; /* Increment the index of the smaller element */
			if (i != j)
			{
				/* Swap the elements */
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > pivot)
	{
		/* Swap the pivot with the element next to the smaller element */
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		/* Print the array after the swap */
		print_array(array, size);
	}
	return (i + 1); /* Return the final index of the pivot */
}

/**
 * quick_sort_helper - Recursively sorts an array using the Quick sort algo
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		/* Partition the array and get the pivot index */
		pi = partition(array, low, high, size);
		/* Sort the elements before and after the pivot */
		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Call the helper function with the initial low and high values */
	quick_sort_helper(array, 0, size - 1, size);
}
