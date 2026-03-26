# Benchmarking

## Overview

This project teaches you how to measure and compare the performance of your programs. Benchmarking is the process of measuring how fast your code runs. This helps you identify slow parts and make them faster.

## What You Will Learn

- What benchmarking is and why it matters
- How to measure program execution time
- How to use system tools to measure performance
- How to compare different implementations
- How to identify bottlenecks
- How to optimize code based on measurements
- Best practices for benchmarking
- How to avoid misleading measurements

## Key Concepts

### What is Benchmarking?

Benchmarking is measuring performance. Questions it answers:
- How fast does my program run?
- Which version is faster?
- Where is my program spending time?
- What's the slowest part?

### Time Measurement

There are different types of time:
1. **Elapsed Time**: How long the program took (wall clock)
2. **CPU Time**: How much processor time was used
3. **System Time**: Time spent in the kernel
4. **User Time**: Time spent in your code

### Using `time` Command

```bash
time ./program
```

Output:
```
real    0m0.123s   # Total elapsed time
user    0m0.110s   # CPU time used
sys     0m0.013s   # System time used
```

### Measuring in C Code

Using `clock()`:

```c
#include <time.h>

clock_t start = clock();
// Code to measure
clock_t end = clock();
double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
printf("Time: %f seconds\n", elapsed);
```

Using `gettimeofday()`:

```c
#include <sys/time.h>

struct timeval start, end;
gettimeofday(&start, NULL);
// Code to measure
gettimeofday(&end, NULL);
long elapsed = (end.tv_sec - start.tv_sec) * 1000 +
               (end.tv_usec - start.tv_usec) / 1000;
printf("Time: %ld milliseconds\n", elapsed);
```

## Exercises

The tasks in this folder include:

1. Measuring program execution time
2. Comparing different implementations
3. Finding bottlenecks
4. Optimizing code
5. Measuring memory usage
6. Creating benchmark programs
7. Comparing algorithms

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -O2 filename.c -o filename
```

Note: `-O2` enables optimizations. For fair comparison, use the same optimization level for all versions.

## Using GProf for Profiling

Compile with profiling:

```bash
gcc -pg program.c -o program
./program
gprof program gmon.out
```

Output shows which functions take the most time.

## Best Practices

### 1. Warm Up

Run code before measuring (CPU cache effects):

```c
// Warm up
for (int j = 0; j < 10; j++)
    function_to_test();

// Now measure
clock_t start = clock();
for (int j = 0; j < 1000; j++)
    function_to_test();
clock_t end = clock();
```

### 2. Measure Multiple Times

```c
double total = 0;
for (int run = 0; run < 5; run++)
{
    clock_t start = clock();
    // Run your code
    clock_t end = clock();
    total += (double)(end - start) / CLOCKS_PER_SEC;
}
double average = total / 5;
printf("Average: %f seconds\n", average);
```

### 3. Use Large Input Sizes

Small measurements are unreliable:

```c
// Too small - measurement error significant
for (int i = 0; i < 10; i++)  // Bad
    do_something();

// Better
for (int i = 0; i < 1000000; i++)  // Good
    do_something();
```

## Common Mistakes

- Measuring too-small operations
- Not considering compiler optimizations
- Comparing different optimization levels
- Measuring including I/O
- Running once (results vary)
- Using wrong time measurement
- Comparing on different systems

## Tips for Success

- Measure before optimizing
- Profile to find real bottlenecks
- Don't optimize prematurely
- Keep benchmarks in version control
- Document why you optimized something
- Test that optimization didn't break correctness

Benchmarking helps you write faster programs!
