#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of inetgers in ascending order using the insertion sort algorithm.
 * @list: pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *c, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	c = (*list)->next;

	while (c != NULL)
	{
		tmp = c;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;

			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;

			if (tmp->prev == NULL)
				*list = tmp;

			print_list(*list);
		}

		c = c->next;
	}
}
