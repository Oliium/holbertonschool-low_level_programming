# Recursion

## Overview

This project teaches you about recursion, which is when a function calls itself. Recursion is a powerful technique for solving certain types of problems, especially those that have a natural repeating structure.

## What You Will Learn

- What recursion is
- How to identify problems that can be solved with recursion
- How to write recursive functions
- Base cases and recursive cases
- The call stack and how recursion uses it
- How recursion differs from loops
- When to use recursion vs loops

## Key Concepts

### What is Recursion?

Recursion is when a function calls itself. Every recursive function needs:

1. **Base Case**: The condition that stops the recursion
2. **Recursive Case**: Where the function calls itself with a simpler problem

### Simple Example - Counting Down

```c
void countdown(int n)
{
    if (n == 0)  // Base case
    {
        printf("Done!\n");
        return;
    }
    printf("%d\n", n);
    countdown(n - 1);  // Recursive case
}
```

When you call `countdown(3)`, here's what happens:
- countdown(3) prints 3, calls countdown(2)
- countdown(2) prints 2, calls countdown(1)
- countdown(1) prints 1, calls countdown(0)
- countdown(0) prints "Done!" and stops

### Factorial Example

Factorial is often the first example of recursion:

```c
int factorial(int n)
{
    if (n == 0 || n == 1)  // Base case
        return (1);
    return (n * factorial(n - 1));  // Recursive case
}
```

## Exercises

The tasks in this folder include:

1. Understanding base cases
2. Writing simple recursive functions
3. Calculating factorials
4. Working with strings recursively
5. Solving mathematical problems with recursion
6. Comparing recursive and iterative solutions

## The Call Stack

When a function calls itself, each call is added to the call stack:

```
factorial(5) calls factorial(4)
    factorial(4) calls factorial(3)
        factorial(3) calls factorial(2)
            factorial(2) calls factorial(1)
                factorial(1) returns (because base case)
            factorial(2) returns 2 * 1 = 2
        factorial(3) returns 3 * 2 = 6
    factorial(4) returns 4 * 6 = 24
factorial(5) returns 5 * 24 = 120
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

```bash
./output_name
```

## Rules for Recursion

1. Every recursive function must have a base case
2. Each recursive call must move toward the base case
3. Avoid infinite recursion
4. Test your base case first
5. Trust that the function works for the simpler case

## When to Use Recursion

Recursion is good for:
- Tree or graph traversal
- Divide and conquer problems
- Mathematical sequences
- Processing nested structures

Loops might be better for:
- Simple counting
- Iterating through lists
- When performance is critical

## Common Mistakes

- Forgetting the base case (infinite recursion!)
- Not moving toward the base case
- Making the problem more complex instead of simpler
- Stack overflow from too many calls
- Comparing recursion to loops unfairly

## Tips to Succeed

- Always write the base case first
- Test with small numbers
- Draw diagrams of the call stack
- Print values to trace execution
- Start with simple examples
- Don't worry if recursion seems confusing at first
- Practice is the key to understanding

Remember: recursion is powerful but take time to understand it!
