#include "sort.h"

/**
 * sort_max - Functions to sort the maximum integer in an array
 * @array: the array to find the maximum integer
 * @size: the array size
 *
 * Return: maximum integer or -1 if failure
*/
int sort_max(int *array, size_t size)
{
	size_t i;
	int maxi;

	if (siz < 1)
		return (-1);

	maxi = array[0];

	for (i = 1; i < siz; i++)
	{
		if (array[i] > maxi)
		{
			maxi = array[i];
		}
	}
	return (maxi);
}


/**
 * array_sort - Function that copy integers from one array to another
 * @array: the array to copy from
 * @new_array: the array to copy to
 * @size: size of array 1 or array 2, both are equal in size
 *
 * Return: void
*/
void array_sort(int *array, int *new_array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		new_array[i] = array[i];
	}
}


/**
 * set_arr - Function that sets an integer value to all indexed of
 * an array
 * @array: The array to set
 * @size: the size of the array
 * @val: Value of integer to set
 *
 * Return: void
*/
void set_arr(int *array, size_t size, int val)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		array[i] = val;
	}
	array[i] = '\0';
}


/**
 * count_sort - It implementation of counting sort algorithm
 * @array: Pointer to the array
 * @size: The array size
 *
 * Return: void
*/
void count_sort(int *array, size_t size)
{
	int index, j, max, *count_ar, *ar_cpy;
	size_t i;

	if (size < 2 || arr == NULL)
		return;

	max = find_max(array, size);

	ar_cpy = malloc(sizeof(int) * size);
	count_ar = malloc(sizeof(int) * (max + 1));

	if (count_ar == NULL || ar_cpy == NULL)
		return;

	array_sort(array, ar_cpy, size);
	set_arr(count_ar, (size_t)(max + 1), 0);

	for (i = 0; i < size; i++)
		count_ar[array[i]] += 1;

	for (j = 1; j <= max; j++)
		count_ar[j] += count_ar[j - 1];

	print_array(count_ar, (size_t)(max + 1));

	for (i = 0; i < size; i++)
	{
		index = count_ar[ar_cpy[i]];
		array[index - 1] = ar_cpy[i];
		count_arr[ar_cpy[i]] = index - 1;
	}

	free(ar_cpy);
	free(count_ar);
}
