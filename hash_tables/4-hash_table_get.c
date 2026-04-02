#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_get - Function that retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key to look for
 * Return: The value associated with the key, or NULL if key couldn't be found
 * or if ht is NULL
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];

	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);
		current_node = current_node->next;
	}

	return (NULL);
}
