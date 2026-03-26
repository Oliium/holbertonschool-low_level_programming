# Variables, If Else, While

## Overview

This project teaches you how to work with variables, use conditional statements (if/else), and create loops (while). These are fundamental building blocks for any program.

## What You Will Learn

- How to declare and initialize variables
- Different variable types (int, float, char, etc.)
- How to use if and else statements
- How while loops work
- How to write conditions
- Getting input from users

## Key Concepts

### Variables
Variables are containers that store data. Different types of variables can store different kinds of data:
- `int` - whole numbers
- `float` - decimal numbers
- `char` - single characters
- `double` - larger decimal numbers

### If Statements
If statements let you run code only when a condition is true:

```c
if (age >= 18)
{
    printf("You are an adult\n");
}
else
{
    printf("You are a minor\n");
}
```

### While Loops
While loops repeat code as long as a condition is true:

```c
while (number < 10)
{
    printf("%d\n", number);
    number++;
}
```

## Exercises

The tasks in this folder include:

1. Using variables to store numbers
2. Comparing numbers with if/else
3. Creating loops that repeat until a condition changes
4. Combining variables, conditionals, and loops
5. Reading input and making decisions based on it

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

```bash
./output_name
```

## Common Mistakes to Avoid

- Forgetting the condition after while in parentheses
- Not initializing variables before using them
- Infinite loops (condition never becomes false)
- Using `=` instead of `==` in comparisons

## Tips

- Test your loops by printing values to see what happens
- Always initialize your loop counter before the loop
- Use curly braces `{}` to organize your code blocks
- Remember to increment or decrement your loop variable

Good luck!
