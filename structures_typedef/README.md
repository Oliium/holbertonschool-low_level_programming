# Structures and Typedef

## Overview

This project teaches you how to create custom data types in C using structures and typedef. Structures let you group related data together, and typedef lets you give them convenient names.

## What You Will Learn

- What structures are and why they are useful
- How to define a structure
- How to use typedef to create type aliases
- How to access structure members
- How to pass structures to functions
- Nested structures
- Structures with pointers
- How structures differ from arrays

## Key Concepts

### Basic Structures

A structure groups related data:

```c
struct person
{
    char name[50];
    int age;
    float height;
};
```

This creates a new data type that can store a person's information.

### Using Typedef

Typedef makes the code cleaner:

```c
typedef struct
{
    char name[50];
    int age;
    float height;
} Person;

// Now you can use Person instead of struct person
Person p1;
```

### Accessing Members

Use the dot operator (`.`) to access members:

```c
Person p1;
p1.age = 25;
strcpy(p1.name, "Alice");
printf("%s is %d years old\n", p1.name, p1.age);
```

### Pointers to Structures

When you have a pointer, use `->` instead of `.`:

```c
Person *p = malloc(sizeof(Person));
p->age = 30;              // With pointer
strcpy(p->name, "Bob");
free(p);
```

### Initializing Structures

```c
// Method 1: Field by field
Person p1;
p1.age = 25;
strcpy(p1.name, "Charlie");

// Method 2: All at once
Person p2 = {"Diana", 28, 1.70};

// Method 3: Named initialization
Person p3 = {
    .name = "Eve",
    .age = 26,
    .height = 1.65
};
```

## Exercises

The tasks in this folder include:

1. Defining simple structures
2. Creating and initializing structures
3. Passing structures to functions
4. Creating arrays of structures
5. Nested structures (structure in structure)
6. Structures containing pointers
7. Using typedef for cleaner code
8. Creating structure functions

## Example: Student Structure

```c
typedef struct
{
    char name[100];
    int id;
    float gpa;
} Student;

void print_student(Student s)
{
    printf("Name: %s\n", s.name);
    printf("ID: %d\n", s.id);
    printf("GPA: %.2f\n", s.gpa);
}

int main(void)
{
    Student s1 = {"Alice", 123, 3.8};
    print_student(s1);
    return (0);
}
```

## Structures vs Arrays

### Structures
- Mix different data types
- Give names to members
- Logical grouping of related data
- Clearer code

### Arrays
- All same data type
- Access by index
- Good for lists of similar items

## Nested Structures

Structures can contain other structures:

```c
typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char name[50];
    Date birth_date;
    float salary;
} Employee;

// Access nested members
Employee e1;
e1.birth_date.year = 1990;
```

## Passing Structures to Functions

### By Value (Copy)
```c
void modify_student(Student s)  // Receives a copy
{
    s.gpa = 4.0;  // Only changes the copy
}
```

### By Pointer (Reference)
```c
void modify_student(Student *s)  // Receives a pointer
{
    s->gpa = 4.0;  // Changes the original
}
```

If a structure is large, pass by pointer to save memory!

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic filename.c -o output_name
```

## Running

```bash
./output_name
```

## Memory Layout

Structures take memory for all members:

```c
struct data
{
    char c;     // 1 byte
    int i;      // 4 bytes
    char c2;    // 1 byte
};
// Total: 8 or more bytes (due to alignment)
```

Sometimes the computer adds padding for alignment.

## Tips

- Keep structures organized and logical
- Use typedef for cleaner code
- Pass large structures by pointer
- Initialize all members
- Use meaningful names for structures and members
- Consider using nested structures for complex data
- Document what each member means

## Common Mistakes

- Confusing `.` and `->`
- Forgetting to include the semicolon after structure definition
- Not initializing structure members
- Using wrong sizeof() calculations
- Passing structures by value when they're large
- Memory leaks with structures containing pointers

## Example: Complete Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char title[100];
    char author[100];
    int year;
} Book;

Book *create_book(char *title, char *author, int year)
{
    Book *b = malloc(sizeof(Book));
    strcpy(b->title, title);
    strcpy(b->author, author);
    b->year = year;
    return (b);
}

void print_book(Book *b)
{
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Year: %d\n", b->year);
}

int main(void)
{
    Book *b = create_book("C Programming", "K&R", 1978);
    print_book(b);
    free(b);
    return (0);
}
```

Structures are powerful tools for organizing data!
