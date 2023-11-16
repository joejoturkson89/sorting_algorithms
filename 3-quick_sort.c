#include "sort.h"
/**
 * partition - function that partitions the array
 * @array: array to be partitioned
 * @start: start of the array
 * @end: end of the array
 * @size: full size of the array
 * Return: return position of pivot
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int i = start, k, tmp;

	for (k = start; k < end; k++)
	{
		if (array[k] <= pivot)
		{
			if (i != k)
			{
				tmp = array[i];
				array[i] = array[k];
				array[k] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quickSort - quick sort function with recursion
 * @array: array to be sorted
 * @start: start of array and subarray
 * @end: end of array
 * @size: size of full array
 */
void quickSort(int *array, int start, int end, int size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		quickSort(array, start, pivot - 1, size);
		quickSort(array, pivot + 1, end, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order using quicksort
 * algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
