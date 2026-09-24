# C / Linux System Programming Practice

A collection of 68 C programming and Linux system programming exercises.
The programs progress from basic C concepts to memory management,
data structures, processes, IPC, multithreading, networking, and
advanced Linux system calls.

---

# Learning Points

## 01. Hello World — `01_hello_world.c`

### Learning Points
- Basic structure of a C program
- `main()` function
- `printf()`
- Header files
- Compilation and execution
- Standard output

---

## 02. Sort Array — `02_sort_array.c`

### Learning Points
- One-dimensional arrays
- Array traversal
- Nested loops
- Swapping values
- Sorting algorithms
- Time complexity basics

---

## 03. Pointers — `03_pointers.c`

### Learning Points
- Address operator `&`
- Dereference operator `*`
- Pointer declaration
- Storing addresses
- Accessing data through pointers
- Relationship between pointers and variables

---

## 04. Strings — `04_strings.c`

### Learning Points
- Character arrays
- Null terminator `'\0'`
- String input/output
- String traversal
- Basic string manipulation

---

## 05. Functions — `05_functions.c`

### Learning Points
- Function declaration
- Function definition
- Function parameters
- Return values
- Function calls
- Code modularity

---

## 06. Recursion — `06_recursion.c`

### Learning Points
- Recursive functions
- Base conditions
- Recursive calls
- Stack behavior
- Converting repetitive problems into recursive solutions

---

## 07. Structures — `07_structures.c`

### Learning Points
- `struct`
- Structure members
- Creating structure variables
- Accessing members
- Grouping related data
- User-defined data types

---

# Memory Management and Advanced C

## 08. Dynamic Memory — `08_dynamic_memory.c`

### Learning Points
- Heap memory
- `malloc()`
- Dynamic allocation
- Checking allocation failures
- `free()`
- Memory lifetime

---

## 09. calloc/realloc — `09_calloc_realloc.c`

### Learning Points
- `calloc()`
- `realloc()`
- Dynamic array resizing
- Zero-initialized memory
- Memory allocation errors
- Releasing allocated memory

---

## 10. File Handling — `10_file_handling.c`

### Learning Points
- Opening files
- Reading files
- Writing files
- Closing files
- File modes
- `FILE *`
- Standard C file APIs

---

## 11. Command Line — `11_command_line.c`

### Learning Points
- `argc`
- `argv`
- Command-line arguments
- Passing data to programs
- Processing user input from the shell

---

## 12. Bitwise Operations — `12_bitwise_operations.c`

### Learning Points
- Bit representation
- AND `&`
- OR `|`
- XOR `^`
- NOT `~`
- Left shift `<<`
- Right shift `>>`

---

## 13. Bit Manipulation — `13_bit_manipulation.c`

### Learning Points
- Setting bits
- Clearing bits
- Toggling bits
- Checking bits
- Bit masks
- Low-level data manipulation

---

## 14. Function Pointers — `14_function_pointer.c`

### Learning Points
- Function addresses
- Function pointer declaration
- Calling functions through pointers
- Callbacks
- Passing functions as arguments

---

## 15. Static and Extern — `15_static_extern.c`

### Learning Points
- `static`
- `extern`
- Variable lifetime
- Variable scope
- Internal linkage
- External linkage
- Sharing variables between source files

---

## 16. Const and Volatile — `16_const_volatile.c`

### Learning Points
- `const`
- Read-only variables
- `volatile`
- Compiler optimization considerations
- Memory-mapped hardware concepts
- Qualifiers in C

---

## 17. Pointer Arithmetic — `17_pointer_arithmetic.c`

### Learning Points
- Pointer increment/decrement
- Pointer subtraction
- Pointer comparison
- Array and pointer relationship
- Pointer offsets
- Pointer traversal

---

## 18. String Functions — `18_string_functions.c`

### Learning Points
- `strlen()`
- `strcpy()`
- `strncpy()`
- `strcmp()`
- `strcat()`
- Standard string library
- Safe string handling

---

## 19. Structure Pointers — `19_struct_pointer.c`

