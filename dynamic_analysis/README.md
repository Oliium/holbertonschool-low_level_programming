# Dynamic Analysis

## Overview

This project teaches you about dynamic analysis tools that help you understand how your program behaves while it's running. These tools can find memory leaks, buffer overflows, performance problems, and other issues that are hard to spot with just reading code.

## What You Will Learn

- What dynamic analysis is
- How to use Valgrind for memory analysis
- How to use GDB for program analysis
- How to profile programs to find slow code
- How to trace system calls
- How to detect memory leaks
- How to find buffer overflows
- Best practices for analyzing programs

## Key Concepts

### What is Dynamic Analysis?

Dynamic analysis means running your program and watching what it does. This is different from reading the code (static analysis). Dynamic analysis tools let you:
- Track memory usage
- Find memory leaks
- Detect crashes
- See what system calls are made
- Measure performance
- Understand program flow

### Valgrind - Memory Debugging

Valgrind is a powerful tool that watches your program's memory usage:

```bash
valgrind --leak-check=full ./program
```

This checks for:
- Memory leaks (allocated but never freed)
- Use-after-free bugs (using memory after freeing it)
- Out-of-bounds access
- Invalid memory access

### Output Example

```
==12345== HEAP SUMMARY:
==12345== in use at exit: 100 bytes in 1 blocks
==12345== total heap alloc+free: 200 bytes + 100 bytes
==12345== LEAK SUMMARY:
==12345== definitely lost: 100 bytes in 1 blocks
```

### GDB - Program Debugging

GDB lets you step through code and watch variables:

```bash
gcc -g program.c -o program
gdb ./program
```

### Strace - System Call Tracing

Strace shows what system calls your program makes:

```bash
strace ./program
```

## Exercises

The tasks in this folder include:

1. Analyzing simple programs with Valgrind
2. Finding memory leaks
3. Detecting buffer overflows
4. Using GDB for step-by-step analysis
5. Profiling program performance
6. Comparing program behavior before and after fixes
7. Analyzing complex programs

## Common Problems Detected

### Memory Leak
```c
void leak(void)
{
    int *ptr = malloc(sizeof(int) * 10);
    // Never freed!
}
```

Valgrind output: "definitely lost: 40 bytes"

### Use After Free
```c
int *ptr = malloc(sizeof(int));
free(ptr);
printf("%d\n", *ptr);  // Crash!
```

### Buffer Overflow
```c
char arr[10];
strcpy(arr, "This is a very long string that exceeds array size");
```

Valgrind detects this!

## Running Valgrind

Basic usage:
```bash
valgrind ./program
```

With more details:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./program
```

## Compilation Recommendations

For analysis:

```bash
gcc -Wall -Werror -Wextra -pedantic -g filename.c -o filename
```

## Tips for Using Dynamic Analysis

1. Always compile with `-g` for debugging info
2. Run Valgrind on all programs
3. Fix warnings immediately
4. Test with different inputs
5. Use GDB to understand crashes
6. Profile before optimizing
7. Keep old versions to compare

## Best Practices

1. Analyze frequently
2. Fix problems as you find them
3. Use version control
4. Test edge cases
5. Document problems and fixes
6. Share tools with team
7. Use analysis in your development workflow

## Important Commands Summary

```bash
# Compile with debugging
gcc -g -Wall program.c -o program

# Check for memory errors
valgrind ./program

# Debug step by step
gdb ./program

# Trace system calls
strace ./program
```

Dynamic analysis is essential for writing reliable C code!
