#include "sort.h"

/**
* quick_sort - The implementation of quick_sort with Lomuto partition
*
* @arr: the array of integers
* @siz: the size of array
*/

void quick_sort(int *arr, size_t siz)
{
	int my_size = (int)siz;

	if (!array || my_size < 0)
	{
		return;
	}

	sorted(arr, 0, my_size - 1, siz);
}


/**
* sorted - Recursive the call partitions of quick sort
*
* @arr: the array of integers
* @a: Pointer(or origin) to the first array element
* @z: Pointer to the last array element
* @n: size of array
*
* Return: void
*/
void sorted(int *arr, int a, int z, size_t n)
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
* @arr: the array of integers
* @a: Pointer to the first array element
* @z: Pointer to the last array element
* @n: size of array
*
* Return: void
*/
int partition(int *arr, int a, int z, size_t n)
{
	int j = a + 1;
	int i = a;
	int tem;

	while (j < z && a >= 0)
	{
		if (arr[i] <= arr[z])
			i++, j++;
		else if (arr[j] < arr[z])
		{
			tem = arr[i];
			arr[i] = arr[j];
			arr[j] = tem;
			print_arr(arr, n);
			j++, i++;
		}
		else
			j++;
	}
	if (arr[j] <= arr[i])
	{
		tem = arr[i];
		arr[i] = arr[j];
		arr[j] = tem;
		if (arr[i] != arr[j])
			print_arr(arr, n);
	}
	else
	{
		i++;
	}
	return (i);
}
