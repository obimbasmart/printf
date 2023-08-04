#include "main.h"

/**
 * get_func - function gets the appropriate function for print
 * given the correct format specifier
 * @fmt: the format specifier
 *
 * Return: pointer to a function that takes a va_list type and returns size_t
 */
void (*get_func(char fmt))(va_list args)
{
	p_action arr_funcs[] = {
		{ 's', write_str },
		{ 'S', write_string_none_printables },
		{ 'c', write_char },
		{ 'p', write_address },
		{ 'd', write_int },
		{ 'i', write_int },
		{ 'u', write_unsigned_int },
		{ 'o', write_octal },
		{ 'X', write_hex },
		{ 'x', write_hex },
		{ 'b', write_binary },
		{ 'R', write_rot13 }
	};
	int arr_size, i;

	arr_size = 12;
	i = 0;
	while (i < arr_size)
	{
		if (arr_funcs[i].fmt == fmt)
			return (arr_funcs[i].func);
		i++;
	}
	return (NULL);
}

/**
 * get_options - gets all options for printf such flag, width, length modifier
 * @str: pointer to char
 *
 * Return: nothing
 */
void get_options(const char **str)
{
	while (get_flag(**str))
		(*str)++;

	p_data.length_modifier = get_length_modifier(**str);
	if (p_data.length_modifier)
		(*str)++;

	p_data.field_width = get_field_width(*str);
	if (**str == 'X')
		p_data.CASE = UPPERCASE;
}

/**
 * get_length_modifier - gets the length modifier of a printf func
 * @ch: length character
 *
 * Return: integer. 0 on failure. 1 on success
 */
size_t get_length_modifier(char ch)
{
	switch (ch)
	{
		case 'h':
			return (SHORT);
		case 'l':
			return (LONG);
		default:
			return (0);
	}
}

/**
 * get_field_width - get the field width for print function
 * @ch: width char
 *
 * Return: integer, length of field
 */
size_t get_field_width(const char *ch)
{
	size_t width = 0;

	while (*ch >= '0' && *ch <= '9')
	{
		width += *ch - '0';
		ch++;
	}
	return (width);
}

/**
 * get_flag - function that gets the flags for a printf format specifier
 * @ch: flag character
 *
 * Return: integer. 0 on failure. 1 on success
 */
int get_flag(char ch)
{
	switch (ch)
	{
		case '+':
			p_data.flag.plus = 1;
			return (1);
		case '#':
			p_data.flag.hash = 1;
			return (1);
		case ' ':
			p_data.flag.space = 1;
			return (1);
		default:
			return (0);
	}
}

