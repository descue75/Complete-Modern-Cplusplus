<nav>
  <a href="../README.md">📚 Table of Contents</a> |
  <a href="../docs/03-memory-management-part1.md">Next: Memory Management Part 1 →</a>
</nav>

---

## Basic Language Facilities

### 🔧 Programs

- First Program
  - Solution: [Open project](../src/02-basic-language-facilities/FirstProgram/FirstProgram.slnx)
  - Concepts: `main()`, compilation, basic I/O
  - Notes:
    - Entry point is `main()`

- Types
  - Solution: [Open project](../src/02-basic-language-facilities/Types/Types.slnx)
  - Concepts: scalars, vectors, initialization
  - Notes:
    - Value initialization: `T obj{}` (C++11)
    - Direct initialization with braces: `T obj{v}` (C++11)
    - Copy initialization: `T obj = v`
    - Prefer brace/uniform initialization in modern C++ (C++11)
    - Brace initialization prevents narrowing conversions (C++11)
    - Provides consistent syntax across built-in and user-defined types (C++11)
    - Avoid copy initialization with user-defined objects when possible

- Basic I/O
  - Solution: [Open project](../src/02-basic-language-facilities/BasicIO/BasicIO.slnx)
  - Concepts: `std::cin`, `std::cout`, `std::getline`, input buffer
  - Notes:
    - `std::cin >>` stops at whitespace
    - `std::getline()` reads a full line
    - Use `std::cin.ignore()` before `getline()` when mixing input methods

- Functions
  - Solution: [Open project](../src/02-basic-language-facilities/Functions/Functions.slnx)
  - Concepts: declaration vs definition, header files, compilation order
  - Notes:
    - Functions must be declared before they are used
    - Header files (`.h`) contain declarations shared across source files
    - `#pragma once` prevents multiple inclusion of the same header
    - Source files (`.cpp`) contain function definitions
    - A function defined above its usage does not need a separate declaration (`Print()`)
    - `Add()` requires a declaration from `math.h` because it is defined in another file

- Pointers
  - Solution: [Open project](../src/02-basic-language-facilities/Pointers/Pointers.slnx)
  - Concepts: address-of, dereference, typed pointers, `void*`, `nullptr`
  - Notes:
    - `&x` gets the memory address of an object
    - `T* ptr` stores the address of an object of type `T`
    - `*ptr` accesses or modifies the value being pointed to
    - Pointer types must match the object type
    - `void*` can store the address of any object type but cannot be dereferenced directly
    - Uninitialized pointers contain garbage and must not be used
    - `nullptr` represents a pointer that points to nothing (C++11)
    - Dereferencing a null or uninitialized pointer is invalid

- Pointer Functions
  - Solution: [Open project](../src/02-basic-language-facilities/PointerFunctions/PointerFunctions.slnx)
  - Concepts: pointer parameters, output parameters, modifying caller state
  - Notes:
    - Pointers can be used to pass arguments by address (`&x`)
    - `*ptr` is required to access or modify the value being pointed to
    - Modifying the pointer itself does not affect the caller (only dereferenced values do)
    - Functions can return values through pointer parameters (`AddVal`, `Factorial`)
    - Pointers allow functions to modify caller variables (`Swap`)
    - Factorial is undefined for negative values; this implementation returns 0
    - `0! = 1`
    - This pattern is commonly replaced by references in modern C++

- Reference Functions
  - Solution: [Open project](../src/02-basic-language-facilities/ReferenceFunctions/ReferenceFunctions.slnx)
  - Concepts: reference parameters, aliasing, pass-by-reference
  - Notes:
    - References (`T&`) allow functions to modify caller variables without pointers
    - No need for `&` when calling or `*` when accessing values
    - References act as aliases to existing variables
    - Used for output parameters and modifying arguments (`Swap`, `AddVal`)
    - Simpler and safer than pointer-based equivalents
    - References must be initialized and cannot be null

- Const Pointers and References
  - Solution: [Open project](../src/02-basic-language-facilities/ConstQualifier/ConstQualifier.slnx)
  - Concepts: `const T*`, `T* const`, `const T* const`, `const T&`
  - Notes:
    - `const T* ptr` means the value cannot be modified through the pointer
    - `T* const ptr` means the pointer cannot be reassigned
    - `const T* const ptr` means neither the pointer nor the value can be modified
    - `const T&` creates a read-only reference
    - Non-const references cannot bind to temporaries; const references can
    - `const T&` is preferred for read-only function parameters in modern C++

- Auto Type Deduction
  - Solution: [Open project](../src/02-basic-language-facilities/Auto/Auto.slnx)
  - Concepts: `auto`, type deduction, references, const
  - Notes:
    - `auto` deduces the type from the initializer (C++11)
    - Top-level `const` is dropped (`const int` → `int`)
    - Use `auto&` to preserve reference and constness
    - `auto list = {1, 2, 3}` deduces `std::initializer_list<int>` (C++11)
    - `auto list{1, 2, 3}` is invalid because the type cannot be deduced
    - `auto` is commonly used with iterators and range-based for loops (C++11)
    - Prefer `auto` when the type is obvious or verbose

