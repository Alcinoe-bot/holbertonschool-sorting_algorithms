#include "sort.h"
/**
 * insertion_sort_list - Function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 * @list: It's a pointer that pointe a struct.
 * Return: return void in end.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *prv, *nxt;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;

	for (; current != NULL ;)
	{
		tmp = current;
		for (; tmp->prev && tmp->n < tmp->prev->n ;)
		{
			prv = tmp->prev;
			nxt = tmp->next;

			if (prv->prev != NULL)
			{
				prv->prev->next = tmp;
			}
			tmp->prev = prv->prev;
			tmp->next = prv;
			prv->prev = tmp;
			prv->next = nxt;
			if (nxt != NULL)
			{
				nxt->prev = prv;
			}
			if (tmp->prev == NULL)
			{
				*list = tmp;
			}
			print_list(*list);
		}
		current = current->next;
	}
}
