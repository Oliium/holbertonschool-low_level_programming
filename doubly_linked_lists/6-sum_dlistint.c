#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sum_dlistint - Function that returns the sum of all the data (n) of a
 * dlistint_t linked list
 * @head: Points to the head of the list
 * Return: If the list is empty, return 0. Otherwise, return the sum of
 * all the data (n) of a dlistint_t linked list
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
