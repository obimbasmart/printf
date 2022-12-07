#include "main.h"

/**
 * write_char - function that writes a single character to stdout
 * @args: va_list argument list
 * @flag: struct of flag characters
 * @length_modifier: length modifier for SHORT | LONG
 *
 * Return: int, always 1;
 */
size_t write_char(va_list args, __attribute__((unused)) flag_t *flag,
		 __attribute__((unused)) size_t length_modifier)
{
	char ch;

	ch = va_arg(args, int);
	return (_putchar(ch));

}

