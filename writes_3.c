#include "main.h"

/**
 * write_address - print the address of a variable
 * @args: va_list argument list
 *
 * Return: number of chars written
 */
void write_address(va_list args)
{
	uintmax_t var;
	char *str_var;

	var = va_arg(args, unsigned long int);

	if (!var)
	{
		update_buffer("(nil)");
		return;
	}

	update_buffer("0x");
	str_var = convert_unsigned_to_base(var, 16, p_options.CASE);
	update_buffer(str_var);
	free(str_var);
}

