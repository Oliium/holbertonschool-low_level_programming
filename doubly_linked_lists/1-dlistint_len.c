#include "lists.h"
#include <stdio.h>

/**
 * dlistint_len - Function that returns the number of elements in a linked
 * list
 * @h: Points to the head of the list
 * Return: number of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h != NULL)
	{
		h = h->next;
		nodes++;
	}
	return (nodes);
}
