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
 * tkn_arr - Function to tokenize an array using pivot
 * @array: pointer to the array
 * @fir: pointer to firtt integer
 * @sec: pointer to second integer
 * @size: pointer to size of the array
 * Return: Index of the pivot
 */
int tkn_arr(int *array, int fir, int sec, size_t size)
{
	int p = array[sec];
	int q = fir - 1, r;

	for (r = fir; r <= sec; r++)
	{
		if (array[r] <= p)
		{
			q++;
			if (q != r)
			{
				swap_int(&array[q], &array[r]);
				print_array(array, size);
			}
		}
	}
	return (q);
}


/**
 * lomunto_recsort - Function to sort recursively an Array
 * @array: pointer to the array
 * @fir: low value in array
 * @sec: highest value in array
 * @size: pointer to size of the array
 * Return: Null
 */
void lomunto_recsort(int *array, int fir, int sec, size_t size)
{
	int i;

	if (fir < sec)
	{
		i = tkn_arr(array, fir, sec, size);
		lomunto_recsort(array, fir, i - 1, size);
		lomunto_recsort(array, i + 1, sec, size);
	}
}

/**
 * quick_sort - Function to do a quick sort algorithm using lomunto partition
 * @array: pointer to the array
 * @size: poiter to the size of array
 * Return: Null
 */
void quick_sort(int *array, size_t size)
{
	lomunto_recsort(array, 0, size - 1, size);
}
