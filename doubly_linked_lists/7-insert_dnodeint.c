#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Function that inserts a new node at a given
 * position in a dlistint_t list
 * @h: Points to the pointer to the first node
 * @idx: Index of the list where the new node should be added.Index starts at 0
 * @n: Integer stored in the new node
 * Return: new_node (Added a new node at the given position),
 * or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current_node;
	unsigned int i = 0;

	if (h == NULL)
	{
		return (NULL);
	}
	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}
	current_node = *h;
	while (current_node != NULL && i < idx - 1)
	{
		current_node = current_node->next;
		i++;
	}
	if (current_node == NULL)
	{
		return (NULL);
	}
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;
	new_node->next = current_node->next;
	new_node->prev = current_node;
	if (current_node->next != NULL)
	{
		current_node->next->prev = new_node;
	}
	current_node->next = new_node;
	return (new_node);
}
