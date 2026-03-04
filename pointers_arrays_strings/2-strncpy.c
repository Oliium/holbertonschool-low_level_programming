#include "main.h"

/**
 * _strncpy - copies a string, using at most n bytes from src
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * @n: maximum number of bytes to copy from src
 * Return: pointer to the resulting string dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0' && i < n; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
