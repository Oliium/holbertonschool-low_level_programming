#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * update_existing_value - Update value for an existing key in a list
 * @head: Head of the collision list
 * @key: Key to search for
 * @value: New value to store
 *
 * Return: 1 if key found and updated, 0 if key not found, -1 on failure
 */
static int update_existing_value(hash_node_t *head, const char *key,
	const char *value)
{
	hash_node_t *node;
	char *new_value;

	node = head;
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (-1);
			free(node->value);
			node->value = new_value;
			return (1);
		}
		node = node->next;
	}

	return (0);
}

/**
 * create_node - Create a new hash node from key/value
 * @key: Key to duplicate
 * @value: Value to duplicate
 *
 * Return: Pointer to allocated node, or NULL on failure
 */
static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	return (new_node);
}

/**
 * hash_table_set - Function that adds an element to the hash table
 * @ht: The hash table to add or update the key/value to
 * @key: The key to add or update
 * @value: The value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	unsigned long int index;
	int update_status;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	update_status = update_existing_value(ht->array[index], key, value);
	if (update_status != 0)
		return (update_status == 1);

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
