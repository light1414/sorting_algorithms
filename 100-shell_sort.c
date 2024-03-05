#include "sort.h"

/**
* shell_sort - shell sort sorting implementation
*
* @array: integers array 
* @size: array size
*/

void shell_sort(int *array, size_t size)
{
	size_t interval;

	if (array == NULL || size == 0)
	{
		return;
	}

	interval = 1;

	while (interval < size)
	{
		interval = (interval * 3) + 1;
	}

	interval = interval / 3;

	while (interval >= 1)
	{
		interval_insertion(array, (int)size, (int)interval);
		print_array(array, size);
		interval /= 3;
	}
}


/**
* power - Functions to find power of a numb
*
* @num: the number to find the power
* @pow: power of the number
*
* Return: Number raised to the power
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
		result *= num;
	}
	return (result);
}


/**
* interval_insertion - the insertion sort at a given interval
*
* @array: array to perform the insertion at interval sort
* @size: array size
* @inter: intervals to implement insertion sort
*
* Return: void
*/
void interval_insertion(int *array, int size, int inter)
{
	int tem, i, j;

	j = inter;

	while (j < size)
	{
		i = j - inter;

		while (i >= 0)
		{
			if (array[i] > array[i + inter])
			{
				tem = array[i];
				array[i] = array[i + inter];
				array[i + inter] = tem;
			}
			else
			{
				break;
			}
			i = i - inter;
		}
		j++;
	}
}
