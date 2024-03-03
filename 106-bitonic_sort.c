#include "sort.h"
#include <stdio.h>
/**
 * prt_bitonic - Prints array modified by
 * bitonic algorithm
 *
 * @arr: The input array
 * @A: first index
 * @B: last index
 * Return: no return
 */
void prt_bitonic(int *arr, int A, int B)
{
	char *tep;

	for (tep = ""; A < B; A++)
	{
		printf("%s%d", sep, arr[A]);
		tep = ", ";
	}
	printf("\n");
}

/**
 * sot_up - Sorts array in UP mode
 *
 * @arr: input array
 * @l: the first index
 * @h: the last index
 * Return: no return
 */
void sot_up(int *arr, int l, int h)
{
	int i, j, max;

	for (i = l; i < h; i++)
	{
		max = i;

		for (j = i + 1; j < h; j++)
		{
			if (arr[max] > arr[j])
				max = j;
		}

		if (max != i)
		{
			arr[i] = arr[i] + arr[max];
			arr[max] = arr[i] - arr[max];
			arr[i] = arr[i] - arr[max];
		}
	}
}

/**
 * sot_down - Sorts the array in DOWN mode
 *
 * @arr: input array
 * @l: the first index
 * @h: the last index
 * Return: no return
 */
void sot_down(int *arr, int l, int h)
{
	int i, j, max;

	for (i = l; i < h; i++)
	{
		max = i;

		for (j = i + 1; j < h; j++)
		{
			if (arr[max] < arr[j])
				max = j;
		}

		if (max != i)
		{
			arr[i] = arr[i] + arr[max];
			arr[max] = arr[i] - arr[max];
			arr[i] = arr[i] - arr[max];
		}
	}
}

/**
 * Recursion - Recursive function that executes the bitonic sort
 * algorithm
 *
 * @arr: input array
 * @l: the first index
 * @h: the last index
 * @cool: UP or DOWN
 * @size: size of the array
 * Return: no return
 */
void Recursion(int *arr, int l, int h, int cool, size_t size)
{
	char *option;

	if (h - l < 2)
		return;

	option = (cool == 0) ? "UP" : "DOWN";
	printf("Merging [%d/%ld] (%s):\n", h - l, size, option);
	prt_bitonic(arr, l, h);

	if (h - l == 2)
		return;

	Recursion(arr, l, (h + l) / 2, 0, size);
	sot_up(arr, l, (h + l) / 2);
	printf("Result [%d/%ld] (%s):\n", ((h + l) / 2) - l, size, "UP");
	prt_bitonic(arr, l, (h + l) / 2);

	Recursion(arr, (h + l) / 2, h, 1, size);
	sot_down(arr, (h + l) / 2, h);
	printf("Result [%d/%ld] (%s):\n", h - ((h + l) / 2), size, "DOWN");
	prt_bitonic(arr, (h + l) / 2, h);
}

/**
 * bitonic_sort - Function that executes the bitonic_sort
 * algorithm
 *
 * @array: The input array
 * @size: thr size of the array
 * Return: no return
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursion(array, 0, size, 0, size);
	sot_up(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	print_bitonic(array, 0, size);
}
