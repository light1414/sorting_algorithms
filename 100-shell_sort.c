#include "sort.h"

/**
* shell_sort - Implements the shell sort sorting
*
* @array: the array of integers
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
		interval = (intervall * 3) + 1;
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
* power - Functions to sort the power of a num
*
* @number: num to sort the power
* @power: Power of the num
*
* Return: num raised to the power
*/
size_t power(size_t number, size_t power)
{
	size_t i, result = 1;

	if (power == 0)
	{
		return (1);
	}
	for (i = 0; i < power; i++)
	{
		result *= number;
	}
	return (result);
}


/**
* interval_insertion - Insertion sort at a given interval
*
* @array: the array to perform the insertion at interval sort
* @size: size of array
* @interval: the intervals to implement insertion sort
*
* Return: void
*/
void interval_insertion(int *array, int size, int interval)
{
	int tem, i, j;

	k = interval;

	while (k < size)
	{
		i = k - interval;

		while (i >= 0)
		{
			if (array[i] > array[i + interval])
			{
				tem = array[i];
				array[i] = array[i + interval];
				array[i + interval] = tem;
			}
			else
			{
				break;
			}
			i = i - interval;
		}
		k++;
	}
}
