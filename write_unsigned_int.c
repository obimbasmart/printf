#include "main.h"

/**
 * write_unsigned_int - function that writes an integer to stdout
 * @args: va_list argument list
 * @flag: flag characters
 * @length_m: length modifier for SHORT | LONG
 *
 * Return: int : number of bytes written + counter
 */
size_t  write_unsigned_int(va_list args,
			 __attribute__((unused)) flag_t *flag,
			size_t length_m)
{
	uintmax_t num = (length_m == SHORT)
				? va_arg(args, unsigned int)
				: va_arg(args, unsigned int);

	return (convert_unsigned_to_base(num, 10, 0));
}

