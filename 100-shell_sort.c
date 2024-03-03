#include "sort.h"

/**
* shell_sort - Shell sort sorting implimetatiion
*
* @arr: the array of integers
* @siz: array size
*/

void shell_sort(int *arr, size_t siz)
{
	size_t interval;

	if (arr == NULL || siz == 0)
	{
		return;
	}

	interval = 1;

	while (interval < siz)
	{
		interval = (interval * 3) + 1;
	}

	interval = interval / 3;

	while (interval >= 1)
	{
		interval_insertion(arr, (int)siz, (int)interval);
		print_array(arr, siz);
		interval /= 3;
	}
}


/**
* power - A function to sort the power of a numb
*
* @numb: the number to find the power
* @pow: power of the number
*
* Return: the number raised to the power
*/
size_t power(size_t numb, size_t pow)
{
	size_t i, result = 1;

	if (pow == 0)
	{
		return (1);
	}
	for (i = 0; i < pow; i++)
	{
		result *= number;
	}
	return (result);
}


/**
* interval_insertion - Insertion sort at a given interval
*
* @arr: the array to perform the insertion at interval sort
* @siz: the array size
* @interval: the intervals to implement insertion sort
*
* Return: void
*/
void interval_insertion(int *arr, int siz, int interval)
{
	int tem, i, j;

	j = interval;

	while (j < siz)
	{
		i = j - interval;

		while (i >= 0)
		{
			if (arr[i] > arr[i + interval])
			{
				tem = arr[i];
				arr[i] = arr[i + interval];
				arr[i + interval] = tem;
			}
			else
			{
				break;
			}
			i = i - interval;
		}
		j++;
	}
}
