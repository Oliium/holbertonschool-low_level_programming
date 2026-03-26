#include "main.h"

/**
 * sqrt_helper - helper function to find the natural square root of a number
 * @n: Stores the number
 * @i: Stores the current number being tested
 * Return: The natural square root of the number
 */

static int sqrt_helper(int n, int i)
{
	long sq = (long)i * i;

	if (sq == n)
		return (i);
	if (sq > n)
		return (-1);
	return (sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number by recursion
 * @n: Stores the number
 * Return: The natural square root of the number
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 0));
}
