# More Malloc and Free

## Overview

This project builds on memory management by teaching you how to allocate memory for more complex data structures. You will learn about 2D arrays, structures, and deallocating complex memory layouts.

## What You Will Learn

- How to allocate memory for 2D arrays
- How to allocate memory for structures
- How to work with arrays of structures
- How to properly free complex data structures
- Memory alignment and efficiency
- Reallocating memory
- Working with multidimensional arrays

## Key Concepts

### 2D Arrays with malloc()

A 2D array is an array of arrays. You need to allocate memory for both the rows and the columns:

```c
// Method 1: Array of pointers
int **arr = malloc(3 * sizeof(int *));
for (int i = 0; i < 3; i++)
    arr[i] = malloc(4 * sizeof(int));

// Use it like normal
arr[0][0] = 5;
arr[2][3] = 10;

// Free it
for (int i = 0; i < 3; i++)
    free(arr[i]);
free(arr);
```

### Structures with malloc()

You can allocate memory for structures:

```c
typedef struct
{
    char name[50];
    int age;
} Person;

Person *p = malloc(sizeof(Person));
strcpy(p->name, "Alice");
p->age = 25;
free(p);
```

### Arrays of Structures

```c
Person *people = malloc(10 * sizeof(Person));
people[0].age = 30;
strcpy(people[0].name, "Bob");
free(people);
```

### Using realloc()

`realloc()` lets you resize memory you already allocated:

```c
int *arr = malloc(5 * sizeof(int));
arr = realloc(arr, 10 * sizeof(int));  // Now bigger
free(arr);
```

## Exercises

The tasks in this folder include:

1. Allocating 2D arrays
2. Allocating arrays of structures
3. Using realloc() to resize memory
4. Properly freeing complex structures
5. Creating data structure collections
6. Managing memory efficiently

## Importance of Order

Always free memory in reverse order of allocation:

```c
// Allocate in this order
int **matrix = malloc(rows * sizeof(int *));
for (i = 0; i < rows; i++)
    matrix[i] = malloc(cols * sizeof(int));

// Free in this order (opposite)
for (i = 0; i < rows; i++)
    free(matrix[i]);  // Free rows first
free(matrix);         // Then free the main pointer
```

## Memory Alignment

The computer sometimes needs memory at certain addresses. Use `sizeof()` to be safe:

```c
// Safe way
struct Data *arr = malloc(count * sizeof(struct Data));

// Potentially unsafe
struct Data *arr = malloc(count * 20);  // Don't guess sizes
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

```bash
./output_name
```

## Using Valgrind for Complex Programs

```bash
valgrind --leak-check=full --show-leak-kinds=all ./output_name
```

This will show you all memory leaks in detail.

## Common Mistakes

- Freeing in the wrong order
- Forgetting to free intermediate pointers in 2D arrays
- Not allocating enough space
- Using the wrong sizeof()
- Accessing freed memory
- Memory leaks in nested structures

## Debugging Tips

- Draw a diagram of your memory layout
- Use print statements to track allocation/freeing
- Run valgrind frequently
- Test with small data first
- Check all return values from malloc()

## Example: Student Database

```c
typedef struct
{
    char name[50];
    int *grades;
    int grade_count;
} Student;

Student *create_student(char *name, int num_grades)
{
    Student *s = malloc(sizeof(Student));
    strcpy(s->name, name);
    s->grades = malloc(num_grades * sizeof(int));
    s->grade_count = num_grades;
    return (s);
}

void free_student(Student *s)
{
    free(s->grades);
    free(s);
}
```

Memory management is complex but essential. Keep practicing!
