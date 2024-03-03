#include "sort.h"

/**
* selection_sort - Sorts the selection implemention type
*
* @arr: the array of integers
* @siz: size of array
*/

void selection_sort(int *arr, size_t siz)
{
	int tem, minimum, min_index;
	size_t i, j;

	for (i = 0; i < siz; i++)
	{
		minimum = arr[i];
		min_index = i;

		for (j = i; j < siz; j++)
		{
			if (minimum > arr[j])
			{
				min_index = j;
				minimum = arr[j];
			}
		}
		if (min_index != (int)i)
		{
			tem = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = tem;

			print_arr(arr, siz);
		}
	}
}
