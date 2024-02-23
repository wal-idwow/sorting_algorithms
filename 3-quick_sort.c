#include "sort.h"

/**
 * val_swap - Swap values of start and next index.
 * @arr: the array to work in.
 * @size: size of array.
 * @lef: left most value
 * @righ: right most value
 * Return: nothing.
 */
void val_swap(int *arr, size_t size, int lef, int righ)
{
	int tmp;

	if (arr[lef] != arr[righ])
	{
		tmp = arr[lef];
		arr[lef] = arr[righ];
		arr[righ] = tmp;
		print_array(arr, size);
	}
}
/**
 * lom_part - using Lomuto partition scheme for quicksort
 * @arr: pointer to array
 * @size: size of array
 * @lef: left most value
 * @righ: right most value
 * Return: pivot value
 */
int lom_part(int *arr, size_t size, int lef, int righ)
{
	int p_val = arr[righ];

	int i = lef - 1, j;

	for (j = lef; j <= righ; j++)
	{
		if (arr[j] < p_val)
		{
			i++;
			val_swap(arr, size, i, j);

		}
	}
	val_swap(arr, size, i + 1, righ);

	return (i + 1);
}
/**
 * recur_quik - recursive funtion for quicksort
 * @arr: pointer to array
 * @size: size of array
 * @lef: lowest value
 * @righ: highest value
 */
void recur_quik(int *arr, size_t size, int lef, int righ)
{
	int pivot_i;

	if (lef < righ)
	{
		pivot_i = lom_part(arr, size, lef, righ);
		recur_quik(arr, size, lef, pivot_i - 1);
		recur_quik(arr, size, pivot_i + 1, righ);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to sort.
 * @size: size of the array.
 * Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recur_quik(array, size, 0, size - 1);
}
