#include "main.h"

/**
 * write_char - function that writes a single character to stdout
 * @args: va_list argument list
 *
 * Return: int, always 1;
 */
size_t write_char(va_list args)
{
	char ch;

	ch = va_arg(args, int);
	return (_putchar(ch));

}

