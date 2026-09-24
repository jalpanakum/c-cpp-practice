# C/C++ Practice

This repository contains my C/C++ practice programs while learning programming fundamentals and preparing for technical interviews.

The programs are organized progressively, starting with basic C concepts and moving toward more important programming concepts.

## 📚 Topics Covered

### C Programming

* Basic syntax and input/output
* Arrays
* Strings
* Functions
* Pointers
* Recursion

### Upcoming Topics

* Structures
* Dynamic memory allocation
* File handling
* Linked lists
* C++ fundamentals
* Object-oriented programming
* STL
* Multithreading
* Linux programming
* Socket programming

## 📂 Programs

| File               | Topic     | Description                                  |
| ------------------ | --------- | -------------------------------------------- |
| `01_hello_world.c` | Basics    | First C program                              |
| `02_sort_array.c`  | Arrays    | Sorts an integer array using bubble sort     |
| `03_pointers.c`    | Pointers  | Demonstrates basic pointer usage             |
| `04_strings.c`     | Strings   | Reads and processes a string                 |
| `05_functions.c`   | Functions | Demonstrates defining and calling a function |
| `06_recursion.c`   | Recursion | Calculates factorial using recursion         |
| `07_structures.c` | Structures | Stores and displays student information using a structure |
| `08_dynamic_memory.c` | Dynamic Memory Allocation | Uses malloc and free to allocate and release memory dynamically |
| `09_calloc_realloc.c` | Dynamic Memory Allocation | Demonstrates calloc, realloc, and free |
| `10_file_handling.c` | File Handling | Demonstrates opening, reading, writing, and closing files |
| `11_command_line_arguments.c` | Command-Line Arguments | Demonstrates argc and argv |
| `12_bitwise_operators.c` | Bitwise Operators | Demonstrates AND, OR, XOR, NOT, and bit shifting |
| `13_bit_manipulation.c` | Bit Manipulation | Demonstrates setting, clearing, toggling, and checking individual bits |
| `14_function_pointers.c` | Function Pointers | Demonstrates function pointers and callback-style function passing |
| `15_static_extern.c` | Storage Classes | Demonstrates static local variables, static functions, and extern |


## 📝 Learning Notes

### 1. Hello World — `01_hello_world.c`

* `#include <stdio.h>` → includes the standard input/output library.
* `main()` → the starting point of a C program.
* `printf()` → displays output on the screen.
* `return 0` → indicates that the program completed successfully.

### 2. Array Sorting — `02_sort_array.c`

* An array stores multiple values of the same data type.
* Array indexing starts from `0`.
* Nested loops can be used to compare array elements.
* Bubble sort repeatedly compares adjacent elements and swaps them when necessary.
* `sizeof(arr) / sizeof(arr[0])` → calculates the number of elements in the array.

### 3. Pointers — `03_pointers.c`

* `int *ptr` → declares a pointer that stores the address of an integer.
* `&num` → gets the memory address of `num`.
* `*ptr` → accesses the value stored at the address held by `ptr`.
* `*ptr = 20` → changes the value of `num` through the pointer.
* Pointers are an important part of C and are widely used with arrays, functions, structures, and dynamic memory.

### 4. Strings — `04_strings.c`

* A C string is stored as an array of characters ending with a null character (`\0`).
* `char name[50]` → creates a character array that can store a string.
* `fgets()` → safely reads a line of text.
* `strcspn()` → helps remove the newline character read by `fgets()`.
* `strlen()` → returns the length of a string.

### 5. Functions — `05_functions.c`

* Functions divide a program into smaller, reusable sections.
* Parameters allow data to be passed into a function.
* `return` sends a value back to the calling function.
* A function can be called multiple times.
* Functions make programs easier to organize, test, and maintain.

### 6. Recursion — `06_recursion.c`

* Recursion occurs when a function calls itself.
* A **base case** is required to stop the recursion.
* Each recursive call should move toward the base case.
* Recursive function calls use the program's call stack.
* Factorial is a simple example of a recursive problem.

Example:

```text
factorial(5)
→ 5 × factorial(4)
→ 5 × 4 × factorial(3)
→ 5 × 4 × 3 × factorial(2)
→ 5 × 4 × 3 × 2 × factorial(1)
→ 120
```
### 7. Structures — `07_structures.c`

- A structure groups related variables of different data types.
- `struct Student` defines a new structure type.
- Structure members are accessed using the `.` operator.
- Structures are useful for representing real-world entities such as students, employees, products, and devices.

  
## 🎯 Goal

The goal of this repository is to build strong C/C++ fundamentals through hands-on practice and gradually progress toward interview-level programming and systems concepts.

## 🛠️ Tools

* C
* C++
* GCC / G++
* Git
* GitHub
* Linux

## 📈 Progress

* [x] Basic C program
* [x] Arrays and sorting
* [x] Pointers
* [x] Strings
* [x] Functions
* [x] Recursion
* [ ] Structures
* [ ] Dynamic memory allocation
* [ ] File handling
* [ ] Data structures
* [ ] C++ fundamentals
* [ ] Object-oriented programming
* [ ] STL
* [ ] Multithreading
* [ ] Linux programming
* [ ] Socket programming

---

More programs and learning notes will be added as I progress.
