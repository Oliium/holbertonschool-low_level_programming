#include <stdio.h>

/**
*/

int main (void)
{
	int num0, num1, num2, result;

	printf("Hi, Welcome to THE GAME\n");
	printf(" 1 is for Addition\n");
	printf(" 2 is for Subtraction\n");
	printf(" 3 is for Multiplication\n");
	printf(" 4 is for Division\n");
	printf(" 0 is for leaving THE GAME\n");
	printf("Choose your difficulty: ");
	scanf("%d", &num0);

	while (num0 != 0 && num0 != 1 && num0 != 2 && num0 != 3 && num0 != 4)
	{
		printf("Game Over ! Try again: ");
		scanf("%d", &num0);
	}
	if (num0 == 0)
	{
		printf("You're too weak to play THE GAME !\n");
		return (0);
	}
	if (num0 == 1)
	{
		printf("Welcome to the Addition Difficulty !\n");
		printf("Enter number 1: ");
		scanf("%d", &num1);
		printf("Enter number 2: ");
		scanf("%d", &num2);
		result = num1 + num2;
		printf("The Game result is: %d\n", result);
	}
}
