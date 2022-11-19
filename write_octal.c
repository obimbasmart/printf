#include "main.h"

/**
 * write_octal - print an unsigned integer in base 8
 * @args: argument list
 *
 * Return: number of bytes written to stdout
 */
size_t write_octal(va_list args)
{
	uintmax_t num = va_arg(args, int);

	return (convert_unsigned_to_base(num, 8, 0));
}


