#include "main.h"

/**
 * write_binary - write the binary reps of an unsigned int
 * @args: va_list argument list
 *
 * Return: number of chars written to stdout
 */
size_t write_binary(va_list args)
{
	uint32_t num = va_arg(args, int);

	return (convert_unsigned_to_base(num, 2, 0));
}

