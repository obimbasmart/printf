#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define SHORT 10
#define LONG  100
#define LOWERCASE 1
#define UPPERCASE 0

extern char *p_buffer; /* variable to hold the content of printf */

/**
 * struct flag - structure representing the three printf flags
 * @plus: + flag
 * @hash: # flag
 * @space: ' ' flag
 */
typedef struct flag
{
	int plus;
	int hash;
	int space;
} flag_t;

/**
 * struct print_specifiers - hold extra option/specifiers for printf
 * @flag: struct: flag characters
 * @length_modifier: length modifier
 * @field_width: minimun field width
 * @CASE: specifies if lowercase or uppercase for hexadecimal values
 *
 * Description: Each member of this struct represents some extra
 * format specifiers passed to printf
 */
typedef struct print_specifiers
{
	flag_t flag;
	size_t length_modifier;
	size_t field_width;
	size_t CASE;
} p_options_t;

extern p_options_t p_options;
/**
 * struct printf_action - structure representing a printf
 * format specifier
 * @fmt: the format specifier
 * @func: the function for the format specifier
 */
typedef struct printf_action
{
	char fmt;
	void (*func)(va_list);
} p_action;


/* helper functions */
void (*get_func(char fmt))(va_list);
int get_flag(char ch);
size_t get_length_modifier(char ch);
size_t get_field_width(const char *ch);
void get_options(const char **str);
void init_printf_data(void);
size_t _strlen(char *);

/* utility functions */
size_t _puts(char *);
void update_buffer_c(char ch);
void update_buffer(char *str);

/* _printf function */
int _printf(const char *format, ...);
void write_char(va_list);
void write_str(va_list);
void write_hex(va_list);
void write_hex_bigLetter(va_list);
void write_binary(va_list);
void write_string_none_printables(va_list);
void write_address(va_list);
void write_int(va_list);
void write_unsigned_int(va_list);
void write_octal(va_list);
void write_reversed(va_list);
void write_rot13(va_list);

/*converters */
char *convert_to_base(long int, int, size_t);
char *convert_unsigned_to_base(uintmax_t, size_t, size_t);
char *convert_to_rot13(char *);

#endif /* MAIN_H_INCLUDED */


