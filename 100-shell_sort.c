#include "sort.h"

/**
 * shell_sort - Function tosort array of intregers in ascending order
 * using shell sort and knuth sequence
 * @array: pointer to the array of integers
 * @size: pointer to size of the array
 * Return: Null
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, g = 1;
	int tmp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (g < size / 3)
		g = g * 3 + 1;

	while (g > 0)
	{

		for (i = g; i < size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= g && array[j - g] > tmp)
			{
				array[j] = array[j - g];
				j = j - g;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		g /= 3;
	}
}
