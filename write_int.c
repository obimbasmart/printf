#include "main.h"

/**
 * write_int - function that writes an integer to stdout
 * @args: va_list argument list
 *
 * Return: int : number of bytes written + counter
 */
size_t  write_int(va_list args)
{
	long int num = va_arg(args, int);

	return (convert_to_base(num, 10, 0));
}

