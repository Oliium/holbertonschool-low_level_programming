#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Function that places a new node at the end
 * of the list
 * @head: Points to the pointer to the first node
 * @str: String stored
 * Return: new_node_end (Added a new node at the end of the list)
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node_end;
	list_t *index_node = NULL;
	unsigned int length = 0;

	if (head == 0 || str == 0)
	{
		return (NULL);
	}
	new_node_end = malloc(sizeof(list_t));
	if (new_node_end == 0)
	{
		return (NULL);
	}
	new_node_end->str = strdup(str);
	if (new_node_end->str == 0)
	{
		free(new_node_end);
		return (NULL);
	}
	while (str[length] != '\0')
	{
		length++;
	}
	new_node_end->len = length;
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
	}
	return (new_node_end);
}
