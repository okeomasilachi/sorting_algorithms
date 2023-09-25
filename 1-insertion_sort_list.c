#include "sort.h"

/**
 * insertion_sort_list - implements the insertion sort algorithm
 *                  to sort a doubly linked list in ascending order.
 * @list: Pointer to a pointer of type `listint_t`. It represents a
 *          doubly linked list.
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *fst = NULL, *tmp = NULL;
	FILE *file = NULL;


	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (fst = (*list)->next; fst; fst = fst->next)
	{
		tmp = fst;
		while (tmp->prev != NULL && tmp->prev->n > tmp->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;
			print_list(*list);
		}
	}
}
