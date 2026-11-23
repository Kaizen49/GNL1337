*This project has been created as part of the 42 curriculum by selkasba.*

# Get Next Line

## Description

Get Next Line is a C project that reads a file descriptor one line at a time. Its goal is to practise file descriptors, the `read()` system call, static variables, pointers, and dynamic memory management.

```c
char *get_next_line(int fd);
```

Each successful call returns a newly allocated line, including the newline character (`\n`) when present. The last line is returned even when it has no final newline. The function returns `NULL` when no text remains or an error occurs. The caller must free every returned line.

The mandatory implementation keeps a single static remainder and is intended for successive calls on one file descriptor.

## Instructions

### Requirements

Use a Unix-like environment such as Linux, macOS, or Ubuntu on WSL, with a C compiler such as `cc`, Clang, or GCC. Valgrind is optional for memory checks on supported systems.

Place this README at the root of the repository alongside the project files.

| File | Purpose |
| --- | --- |
| `get_next_line.c` | Reading, line extraction, remainder handling, and the main function of the project |
| `get_next_line_utils.c` | String length, character search, string copy, and concatenation helpers |
| `get_next_line.h` | Function declarations, required includes, and the default buffer size |

### Compilation and execution

Create a separate `main.c` test file that opens `test.txt` with `O_RDONLY`, calls `get_next_line(fd)` until it returns `NULL`, prints and frees each returned line, then closes the descriptor. Include `get_next_line.h`, `<fcntl.h>`, `<stdio.h>`, `<stdlib.h>`, and `<unistd.h>` in that test file.

Create sample input and compile the test program from the repository root.

```bash
printf 'dima\nraja\nmagica\n1949' > test.txt
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
./a.out
```

This command replaces the contents of `test.txt`. It produces an executable named `a.out`. Change `BUFFER_SIZE` in the compilation command to test other read sizes, for example `1` or `1024`.

### Testing

On Linux, run the executable under Valgrind.

```bash
valgrind --leak-check=full --show-leak-kinds=all ./a.out
```

Test an empty file, a file containing only a newline, consecutive empty lines, a final line without a newline, and a line longer than the buffer. Also check invalid descriptors and repeated calls after end-of-file. A test that consumes the entire input should finish with no remaining heap allocations and no reported memory errors.

## Algorithm and justification

The implementation uses buffered reading with a persistent remainder. The static pointer `saved` holds text that has been read but has not yet been returned to the caller.

1. Validate the descriptor and require a positive `BUFFER_SIZE`.
2. In `ft_read`, read up to `BUFFER_SIZE` bytes at a time while `saved` has no newline. Terminate each successful read with `\0` and append it to `saved` using `ft_strjoin`. Release the previous allocation after a successful join.
3. When `read()` returns zero, stop reading and keep any accumulated text. When reading or allocation fails, release the owned allocations and return `NULL`.
4. In `ft_line`, copy the first line into a new allocation. Include `\n` only when it exists, then append `\0`.
5. In `ft_rest`, copy the text after the extracted line into a separate allocation. Free the old `saved` and keep the new remainder for the next call.
6. Return the extracted line. When `saved` is empty, release it, reset the static pointer to `NULL`, and return `NULL`.

For example, if one read produces `dima\nraja\n`, the first call returns `dima\n` and retains `raja\n`. The next call extracts the retained line without another read. A final line without a newline is returned after end-of-file is detected.

This algorithm handles lines whose lengths are unknown in advance. Reading in blocks reduces system calls when the buffer contains several bytes, and retaining extra text preserves subsequent lines. Separate allocations for the returned line and the remainder allow the caller to free the line independently.

The approach favours straightforward memory ownership. Repeated concatenation copies the accumulated text each time, so assembling a long line can take quadratic time with a small fixed buffer. Memory use is proportional to the accumulated text plus the read buffer, with temporary allocations during concatenation and extraction.

## Resources

- Linux manual for `read()`, including its return values and file-offset behaviour.
- Linux manual for opening files and using flags.
- Linux manual for dynamic allocation and deallocation.
- Official introduction to memory checking with Valgrind.
- The project subject and evaluation requirements available through the 42 Intra.

### AI usage

AI was used for explanations of file descriptors, system calls, static variables, pointers, null termination, and memory ownership. It also helped review the author's implementation,  Valgrind reports, and suggest test commands.    