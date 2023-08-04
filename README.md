# _printf
_printf is a custom implementation of the the `printf` function in C.It provides similar functionality to the standard printf function in the C Standard Library but is implemented from scratch as a learning exercise. This project has been developed under stringent measures for good memory management, clean code and good practices

## Features
 - Supports basic format specifiers, which includes `%d`, `i`, `%s`, `%c`, `u`, `o`, `x`,  and more.
 - Supports non-custom format specifiers, which includes:
    - `r`: prints the reversed string
    - `S`: handles non-printable characters
    - `R`: prints the rot13'ed string
 - Supports basic field width, flags and precision formatting options
 
## Limitations: 
 - Limited Format Specifiers: This implementation supports only a basic set of custom format specifiers. Advanced format specifiers such as `%f` (floating point), `%e`, and `%g` are not supported at this time.

## Usage
- Clone the repository or download the source files.
- Copy the `main.h` header file and the necessary source files into your project directory.
- ### Example
```C
#include "main.h"

/**
 * main - main program
 *
 * Return: int
 */
 int main(void)
 {
     int age = 30;
     char *name = "MyName";
     char favoriteLetter = 'M';
     
     _printf("My name is %s. I am %d yr old and my favorite letter is %c\n");
     
     return(0);
 }

```

Once the interpreter is running, you can type commands and press Enter to execute them. The interpreter will process the command and perform the appropriate actions

Here are some list of supported commands amongst others:
- `ls` - List files and directories in the current directory
- `cd` - Change the current working directory to the specified directory
- `mkdir` : Create a new directory with the given name. rm

## File Structure
 - **_printf.c**: This file serves as the entry point of the program. It contains the main printf function that handles the format string parsing and calls the appropriate format specifier functions.
- **writes.c** (and family): contains functions that handle each format specifier supported by the custom printf. For example, `write_char.c` for `%c`, `write_integer.c` for `%d` and %i, `writes_string.c`  for %s, and so on.
- **converter.c**: contains functions responsible for converting numeric values to different bases. It include functions to convert integers to binary, hexadecimal, etc.
- **gets.c**: consists of functions that serve as getters and setters
- **utils.c** (and family): contains extra helper functions used throughout the program to enforce modularity and improve code readability. The functions in this file group may include commonly used utility functions.
** memory.c**: This file contains functions for memory management, allocations, and reallocations used within the program.

## Contributing
Contributions are welcome to improve the project. If you find any issues or have ideas for enhancements, please open an issue or submit a pull request

