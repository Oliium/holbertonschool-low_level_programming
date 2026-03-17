#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - prints a char
 * @ap: va_list containing the argument
 */
void print_char(va_list ap)
{
	printf("%c", va_arg(ap, int));
}

/**
 * print_int - prints an int
 * @ap: va_list containing the argument
 */
void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_float - prints a float
 * @ap: va_list containing the argument
 */
void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_string - prints a string
 * @ap: va_list containing the argument
 */
void print_string(va_list ap)
{
	char *str = va_arg(ap, char *);

	if (!str)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *separator = "";

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s", separator);
				print_char(ap);
				separator = ", ";
				break;
			case 'i':
				printf("%s", separator);
				print_int(ap);
				separator = ", ";
				break;
			case 'f':
				printf("%s", separator);
				print_float(ap);
				separator = ", ";
				break;
			case 's':
				printf("%s", separator);
				print_string(ap);
				separator = ", ";
				break;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}
