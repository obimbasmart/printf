#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED



#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * struct printf_action - structure representing a printf
 * format specifier
 * @fmt: the format specifier
 * @func: the function for the format specifier
 */
typedef struct printf_action
{
	char fmt;
	size_t (*func)(va_list);
} p_action;

/* helper functions */
size_t (*get_func(char fmt))(va_list);
size_t convert_to_base(long int, int, size_t);
size_t convert_unsigned_to_base(uint32_t, size_t, size_t);
size_t write_char(va_list);
size_t _putchar(int);
size_t _puts(char *);

/* _printf function */
int _printf(const char *format, ...);
size_t write_string(va_list);
size_t write_hex(va_list);
size_t write_hex_bigLetter(va_list);

size_t write_binary(va_list);
size_t write_string_none_printables(va_list);
size_t write_address(va_list);
size_t write_int(va_list);
size_t write_unsigned_int(va_list);
size_t write_octal(va_list);
#endif /* MAIN_H_INCLUDED */


