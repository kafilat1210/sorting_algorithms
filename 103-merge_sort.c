#include "sort.h"

/**
 * merge - Merges two sub-arrays of integers
 * @array: The array to be sorted
 * @left: The left sub-array
 * @right: The right sub-array
 * @size: The size of the array
 */
void merge(int *array, int *left, int *right, size_t size)
{
	int i = 0, j = 0, k = 0;
	int left_size, right_size;

	left_size = size / 2;
	right_size = size - left_size;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i;
	int *left, *right;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;

	/* Allocate memory for the left and right sub-arrays */
	left = malloc(sizeof(int) * mid);
	right = malloc(sizeof(int) * (size - mid));
	if (left == NULL || right == NULL)
	{
		free(left);
		free(right);
		return;
	}

	/* Copy the data to the left and right sub-arrays */
	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	/* Sort the left and right sub-arrays */
	merge_sort(left, mid);
	merge_sort(right, size - mid);

	/* Merge the left and right sub-arrays */
	merge(array, left, right, size);

	/* Free the left and right sub-arrays */
	free(left);
	free(right);
}
