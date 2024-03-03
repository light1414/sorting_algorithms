#include "sort.h"

/**
* bubble_sort - Sorts using bubble sort algorithm
*
* @arr: the array of integers
* @siz: the size of array
*/

void bubble_sort(int *arr, size_t siz)
{
	size_t k, j;
	int tem, checker;

	if (siz <= 1 || arr == NULL)
	{
		return;
	}

	for (k = 0; k < (siz - 1); k++)
	{
		checker = 0;

		for (j = 0; j < (size - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;

				print_arr(arr, siz);
				checker = 1;
			}
		}
		if (checker == 0)
		{
			break;
		}
	}
}