### Learning Points
- Pointer to structure
- `->` operator
- `(*ptr).member`
- Passing structures to functions
- Dynamic structures

---

## 20. Enum and Typedef — `20_enum_typedef.c`

### Learning Points
- `enum`
- Named constants
- `typedef`
- Creating readable type names
- Improving code readability

---

## 21. Macros — `21_macros.c`

### Learning Points
- Preprocessor
- `#define`
- Object-like macros
- Function-like macros
- Conditional compilation
- Macro expansion

---

## 22. memcpy and memmove — `22_memcpy_memmove.c`

### Learning Points
- Raw memory copying
- `memcpy()`
- `memmove()`
- Overlapping memory
- Difference between `memcpy()` and `memmove()`
- `<string.h>`

---

## 23. File Copy — `23_file_copy.c`

### Learning Points
- Reading from a source file
- Writing to a destination file
- File descriptors
- Buffer-based copying
- Error handling
- File operations

---

# Data Structures

## 24. Linked List — `24_linked_list.c`

### Learning Points
- Nodes
- Self-referential structures
- Dynamic memory
- Head pointer
- Insertion
- Deletion
- Traversal
- Linked data structures

---

## 25. Stack — `25_stack.c`

### Learning Points
- Stack data structure
- LIFO
- `push()`
- `pop()`
- `peek()`
- Stack overflow/underflow concepts

---

## 26. Queue — `26_queue.c`

### Learning Points
- Queue data structure
- FIFO
- Enqueue
- Dequeue
- Front and rear
- Queue management

---

# Processes and IPC

## 27. Fork Process — `27_fork_process.c`

### Learning Points
- Linux processes
- `fork()`
- Parent process
- Child process
- Process IDs
- `getpid()`
- `getppid()`

---

## 28. Fork and Wait — `28_fork_wait.c`

### Learning Points
- Parent-child relationship
- `fork()`
- `wait()`
- Process synchronization
- Child termination
- Zombie-process concepts

---

## 29. Fork and Exec — `29_fork_exec.c`

### Learning Points
- `fork()`
- `exec()`
- Process replacement
- Running another program
- Parent/child execution flow
- `waitpid()`

---

## 30. Signals — `30_signals.c`

### Learning Points
- Linux signals
- `signal()`
- Signal handlers
- `SIGINT`
- `SIGTERM`
- `SIGCHLD`
- Asynchronous events

---

## 31. Pipe IPC — `31_pipe_ipc.c`

### Learning Points
- Inter-process communication
- `pipe()`
- File descriptors
- Parent-child communication
- Read end
- Write end
- Synchronization

---

# Multithreading and Synchronization

## 32. POSIX Thread Basics — `32_pthread_basic.c`

### Learning Points
- POSIX threads
- `pthread_create()`
- `pthread_join()`
- Thread functions
- Thread IDs
- Concurrent execution

---

## 33. Mutex — `33_mutex.c`

### Learning Points
- Mutual exclusion
- Race conditions
- `pthread_mutex_t`
- `pthread_mutex_lock()`
- `pthread_mutex_unlock()`
- Critical sections

---

## 34. Semaphore — `34_semaphore.c`

### Learning Points
- Semaphores
- Counting resources
- `sem_init()`
- `sem_wait()`
- `sem_post()`
- Thread/process synchronization

---

## 35. Condition Variables — `35_condition_variable.c`

### Learning Points
- Condition variables
- `pthread_cond_wait()`
- `pthread_cond_signal()`
- `pthread_cond_broadcast()`
- Mutex + condition variable
- Waiting for state changes

---

## 36. Producer Consumer — `36_producer_consumer.c`

### Learning Points
- Producer-consumer problem
- Shared buffer
- Mutex
- Condition variables
- Synchronization
- Blocking producers/consumers
- Race-condition prevention

---

## 37. Deadlock — `37_deadlock.c`

### Learning Points
- Deadlock
- Resource contention
- Mutual exclusion
- Hold and wait
- No preemption
- Circular wait
- Thread synchronization problems

