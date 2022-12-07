#include "main.h"

/**
 * write_binary - write the binary reps of an unsigned int
 * @args: va_list argument list
 * @flag: struct of flag characters
 * @length_modifier: length modifier for SHORT | LONG
 *
 * Return: number of chars written to stdout
 */
size_t write_binary(va_list args, __attribute__((unused)) flag_t *flag,
		 __attribute__((unused)) size_t length_modifier)
{
	uint32_t num = va_arg(args, int);

	return (convert_unsigned_to_base(num, 2, 0));
}

