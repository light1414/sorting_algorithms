#include "sort.h"

/**
* shell_sort - Shell sort sorting implimetatiion
*
* @array: the array of integers
* @size: array size
*/

void shell_sort(int *array, size_t size)
{
	size_t inter;

	if (array == NULL || size == 0)
	{
		return;
	}

	inter = 1;

	while (inter < size)
	{
		inter = (inter * 3) + 1;
	}

	inter = inter / 3;

	while (inter >= 1)
	{
		inter_insertion(array, (int)size, (int)inter);
		print_array(array, size);
		inter /= 3;
	}
}


/**
* power - A function to sort the power of a numb
*
* @number: the number to find the power
* @power: power of the number
*
* Return: the numb raised to the power
*/
size_t power(size_t number, size_t power)
{
	size_t p, result = 1;

	if (power == 0)
	{
		return (1);
	}
	for (p = 0; p < power; p++)
	{
		result *= number;
	}
	return (result);
}


/**
* interval_insertion - Insertion sort at a given interval
*
* @array: the array to perform the insertion at interval sort
* @size: the array size
* @interval: the intervals to implement insertion sort
*
* Return: void
*/
void interval_insertion(int *array, int size, int interval)
{
	int temp, i, k;

	k = interval;

	while (k < size)
	{
		i = k - interval;

		while (i >= 0)
		{
			if (array[i] > array[i + interval])
			{
				temp = array[i];
				array[i] = array[i + interval];
				array[i + interval] = temp;
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
