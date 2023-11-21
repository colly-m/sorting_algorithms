#include "sort.h"

/**
 * swap_int - Function to swap integers in an array
 * @ia: The first integer
 * @ib: The second integer
 * Return: Null
 */
void swap_int(int *ia, int *ib)
{
	int num;

	num = *ia;
	*ia = *ib;
	*ib = num;
}


/**
 * bubble_sort - Function to sort integer array in ascending arder
 * using bubble sort algorithm
 * @array: pointer to array to sort through
 * @size: poinet to the size of the array
 * Return: Null
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
