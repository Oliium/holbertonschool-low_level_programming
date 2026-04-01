#include "hash_tables.h"
#include <stdlib.h>

/**
 * key_index - Function that gives you the index of a key
 * @key: The key to get the index of
 * @size: The size of the array of the hash table
 * Return: The index at which the key/value pair should be stored in the array
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	if (key == NULL || size == 0)
		return (0);
	hash = hash_djb2(key);
	return (hash % size);
}
