#include "sort.h"

/**
 * swap - Swaps two nodes
 * @h: The head of the list
 * @nodeA: The first node to sort
 * @nodeB: The second node to sort
 */
void swap(listint_t **h, listint_t *nodeA, listint_t *nodeB)
{
	listint_t *prev, *next;

	prev = nodeA->prev;
	next = nodeB->next;

	if (prev != NULL)
		prev->next = nodeB;
	else
		*h = nodeB;
	nodeA->prev = nodeB;
	nodeA->next = next;
	nodeB->prev = prev;
	nodeB->next = nodeA;
	if (next)
		next->prev = nodeA;
}
/**
 * cocktail_sort_list - Sorts a list using the cocktail sort algorithm
 * @listt: The list to sort
 */
void cocktail_sort_list(listint_t **listt)
{
	listint_t *h;
	int flag = 0;

	if (!listt || !*listt || !(*listt)->next)
		return;

	do {
		for (h = *listt; h->next != NULL; h = h->next)
		{
			if (h->n > h->next->n)
			{
				swap(listt, h, h->next);
				print_list(*listt);
				flag = 1;
				h = h->prev;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		for (; h->prev != NULL; h = h->prev)
		{
			if (h->n < h->prev->n)
			{
				swap(listt, h->prev, h);
				print_list(*listt);
				flag = 1;
				h = h->next;
			}
		}
	} while (flag == 1);
}
