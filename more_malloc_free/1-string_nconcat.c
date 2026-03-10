#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings, up to n bytes of s2
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to concatenate from s2
 * Return: pointer to newly allocated string, or NULL on failure
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *result;

	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;

	if (n < len2)
		len2 = n;

	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];
	for (j = 0; j < len2; j++)
		result[i + j] = s2[j];
	result[i + j] = '\0';

	return (result);
}
