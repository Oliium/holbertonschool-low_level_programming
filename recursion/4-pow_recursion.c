#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * by using recursion
 * @x: Stores the base number
 * @y: Stores the exponent number
 * Return: The value of x raised to the power of y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
