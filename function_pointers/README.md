# Function Pointers

## Overview

This project teaches you about function pointers, which allow you to store the address of a function and call it through a pointer. This is an advanced concept that enables powerful programming patterns like callbacks and higher-order functions.

## What You Will Learn

- What function pointers are
- How to declare a function pointer
- How to initialize a function pointer
- How to call functions through pointers
- How to pass function pointers to other functions
- How to return function pointers
- How to use function pointers in arrays
- Practical applications of function pointers

## Key Concepts

### Function Pointer Basics

A function pointer stores the address of a function:

```c
// Declare a function pointer
int (*ptr)(int, int);  // Points to a function that takes two ints and returns int

// Point it to a real function
int add(int a, int b)
{
    return (a + b);
}

ptr = add;  // Make the pointer point to the function
```

### Calling Functions Through Pointers

```c
// Method 1: Using the pointer like a function
int result = (*ptr)(5, 3);  // Result is 8

// Method 2: Simpler (automatic dereferencing)
int result = ptr(5, 3);  // Same thing, C accepts this
```

### Declaring Function Pointers

The syntax can be confusing. The key is understanding the parameters:

```c
// Function that returns int and takes (int, int)
int (*ptr)(int, int);

// Function that returns void and takes (char *)
void (*print_func)(char *);

// Function that returns int and takes nothing
int (*get_value)(void);
```

## Exercises

The tasks in this folder include:

1. Creating simple function pointers
2. Pointing to different functions
3. Calling functions through pointers
4. Arrays of function pointers
5. Passing function pointers to functions
6. Creating callback functions
7. Building function tables
8. Implementing common patterns

## Example 1: Simple Function Pointer

```c
int add(int a, int b)
{
    return (a + b);
}

int subtract(int a, int b)
{
    return (a - b);
}

int main(void)
{
    int (*operation)(int, int);

    operation = add;
    printf("%d\n", operation(10, 5));  // Prints 15

    operation = subtract;
    printf("%d\n", operation(10, 5));  // Prints 5

    return (0);
}
```

## Example 2: Function Pointers as Parameters

```c
void print_result(int (*func)(int, int), int x, int y)
{
    printf("Result: %d\n", func(x, y));
}

int multiply(int a, int b)
{
    return (a * b);
}

int main(void)
{
    print_result(multiply, 4, 5);  // Prints 20
    return (0);
}
```

## Example 3: Array of Function Pointers

```c
int add(int a, int b) { return (a + b); }
int subtract(int a, int b) { return (a - b); }
int multiply(int a, int b) { return (a * b); }
int divide(int a, int b) { return (a / b); }

int main(void)
{
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};

    printf("%d\n", operations[0](10, 5));  // 15 (add)
    printf("%d\n", operations[1](10, 5));  // 5 (subtract)
    printf("%d\n", operations[2](10, 5));  // 50 (multiply)
    printf("%d\n", operations[3](10, 5));  // 2 (divide)

    return (0);
}
```

## Real-World Usage: Sorting

Function pointers enable flexible sorting:

```c
// Sort with custom comparison function
typedef int (*compare_t)(int, int);

void sort_array(int *arr, int size, compare_t compare)
{
    // Sorting logic using compare function
}

int ascending(int a, int b)
{
    return (a - b);
}

int descending(int a, int b)
{
    return (b - a);
}

int main(void)
{
    int arr[] = {3, 1, 4, 1, 5};
    sort_array(arr, 5, ascending);   // Sorts ascending
    sort_array(arr, 5, descending);  // Sorts descending
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

## Advantages of Function Pointers

1. **Flexibility**: Choose which function to call at runtime
2. **Callbacks**: Pass functions to be called later
3. **Callbacks**: Event handling
4. **Tables**: Store multiple functions in arrays
5. **Mapping**: Implement multiple operations uniformly

## Common Patterns

### Pattern 1: Callback Functions
```c
void process_data(int *data, int size, void (*callback)(int))
{
    for (int i = 0; i < size; i++)
        callback(data[i]);  // Call the callback
}
```

### Pattern 2: Function Table
```c
struct operation
{
    char symbol;
    int (*func)(int, int);
};
```

### Pattern 3: Optional Operations
```c
void validate(int value, int (*validator)(int))
{
    if (validator != NULL && validator(value))
        printf("Valid!\n");
}
```

## Typedef for Cleaner Code

Using typedef makes function pointer declarations cleaner:

```c
typedef int (*operation_t)(int, int);

operation_t ptr = add;
int result = ptr(5, 3);
```

## Tips to Succeed

- Start with simple examples
- Draw what each pointer points to
- Use typedef for cleaner code
- Remember the syntax: `return_type (*pointer_name)(param1_type, ...)`
- Test each function individually first
- Use function pointers to reduce code duplication

## Common Mistakes

- Confusing the declaration syntax
- Forgetting to dereference the pointer when calling
- Using NULL pointers without checking
- Mismatched function signatures
- Not understanding the order of operations

## Debugging

```c
// Print function pointer value
printf("Function pointer: %p\n", (void *)ptr);

// Check if pointer is NULL
if (ptr != NULL)
    ptr();

// Make sure signatures match!
```

Function pointers are powerful but take practice!
