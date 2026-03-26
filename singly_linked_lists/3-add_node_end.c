#include "lists.h"

/**
 * list_t *add_node_end - Function that adds a node at the end of the list
 * @head: Pointer to the pointer to the first node of the list
 * @str: Pointer that stores the string
 * Return: new node (Returns the new node)
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *current;
	unsigned int len = 0;
	if (head == NULL || str == NULL)
	{
		return (NULL);
	}
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	new_node->len = len;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
	return (new_node);
}
