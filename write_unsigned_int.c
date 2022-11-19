#include "main.h"

/**
 * write_unsigned_int - function that writes an integer to stdout
 * @args: va_list argument list
 *
 * Return: int : number of bytes written + counter
 */
size_t  write_unsigned_int(va_list args)
{
	uint32_t num = va_arg(args, int);

	return (convert_unsigned_to_base(num, 10, 0));
}

