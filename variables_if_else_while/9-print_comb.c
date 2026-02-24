#include <stdio.h>

/**
* main - Entry point
* Return: Always 0
*/
int main(void)
{
	int combo;

	for (combo =0; combo <= 9; combo++)
	{
		int second_combo;

		for (second_combo = combo + 1; second_combo <= 9; second_combo++)
		{
			if (combo != 0)
			{
				putchar(' ');
				putchar('0' + combo);
			
			if (combo != 9)
				putchar(',');
			}
		}
	putchar('\n');
	return (0);
	}
