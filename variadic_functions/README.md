# Variadic Functions

## Overview

This project teaches you how to create functions that accept a variable number of arguments. Variadic functions are functions that can take a different number of parameters each time they are called. The `printf()` function is a famous example!

## What You Will Learn

- What variadic functions are
- How to use `<stdarg.h>` for variadic functions
- How to use `va_list`, `va_start()`, `va_arg()`, and `va_end()`
- How to create your own variadic functions
- When and why to use variadic functions
- How printf() works internally
- Best practices for variadic functions

## Key Concepts

### Why Variadic Functions?

Sometimes you want a function to accept different numbers of arguments:

```c
// Same function, different calls
add(1, 2);           // Add 2 numbers
add(1, 2, 3);        // Add 3 numbers
add(1, 2, 3, 4, 5);  // Add 5 numbers
```

### Using `<stdarg.h>`

C provides tools in `<stdarg.h>` to handle this:

```c
#include <stdarg.h>

int sum_numbers(int count, ...)
{
    va_list args;
    int total = 0;

    va_start(args, count);      // Start reading arguments
    for (int i = 0; i < count; i++)
    {
        total += va_arg(args, int);  // Get next integer
    }
    va_end(args);               // Clean up

    return (total);
}
```

### How It Works

The `. . .` (ellipsis) in the function signature means "accept more arguments":

```c
int my_function(int first, ...)  // first, then any number of other args
int printf(const char *format, ...) // We know printf uses this
```

The functions in `<stdarg.h>`:
- `va_list args` - A way to access the extra arguments
- `va_start(args, last_named_arg)` - Initialize the argument list
- `va_arg(args, type)` - Get the next argument of given type
- `va_end(args)` - Clean up (important!)

## Exercises

The tasks in this folder include:

1. Creating simple variadic functions
2. Using va_list, va_start, va_arg, va_end
3. Creating a custom printf() function
4. Working with different data types
5. Error handling in variadic functions
6. Understanding how printf() works

## Example 1: Simple Sum Function

```c
#include <stdio.h>
#include <stdarg.h>

int sum(int num_args, ...)
{
    va_list args;
    int total = 0;

    va_start(args, num_args);
    for (int i = 0; i < num_args; i++)
    {
        total += va_arg(args, int);
    }
    va_end(args);

    return (total);
}

int main(void)
{
    printf("%d\n", sum(3, 10, 20, 30));  // Outputs 60
    printf("%d\n", sum(5, 1, 2, 3, 4, 5));  // Outputs 15
    return (0);
}
```

## Example 2: Custom Printf

```c
#include <stdio.h>
#include <stdarg.h>

void my_print(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'd')
        {
            printf("%d", va_arg(args, int));
            format += 2;
        }
        else if (*format == '%' && *(format + 1) == 's')
        {
            printf("%s", va_arg(args, char *));
            format += 2;
        }
        else
        {
            printf("%c", *format);
            format++;
        }
    }
    va_end(args);
}
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

```bash
./output_name
```

## Important Rules

### Always Match Types
```c
// va_arg must match what you passed
int num = va_arg(args, int);      // For integer argument
char *str = va_arg(args, char *); // For string argument
```

### Always Call va_end()
```c
va_list args;
va_start(args, last_param);
// Use args...
va_end(args);  // Important! Cleans up
```

### You Need a Way to Know When to Stop

Usually you either:
- Pass a count (like printf with format string)
- Use a special ending value (like NULL)
- Use a format string to determine types

## Common Patterns

### Pattern 1: Count Based
```c
void print_nums(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
        printf("%d ", va_arg(args, int));
    va_end(args);
}
```

### Pattern 2: Sentinel Based
```c
void print_strings(const char *first, ...)
{
    va_list args;
    const char *str = first;

    va_start(args, first);
    while (str != NULL)
    {
        printf("%s\n", str);
        str = va_arg(args, const char *);
    }
    va_end(args);
}
```

## Tips to Succeed

- Start with simple examples
- Test with different numbers of arguments
- Use the format string approach like printf does
- Always remember va_end()
- Understand that va_arg can mess up if you use wrong types
- Debug by printing what you read

## Common Mistakes

- Forgetting to call va_end()
- Using wrong types with va_arg()
- No way to know when arguments end
- Trying to get more arguments than exist
- Not initializing va_list with va_start()

This is advanced but powerful!