- For Each
  - Solution: [Open project](../src/02-basic-language-facilities/ForEach/ForEach.slnx)
  - Concepts: range-based for, `std::begin`, `std::end`, iterators
  - Notes:
    - Range-based for loops iterate directly over elements (C++11)
    - `std::begin()` / `std::end()` work with arrays and containers (C++11)
    - Arrays use pointers for traversal; containers use iterators
    - Iterators are the modern equivalent of pointer traversal
    - Prefer range-based for when no index is needed
    - Use traditional `for` loops when index or fine control is required

- Function Overloading
  - Solution: [Open project](../src/02-basic-language-facilities/FunctionOverloading/FunctionOverloading.slnx)
  - Concepts: overload resolution, return type, name mangling, `extern "C"`
  - Notes:
    - Multiple functions can share the same name if their parameters differ in type and/or number
    - Return type alone cannot distinguish overloaded functions
    - The compiler selects the correct overload based on the arguments
    - Overload resolution happens at compile time (static polymorphism)
    - Name mangling encodes function name and parameter types into a unique symbol
    - `extern "C"` suppresses name mangling and allows C++ functions to be called from C
    - `extern "C"` cannot be used on overloaded functions
    - For member functions, qualifiers like `const` can participate in overload resolution

- Default Function Arguments
  - Solution: [Open project](../src/02-basic-language-facilities/DefaultFunctionArgs/DefaultFunctionArgs.slnx)
  - Concepts: default parameters, function calls
  - Notes:
    - Function parameters can have default values
    - Arguments with defaults become optional at the call site
    - Explicit arguments override default values
    - Default arguments must be specified from right to left
    - Default values are typically defined in the function declaration

- Inline Functions
  - Solution: [Open project](../src/02-basic-language-facilities/InlineFunctions/InlineFunctions.slnx)
  - Concepts: `inline`, macros vs functions, function call overhead
  - Notes:
    - `inline` suggests the compiler replace a function call with its body
    - Inline functions may reduce function call overhead
    - The compiler may ignore the `inline` request
    - `inline` must appear on the function definition; it may also appear on declarations
    - Excessive use of `inline` can increase binary size
    - Macros perform text substitution and can introduce bugs
    - Inline functions are safer because they follow normal function semantics

- Function Pointers
  - Solution: [Open project](../src/02-basic-language-facilities/FunctionPointer/FunctionPointer.slnx)
  - Concepts: function pointers, indirect calls, function signatures
  - Notes:
    - A function pointer stores the address of a function
    - The type must match the function signature (return type and parameters)
    - Function names can decay to pointers
    - Functions can be called indirectly through a pointer
    - `(*fn)(args)` and `fn(args)` are equivalent
    - Used for callbacks and customization (e.g., `atexit`)

- Namespaces
  - Solution: [Open project](../src/02-basic-language-facilities/Namespace/Namespace.slnx)
  - Concepts: namespaces, scope, qualification, `using`, anonymous namespace
  - Notes:
    - Namespaces group related declarations and prevent name clashes
    - Types inside a namespace must be accessed with qualification unless brought into scope
    - `using namespace` brings all names into scope (use sparingly)
    - Use `using std::name` to bring in specific names instead of entire namespaces
    - Nested namespaces organize code hierarchically
    - Anonymous namespaces provide internal linkage (file-local)
    - Namespace aliases provide shorter names (e.g., `namespace fs = std::filesystem`)
    - Avoid `using namespace` in header files to prevent name conflicts

### 🧠 Pointer vs Reference

- Concepts: pointer vs reference, nullability, reseating
- Notes:
  - Use references (`T&`) when the value must exist and should be modified
  - Use pointers (`T*`) when null is a valid state or the object is optional
  - References must be initialized and cannot be null
  - References are bound to an object and cannot be reseated
  - Pointers can be null and reassigned
  - Use `*ptr` to access pointer values; references do not require dereferencing
  - Prefer references for function parameters in modern C++

### 🧠 const Reference Usage

- Concepts: `const T&`, pass-by-value vs reference
- Notes:
  - `const T&` avoids copying while preventing modification
  - Passing by value creates a copy; `const T&` binds to the original object
  - More efficient for large objects (e.g., vectors, strings)
  - Allows binding to temporaries (e.g., `Print(5)`)
  - Preferred for read-only function parameters in modern C++
  - For small types (e.g., `int`, `char`, `double`), pass by value is usually better
  - Using `const T&` for small types can be less efficient than copying
  - Prefer `const T&` for larger or non-trivial types (e.g., `std::string`, containers)

### 🔗 Navigation

📚 [Table of Contents](../README.md)  
→ [Next: Memory Management Part 1](../docs/03-memory-management-part1.md)
