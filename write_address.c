#include "main.h"

/**
 * write_address - print the address of a variable
 * @args: va_list argument list
 * @flag: struct of flag characters
 *
 * Return: number of chars written
 */
size_t write_address(va_list args, __attribute__((unused)) flag_t *flag)
{
	size_t nwrite;
	uintmax_t var;

	var = va_arg(args, unsigned long int);

	nwrite = 0;
	if (!var)
		return (write(1, "(nil)", 5));

	nwrite += write(1, "0x", 2);
	nwrite += convert_unsigned_to_base(var, 16, 1);
	return (nwrite);
}

