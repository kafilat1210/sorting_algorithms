#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @array: The array
 * @i: The index of the first element
 * @j: The index of the second element
 * @size: The size of the array
 */
void swap(int *array, int i, int j, size_t size)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * sift_down - Sifts down a node in a heap
 * @array: The array
 * @start: The start index of the heap
 * @end: The end index of the heap
 * @size: The size of the array
 */
void sift_down(int *array, int start, int end, size_t size)
{
	int root, left, right, temp;

	root = start;
	while (root * 2 + 1 <= end)
	{
		left = root * 2 + 1;
		right = root * 2 + 2;
		temp = root;

		if (array[temp] < array[left])
			temp = left;

		if (right <= end && array[temp] < array[right])
			temp = right;

		if (temp == root)
			return;

		swap(array, root, temp, size);
		root = temp;
	}
}

/**
 * heapify - Turns an array into a heap
 * @array: The array
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
	int start;

	start = (size - 2) / 2;
	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int end;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array, 0, end, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
