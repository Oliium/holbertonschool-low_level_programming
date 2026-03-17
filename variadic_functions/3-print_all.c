#include "variadic_functions.h"
#include "stdarg.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * Return: void
 */

void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0, j = 0;
	char *str;

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(ap, int));
				j = 0;
				break;
			case 'i':
				printf("%d", va_arg(ap, int));
				j = 0;
				break;
			case 'f':
				printf("%f", va_arg(ap, double));
				j = 0;
				break;
			case 's':
				str = va_arg(ap, char *);
				if (!str)
					str = "(nil)";
				printf("%s", str);
				j = 0;
				break;
			default:
				j = 1;
				break;
		}
		if (format[i + 1] && !j)
			printf(", ");
		i++;
	}

	printf("\n");

	va_end(ap);
}
