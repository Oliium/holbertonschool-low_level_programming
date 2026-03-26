#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Function that frees a list
 * @head: Pointer to the first node of the list
 */

void free_list(list_t *head)
{
	list_t *current;
	while (head)
	{
		current = head;
		head = head->next;
		free(current->str);
		free(current);
	}
}
