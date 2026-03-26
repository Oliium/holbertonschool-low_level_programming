# Argc and Argv

## Overview

This project teaches you how to use command line arguments in your programs. Instead of hard-coding values, you can pass them to your program when you run it. `argc` and `argv` are how you access these arguments.

## What You Will Learn

- What command line arguments are
- How `argc` (argument count) works
- How `argv` (argument vector) works
- How to read and process command line arguments
- How to convert strings to other data types
- Error handling for invalid arguments
- Building programs that accept user input from the command line

## Key Concepts

### argc and argv

When you run a program, the operating system passes information to main():

```c
int main(int argc, char *argv[])
```

- **argc**: The number of arguments (including the program name)
- **argv**: An array of strings containing the arguments

### Example

If you run: `./program hello 42 world`

Then:
- `argc = 4`
- `argv[0] = "./program"` (the program name)
- `argv[1] = "hello"`
- `argv[2] = "42"`
- `argv[3] = "world"`

### Using Arguments

```c
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <name>\n", argv[0]);
        return (1);
    }

    printf("Hello, %s!\n", argv[1]);
    return (0);
}
```

Run with: `./program Alice`
Output: `Hello, Alice!`

### Converting Strings to Numbers

Arguments are always strings, so you need to convert them:

```c
#include <stdlib.h>

char *str = argv[1];
int num = atoi(str);        // String to integer
float fnum = atof(str);     // String to float
```

## Exercises

The tasks in this folder include:

1. Printing all arguments
2. Checking the number of arguments
3. Converting string arguments to numbers
4. Using arguments in calculations
5. Creating programs that behave differently based on arguments
6. Building simple command-line tools

## Example Programs

### Program 1: Echo Arguments
```c
int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return (0);
}
```

### Program 2: Add Two Numbers
```c
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return (1);
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("Sum: %d\n", a + b);
    return (0);
}
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

```bash
./output_name arg1 arg2 arg3
```

## Important Functions

- `atoi()` - Convert string to integer
- `atof()` - Convert string to float
- `strtol()` - More robust integer conversion
- `strcmp()` - Compare strings
- `strlen()` - Get string length

## Error Checking

Always check `argc` before accessing `argv`:

```c
if (argc < 2)
{
    printf("Error: Not enough arguments\n");
    return (1);
}
if (argc > 2)
{
    printf("Error: Too many arguments\n");
    return (1);
}
```

## Tips

- Always check argc before using arguments
- Remember that argv[0] is the program name
- String arguments need conversion for math
- Provide helpful error messages when arguments are wrong
- Test with different inputs
- Use argc to make programs flexible

## Common Mistakes

- Forgetting that argv is strings, not numbers
- Not checking argc before accessing argv
- Forgetting that argv[0] is the program name
- Not converting strings to numbers when needed
- Confusing the parameter order

This is an important skill for creating useful command-line programs!
