#include "sort.h"

/**
 * int_swap - Swap integers in an array.
 * @fst: The first integer to swap.
 * @scnd: The second integer to swap.
 */
void int_swap(int *fst, int *scnd)
{
	int tmp = *fst;

	*fst = *scnd;
	*scnd = tmp;
}

/**
 * shell_sort - Sort an array of integers with ascending
 *         order using shell sort.
 * @array: array of integers.
 * @size: size of the array.
 * Description: uses Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t n, index, j;

	if (array == NULL || size < 2)
		return;

	for (n = 1; n < (size / 3);)
		n = n * 3 + 1;

	for (; n >= 1; n /= 3)
	{
		for (index = n; index < size; index++)
		{
			j = index;
			while (j >= n && array[j - n] > array[j])
			{
				int_swap(array + j, array + (j - n));
				j -= n;
			}
		}
		print_array(array, size);
	}
}