---

## 38. Deadlock Prevention — `38_deadlock_prevention.c`

### Learning Points
- Avoiding deadlocks
- Lock ordering
- Resource management
- Synchronization design
- Safe mutex usage

---

## 39. Atomic Counter — `39_atomic_counter.c`

### Learning Points
- Atomic operations
- Race-condition prevention
- Thread-safe counters
- Atomic variables
- Lock-free programming concepts

---

# Shared Memory and Message Queues

## 40. Shared Memory — `40_shared_memory.c`

### Learning Points
- Shared-memory IPC
- Multiple processes accessing common memory
- Synchronization requirements
- Memory mapping concepts
- Inter-process communication

---

## 41. Message Queue — `41_message_queue.c`

### Learning Points
- Message-based IPC
- Sending messages
- Receiving messages
- Queue-based communication
- Process synchronization
- Message boundaries

---

# Network Programming

## 42. TCP Server — `42_tcp_server.c`

### Learning Points
- Network sockets
- `socket()`
- `bind()`
- `listen()`
- `accept()`
- TCP server architecture
- Client connections

---

## 43. TCP Client — `43_tcp_client.c`

### Learning Points
- TCP client
- `socket()`
- `connect()`
- `send()`
- `recv()`
- Client-server communication

---

## 44. TCP Echo Server — `44_tcp_echo_server.c`

### Learning Points
- TCP communication
- Receiving client data
- Sending data back
- Echo-server design
- Socket lifecycle

---

## 45. TCP Echo Client — `45_tcp_echo_client.c`

### Learning Points
- TCP client communication
- Sending messages
- Receiving responses
- Socket connection handling
- Client-server request/response

---

## 46. UDP Server — `46_udp_server.c`

### Learning Points
- UDP sockets
- Connectionless communication
- `sendto()`
- `recvfrom()`
- Datagram communication
- UDP server design

---

## 47. UDP Client — `47_udp_client.c`

### Learning Points
- UDP client
- Datagram transmission
- `sendto()`
- `recvfrom()`
- Connectionless networking

---

## 48. Select Server — `48_select_server.c`

### Learning Points
- I/O multiplexing
- `select()`
- File descriptor sets
- `FD_SET()`
- `FD_ISSET()`
- Handling multiple clients

---

## 49. Non-blocking Server — `49_nonblocking_server.c`

### Learning Points
- Blocking vs non-blocking I/O
- `fcntl()`
- `O_NONBLOCK`
- Non-blocking sockets
- Event-driven programming

---

## 50. Poll Example — `50_poll_example.c`

### Learning Points
- `poll()`
- File descriptor monitoring
- I/O multiplexing
- Multiple simultaneous connections
- Event handling

---

## 51. Epoll Example — `51_epoll_example.c`

### Learning Points
- Linux `epoll`
- Event-driven I/O
- `epoll_create()`
- `epoll_ctl()`
- `epoll_wait()`
- Scalable network servers

---

# Advanced Threads and Linux APIs

## 52. Read-Write Lock — `52_rwlock.c`

### Learning Points
- Reader-writer locks
- `pthread_rwlock_t`
- Multiple readers
- Exclusive writers
- Synchronization strategy

---

## 53. Thread Cancellation — `53_pthread_cancel.c`

### Learning Points
- Thread cancellation
- `pthread_cancel()`
- Cancellation points
- Thread cleanup
- Resource management

---

## 54. Detached Threads — `54_pthread_detach.c`

### Learning Points
- Detached threads
- `pthread_detach()`
- Thread resources
- Difference between joinable and detached threads

---

## 55. Thread Specific Data — `55_thread_specific_data.c`

### Learning Points
- Thread-local storage
- Thread-specific data
- `pthread_key_create()`
- `pthread_setspecific()`
- `pthread_getspecific()`
- Per-thread state

---

## 56. File System Calls — `56_file_system_calls.c`

### Learning Points
- Linux file system APIs
- File descriptors
- File creation
- File access
- System calls
- Low-level file operations

---

