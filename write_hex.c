#include "main.h"

/**
 * write_hex - prints hexadecimal reps of unsigned int in small letters
 * @args: va_list argument list
 * @flag: struct of flag characters
 * @length_modifier: length modifier for SHORT | LONG
 *
 * Return: number of chars printed to stdout
 */
size_t write_hex(va_list args, flag_t *flag, size_t length_modifier)
{
	size_t nwrite = 0;
	uintmax_t num = (length_modifier == SHORT)
		? va_arg(args, unsigned int)
		: va_arg(args, unsigned long int);

	if (flag->hash && num > 0)
		nwrite += _puts("0x");

	nwrite += convert_unsigned_to_base(num, 16, 1);

	flag->plus = 0;
	flag->hash = 0;
	flag->space = 0;

	return (nwrite);

}

