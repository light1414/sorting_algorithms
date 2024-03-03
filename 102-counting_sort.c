#include "sort.h"

/**
 * sort_max - Functions to sort the maximum integer in an array
 * @arr: the array to find the maximum integer
 * @siz: the array size
 *
 * Return: maximum integer or -1 if failure
*/
int sort_max(int *arr, size_t siz)
{
	size_t i;
	int maximum;

	if (siz < 1)
		return (-1);

	maximum = arr[0];

	for (i = 1; i < siz; i++)
	{
		if (arr[i] > maximum)
		{
			maximum = arr[i];
		}
	}
	return (maximum);
}


/**
 * array_sort - Function that copy integers from one array to another
 * @arr: the array to copy from
 * @new_array: the array to copy to
 * @siz: size of array 1 or array 2, both are equal in size
 *
 * Return: void
*/
void array_sort(int *arr, int *new_array, size_t siz)
{
	size_t i;

	for (i = 0; i < siz; i++)
	{
		new_array[i] = arr[i];
	}
}


/**
 * set_arr - Function that sets an integer value to all indexed of
 * an array
 * @arr: The array to set
 * @siz: the size of the array
 * @val: Value of integer to set
 *
 * Return: void
*/
void set_arr(int *arr, size_t siz, int val)
{
	size_t i;

	for (i = 0; i < siz; i++)
	{
		arr[i] = val;
	}
	arr[i] = '\0';
}


/**
 * count_sort - It implementation of counting sort algorithm
 * @arr: Pointer to the array
 * @siz: The array size
 *
 * Return: void
*/
void count_sort(int *arr, size_t siz)
{
	int index, j, max, *count_arr, *ar_cpy;
	size_t i;

	if (size < 2 || arr == NULL)
		return;

	max = find_max(arr, siz);

	ar_cpy = malloc(sizeof(int) * size);
	count_arr = malloc(sizeof(int) * (max + 1));

	if (count_arr == NULL || ar_cpy == NULL)
		return;

	arraysort(arr, ar_cpy, siz);
	set_arr(count_arr, (size_t)(max + 1), 0);

	for (i = 0; i < size; i++)
		count_arr[arr[i]] += 1;

	for (j = 1; j <= max; j++)
		count_arr[j] += count_arr[j - 1];

	print_array(count_arr, (size_t)(max + 1));

	for (i = 0; i < size; i++)
	{
		index = count_arr[ar_cpy[i]];
		array[index - 1] = ar_cpy[i];
		count_arr[ar_cpy[i]] = index - 1;
	}

	free(ar_cpy);
	free(count_arr);
}
