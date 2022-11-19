#include "main.h"

/**
 * write_hex_bigLetter - prints hexadecimal reps of unsigned int in big letters
 * @args: va_list argument list
 *
 * Return: number of chars printed to stdout
 */
size_t write_hex_bigLetter(va_list args)
{
	uintmax_t num = va_arg(args, unsigned long int);

	return (convert_unsigned_to_base(num, 16, 0));
}
