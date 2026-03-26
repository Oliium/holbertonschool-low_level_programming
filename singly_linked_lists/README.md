# Singly Linked Lists

## Overview

This project teaches you about singly linked lists, which are a fundamental data structure in computer science. Unlike arrays, linked lists can grow and shrink easily and don't need contiguous memory.

## What You Will Learn

- What linked lists are and how they work
- How to create a linked list node
- How to add nodes to a linked list
- How to traverse (walk through) a linked list
- How to search in a linked list
- How to delete nodes
- When to use linked lists vs arrays
- Memory management with linked lists

## Key Concepts

### What is a Linked List?

A linked list is a collection of nodes connected by pointers. Each node contains:
1. Data (the value you want to store)
2. A pointer to the next node

```
┌─────┐     ┌─────┐     ┌─────┐
│ 10  │ --> │ 20  │ --> │ 30  │ --> NULL
└─────┘     └─────┘     └─────┘
```

### Node Structure

```c
typedef struct s_node
{
    int data;              // The value
    struct s_node *next;   // Pointer to next node
} t_node;
```

### Creating and Adding Nodes

```c
t_node *create_node(int value)
{
    t_node *node = malloc(sizeof(t_node));
    node->data = value;
    node->next = NULL;
    return (node);
}

// Add at beginning
void add_to_front(t_node **head, int value)
{
    t_node *new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}
```

### Traversing a List

Walking through all nodes:

```c
void print_list(t_node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;  // Move to next node
    }
}
```

### Searching

Finding a specific node:

```c
t_node *find_node(t_node *head, int value)
{
    while (head != NULL)
    {
        if (head->data == value)
            return (head);
        head = head->next;
    }
    return (NULL);  // Not found
}
```

### Deleting Nodes

Removing a node from the list:

```c
void delete_node(t_node **head, int value)
{
    t_node *current = *head;
    t_node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == value)
        {
            if (prev == NULL)
                *head = current->next;  // Delete first node
            else
                prev->next = current->next;  // Skip this node
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
```

## Exercises

The tasks in this folder include:

1. Creating a linked list
2. Adding nodes to the beginning and end
3. Printing a linked list
4. Finding nodes
5. Deleting nodes
6. Copying lists
7. Reversing lists
8. Merging lists
9. Sorting lists
10. Advanced operations

## Linked Lists vs Arrays

### Arrays
- Fast access by index
- Fixed size (usually)
- Contiguous memory

### Linked Lists
- Slow access (must walk through)
- Can grow/shrink easily
- Non-contiguous memory

## Important Pattern: Pointer to Pointer

When you modify the head pointer (like adding to front), use pointer to pointer:

```c
// Wrong - changes local copy
void add_node(t_node *head, int value)
{
    t_node *new = create_node(value);
    new->next = head;
    head = new;  // Only changes local copy!
}

// Right - changes actual list
void add_node(t_node **head, int value)
{
    t_node *new = create_node(value);
    new->next = *head;
    *head = new;  // Changes the real head
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

## Memory Management

Always free lists when done:

```c
void free_list(t_node **head)
{
    t_node *current;

    while (*head != NULL)
    {
        current = *head;
        *head = current->next;
        free(current);
    }
}
```

## Debugging Linked Lists

- Use print_list() to visualize the structure
- Check for NULL pointers before accessing
- Make sure you're updating pointers correctly
- Watch out for infinite loops
- Use valgrind to find memory leaks

## Common Mistakes

- Forgetting to allocate memory for nodes
- Not updating pointers correctly
- Using single pointer instead of double pointer for head
- Infinite loops while traversing
- Memory leaks (not freeing nodes)
- Going past the end of the list

## Tips to Succeed

- Draw diagrams of how pointers change
- Write helper functions for common operations
- Test each function separately
- Start simple - add at beginning before adding at end
- Use print_list() to debug
- Practice with small examples first

Linked lists are powerful once you understand them!
