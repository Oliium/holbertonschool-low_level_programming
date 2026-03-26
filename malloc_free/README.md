# Malloc and Free

## Overview

This project teaches you about dynamic memory allocation. Instead of declaring a fixed-size array, you can ask the computer for memory at runtime and give it back when you are done. This is powerful but requires careful management.

## What You Will Learn

- What dynamic memory allocation is
- How to use `malloc()` to request memory
- How to use `free()` to return memory
- The difference between stack and heap memory
- Memory leaks and how to avoid them
- How to allocate memory for strings, arrays, and structures
- Best practices for memory management

## Key Concepts

### Static vs Dynamic Memory

**Static (Stack):**
```c
int arr[10];  // Size must be known at compile time
```

**Dynamic (Heap):**
```c
int *arr = malloc(10 * sizeof(int));  // Size decided at runtime
```

### Using malloc()

`malloc()` allocates memory on the heap and returns a pointer to it:

```c
int *ptr = malloc(sizeof(int));
*ptr = 42;  // Store a value
free(ptr);  // Return the memory
```

### Allocating Arrays

```c
int *arr = malloc(10 * sizeof(int));
arr[0] = 5;
arr[1] = 10;
free(arr);
```

### Allocating Strings

```c
char *str = malloc(50 * sizeof(char));
strcpy(str, "Hello");
printf("%s\n", str);
free(str);
```

## Exercises

The tasks in this folder include:

1. Basic malloc and free usage
2. Allocating memory for different data types
3. Creating and freeing arrays
4. Allocating memory for strings
5. Checking if malloc succeeded
6. Learning about memory leaks
7. Proper cleanup practices

## Important Rules

### Always Check if malloc() Succeeded
```c
int *ptr = malloc(sizeof(int));
if (ptr == NULL)
{
    printf("Memory allocation failed!\n");
    return (1);
}
```

### Always Free Memory When Done
```c
int *ptr = malloc(sizeof(int));
// Use ptr
free(ptr);
ptr = NULL;  // Good practice
```

### Size Calculations

Always use `sizeof()` to get the correct size:
```c
// Right way
int *arr = malloc(10 * sizeof(int));

// Wrong way (might not work on all systems)
int *arr = malloc(10 * 4);  // Don't do this!
```

## Memory Leaks

A memory leak happens when you allocate memory but forget to free it:

```c
// BAD - Memory leak!
if (some_condition)
{
    int *ptr = malloc(sizeof(int));
    return;  // Oops, forgot to free!
}
```

```c
// GOOD - No leak
if (some_condition)
{
    int *ptr = malloc(sizeof(int));
    free(ptr);
    return;
}
```

## Checking for Leaks with Valgrind

```bash
gcc -Wall -Werror -Wextra -pedantic -g filename.c -o output_name
valgrind --leak-check=full ./output_name
```

The `-g` flag adds debugging information. Valgrind will show you any memory leaks!

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

```bash
./output_name
```

## Common Mistakes

- Forgetting to free memory
- Freeing memory twice
- Using memory after freeing it
- Not checking if malloc() succeeded
- Using pointer before allocating memory
- Not using `sizeof()` correctly

## Tips to Succeed

- Always allocate + check + use + free
- Use valgrind to find leaks
- Free memory in the opposite order you allocated it
- Set pointers to NULL after freeing
- Test with small amounts of memory first
- Read error messages carefully

This is an important skill - memory management is critical in C!
