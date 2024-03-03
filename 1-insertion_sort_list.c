#include "sort.h"

/**
* insertion_sort_list - Sorting insertion method
*
* @list: the doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *t, *nod, *pre_nod;

	if (!list || !(*list) || !(*list)->next)
		return;
	t = *list;

	while (t != NULL)
	{
		nod = t;
		while ((nod->prev != NULL) && (nod->prev->n > nod->n))
		{
			pre_nod = nod->prev;

			if (nod->next != NULL)
			{
				nod->next->prev = pre_nod;
			}
			if (pre_nod->prev != NULL)
			{
				pre_nod->prev->next = nod;
			}

			pre_nod->next = nod->next;
			nod->next = pre_nod;
			nod->prev = pre_nod->prev;
			pre_nod->prev = nod;

			if (nod->prev == NULL)
			{
				*list = nod;
			}

			print_list(*list);
		}

		t = t->next;
	}
}
