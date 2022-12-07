#include <stdio.h>
#include "main.h"
/**
 * _printf - function that prints anything - characters and strings
 * @format: the format specifier
 * Return: integer : number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	size_t (*p_func)(va_list, flag_t *, size_t);
	size_t count = 0;
	flag_t flag = { 0, 0, 0 };
	size_t length_modifier = 0;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			while (get_flag(*format, &flag))
				format++;

			length_modifier = get_length_modifier(*format);

			if (length_modifier)
				format++;

			if (*format == '\0')
				return (-1);

			if (*format == '%')
			{
				count += _putchar('%');
				continue;
			}

			p_func = get_func(*format);
			if (p_func)
			{
				count += p_func(arg_list, &flag, length_modifier);
				continue;
			}
			count += _putchar('%');
			count += _putchar(*format);
		}
		else
			count += _putchar(*format);
	}
	return (count);
}
