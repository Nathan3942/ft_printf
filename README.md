# ft_printf

A custom reimplementation of the `printf` function in C, built as part of 42's common core curriculum.

## About

ft_printf recreates the core behavior of the standard C library's `printf`, handling variadic arguments and formatted output without relying on the original implementation. The goal is to understand how a formatted output function actually works under the hood: parsing a format string, handling variadic arguments with `stdarg.h`, and converting values to their correct string representation for each format specifier.

## Supported conversions

| Specifier | Description |
|---|---|
| `%c` | character |
| `%s` | string |
| `%p` | pointer address |
| `%d` | signed decimal integer |
| `%i` | signed decimal integer |
| `%u` | unsigned decimal integer |
| `%x` | unsigned hexadecimal integer (lowercase) |
| `%X` | unsigned hexadecimal integer (uppercase) |
| `%%` | literal percent sign |

*(Adjust this table if you implemented additional flags/specifiers, such as width, precision, or the `-`, `0`, `#` flags.)*

## Build

`ft_printf` is meant to be compiled as a static library and linked into other projects.

```bash
make
```

This generates `libftprintf.a` at the root of the project.

Other available targets:
```bash
make clean    # removes object files
make fclean   # removes object files and the library
make re       # rebuilds the library from scratch
```

## Usage

Include the header and link the library when compiling your project:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    ft_printf("Pointer: %p, hex: %x\n", &main, 255);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Project structure

```
ft_printf/
├── srcs/
│   ├── ft_printf.c
│   ├── conversions/
│   └── utils/
├── includes/
│   └── ft_printf.h
├── libft/          # personal library reused across projects
├── Makefile
└── README.md
```

*(Adjust this tree to match your actual project structure.)*

## What I learned

- Working with variadic functions using `stdarg.h` (`va_start`, `va_arg`, `va_end`)
- Converting values between types and formatting them correctly for each base and representation (decimal, hexadecimal, pointer addresses)
- Designing a small, extensible parser for a format string
- Building and linking a static library (`.a`) for reuse across other C projects

## Authors

- [Nathan Jeanbourquin](https://github.com/Nathan3942) — 42

## License

Project built as part of the 42 curriculum. Educational use.
