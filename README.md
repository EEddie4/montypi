# ​🧑‍💻​  C - Stacks, Queues - LIFO, FIFO
## Learning Objectives
------------
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

### General
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

## Requirements
------------
### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- All your files should end with a new line.
- A README.md file, at the root of the folder of the project is mandatory.
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You allowed to use a maximum of one global variable.
- No more than 5 functions per file.
- You are allowed to use the C standard library.
- The prototypes of all your functions should be included in your header file called monty.h.
- All your header files should be include guarded

## More Info
------------
### Data Structures

```
    /**
     * struct stack_s - doubly linked list representation of a stack (or queue)
     * @n: integer
     * @prev: points to the previous element of the stack (or queue)
     * @next: points to the next element of the stack (or queue)
     *
     * Description: doubly linked list node structure
     * for stack, queues, LIFO, FIFO
     */
    typedef struct stack_s
    {
            int n;
            struct stack_s *prev;
            struct stack_s *next;
    } stack_t;
```
```
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
