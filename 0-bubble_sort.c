#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 * using bubble sort algorithm.
 * @array: array to be sorted
 * @size: size of the array
 * Return: return nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, k;
	int tmp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (k = 0; k < size - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				tmp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
