#include "main.h"

char  *p_buffer;
p_data_t p_data;

/**
 * _printf - function that prints anything - characters and strings
 * @format: the format specifier
 * Return: integer : number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	void (*p_func)(va_list);

	init_printf_data(); /* initialize global vars */
	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			get_options(&format);
			if (*format == '\0')
				return (-1);

			if (*format == '%')
			{
				update_buffer_c('%');
				continue;
			}
			p_func = get_func(*format);
			if (p_func)
			{
				p_func(arg_list);
				continue;
			}

			update_buffer_c('%');
			update_buffer_c(*format);
		} /* end of if */
		else
			update_buffer_c(*format);
	} /* end of for-loop */

	update_buffer_c(*format);
	_puts(p_data.buffer);
	free(p_data.buffer);
	return (p_data.p_count - 1);
}

