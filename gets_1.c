#include "main.h"

/**
 * get_precision - get the precision for _print function
 * @str: format
 * @arg_list: variadic list of args passed to _printf
 *
 * Return: the precision, a number specifying the min number of
 * chars to be printed
 */
size_t get_precision(const char **str, va_list arg_list)
{
	size_t precision, precision_copy;

	precision = 0;
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			(*str)++;
			return (va_arg(arg_list, unsigned int));
		}

		precision = atoi(*str);
		precision_copy = precision;

		while (precision_copy)
		{
			precision_copy /= 10;
			(*str)++;
		}
	}
	return (precision);
}
