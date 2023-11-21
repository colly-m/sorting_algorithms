#include "sort.h"

/**
 * getz_max - Funtion to get maximum value in the array
 * @array: pointer to the array
 * @size: pointer to size of the array
 * Return: maximum integer in array
 */
int getz_max(int *array, int size)
{
	int m = array[0], n = 1;

	for (; n < size; n++)
	{
		if (array[n] > m)
			m = array[n];
	}
	return (m);
}


/**
 * counting_sort - Function sort an array of integers in ascending order
 * using counting sort algorithm
 * @array: pointer to the array
 * @size: pointer to array size
 * Return: Null
 */
void counting_sort(int *array, size_t size)
{
	int m, *count, *output, n;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	m = getz_max(array, size);
	count = malloc(sizeof(int) * (m + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}

	for (n = 0; n < (m + 1); n++)
		count[n] = 0;
	for (n = 0; n < (int)size; n++)
		count[array[n]] += 1;
	for (n = 0; n < (m + 1); n++)
		count[n] += count[n - 1];
	print_array(count, m + 1);

	for (n = 0; n < (int)size; n++)
	{
		output[count[array[n]] - 1] = array[n];
		count[array[n]] -= 1;
	}

	for (n = 0; n < (int)size; n++)
		array[n] = output[n];

	free(output);
	free(count);
}
