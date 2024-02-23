#include "sort.h"

/**
 * swap_index - Swap values of start and next index.
 * @arr: array to work in.
 * @spoint: start point of the array.
 * @val: value to swap with start point.
 * Return: Nothing.
 */
void swap_index(int *arr, size_t spoint, size_t val)
{
	int fst, scnd;

	fst = arr[spoint];
	scnd = arr[val];

	arr[spoint] = scnd;
	arr[val] = fst;
}

/**
 * selection_sort - Sort array with selection algorithm.
 * @array: array to sort.
 * @size: array size.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, start = 0, min = 0;

	if (!array || size < 2)
		return;

	while (start < size)
	{
		min = start;
		i = start + 1;
		while (i < size)
		{
			if (array[i] < array[min])
				min = i;
			i++;
		}
		if (min != start)
		{
			swap_index(array, start, min);
			print_array(array, size);
		}
		start++;
	}
}
