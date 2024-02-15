#include "sort.h"

/**
 * bitonic_compare - Compares and swaps elements in a bitonic sequence
 * @array: The array
 * @size: The size of the array
 * @i: The index of the first element
 * @j: The index of the second element
 * @dir: The direction of sorting (1 for up, 0 for down)
 */
void bitonic_compare(int *array, size_t size, size_t i, size_t j, int dir)
{
	int temp;

	if (dir == (array[i] > array[j]))
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * bitonic_merge - Merges two bitonic sequences in a given direction
 * @array: The array
 * @size: The size of the array
 * @low: The lowest index of the sequence
 * @count: The number of elements in the sequence
 * @dir: The direction of sorting (1 for up, 0 for down)
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int dir)
{
	size_t i, k;

	if (count > 1)
	{
		k = count / 2;
		for (i = low; i < low + k; i++)
			bitonic_compare(array, size, i, i + k, dir);
		bitonic_merge(array, size, low, k, dir);
		bitonic_merge(array, size, low + k, k, dir);
	}
}

/**
 * bitonic_sort_rec - Recursively sorts a bitonic sequence
 * @array: The array
 * @size: The size of the array
 * @low: The lowest index of the sequence
 * @count: The number of elements in the sequence
 * @dir: The direction of sorting (1 for up, 0 for down)
 */
void bitonic_sort_rec(int *array, size_t size, size_t low,
		size_t count, int dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%lu/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
		print_array(array + low, count);
		bitonic_sort_rec(array, size, low, k, 1);
		bitonic_sort_rec(array, size, low + k, k, 0);
		bitonic_merge(array, size, low, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_rec(array, size, 0, size, 1);
}
