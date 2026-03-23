# Valgrind Analysis

## 1) stack_example.c

**Result**: No errors. Valgrind: "All heap blocks were freed -- no leaks are possible."

**Analysis**: Stack frames allocate and deallocate correctly on function entry/exit. No dangling pointers, no aliasing. All memory properly managed.

---

## 2) heap_example.c

**Result**: 1 memory leak (6 bytes, definitely lost).

**Error location**: `person_new()` line 21 allocates `p->name`, but `person_free_partial()` only frees `p`, not `p->name`.

**Memory object**: 6-byte string buffer "Alice\0" allocated on heap.

**Lifetime violation**: 
- `alice` points to a `Person` struct (allocated).
- `alice->name` points to a separate 6-byte heap block.
- `person_free_partial(alice)` calls `free(p)`, which frees only the struct.
- `p->name` (the string) is never freed → **leak due to missing free()**.
- After `free(p)`, pointer `alice` is dangling, so `alice->name` becomes unreachable.

**Why**: Incomplete deallocation. The owner freed the container but not the contained object. Pointer ownership is not automatically cascading.

---

## 3) aliasing_example.c

**Result**: 3 use-after-free errors (at lines 42, 44, 45).

**Memory object**: 20-byte heap array of 5 ints, allocated at line 12 in `make_numbers(5)`.

**Aliases**: 
```c
a = make_numbers(n);  // line 30
b = a;                 // line 33 (same pointer)
```

**Lifetime violation sequence**:
- Line 38: `free(a)` → block at 0x4a75080 is deallocated.
- Line 42: `b[2]` reads offset 8 → Valgrind: "Address 0x4a75088 is 8 bytes inside a block of size 20 free'd."
- Line 44: `b[3] = 1234` writes offset 12 → same violation.
- Line 45: `b[3]` reads offset 12 → same violation.

**Why**: After `free(a)`, the entire block is deallocated. Both pointers `a` and `b` are now dangling. Any access through `b` is use-after-free. The offset being "within bounds" (8 < 20) is irrelevant—the block no longer exists.

---

## 4) crash_example.c

**Result**: 1 invalid write (NULL dereference) at line 32, causes segmentation fault.

**Memory object**: None (NULL = 0x0, unmapped).

**Lifetime violation**:
```c
int n = 0;
nums = allocate_numbers(0);  // returns NULL because n <= 0
nums[0] = 42;                 // dereference NULL → invalid write
```

**Why**: `allocate_numbers(0)` explicitly returns NULL. Writing to NULL is undefined behavior. Not a memory leak—an unrecoverable logic error.

---

## AI-generated explanation audit

### Incorrect AI claim

> "The offset being within bounds (offset 8 < size 20) suggests the access might eventually be safe if the block gets reallocated and reinitialized before the access."

### Why this is wrong

- Once `free(a)` is called, the block's lifetime ends **immediately**.
- Offset calculation is independent from lifetime. A valid offset into a freed block is still a use-after-free violation.
- "Within bounds" only matters if the block is still alive. After free, boundary checks are irrelevant.

### Correct interpretation

All three errors in `aliasing_example` are identical violations: use-after-free via aliasing. The offsets (8, 12) don't change the classification—they're just the specific memory addresses accessed, not evidence of safety.

---

## Summary

| Program | Error | Count | Cause |
|---------|-------|-------|-------|
| `stack_example` | None | 0 | Correct stack unwinding |
| `heap_example` | Leak | 1 | Missing `free()` for `alice->name` |
| `aliasing_example` | Use-after-free | 3 | `free(a)` invalidates alias `b`; three subsequent accesses |
| `crash_example` | NULL dereference | 1 | `nums = allocate_numbers(0)` returns NULL |

---

## Key takeaways

1. **Lifetime ends at `free()`**, not when the memory gets reallocated.
2. **One `free()` invalidates all aliases** to the same block.
3. **Offset validation is orthogonal to lifetime validation**—both must pass.
4. **Valgrind reports concrete violations**, not abstract patterns.
