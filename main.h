#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define BUFFERSIZE 1024
#define SHORT 10
#define LONG  100
#define LOWERCASE 1
#define UPPERCASE 0

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
 * struct printf_global_vars - hold extra format specifiers
 * and global varaibles for printf
 *
 * @flag: struct: flag characters
 * @length_modifier: length modifier
 * @field_width: minimun field width
 *
 * @CASE: specifies if lowercase or uppercase for hexadecimal values
 * @BUFFER_SIZE: number of bytes allocated to p_buffer
 *
 * @p_count: this is used to track the index of the next char to write to
 * for each write to buffer, p_count is increamented accordinly
 * and can also be used to denote the number of characters written to buffer
 * @buffer: pointer to characters of size @BUFFER_SIZE
 *
 * Description: Each member of this struct represents some extra
 * format specifiers passed to printf
 */
typedef struct printf_global_vars
{
	flag_t flag;
	size_t length_modifier;
	size_t field_width;
	size_t CASE;
	size_t BUFFER_SIZE;
	size_t p_count;
	char *buffer;
} p_data_t;

extern p_data_t p_data;

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
size_t get_field_width(const char **ch, va_list arg_list);
void get_options(const char **str, va_list args_list);
void init_printf_data(void);
size_t _strlen(char *);

/* utility functions */
size_t _puts(char *);
void update_buffer_c(char ch);
void update_buffer(char *str);
void write_field_width(size_t field_width);
void reset_global_data(void);

/* memory management */
void memcheck(void);
void *_realloc(void *ptr, unsigned int prev_size, unsigned int curr_size);

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


