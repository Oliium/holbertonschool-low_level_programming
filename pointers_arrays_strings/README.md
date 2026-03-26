# Pointers, Arrays, and Strings

## Overview

This project introduces three fundamental concepts in C: pointers, arrays, and strings. These are essential skills for becoming a proficient C programmer.

## What You Will Learn

- What pointers are and how they work
- How to use the `&` (address) and `*` (dereference) operators
- How arrays store multiple values
- How strings are arrays of characters
- How to manipulate strings
- The relationship between pointers and arrays
- Memory addresses and how they work

## Key Concepts

### Pointers

A pointer is a variable that stores a memory address. Think of it as an arrow pointing to a location in memory:

```c
int x = 10;
int *ptr = &x;  // ptr stores the address of x
printf("%d\n", *ptr);  // Prints 10
```

The `&` operator gives you the address (creates a pointer).
The `*` operator gets the value at that address (dereferences a pointer).

### Arrays

Arrays store multiple values of the same type:

```c
int numbers[5] = {1, 2, 3, 4, 5};
printf("%d\n", numbers[0]);  // Prints 1
printf("%d\n", numbers[2]);  // Prints 3
```

Arrays are actually pointers to the first element.

### Strings

Strings are arrays of characters that end with a null character `\0`:

```c
char name[] = "Alice";
printf("%s\n", name);  // Prints "Alice"
```

## Exercises

The tasks in this folder include:

1. Creating and using pointers
2. Printing memory addresses
3. Using arrays to store data
4. Manipulating and printing strings
5. Writing functions that work with strings
6. Understanding pointer arithmetic
7. Working with strings and pointers together

## Important Functions

- `strlen()` - Get the length of a string
- `strcpy()` - Copy a string to another location
- `strcat()` - Join two strings together
- `strcmp()` - Compare two strings

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

```bash
./output_name
```

## Pointer Rules to Remember

- `int *ptr;` declares a pointer to an int
- `&variable` gets the address of a variable
- `*pointer` gets the value at the address
- Arrays and pointers are closely related
- String indexing works just like array indexing

## Common Mistakes

- Forgetting to initialize pointers
- Using `*` and `&` in the wrong places
- Not including the null terminator in strings
- Going out of array bounds
- Forgetting that arrays start at index 0

## Tips

- Draw diagrams to understand memory layout
- Use `printf()` to print addresses and values
- Practice with small examples first
- Remember that arrays start at index 0
- Test your string functions with different inputs

This is challenging material, so take your time!
