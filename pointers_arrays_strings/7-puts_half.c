#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line.
 * @str: pointer to the string to be printed 
 */

void puts_half(char *str)
{
	int length = 0;
	int start;

	while (str[length] != '\0')
		length++;

	if (length % 2 == 0)
		start = length / 2;
	else
		start = (length + 1) / 2;

	while (start < length)
	{
		_putchar(str[start]);
		start++;
	}
	_putchar('\n');
}
