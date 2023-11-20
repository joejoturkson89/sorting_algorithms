#include "sort.h"
/**
 * counting_sort - sorts an array of integers using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, k, num, dup, *count;

	if (array == NULL || size < 2)
		return;
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;
	for (j = 0; j < (k + 1); j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		count[num] += 1;
	}
	for (j = 0; j < k; j++)
	{
		count[j + 1] += count[j];
	}
	print_array(count, k + 1);
	for (i = 0, j = 0; j < k; j++)
	{
		if ((j == 0) && count[j] != 0)
		{
			for ((dup = count[j]); dup > 0; dup--)
				array[i++] = j;
		}
		if (count[j + 1] > count[j])
		{
			for ((dup = count[j + 1] - count[j]); dup > 0; dup--)
				array[i++] = (j + 1);
		}
	}
	free(count);
}
