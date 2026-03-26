# Hello World

## Overview

This is the first project in the C programming journey. It introduces you to the basics of C programming by creating simple programs that print messages to the console.

## What You Will Learn

- How to write your first C program
- How to use the `main()` function
- How to use `printf()` to display text
- How to compile a C program
- How to run a compiled program

## Tasks

The exercises in this folder cover:

1. Creating a simple "Hello, World!" program
2. Using printf() with different formatting
3. Understanding program structure
4. Basic compilation and execution

## Compilation

To compile a C file:

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

After compilation, run your program:

```bash
./output_name
```

## Example

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");
    return (0);
}
```

This simple program demonstrates:
- Including the stdio library for input/output
- The main() function (where programs start)
- Using printf() to print text
- Returning 0 to indicate success

## Tips

- Always include the necessary header files
- Remember to add `return (0);` at the end of main()
- Use `\n` for new lines
- Compile with all warnings enabled to catch errors early

Happy coding!
