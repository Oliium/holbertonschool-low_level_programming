#include "main.h"

/**
* times_table - affiche la table de multiplication de 0 à 9
*
* Retour : rien (utilise _putchar)
*/
void times_table(void)
{
	int i, j, k;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			k = i * j;
			if (j == 0)
			{
				/* premier nombre de la ligne : aucun séparateur */
				if (k < 10)
					_putchar('0');
				else
				{
					_putchar((k / 10) + '0');
					_putchar((k % 10) + '0');
				}
			}
			else
			{
				_putchar(',');
				_putchar(' ');
				if (k < 10)
					_putchar(' ');
				if (k >= 10)
					_putchar((k / 10) + '0');
				_putchar((k % 10) + '0');
			}
		}
		_putchar('\n');
	}
}