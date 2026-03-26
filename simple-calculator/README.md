# Simple Calculator

## Overview

This project brings together many concepts you've learned: functions, control flow, command line arguments, and error handling. You will build a command-line calculator program that can perform basic arithmetic operations.

## What You Will Learn

- How to combine multiple concepts in one project
- How to parse command line arguments
- How to implement calculator operations
- How to handle errors gracefully
- How to validate user input
- How to structure a larger program
- Best practices for program organization

## Project Requirements

Build a calculator that:
1. Takes command line arguments
2. Performs the requested operation
3. Returns the result
4. Handles errors properly

## Example Usage

```bash
./calculator 10 + 5      # Outputs: 15
./calculator 20 - 8      # Outputs: 12
./calculator 6 '*' 7     # Outputs: 42
./calculator 100 / 4     # Outputs: 25
```

## Key Concepts

### Program Structure

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// Main program
int main(int argc, char *argv[])
{
    // Parse arguments
    // Perform calculation
    // Display result
}
```

### Command Line Parsing

```c
int main(int argc, char *argv[])
{
    // Check we have the right number of arguments
    if (argc != 4)
    {
        printf("Usage: calculator <num1> <operator> <num2>\n");
        return (1);
    }

    // Parse the arguments
    int num1 = atoi(argv[1]);
    char *operator = argv[2];
    int num2 = atoi(argv[3]);

    // Perform calculation
    int result = 0;
    if (strcmp(operator, "+") == 0)
        result = add(num1, num2);
    else if (strcmp(operator, "-") == 0)
        result = subtract(num1, num2);

    printf("%d\n", result);
    return (0);
}
```

### Operation Functions

```c
int add(int a, int b)
{
    return (a + b);
}

int subtract(int a, int b)
{
    return (a - b);
}

int multiply(int a, int b)
{
    return (a * b);
}

int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Division by zero\n");
        return (0);
    }
    return (a / b);
}
```

## Features to Implement

### Basic (Required)
1. Addition
2. Subtraction
3. Multiplication
4. Division with zero check

### Enhanced (Optional)
1. More operations (modulo, power)
2. Float support
3. Multiple operations in one call
4. Input validation
5. Better error messages

## Exercises

The tasks in this folder include:

1. Creating basic operation functions
2. Parsing command line arguments
3. Handling division by zero
4. Displaying results correctly
5. Handling invalid operators
6. Error messages and validation

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o calculator
```

## Running

```bash
./calculator num1 operator num2
```

Examples:

```bash
./calculator 15 + 7
./calculator 30 - 12
./calculator 8 '*' 9      # Note quotes around * due to shell
./calculator 20 / 4
```

## Error Handling

Important: Check for these errors:

```c
// 1. Wrong number of arguments
if (argc != 4)
{
    printf("Usage: calculator <num1> <operator> <num2>\n");
    return (1);
}

// 2. Invalid operator
if (operator is not valid)
{
    printf("Error: Unknown operator '%s'\n", argv[2]);
    return (1);
}

// 3. Division by zero
if (divisor == 0)
{
    printf("Error: Division by zero\n");
    return (1);
}
```

## Complete Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b)
{
    return (a + b);
}

int subtract(int a, int b)
{
    return (a - b);
}

int multiply(int a, int b)
{
    return (a * b);
}

int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Division by zero\n");
        return (0);
    }
    return (a / b);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <num1> <operator> <num2>\n", argv[0]);
        return (1);
    }

    int num1 = atoi(argv[1]);
    char *operator = argv[2];
    int num2 = atoi(argv[3]);
    int result;

    if (strcmp(operator, "+") == 0)
        result = add(num1, num2);
    else if (strcmp(operator, "-") == 0)
        result = subtract(num1, num2);
    else if (strcmp(operator, "*") == 0)
        result = multiply(num1, num2);
    else if (strcmp(operator, "/") == 0)
        result = divide(num1, num2);
    else
    {
        printf("Error: Unknown operator '%s'\n", operator);
        return (1);
    }

    printf("%d\n", result);
    return (0);
}
```

## Testing

Test cases:

```bash
./calculator 5 + 3      # 8
./calculator 10 - 7     # 3
./calculator 4 '*' 6    # 24
./calculator 15 / 3     # 5
./calculator 20 / 0     # Error message
```

## Tips

- Use strcmp() to compare operator strings
- Handle division by zero specially
- Remember atoi() returns strings to integers
- Shell treats * as wildcard, put it in quotes
- Test edge cases (zero, negative numbers)
- Use meaningful error messages
- Keep functions small and focused

This is a good capstone project combining several concepts!
