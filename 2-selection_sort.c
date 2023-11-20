#include "sort.h"

/**
 * selection_sort - Function to sort array of integers in ascending order
 * using selection sort algorithm
 * @array: Pointer to the array of integers
 * @size: pointer to the size of the array
 * Return: Null
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	size_t min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
		}

		for (j = 0; j < size; j++)
		{
			printf("%d ", array[j]);
		}
		printf("\n");
	}
}
