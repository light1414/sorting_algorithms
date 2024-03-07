#include "sort.h"

void swap_int(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_int - Swap two integers in array.
 * @a: first integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmpp;

	tmpp = *a;
	*a = *b;
	*b = tmpp;
}

/**
 * hoare_parti - Orders a subset of an array of integers
 *                   like the hoare partition scheme.
 * @array: Integers array.
 * @size: array size.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: The last partition index.
 *
 * Description: Uses final element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, up, below;

	pivot = array[right];
	for (up = left - 1, below = right + 1; up < below;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (up < below)
		{
			swap_ints(array + up, array + below);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sot - Implements the quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Array size.
 * @left: Starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: IT Uses the Hoare partition scheme.
 */
void hoare_sot(int *array, size_t size, int left, int right)
{
	int pat;

	if (right - left > 0)
	{
		pat = hoare_parti(array, size, left, right);
		hoare_sot(array, size, left, pat - 1);
		hoare_sot(array, size, pat, right);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: IT uses the Hoare partition scheme. Prints
 * the array after the swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sot(array, size, 0, size - 1);
}
