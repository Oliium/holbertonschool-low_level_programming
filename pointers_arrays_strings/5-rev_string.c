#include "main.h"

/**
 * rev_string - reverses a string.
 * @s: pointer to the string to be reversed
 */

void rev_string(char *s)
{
	int length = 0;
	char *start = s;
	char temp;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	s--; /* Move back to the last character of the string */

	while (start < s)
	{
		temp = *start;
		*start = *s;
		*s = temp;

		start++;
		s--;
	}
}
