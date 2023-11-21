#include "sort.h"

/**
 * counting_sort - Function sort an array of integers in ascending order
 * using counting sort algorithm
 * @array: pointer to the array
 * @size: pointer to array size
 * Return: Null
 */
void counting_sort(int *array, size_t size)
{
	size_t j;
	int max = array[0], *counting_array, *output_array, i;

	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
		{
			max = array[j];
		}
	}

	counting_array = (int *)malloc((max + 1) * sizeof(int));

	for (i = 0; i <= max; i++)
	{
		counting_array[i] = 0;
	}
	for (j = 0; j < size; j++)
	{
		counting_array[array[j]]++;
	}
	for (i = 1; i <= max; i++)
	{
		counting_array[i] += counting_array[i - 1];
	}

	output_array = (int *)malloc(size * sizeof(int));

	for (i = size - 1; i >= 0; i--)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (j = 0; j < size; j++)
	{
		array[j] = output_array[j];
	}
	free(counting_array);
	free(output_array);
}
