#include "sort.h"
/**
 * radix_sort -Sorts array of integers in ascending
 * order with the Radix sort algorithm
 *
 * @array: the input array
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int flag = 1, n = 10;
	size_t k, f;

	if (!array || size == 1)
		return;
	while (flag)
	{
		flag = 0;
		for (k = 1, f = 1; k <  size; i++, f++)
		{
			if ((array[k - 1] % (n * 10)) / ((n * 10) / 10) > 0)
				flag = 1;
			if (((array[k - 1] % n) / (n / 10)) > ((array[k] % n) / (n / 10)))
			{
				array[k - 1] = array[k - 1] + array[k];
				array[k] = array[i - 1] - array[k];
				array[k - 1] = array[k - 1] - array[k];
				if ((k - 1) > 0)
					k = k - 2;
			}
		}
		print_array(array, size);
		n = n * 10;
	}
}
