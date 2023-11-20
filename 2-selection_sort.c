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
	int index = 0;
	int min, tmp;
	size_t i, k;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (k = 1 + 1; k < size; k++)
		{
			if (array[k] < min)
			{
				min = array[k];
				index = k;
			}
		}
		if (min != array[i])
		{
			tmp = array[i];
			array[i] = array[index];
			array[index] = tmp;
			print_array(array, size);
		}
	}
}
