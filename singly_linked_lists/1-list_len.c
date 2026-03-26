#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @h: points towards the list
 * Return: length (Length of the strings)
 */

size_t list_len(const list_t *h)
{
	size_t length = 0;

	while (h)
	{
		h = h->next;
		length++;
	}
	return (length);
}
