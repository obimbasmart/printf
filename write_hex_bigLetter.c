#include "main.h"

/**
 * write_hex_bigLetter - prints hexadecimal reps of unsigned int in big letters
 * @args: va_list argument list
 * @flag: flag characters
 *
 * Return: number of chars printed to stdout
 */
size_t write_hex_bigLetter(va_list args, flag_t *flag)
{
	size_t nwrite = 0;
	uintmax_t num = va_arg(args, unsigned long int);

	if (flag->hash)
		nwrite += _puts("0X");

	flag->plus = 0;
	flag->hash = 0;
	flag->space = 0;

	nwrite += convert_unsigned_to_base(num, 16, 0);
	return (nwrite);
}
