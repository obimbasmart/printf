#include "main.h"
#include <stdio.h>

char  *p_buffer;
p_options_t p_options;

/**
 * _printf - function that prints anything - characters and strings
 * @format: the format specifier
 * Return: integer : number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	void (*p_func)(va_list);
	char *buffer_c;

	p_buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!p_buffer)
		return (-1);
	buffer_c = p_buffer;
	if (format == NULL)
		return (-1);
	init_printf_data(); /* initialize global vars */
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
	p_buffer = buffer_c;
	return (_puts(p_buffer));
}

/**
 * init_printf_data - initialize all printf global variables
 *
 * Return: nothing
 */
void init_printf_data(void)
{

	p_options.flag.plus = 0;
	p_options.flag.hash = 0;
	p_options.flag.space = 0;
	p_options.length_modifier = p_options.field_width = 0;
	p_options.CASE = 1;
}

