#include "main.h"

/**
 * get_func - function gets the appropriate function for print
 * given the correct format specifier
 * @fmt: the format specifier
 *
 * Return: pointer to a function that takes a va_list type and returns size_t
 */
size_t (*get_func(char fmt))(va_list, flag_t *)
{
	p_action arr_funcs[] = {
		{ 's', write_string },
		{ 'S', write_string_none_printables },
		{ 'c', write_char },
		{ 'p', write_address },
		{ 'd', write_int },
		{ 'i', write_int },
		{ 'u', write_unsigned_int },
		{ 'o', write_octal },
		{ 'X', write_hex_bigLetter },
		{ 'x', write_hex },
		{ 'b', write_binary },
		{ 'r', write_reversed },
		{ 'R', write_rot13 }
	};
	int arr_size, i;

	arr_size = 14;
	i = 0;
	while (i < arr_size)
	{
		if (arr_funcs[i].fmt == fmt)
			return (arr_funcs[i].func);
		i++;
	}
	return (NULL);
}
