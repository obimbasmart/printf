#include "main.h"

/**
 * _printf - function that prints anything - characters and strings
 * @format: the format specifier
 *
 * Return: integer : number of characters printed
 */

int _printf(const char *format, ...)
{

	/* initialize variables */
	va_list string_args;
	int i, count;

	if (format == NULL)
	{
		return (-1);
	}

	/* loop through the format specified */
	va_start(string_args, format);
	i = 0;
	count = 0;

	while (format[i] != '\0')
	{
		switch (format[i])
		{
			/* first case checks if character is a format specifier */
			case '%':
				i += 1;
				switch (format[i])
				{
					case 'c':
						count += write_char(va_arg(string_args, int));
						break;
					case 's':
						count += write_string(va_arg(string_args, char *));
						break;
					case '%':
						count += write_char('%');
						break;
					case '\0':
						count -= 1;
						continue;
					default:
						count += write_char('%');
						count += write_char(format[i]);
				}
				break;
				/* if format is not a specifier, just write it out*/
			default:
				write_char(format[i]);
				count += 1;
		}
		i++;
	}
	va_end(string_args);
	return (count);
}
