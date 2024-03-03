#include "sort.h"

void swap_int(int *ar, int *br);
int hoare_partition(int *array, siz_t size, int left, int right);
void hoare_part(int *array, siz_t size, int l, int r);
void quick_sort_hoare(int *array, siz_t size);

/**
 * swap_ints - Swaps two integers in an array.
 * @ar: First integer to swap.
 * @br: Second integer to swap.
 */
void swap_int(int *ar, int *br)
{
	int tmp;

	tmp = *ar;
	*ar = *br;
	*br = tmp;
}

/**
 * hoare_partition - Orders a subset of an array of integers
 *                   acc to the hoare partition scheme.
 * @array: The integers array.
 * @size: The array size.
 * @left: Starting index of the subset to order.
 * @right: The last index of the subset to order.
 *
 * Return: The last partition index.
 *
 * Description: it uses the final element of the par as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, siz_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_int(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_part - Implements the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @l: The starting index of the array partition to order.
 * @r: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, siz_t size, int l, int r)
{
	int part;

	if (r - l > 0)
	{
		part = hoare_partition(array, size, l, r);
		hoare_part(array, size, l, part - 1);
		hoare_part(array, size, part, r);
	}
}

/**
 * quick_sort_hoare - It finds an array of integers in ascending
 *                    order with the quicksort algorithm.
 * @array: Array of integers.
 * @size: array size.
 *
 * Description: it uses the Hoare partition scheme. returns
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, siz_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
