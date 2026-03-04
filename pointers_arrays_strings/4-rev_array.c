#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers.
 * @a: pointer to the first element of the array
 * @n: number of elements in the array
 */

void reverse_array(int *a, int n)
{
	int *start = a;
	int *end = a + n - 1;
	int temp;

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}
