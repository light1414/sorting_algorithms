#include "sort.h"
#include <stdio.h>
/**
 * prt_bitonic - Prints the modified array by
 * bitonic algorithm
 *
 * @arr: the input array
 * @i: The first index
 * @limit: the last index
 * Return: no return
 */
void prt_bitonic(int *arr, int i, int limit)
{
	char *sept;

	for (sept = ""; i < limit; i++)
	{
		printf("%s%d", sept, arr[i]);
		sept = ", ";
	}
	printf("\n");
}

/**
 * sot_up - Sorts the array in UP mode
 *
 * @arr: the input array
 * @low: the first index
 * @high: last index
 * Return: no return
 */
void sot_up(int *arr, int low, int high)
{
	int i, j, maxi;

	for (i = low; i < high; i++)
	{
		maxi = i;

		for (j = i + 1; j < high; j++)
		{
			if (arr[maxi] > arr[j])
				maxi = j;
		}

		if (maxi != i)
		{
			arr[i] = arr[i] + arr[maxi];
			arr[maxi] = arr[i] - arr[maxi];
			arr[i] = arr[i] - arr[maxi];
		}
	}
}

/**
 * sot_down - Sorts the array in DOWN mode
 *
 * @arr: The input array
 * @low: The first index
 * @high: last index
 * Return: no return
 */
void sot_down(int *arr, int low, int high)
{
	int i, j, maxi;

	for (i = low; i < high; i++)
	{
		maxi = i;

		for (j = i + 1; j < high; j++)
		{
			if (arr[maxi] < arr[j])
				maxi = j;
		}

		if (maxi != i)
		{
			arr[i] = arr[i] + arr[maxi];
			arr[maxi] = arr[i] - arr[maxi];
			arr[i] = arr[i] - arr[maxi];
		}
	}
}

/**
 * recursion - Function that executes the bitonic sort
 * algorithm
 *
 * @arr: the input array
 * @low: the first index
 * @high: last index
 * @bool: UP or DOWN
 * @size: array size
 * Return: no return
 */
void recursion(int *arr, int low, int high, int bool, size_t size)
{
	char *opt;

	if (high - low < 2)
		return;

	opt = (bool == 0) ? "UP" : "DOWN";
	printf("Merging [%d/%ld] (%s):\n", high - low, size, opt);
	prt_bitonic(arr, low, high);

	if (high - low == 2)
		return;

	recursion(arr, low, (high + low) / 2, 0, size);
	sot_up(arr, low, (high + low) / 2);
	printf("Result [%d/%ld] (%s):\n", ((high + low) / 2) - low, size, "UP");
	prt_bitonic(arr, low, (high + low) / 2);

	recursion(arr, (high + low) / 2, high, 1, size);
	sot_down(arr, (high + low) / 2, high);
	printf("Result [%d/%ld] (%s):\n", high - ((high + low) / 2), size, "DOWN");
	prt_bitonic(arr, (high + low) / 2, high);
}

/**
 * bitonic_sort - The first function that starts the bitonic_sort
 * algorithm
 *
 * @array: the input array
 * @size: the array size
 * Return: no return
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursion(array, 0, size, 0, size);
	sot_up(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	prt_bitonic(array, 0, size);
}
