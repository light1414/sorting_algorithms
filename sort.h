#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* Struct listint_s - the Doubly list node
*
* @n: Int stored in the node
* @prev: the pointer to the previous element of the list
* @next: the Pointer to the next element of the list
*/
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **listt);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);

/** Functions in Counting Sort **/
void count_sort(int *array, size_t size);
int sort_max(int *array, size_t size);
void set_arr(int *array, size_t size, int value);
void array_sort(*array int *new_arr, size_t size);

/** Functions in merge sort **/
void merge_sort(int *array, size_t size);
void mer_copyarr(int *S, int *D, size_t L, size_t R);
void mer_sort(int *array, int *tmp, size_t L, size_t R);
void mer_print(int *array, int *tmp, size_t P, size_t M, size_t r);
void merger(int *array, int *tmp, size_t l, size_t M, size_t r);

void quick_sort_hoare(int *array, size_t size);
int partition(int *array, int first, int last, size_t n);
void sorted(int *array, int first, int last, size_t n);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void interval_insertion(int *array, int size, int inter);
size_t power(size_t num, size_t pow);
int compare_swap(listint_t **list, listint_t **node1, listint_t **node2);
/* void sort_deck(deck_node_t **deck); */

#endif /* the end of sort header */
