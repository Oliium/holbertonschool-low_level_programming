# Memory Maps: stack_example, heap_example, aliasing_example, crash_example

## Scope and method

- Source files analyzed from `programs/`: `stack_example.c`, `heap_example.c`, `aliasing_example.c`, `crash_example.c`.
- Build intent is from `programs/Makefile` (`-Wall -Wextra -Werror -pedantic -std=gnu89 -g`).
- On this machine, `make` is unavailable, so builds were executed with equivalent `gcc` commands.
- `aliasing_example.c` intentionally contains use-after-free; on this compiler that warning becomes an error under `-Werror`, so runtime observation used `-Wno-error=use-after-free` only for that file.

The maps below are based on real execution output (normal runs, no Valgrind) and then corrected where common AI assumptions are wrong.

---

## 1) `stack_example.c` (recursion + stack frames)

### Key memory-changing points

1. `main` enters and calls `walk_stack(0, 3)`.
2. Each `walk_stack(depth, max_depth)` call creates a new stack frame with local `marker`.
3. Each call to `dump_frame(label, depth)` creates another frame with locals:
	 - `local_int`
	 - `local_buf[16]`
	 - `p_local` (points to `local_int` in the same frame)
4. Recursive call grows stack until depth 3.
5. Returns unwind in reverse order; each frame dies at function return.

### Concrete map at deepest point (inside `dump_frame("enter", 3)`)

```
Higher addresses

[walk_stack depth=0 frame]
	marker = 0

[walk_stack depth=1 frame]
	marker = 10

[walk_stack depth=2 frame]
	marker = 20

[walk_stack depth=3 frame]
	marker = 30

[dump_frame label="enter", depth=3 frame]
	local_int = 103
	p_local  -> &local_int (same frame)
	local_buf[0] = 'D'

Lower addresses
```

Observed addresses decrease with deeper calls (example run), consistent with downward-growing stack on this platform.

### Lifetime rules (explicit)

- `marker` exists only during its specific `walk_stack` invocation.
- `local_int`, `local_buf`, `p_local` exist only during each specific `dump_frame` invocation.
- `p_local` is valid only while that `dump_frame` frame exists; after return, it would be dangling if leaked/stored.
- No heap allocation in this program.

### Aliasing

- `p_local` aliases exactly one object: `local_int` in the same frame.
- Different recursion depths have different `local_int` objects; same variable name, different storage instances.

---

## 2) `heap_example.c` (heap ownership and leak)

### Key memory-changing points

1. `alice = person_new("Alice", 30)`:
	 - allocates `Person` object on heap
	 - allocates `name` buffer on heap
	 - initializes fields
2. `bob = person_new("Bob", 41)` does the same.
3. `free(bob->name); free(bob);` fully releases Bob object graph.
4. `person_free_partial(alice)` frees only `alice` struct, not `alice->name`.

### Object graph after both successful allocations

```
Stack (main frame):
	alice ----+
						|
						v
Heap:   [Person A]
					name -----> ["Alice\0" buffer]
					age  = 30

Stack (main frame):
	bob ------+
						|
						v
Heap:   [Person B]
					name -----> ["Bob\0" buffer]
					age  = 41
```

### End-state after frees in `main`

1. `bob->name` freed -> `bob->name` becomes invalid (pointer value in freed `bob` object is irrelevant after next free).
2. `bob` freed -> no reachable Bob memory.
3. `alice` freed by `person_free_partial(alice)` -> struct gone.
4. `alice->name` was never freed -> leaked block remains allocated until process exit.

### Lifetime rules (explicit)

- `alice` and `bob` (stack pointer variables) die at end of `main`.
- Heap `Person` objects live from successful `malloc` until `free`.
- Heap name buffers live independently from their owner pointers; freeing `Person` does not free `name` automatically.

### Aliasing

- No intentional aliasing between `alice` and `bob`.
- Each `Person.name` points to a distinct heap buffer.

---

## 3) `aliasing_example.c` (alias + use-after-free)

### Key memory-changing points

1. `a = make_numbers(n)` allocates heap array of 5 `int`.
2. `b = a` creates alias: both pointers refer to same heap block.
3. `free(a)` releases that single heap block.
4. `b` still holds same numeric address, but now points to non-owned/non-live memory (dangling).
5. Reads/writes through `b` are undefined behavior.

### Map before free

```
Stack (main):
	a ----+
				|
	b ----+-----> Heap block H (5 ints)
									 [0, 11, 22, 33, 44]
```

### Map after `free(a)`

```
Stack (main):
	a = stale pointer value (not NULL)
	b = same stale pointer value

Heap:
	Block H is deallocated; allocator may reuse/overwrite it.
```

### What runtime showed

- Before free: `a[2]` and `b[2]` both `22`.
- After free: reading `b[2]` printed a garbage integer (`278149402` in this run).
- Writing `b[3] = 1234` appeared to succeed, but is still undefined behavior.

### Lifetime rules (explicit)

- The array lifetime ends exactly at `free(a)`.
- Pointer variable lifetime (`a`, `b`) is independent from pointee lifetime; pointers can outlive what they point to.

### Aliasing

- `a` and `b` are aliases before free.
- After free, both are dangling aliases to the same dead allocation.

---

## 4) `crash_example.c` (NULL dereference)

### Key memory-changing points

1. `n = 0` in `main`.
2. `nums = allocate_numbers(n)` returns `NULL` immediately (because `n <= 0`).
3. `nums[0] = 42` dereferences NULL and causes segmentation fault.

### Map right before crash

```
Stack (main):
	n = 0
	nums = NULL

Heap:
	no allocation from allocate_numbers for this path
```

### Lifetime rules (explicit)

- No heap object exists for `nums` in this execution path.
- `nums` is a valid stack variable, but its value is NULL; dereference is invalid.

### Aliasing

- No aliasing involved; fault is direct NULL dereference.

---

## AI-generated explanation audit (required correction example)

### Incorrect/misleading AI claim

> "After `free(a)`, pointer `b` points to a memory region that still belongs to the program until it is reused, so reading it may be safe for a while."

### Why this is wrong

- In C, once `free` is called, that object lifetime has ended immediately.
- Any access through `b` is undefined behavior at once, regardless of whether the bytes appear unchanged.
- Apparent success is not evidence of validity; it is a property of undefined behavior.

### Corrected statement

- After `free(a)`, both `a` and `b` are dangling pointers to a non-live object.
- Reads/writes (`b[2]`, `b[3]=1234`) are invalid operations even if they print plausible data or do not crash.

---

## Final mental model checkpoints

1. Stack object lifetime is bounded by block/function execution.
2. Heap object lifetime is bounded by successful allocation and explicit `free`.
3. Pointer value lifetime and pointee lifetime are separate concepts.
4. Aliasing means one free can invalidate multiple pointers.
5. "Did not crash" is not proof of memory correctness.
