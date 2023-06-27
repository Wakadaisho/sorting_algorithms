#include "sort.h"

/**
 * swap_adjacent_nodes - swap two nodes in memory in a doubly linked list
 *						the nodes are adjacent
 * @list: linked list to swap nodes within
 * @i: first node
 * @j: second node
 */
void swap_adjacent_nodes(listint_t **list, listint_t *i, listint_t *j)
{
	if (i->next == j)
	{
		if (i->prev)
			i->prev->next = j;
		else
			*list = j;

		if (j->next)
			j->next->prev = i;

		i->next = j->next;
		j->prev = i->prev;
		j->next = i;
		i->prev = j;
	}
	else
	{
		if (j->prev)
			j->prev->next = i;
		else
			*list = i;

		if (i->next)
			i->next->prev = j;

		j->next = i->next;
		i->prev = j->prev;
		i->next = j;
		j->prev = i;
	}
}

/**
 * swap_separate_nodes - swap two nodes in memory in a doubly linked list
 *						the nodes are not adjacent (pointing to each other)
 * @list: linked list to swap nodes within
 * @i: first node
 * @j: second node
 */
void swap_separate_nodes(listint_t **list, listint_t *i, listint_t *j)
{
	listint_t *tempPrev, *tempNext;

	if (i->prev)
		i->prev->next = j;
	else
		*list = j;

	if (i->next)
		i->next->prev = j;

	if (j->prev)
		j->prev->next = i;
	else
		*list = i;

	if (j->next)
		j->next->prev = i;

	tempPrev = i->prev;
	i->prev = j->prev;
	j->prev = tempPrev;

	tempNext = i->next;
	i->next = j->next;
	j->next = tempNext;
}

/**
 * swap_list_nodes - swap two nodes in memory in a doubly linked list
 * @list: linked list to swap nodes within
 * @i: first node
 * @j: second node
 */
void swap_list_nodes(listint_t **list, listint_t *i, listint_t *j)
{
	if (!i || !j || i == j)
		return;

	if (i->next == j || j->next == i)
		swap_adjacent_nodes(list, i, j);
	else
		swap_separate_nodes(list, i, j);
}
/**
 * cocktail_sort_list - sort an linked list using Cocktail Shaker Sort
 * @list: doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *curr, *next;
	int swapped;

	if (list == NULL || *list == NULL)
		return;
	start = *list;
	end = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		curr = start;
		next = curr->next;
		while (next != end)
		{
			if (curr->n > curr->next->n)
			{
				swap_list_nodes(list, curr, curr->next);
				print_list(*list);
				swapped = 1;
			}
			curr = next;
			next = curr ? curr->next : curr->next;
		}
		end = curr;
		swapped = 0;
		next = curr->prev;
		while (next != start->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_list_nodes(list, curr, curr->prev);
				print_list(*list);
				swapped = 1;
			}
			curr = next;
			next = curr ? curr->prev : curr->prev;
		}
		start = curr;
	}
}
