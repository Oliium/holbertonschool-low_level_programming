# Functions and Nested Loops

## Overview

This project teaches you how to create and use functions, and how to use loops inside other loops. Functions help you organize code and avoid repetition.

## What You Will Learn

- How to create and call functions
- How functions can return values
- How functions can accept parameters
- How to use nested loops (loops inside loops)
- How to organize code with functions
- The importance of code reusability

## Key Concepts

### Functions
A function is a block of code that performs a specific task. Functions help you:
- Organize your code
- Avoid writing the same code multiple times
- Make programs easier to understand

### Function Structure

```c
return_type function_name(parameters)
{
    // Code here
    return (value);
}
```

### Example Function

```c
int add_numbers(int a, int b)
{
    return (a + b);
}
```

### Nested Loops
Nested loops are loops inside other loops. They are useful for working with 2D patterns or tables:

```c
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("*");
    }
    printf("\n");
}
```

This creates a 3x3 grid of asterisks.

## Exercises

The tasks in this folder include:

1. Creating simple functions
2. Functions that do calculations
3. Functions that print patterns
4. Using nested loops to create shapes
5. Combining functions with loops

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

```bash
./output_name
```

## Tips for Success

- Plan your functions before writing them
- Give functions clear, descriptive names
- Use parameters instead of global variables
- Test each function separately to make sure it works
- Start with simple nested loops before trying complex ones
- Print debug information to understand what is happening

## Common Mistakes

- Forgetting to return a value from a function
- Using wrong parameter types
- Forgetting loop incrementers (infinite loops)
- Using too many nested loops (hard to understand)

Keep practicing!
