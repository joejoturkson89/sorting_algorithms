#include "sort.h"
/**
 * print - prints left, right, and merged halves.
 * @arr: tmp array
 * @side: left, right, or merged half
 * @start: start index
 * @end: end index
 */
void print(int *arr, char *side, size_t start, size_t end)
{
	size_t i;

	printf("[%s]: ", side);
	for (i = start; i < end; i++)
	{
		if (i != (end - 1))
			printf("%d, ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}
}
/**
 * rec_merge - function that recursively splits and merges halves
 * @array: original array
 * @sort_arr: tmp array to hold sorted elements
 * @l: start index
 * @r: end index
 */
void rec_merge(int *array, int *sort_arr, size_t l, size_t r)
{
	size_t i, l_half, r_half;
	size_t mid = (l + r) / 2;

	if (r - l <= 1)
		return;

	rec_merge(array, sort_arr, l, mid);
	rec_merge(array, sort_arr, mid, r);
	printf("Merging...\n");
	print(array, "left", l, mid);
	print(array, "right", mid, r);
	l_half = l;
	r_half = mid;
	for (i = l; i < r; i++)
	{
		if ((l_half < mid) &&
			((r_half == r) || (array[l_half] < array[r_half])))
		{
			sort_arr[i] = array[l_half];
			l_half++;
		}
		else
		{
			sort_arr[i] = array[r_half];
			r_half++;
		}
	}
	print(sort_arr, "Done", l, r);
	for (i = l; i < r; i++)
		array[i] = sort_arr[i];
}
/**
 * merge_sort - sorts integers using merge sort algorithm
 * @array: array to be sorted
 * @size: size of array to be sorted
 */
void merge_sort(int *array, size_t size)
{
	int *sort_arr;

	if (!(array) || size < 2)
		return;
	sort_arr = malloc(sizeof(int) * size);
	if (!(sort_arr))
		return;
	rec_merge(array, sort_arr, 0, size);
	free(sort_arr);
}