## 57. stat File Information — `57_stat_file_info.c`

### Learning Points
- `stat()`
- File metadata
- File size
- Permissions
- File type
- Timestamps
- Inode information

---

## 58. dup and dup2 — `58_dup_dup2.c`

### Learning Points
- File descriptor duplication
- `dup()`
- `dup2()`
- Standard descriptors
- Descriptor redirection
- File descriptor tables

---

## 59. stdout Redirection — `59_stdout_redirect.c`

### Learning Points
- Standard output
- File descriptors
- `dup2()`
- Output redirection
- Shell redirection concepts

---

## 60. Pipe and Fork — `60_pipe_fork.c`

### Learning Points
- `fork()`
- `pipe()`
- Parent-child communication
- File descriptor inheritance
- IPC design

---

## 61. FIFO — `61_fifo.c`

### Learning Points
- Named pipes
- FIFO
- `mkfifo()`
- Process-to-process communication
- Persistent IPC endpoints

---

## 62. POSIX Shared Memory — `62_posix_shared_memory.c`

### Learning Points
- POSIX shared memory
- `shm_open()`
- `ftruncate()`
- `mmap()`
- Shared memory between processes
- Resource cleanup

---

## 63. POSIX Message Queue — `63_posix_message_queue.c`

### Learning Points
- POSIX message queues
- `mq_open()`
- `mq_send()`
- `mq_receive()`
- Message priorities
- IPC synchronization

---

## 64. mmap File — `64_mmap_file.c`

### Learning Points
- Memory-mapped files
- `mmap()`
- `munmap()`
- File-backed memory
- Memory/file relationship
- Efficient file access concepts

---

## 65. ioctl — `65_ioctl_example.c`

### Learning Points
- `ioctl()`
- Device control
- File descriptors
- Kernel/user-space interface
- Device-specific operations

---

## 66. errno and Error Handling — `66_errno_error.c`

### Learning Points
- `errno`
- `perror()`
- `strerror()`
- System-call errors
- Error checking
- Robust Linux programming

---

## 67. sigaction — `67_sigaction.c`

### Learning Points
- `sigaction()`
- Advanced signal handling
- Signal handlers
- Signal masks
- Signal flags
- Reliable signal programming

---

## 68. Signal Block — `68_signal_block.c`

### Learning Points
- Blocking signals
- Signal masks
- `sigprocmask()`
- Pending signals
- Unblocking signals
- Signal synchronization

---

# Overall Learning

After completing these 68 programs, the main concepts covered are:

## C Programming
- Variables
- Data types
- Operators
- Arrays
- Strings
- Functions
- Recursion
- Pointers
- Structures
- Enums
- Typedef
- Macros
- Function pointers

## Memory Management
- Stack memory
- Heap memory
- `malloc()`
- `calloc()`
- `realloc()`
- `free()`
- `memcpy()`
- `memmove()`
- `mmap()`

## Data Structures
- Arrays
- Linked lists
- Stacks
- Queues

## Linux Processes
- `fork()`
- `exec()`
- `wait()`
- `waitpid()`
- Process IDs
- Parent/child processes

## IPC
- Pipes
- FIFO
- Shared memory
- POSIX shared memory
- Message queues
- POSIX message queues

## Multithreading
- pthreads
- Mutex
- Semaphore
- Condition variables
- Producer-consumer
- Read-write locks
- Thread cancellation
- Detached threads
- Thread-specific data
- Atomic operations

## Synchronization
- Race conditions
- Critical sections
- Deadlocks
- Deadlock prevention
- Atomic operations
- Locking strategies

## Networking
- TCP
- UDP
- Sockets
- Client/server architecture
- `select()`
- `poll()`
- `epoll()`
- Blocking I/O
- Non-blocking I/O

## Linux System Programming
- File descriptors
- File operations
- `stat()`
- `dup()`
- `dup2()`
- `ioctl()`
- `errno`
- Signals
- `sigaction()`
- Signal masks
- Memory mapping

---

# Compilation

Basic C program:

```bash
gcc program.c -o program
