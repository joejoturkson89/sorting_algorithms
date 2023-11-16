#include "sort.h"
/**
 * swapNodes - function that swaps two adjacent nodes
 * of a doubly linked list
 * @f: first node to swap
 * @s: second node to swap
 * @list: pointer to the doubly linked list
 */
void swapNodes(listint_t *f, listint_t *s, listint_t **list)
{
	if (!(f->prev))
	{
		f->next = s->next;
		if (s->next)
			s->next->prev = f;
		s->next = f;
		s->prev = NULL;
		f->prev = s;
		*list = s;
	}
	else
	{
		s->prev->next = s->next;
		if (s->next)
			s->next->prev = s->prev;
		f->prev->next = s;
		s->prev = f->prev;
		f->prev = s;
		s->next = f;
	}
}
/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *s, *nextnode;
	int swapped;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;

	s = (*list);
	do {
		swapped = 0;
		while (s->next)
		{
			nextnode = s->next;
			if (nextnode && s->n > nextnode->n)
			{
				swapNodes(s, nextnode, list);
				swapped = 1;
				print_list((*list));
			}
			else
				s = s->next;
		}
		s = s->prev;
		while (s->prev)
		{
			nextnode = s->prev;
			if (nextnode && s->n < nextnode->n)
			{
				swapNodes(nextnode, s, list);
				swapped = 1;
				print_list((*list));
			}
			else
				s = s->prev;
		}
		s = s->next;
	} while (swapped);
}
