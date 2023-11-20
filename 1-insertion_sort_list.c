#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of inetgers in ascending order using the insertion sort algorithm.
 * @list: pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *c, *p, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	c = (*list)->next;
	tmp = c->next;
	while (c)
	{
		if (c->n < c->prev->n)
		{
			p = c->prev;
			while (p && (c->n < p->n))
			{
				if (!(p->prev))
				{
					p->prev = c;
					c->prev->next = c->next;
					if (c->next)
						c->next->prev = c->prev;
					c->next = p;
					c->prev = NULL;
					*list = c;
				}
				else
				{
					c->prev->next = c->next;
					if (c->next)
						c->next->prev = c->prev;
					p->prev->next = c;
					c->prev = p->prev;
					p->prev = c;
					c->next = p;
				}
				print_list(*list);
				p = c->prev;
			}
		}
		c = tmp;
		c ? (tmp = c->next) : (tmp = NULL);
	}
}
