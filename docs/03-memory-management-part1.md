<nav>
  <a href="../docs/02-basic-language-facilities.md">← Previous: Basic Language Facilities</a> |
  <a href="../README.md">📚 Table of Contents</a> |
  <a href="../docs/04-classes-and-objects.md">Next: Classes and Objects →</a>
</nav>

---

## Memory Management Part 1

### 🔧 Programs

- C Memory Management
  - Solution: [Open project](../src/03-memory-management-part1/MemMgmtC/MemMgmtC.slnx)
  - Concepts: `malloc`, `calloc`, `realloc`, `free`, heap allocation
  - Notes:
    - `malloc` allocates uninitialized memory on the heap
    - `calloc` allocates memory and initializes it to zero
    - `realloc` resizes an existing allocation
    - `free` releases memory back to the heap
    - Allocation size must be specified manually (in bytes)
    - Functions return `NULL` on failure
    - Memory must be explicitly freed to avoid leaks

- C++ Memory Management
  - Solution: [Open project](../src/03-memory-management-part1/MemMgmtCpp/MemMgmtCpp.slnx)
  - Concepts: `new`, `delete`, arrays, exceptions
  - Notes:
    - `new` allocates memory and returns a typed pointer
    - `delete` releases memory allocated with `new`
    - `new[]` and `delete[]` are used for arrays
    - Use `delete` for single objects and `delete[]` for arrays
    - `new` can initialize objects and call constructors
    - Allocation failure throws `std::bad_alloc`
    - Memory must be released with the matching delete form

- 2D Arrays (Pointer-to-Pointer)
  - Solution: [Open project](../src/03-memory-management-part1/TwoDimArrays/TwoDimArrays.slnx)
  - Concepts: 2D arrays, pointer-to-pointer, contiguous vs non-contiguous memory
  - Notes:
    - A 2D array like `int arr[2][3]` is stored in contiguous memory
    - Elements are accessed using `arr[row][col]`
    - A dynamic 2D array using `int**` is an array of pointers to rows
    - Each row can be allocated separately and may not be contiguous
    - Access syntax is the same (`pData[row][col]`) but memory layout differs
    - Memory must be freed in reverse order of allocation (`delete[] rows`, then `delete[] pData`)

- 2D Arrays (Contiguous)
  - Solution: [Open project](../src/03-memory-management-part1/Contiguous2DArray/Contiguous2DArray.slnx)
  - Concepts: contiguous memory, linear indexing, dynamic allocation
  - Notes:
    - A 2D array can be stored in a single contiguous block of memory
    - Allocate using a 1D array of size `rows * cols`
    - Access elements using `row * cols + col`
    - Requires only one allocation and one deallocation
    - More efficient than pointer-to-pointer layouts (better cache locality)
    - Preferred approach for fixed-size 2D data
    - Unlike `int**`, memory is contiguous and not split across multiple allocations

- 2D Arrays (Vector)
  - Solution: [Open project](../src/03-memory-management-part1/Vector2DArray/Vector2DArray.slnx)
  - Concepts: `std::vector`, dynamic arrays, safe memory management
  - Notes:
    - `std::vector` manages memory automatically (RAII)
    - A 2D array can be represented as `std::vector<std::vector<T>>`
    - Provides bounds-safe access with `.at()`
    - Automatically handles allocation and deallocation
    - `std::vector<std::vector<T>>` is not stored contiguously
    - Preferred over raw pointers in modern C++

### 🧠 Memory Management

- Concepts: stack, heap, data section, dynamic allocation
- Notes:
  - Programs use different memory regions: stack, heap, and data section
  - Stack stores local variables and is managed automatically
  - Data section stores global and static variables
  - Heap is used for dynamic (runtime) allocation
  - Heap memory must be manually allocated and freed by the programmer

### 🧠 malloc vs new

- Concepts: C vs C++ allocation
- Notes:
  - `malloc` is a function; `new` is an operator
  - `malloc` requires size in bytes; `new` infers size from type
  - `malloc` returns `void*`; `new` returns typed pointer
  - `malloc` does not initialize memory; `new` can
  - `malloc` returns `NULL` on failure; `new` throws exception

### 🔗 Navigation

📚 [Table of Contents](../README.md)  
← [Previous: Basic Language Facilities](../docs/02-basic-language-facilities.md)  
→ [Next: Classes and Objects](../docs/04-classes-and-objects.md)
