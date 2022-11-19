#include "main.h"

/**
 * write_rot13 - prints the rot13'ed string
 * @args: va_list argument list
 *
 * Return: number of chars printed to stdout
 */
size_t write_rot13(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	return (convert_to_rot13(str));
}

