#include "lists.h"
#include <stdio.h>

/**
 * print_list -prints strings contained in different nodes
 * @h: points towards the list
 * Return: length (Length of the strings)
 */
size_t print_list(const list_t *h)
{
	size_t length = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}
		h = h->next;
		length++;
	}
	return (length);
}
