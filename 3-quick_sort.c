#include "sort.h"

/**
* quick_sort - The implementation of quick_sort with Lomuto partition
*
* @array: the array of integers
* @size: the size of array
*/

void quick_sort(int *array, size_t size)
{
	int my_size = (int)size;

	if (!array || my_size < 0)
	{
		return;
	}

	sorted(array, 0, my_size - 1, size);
}


/**
* sorted - Recursive the call partitions of quick sort
*
* @array: the array of integers
* @a: Pointer(or origin) to the first array element
* @z: Pointer to the last array element
* @n: size of array
*
* Return: void
*/
void sorted(int *array, int a, int z, size_t n)
{
	if (a < z)
	{
		int pivot = partition(arr, a, z, n);

		sorted(arr, a, pivot - 1, n);

		sorted(arr, pivot + 1, z, n);
	}
}


/**
* partition - It sorts each partition
*
* @array: the array of integers
* @a: Pointer to the first array element
* @z: Pointer to the last array element
* @n: size of array
*
* Return: void
*/
int partition(int *array, int a, int z, size_t n)
{
	int j = a + 1;
	int i = a;
	int temp;

	while (j < z && a >= 0)
	{
		if (array[i] <= array[z])
			i++, j++;
		else if (array[j] < array[z])
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, n);
			j++, i++;
		}
		else
			j++;
	}
	if (array[j] <= array[i])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		if (array[i] != array[j])
			print_array(array, n);
	}
	else
	{
		i++;
	}
	return (i);
}
