#include "sort.h"
#include <stdio.h>
#include <stddef.h>
/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, k, i;
	size_t j;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > k)
			k = array[j];
	}
	count = malloc(sizeof(int) * (k + 1));
	output = malloc(sizeof(int) * size);
	if (count == NULL || output == NULL)
	{
		free(count);
		free(output);
		return;
	}
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]]++;
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];

	print_array(count, k + 1);

	for (j = 0; j < size; j++)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(count);
	free(output);
}
