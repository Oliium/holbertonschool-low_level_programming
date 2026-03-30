#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Function that deletes the node at index index of a
 * dlistint_t linked list
 * @head: Points to the pointer to the first node
 * @index: Index of the node that should be deleted. Index starts at 0
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}
	current_node = *head;
	if (index == 0)
	{
		*head = current_node->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(current_node);
		return (1);
	}
	while (current_node != NULL && i < index)
	{
		if (i == index - 1)
		{
			dlistint_t *node_to_delete = current_node->next;
			if (node_to_delete == NULL)
			{
				return (-1);
			}
			current_node->next = node_to_delete->next;
			if (node_to_delete->next != NULL)
			{
				node_to_delete->next->prev = current_node;
			}
			free(node_to_delete);
			return (1);
		}
		current_node = current_node->next;
		i++;
	}
	return (-1);
}
