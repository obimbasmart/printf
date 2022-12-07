#include "main.h"

/**
 * write_string - function that writes a string to stdout
 * @args: va_list argument list
 * @flag: struct of flag characters
 * @length_modifier: length modifier for SHORT | LONG
 *
 * Return: number of bytes written to stdout
 */
size_t write_string(va_list args,
			__attribute__((unused)) flag_t *flag,
		 __attribute__((unused)) size_t length_modifier)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}

	return (_puts(str));
}

