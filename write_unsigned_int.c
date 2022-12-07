#include "main.h"

/**
 * write_unsigned_int - function that writes an integer to stdout
 * @args: va_list argument list
 * @flag: flag characters
 *
 * Return: int : number of bytes written + counter
 */
size_t  write_unsigned_int(va_list args, __attribute__((unused)) flag_t *flag)
{
	uintmax_t num = va_arg(args, unsigned long int);

	return (convert_unsigned_to_base(num, 10, 0));
}

