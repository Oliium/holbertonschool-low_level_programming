#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_dlistint - Function that frees a dlistint_t list
 * @head: Points to the head of the list
 * Return: void
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node = head;
	{
		while (current_node != NULL)
		{
			dlistint_t *next_node = current_node->next;

			free(current_node);
			current_node = next_node;
		}
	}
}
