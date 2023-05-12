# Get Next Line Project

## Project Description

The objective of this project is to code a function that reads a file or standard input line by line. Our function `get_next_line()` will read a text from a file descriptor and return one line ending with a newline character ('\n') each time it is called.

## Usage

The function `get_next_line()` can be used as follows:

```c
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
```

This will read the file pointed to by the file descriptor `fd` line by line, printing each line to the standard output.

## Compilation

The project must be compiled with the following flags:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```

You can change `BUFFER_SIZE` to any value you prefer. The `BUFFER_SIZE` flag is used to define the number of bytes read at a time by the `read()` function. This value can be adjusted by peer-evaluators and the Moulinette to test the function.

## Limitations and Considerations

* The `get_next_line()` function may exhibit undefined behavior if the file pointed to by the file descriptor changes since the last call while `read()` didn’t reach the end of file.
* The function may also behave unpredictably when reading binary files.
* The function is expected to read as little as possible each time it's called, ideally until it encounters a newline character.
* The entire file should not be read at once and then processed. 
* The function should work regardless of the `BUFFER_SIZE` value - be it 1, 9999, or 10000000. 
* `get_next_line()` must return the line read, including the terminating newline character, except if the end of file was reached and it doesn't end with a newline character.

## Restrictions

The following are forbidden in this project:

* Usage of libft.
* Usage of `lseek()`.
* Usage of global variables.

## Helper Functions

Any necessary helper functions can be added in the `get_next_line_utils.c` file.

## Prototype

The prototype of the `get_next_line()` function is declared in the `get_next_line.h` header file.

```c
char *get_next_line(int fd);
```
