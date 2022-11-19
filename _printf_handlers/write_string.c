#include "main.h"

/**
 * write_string - function that writes a string to stdout
 * @args: va_list argument list
 *
 * Return: number of bytes written to stdout
 */
size_t write_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}

	return (_puts(str));
}

