#include "main.h"

/**
 * prime_helper - checks if n is divisible by d recursively
 * @n: number to test
 * @d: current divisor
 * Return: 1 if prime, 0 otherwise
 */

int prime_helper(int n, int d)
{
	if ((long)d * d > n)
	{
		return (1);
	}
	if (n % d == 0)
	{
		return (0);
	}
	return (prime_helper(n, d + 1));
}

/**
 * is_prime_number - returns 1 if n is a prime number, otherwise 0
 * @n: number to test
 * Return: 1 if prime, 0 otherwise
 */

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	if (n == 2)
	{
		return (1);
	}
	if (n % 2 == 0)
	{
		return (0);
	}
	return (prime_helper(n, 3));
}
