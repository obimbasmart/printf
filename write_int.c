#include "main.h"

/**
 * write_int - function that writes an integer to stdout
 * @args: va_list argument list
 * @flag: struct of flag characters
 *
 * Return: int : number of bytes written + counter
 */
size_t  write_int(va_list args, flag_t *flag)
{
	size_t nwrite = 0;
	long int num = va_arg(args, long int);

	if (flag->plus && num >= 0)
		nwrite += _putchar('+');

	else if (flag->space && num >= 0)
		nwrite += _putchar(' ');

	flag->plus = 0;
	flag->hash = 0;
	flag->space = 0;

	nwrite += convert_to_base(num, 10, 0);
	return (nwrite);
}

