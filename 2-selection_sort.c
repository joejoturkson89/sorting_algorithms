#include "sort.h"
/**
 * swap - function that swaps two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of array to be sorted.
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, k, min_index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (k = i + 1; k < size; k++)
		{
			if (array[k] < array[min_index])
				min_index = k;
		}

		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
