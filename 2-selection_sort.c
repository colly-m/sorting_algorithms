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
 * selection_sort - Function to sort array of integers in ascending order
 * using selection sort algorithm
 * @array: Pointer to the array of integers
 * @size: pointer to the size of the array
 * Return: Null
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		idx = array + i;

		for (j = i + 1; j < size; j++)
		{
			idx = (array[j] < *idx) ? (array + j) : idx;
		}

		if ((array + i) != idx)
		{
			swap_int(array + i, idx);
			print_array(array, size);
		}
	}
}
