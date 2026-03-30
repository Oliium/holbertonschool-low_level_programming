#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - Function that adds a new node
 * at the end of a dlistint_t list
 * @head: Points to the pointer to the first node
 * @n: Integer stored in the new node
 * Return: new_node_end (Added a new node at the end of the list)
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node_end;
	dlistint_t *index_node = NULL;
	{
		if (head == NULL)
		{
			return (NULL);
		}
		new_node_end = malloc(sizeof(dlistint_t));
		if (new_node_end == NULL)
		{
			return (NULL);
		}
		new_node_end->n = n;
		new_node_end->prev = NULL;
		new_node_end->next = NULL;
		if (*head == NULL)
		{
			*head = new_node_end;
			return (new_node_end);
		}
		else
		{
			index_node = *head;
			while (index_node->next != NULL)
			{
				index_node = index_node->next;
			}
			index_node->next = new_node_end;
			new_node_end->prev = index_node;
		}
	}
	return (new_node_end);
}
