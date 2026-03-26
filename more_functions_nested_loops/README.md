# More Functions and Nested Loops

## Overview

This project builds on your knowledge of functions and nested loops by introducing more advanced concepts and challenging problems. You will work with more complex patterns and function combinations.

## What You Will Learn

- Advanced function techniques
- How to work with multiple functions together
- Complex nested loop patterns
- Better code organization
- How to solve complex problems step by step

## Key Concepts

### Combining Functions with Loops

You can use functions that work with loops to solve complex problems:

```c
void print_square(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
```

### Helper Functions

Break complex tasks into smaller functions:

```c
int is_prime(int n);
void print_primes(int start, int end);
```

### Multiple Nested Loops

Sometimes you need 3 or more levels of nesting:

```c
for (i = 0; i < 5; i++)
{
    for (j = 0; j < 5; j++)
    {
        for (k = 0; k < 5; k++)
        {
            // Do something
        }
    }
}
```

## Exercises

The tasks in this folder include:

1. Creating more complex functions
2. Working with multiple nested loops
3. Printing complex patterns
4. Combining different functions together
5. Solving mathematical problems
6. Creating reusable function libraries

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

```bash
./output_name
```

## Problem-Solving Tips

- Draw or write out what you want before coding
- Break big problems into smaller pieces
- Create helper functions for repeated tasks
- Test each function individually
- Use print statements to debug
- Start simple and add complexity gradually

## Optimization Tips

- Avoid unnecessary loops
- Don't repeat calculations
- Use functions to avoid code duplication
- Think about performance as you write

## Common Patterns

### Rectangle Pattern
```c
for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        printf("#");
    }
    printf("\n");
}
```

### Triangle Pattern
```c
for (int i = 1; i <= height; i++)
{
    for (int j = 1; j <= i; j++)
    {
        printf("*");
    }
    printf("\n");
}
```

Keep practicing and challenging yourself!
