#include "main.h"

/**
 * write_string_none_printables - function handles non printable characters
 * when writing strings
 * @args: va_list argument list
 * @flag: flag characters
 *
 * Return: number of bytes written to output
 */
size_t write_string_none_printables(va_list args,
		 __attribute__((unused)) flag_t *flag)
{
	size_t nwrite, i, _char;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	nwrite = i = 0;
	while (str[i] != '\0')
	{
		/* convert char to int */
		_char = (int)str[i];
		if ((_char > 0 && _char < 32) || _char >= 127)
		{
			nwrite += write(1, _char < 16 ? "\\x0" : "\\x", _char < 16 ? 3 : 2);
			nwrite += convert_to_base(_char, 16, 0);
		}

		else
			nwrite += _putchar(str[i]);
		i++;
	}
	return (nwrite);
}

