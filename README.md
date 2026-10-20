*This project has been created as part of the 42 curriculum by hamossai.*

# Libft

## Description

**Libft** is the first project of the 42 common core. The goal is to build, from scratch, a static C library (`libft.a`) that re-implements a selection of standard C library functions and adds a set of useful utility functions. The library is reused in all later 42 projects, so it must be robust, norm-compliant and free of memory leaks.

Overview of what the project covers:

- Re-implementation of standard `libc` functions.
- Additional functions that are not in the `libc` (string splitting, joining, trimming, number-to-string conversion, file descriptor output, etc.).
- A generic singly linked list API.
- A `Makefile` that builds the static library with `ar`.

## Library description

`libft.a` is a static library written in C, compiled with `-Wall -Wextra -Werror`, with no use of forbidden functions (only `malloc`, `free` and `write` are allowed where relevant).

### Part 1 – libc re-implementations

| Category | Functions |
|---|---|
| Character checks / conversion | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower` |
| String handling | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory handling | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

### Part 2 – Additional functions

| Function | Description |
|---|---|
| `ft_substr` | Extracts a substring from a string. |
| `ft_strjoin` | Concatenates two strings into a newly allocated one. |
| `ft_strtrim` | Trims a set of characters from both ends of a string. |
| `ft_split` | Splits a string using a delimiter character into a NULL-terminated array. |
| `ft_itoa` | Converts an integer to a string. |
| `ft_strmapi` | Applies a function to each character, returning a new string. |
| `ft_striteri` | Applies a function to each character of a string in place. |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write to a given file descriptor. |

### Part 3 – Linked lists

Uses the `t_list` structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` / `ft_lstadd_back` | Adds a node at the beginning / end. |
| `ft_lstsize` | Counts the nodes. |
| `ft_lstlast` | Returns the last node. |
| `ft_lstdelone` / `ft_lstclear` | Deletes one node / the whole list using a `del` function. |
| `ft_lstiter` | Applies a function to each node's content. |
| `ft_lstmap` | Creates a new list by applying a function to each node, cleaning up on failure. |

### Technical choices

- Functions follow the behavior of their `libc` counterparts (including edge cases) unless the subject says otherwise.
- All allocating functions check `malloc` return values and return `NULL` on failure, without leaks.
- One function per file, one shared header `libft.h`.
- `Makefile` rules: `all`, `clean`, `fclean`, `re`; no unnecessary relinking.

## Instructions

### Requirements

- `cc` (or `gcc`/`clang`)
- `make`
- `ar`

### Compilation

```bash
# Build the library
make

# Remove object files
make clean

# Remove object files and libft.a
make fclean

# Rebuild everything
make re
```

This produces `libft.a` at the root of the repository.

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Compile your program by linking the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

Example:

```c
#include "libft.h"

int main(void)
{
    char **words = ft_split("hello 42 world", ' ');

    ft_putendl_fd(words[0], 1);   /* prints "hello" */
    /* free words and each element when done */
    return (0);
}
```

## Resources

### References

- `man 3` pages of the standard C library (`man 3 strlcpy`, `man 3 memmove`, ...)
- [The C Programming Language – Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- [42 Norm](https://github.com/42School/norminette)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
- [Valgrind documentation](https://valgrind.org/docs/manual/manual.html) for leak checking
- Peer testing: community testers such as `libft-unit-test` and `Libftest`

### Use of AI
AI was used as a conceptual reference to clarify low-level memory mechanics, pointer behaviors, and standard library specifications.

All implementation logic, coding, and debugging were personally written and verified.
