#include "sort.h"

/**
* bubble_sort - Sorts using bubble sort algorithm
*
* @array: the array of integers
* @size: the size of array
*/

void bubble_sort(int *array, size_t size)
{
	size_t k, j;
	int tem, checker;

	if (size <= 1 || array == NULL)
	{
		return;
	}

	for (k = 0; k < (size - 1); k++)
	{
		checker = 0;

		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				tem = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tem;

				print_array(array, size);
				checker = 1;
			}
		}
		if (checker == 0)
		{
			break;
		}
	}
}
