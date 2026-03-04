#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s: pointer to the string to be converted
 * Return: the integer value represented by the string, or 0 if no valid
 * conversion could be performed
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (sign * (int)result);
}
