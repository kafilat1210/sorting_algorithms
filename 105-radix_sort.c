#include "sort.h"

/**
 * get_max - Gets the maximum value in an array
 * @array: The array
 * @size: The size of the array
 * Return: The maximum value
 */
int get_max(int *array, size_t size)
{
	int max, i;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Sorts an array of integers using the Counting sort
 * algorithm for the Radix sort
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The exponent of the significant digit
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, *count, i, digit;
	size_t j;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);
	if (output == NULL || count == NULL)
	{
		free(output);
		free(count);
		return;
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
	{
		digit = (array[j] / exp) % 10;
		count[digit]++;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		digit = (array[i] / exp) % 10;
		output[count[digit] - 1] = array[i];
		count[digit]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(output);
	free(count);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
