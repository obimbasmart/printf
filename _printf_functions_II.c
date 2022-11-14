#include "main.h"

/**
 * write_string_none_printables - function handles non printable characters
 * when writing strings
 * @str: string containing non-printable chars
 *
 * Return: number of bytes written to output
 */
unsigned int write_string_none_printables(char *str)
{
	unsigned int nwrite, i, _char;

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
			nwrite += write(1, _char < 16 ? "\\x0" : "\\x", 2);
			nwrite += write_hexadecimal(_char, 'X');
		}

		else
		{
			nwrite += write_char(str[i]);
		}
		i++;
	}
	return (nwrite);
}
