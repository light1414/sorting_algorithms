#include "sort.h"

/**
 * mer_copyarr - Copies from the source to destination
 * @S: the array to copy from
 * @D: the array to copy to
 * @L: the index to start copying from
 * @R: the index to end to copy
 *
 * Return: void
*/
void mer_copyarr(int *S, int *D, size_t L, size_t R)
{
	size_t i;

	for (i = L; i <= R; i++)
	{
		D[i] = S[i];
	}
}


/**
 * mer_print - Prints a section of a given array
 * @arr: the array to print its section
 * @tmp: the string to print
 * @P: index to start printing from
 * @M: the middle of the array
 * @r: indext to end the print
 *
 * Return: void
*/
void mer_print(int *arr, int *tmp, size_t P, size_t M, size_t r)
{
	size_t i;

	printf("Merging...\n");

	printf("[left]: ");
	for (i = P; i <= M; i++)
	{
		if (i > P)
			printf(", ");

		printf("%i", ar[i]);
	}

	printf("\n[right]: ");
	for (i = (M + 1); i <= r; i++)
	{
		if (i > (M + P))
			printf(", ");

		printf("%i", ar[i]);
	}

	printf("\n[Done]: ");
	for (i = P; i <= r; i++)
	{
		if (i > P)
			printf(", ");

		printf("%i", tmp[i]);
	}
	printf("\n");
}


/**
 * merger - Functions to merge atomized elements of the array
 * @arr: main array that is atomized
 * @tmp: temporary array
 * @l: left index
 * @M: middle index
 * @r: right index
 *
 * Return: void
*/
void merger(int *arr, int *tmp, size_t l, size_t M, size_t r)
{
	size_t i, a, b;

	a = l;
	b = M + 1;

	for (i = l; a <= M && b <= r; i++)
	{
		if (arr[a] < arr[b])
			tmp[i] = arr[a++];
		else
			tmp[i] = arr[b++];
	}

	while (a <= M)
		tmp[i++] = arr[a++];

	while (b <= r)
		tmp[i++] = arr[b++];

	mer_print(arr, tmp, l, M, r);
	mer_copyarr(tmp, arr, l, r);
}

/**
 * mer_sort - Funtions that uses recurssion to break the array
 * @arr: the array to be broken and merged
 * @tmp: temporary array to store values
 * @L: left value
 * @R: right value
 *
 * Return: void
*/
void mer_sort(int *arr, int *tmp, size_t L, size_t R)
{
	size_t m;

	if (L >= R)
		return;

	if ((L + R) % 2 == 0)
		m = (L + R) / 2 - L;
	else
		m = (L + R) / 2;

	mer_sort(arr, tmp, L, m);
	mer_sort(arr, tmp, (m + L), R);
	merger(arr, tmp, L, m, R);
}

/**
 * merge_sort - the implementation of merge sorting
 * @array: the array of integers to be sorted
 * @size: the size of the array
 *
 * Return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t L, R;
	int *tem_arr;

	if (size < 2)
		return;

	tem_arr = (int *)malloc(sizeof(int) * size);

	if (tem_arr == NULL)
		return;

	L = 0;
	R = size - 1;

	mer_sort(array, tem_arr, L, R);

	free(tem_arr);
}
