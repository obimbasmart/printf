#include "main.h"
/**
 * _printf - function that prints anything - characters and strings
 * @format: the format specifier
 * Return: integer : number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	int i, count;
	size_t (*p_func)(va_list);

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	i = 0;
	count = 0;

	for (i = 0; format[i] != '\0'; i += 1)
	{
		if (format[i] == '%')
		{
			i += 1;
			if (format[i] == '%')
			{
				count += _putchar('%');
				continue;
			}

			p_func = get_func(format[i]);

			if (p_func)
			{
				count += p_func(arg_list);
				continue;
			}
			_putchar('%');
			_putchar(format[i]);
		}
		else
			count += _putchar(format[i]);
	}

	return (count);
}

