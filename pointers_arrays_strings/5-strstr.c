#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring.
 * @haystack: the string to be searched
 * @needle: the substring to be located
 * Return: a pointer to the beginning of the located substring, or NULL if the
 * substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	if (*needle == '\0')
		return (haystack);

	while (*haystack)
	{
		h = haystack;
		n = needle;

		while (*h && *n && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
			return (haystack);

		haystack++;
	}

	return (NULL);
}
