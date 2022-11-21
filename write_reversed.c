#include "main.h"

/**
 * write_reversed - write the reverse of the string
 * @args: va_list argument list
 * @flag: struct of flag characters
 *
 * Return: number of bytes written to stdout
 */
size_t write_reversed(va_list args, __attribute__((unused)) flag_t *flag)
{
	char *str;
	size_t nwrite, len;

	nwrite = 0;
	str = va_arg(args, char *);
	len = strlen(str);

	while (len--)
	{
		nwrite += _putchar(str[len]);
	}
	return (nwrite);
}
