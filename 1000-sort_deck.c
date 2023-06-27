#include "deck.h"
#include <stddef.h>
#include <stdio.h>

/**
 * swap_adjacent_nodes - swap two nodes in memory in a doubly linked deck
 *						the nodes are adjacent
 * @deck: linked deck to swap nodes within
 * @i: first node
 * @j: second node
 */
void swap_adjacent_nodes(deck_node_t **deck, deck_node_t *i, deck_node_t *j)
{
	if (i->next == j)
	{
		if (i->prev)
			i->prev->next = j;
		else
			*deck = j;
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
			*deck = i;

		if (i->next)
			i->next->prev = j;

		j->next = i->next;
		i->prev = j->prev;
		i->next = j;
		j->prev = i;
	}
}

/**
 * swap_separate_nodes - swap two nodes in memory in a doubly linked deck
 *						the nodes are not adjacent (pointing to each other)
 * @deck: linked deck to swap nodes within
 * @i: first node
 * @j: second node
 */
void swap_separate_nodes(deck_node_t **deck, deck_node_t *i, deck_node_t *j)
{
	deck_node_t *tempPrev, *tempNext;

	if (i->prev)
		i->prev->next = j;
	else
		*deck = j;

	if (i->next)
		i->next->prev = j;

	if (j->prev)
		j->prev->next = i;
	else
		*deck = i;

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
 * swap_deck_nodes - swap two nodes in memory in a doubly linked deck
 * @deck: linked deck to swap nodes within
 * @i: first node
 * @j: second node
 */
void swap_deck_nodes(deck_node_t **deck, deck_node_t *i, deck_node_t *j)
{
	if (!i || !j || i == j)
		return;

	if (i->next == j || j->next == i)
		swap_adjacent_nodes(deck, i, j);
	else
		swap_separate_nodes(deck, i, j);
}

/**
 * card_value - get the value of a card
 * @card: card to get the value of
 * Return: integer value
 */
int card_value(const card_t *card)
{
	int value;

	value = (card->kind + 1) * 100;
	switch (*(card->value))
	{
		case 'K':
			value += 13;
			break;
		case 'Q':
			value += 12;
			break;
		case 'J':
			value += 11;
			break;
		case '1':
			value += 10;
			break;
		case 'A':
			value += 1;
			break;
		default:
			value += *(card->value) - '0';
			break;
	}

	return (value);
}

/**
 * sort_deck - sort a deck of cards
 * @deck: deck of cards to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr, *prev, *p, *next;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	curr = (*deck)->next;
	next = curr->next;

	while (curr != NULL)
	{
		p = curr;
		prev = p->prev;

		while (prev != NULL && card_value(prev->card) > card_value(p->card))
		{
			swap_deck_nodes(deck, prev, p);
			prev = p->prev;
		}

		curr = next;
		next = curr ? curr->next : NULL;
	}
}
