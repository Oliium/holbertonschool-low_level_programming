# Introduction to Debugging

## Overview

This project teaches you how to debug C programs. Debugging is the process of finding and fixing errors in your code. Knowing how to debug is just as important as knowing how to write code.

## What You Will Learn

- What debugging is and why it's important
- How to use `printf()` for debugging
- How to use the `gdb` debugger
- How to find bugs in your code
- How to use breakpoints
- How to step through code
- How to inspect variables
- Common debugging techniques
- Best practices for writing debuggable code

## Key Concepts

### Two Types of Problems

1. **Compile Errors**: The code doesn't compile - the compiler tells you what's wrong
2. **Runtime Errors**: The code compiles but crashes or behaves incorrectly - you have to find it

### The Debugging Process

1. Understand what the program should do
2. Run the program and observe what it actually does
3. Figure out where the problem is
4. Fix the problem
5. Test to make sure it works

## Debugging Techniques

### Technique 1: Printf Debugging

Add print statements to see what's happening:

```c
int calculate(int x, int y)
{
    printf("DEBUG: x = %d, y = %d\n", x, y);
    int result = x + y;
    printf("DEBUG: result = %d\n", result);
    return (result);
}
```

### Technique 2: Using GDB (GNU Debugger)

Compile with the `-g` flag for debugging symbols:

```bash
gcc -Wall -Werror -Wextra -pedantic -g filename.c -o filename
```

Run with gdb:

```bash
gdb ./filename
```

### Important GDB Commands

```bash
(gdb) run                    # Start running the program
(gdb) break main             # Set breakpoint at main
(gdb) break filename.c:20    # Set breakpoint at line 20
(gdb) continue               # Continue execution
(gdb) next                   # Execute next line
(gdb) step                   # Same as next (for this course)
(gdb) print variable_name    # Print a variable's value
(gdb) print &variable_name   # Print a variable's address
(gdb) list                   # Show source code
(gdb) quit                   # Exit gdb
```

### Technique 3: Valgrind (Memory Debugging)

Valgrind finds memory problems:

```bash
valgrind --leak-check=full ./filename
```

### Technique 4: Compiler Warnings

Always compile with warnings enabled:

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c
```

Address every warning!

## Common Bugs to Look For

### 1. Uninitialized Variables
```c
int x;  // What value does x have?
printf("%d\n", x);  // Garbage!
```

Fix: `int x = 0;`

### 2. Array Out of Bounds
```c
int arr[5];
arr[10] = 5;  // Accessing beyond the array!
```

### 3. Null Pointer Dereference
```c
int *ptr = NULL;
printf("%d\n", *ptr);  // Crash!
```

### 4. Memory Leaks
```c
int *ptr = malloc(100);
// Forgot to free()!
```

### 5. Off-by-One Errors
```c
for (int i = 0; i <= 10; i++)  // Should be < 10?
    arr[i] = i;  // Out of bounds when i = 10
```

### 6. Logic Errors
```c
if (x == 0)  // Should this be != ?
    printf("x is zero\n");
```

## Exercises

The tasks in this folder include:

1. Finding bugs in simple programs
2. Using printf() to debug
3. Using gdb to step through code
4. Finding memory leaks with valgrind
5. Fixing various types of bugs
6. Understanding compile warnings

## A Simple Debugging Session

```c
#include <stdio.h>

int main(void)
{
    int x = 5;
    int y = 10;
    int z;

    z = x + y;
    printf("x = %d, y = %d, z = %d\n", x, y, z);

    return (0);
}
```

Debug with gdb:
```bash
$ gcc -g debug.c -o debug
$ gdb ./debug
(gdb) break main
(gdb) run
(gdb) next
(gdb) print x
(gdb) print y
(gdb) print z
(gdb) continue
(gdb) quit
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -g filename.c -o filename
```

The `-g` flag includes debugging information.

## Running with GDB

```bash
gdb ./filename
```

## Best Practices

1. Compile with all warnings
2. Fix warnings immediately
3. Use meaningful variable names
4. Initialize variables before using them
5. Check return values from functions
6. Test with different inputs
7. Use version control so you can revert changes
8. Write clean, readable code

## Tips for Debugging

- Read error messages carefully - they tell you a lot
- Use breakpoints instead of printing everything
- Understand what the code should do first
- Change one thing at a time
- Test your fix
- Keep a log of bugs you've fixed

## Common GDB Mistakes

- Forgetting to compile with `-g`
- Not setting a breakpoint before running
- Getting lost in complex program flow
- Not understanding what printing a pointer shows
- Confusing syntax

Debugging is a skill that improves with practice!
