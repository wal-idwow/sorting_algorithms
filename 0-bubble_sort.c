#include "sort.h"

/**
 * swap - Swap two ints in an array.
 * @a: The first swaping int.
 * @b: The second swaping int.
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool buble = false;

	if (array == NULL || size < 2)
		return;

	while (buble == false)
	{
		buble = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				buble = false;
			}
		}
		len--;
	}
}
