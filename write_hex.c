#include "main.h"

/**
 * write_hex - prints hexadecimal reps of unsigned int in small letters
 * @args: va_list argument list
 *
 * Return: number of chars printed to stdout
 */
size_t write_hex(va_list args)
{
	uintmax_t num = va_arg(args, unsigned long int);

	return (convert_unsigned_to_base(num, 16, 1));
}

