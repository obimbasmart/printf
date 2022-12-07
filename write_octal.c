#include "main.h"

/**
 * write_octal - print an unsigned integer in base 8
 * @args: argument list
 * @flag: struct of flag characters
 *
 * Return: number of bytes written to stdout
 */
size_t write_octal(va_list args, flag_t *flag)
{
	size_t nwrite = 0;
	uintmax_t num = va_arg(args, unsigned long int);

	if (flag->hash && num > 0)
		nwrite += _putchar('0');

	nwrite += convert_unsigned_to_base(num, 8, 0);
	return (nwrite);
}


