#include "main.h"

/**
 * write_int - function that writes an integer to stdout
 * @args: va_list argument list
 *
 * Return: int : number of bytes written + counter
 */
void  write_int(va_list args)
{
	char *str_num;

	long int num = (p_data.length_modifier == SHORT)
		? va_arg(args, int)
		: va_arg(args, int);

	if (p_data.flag.plus && num >= 0)
		update_buffer_c('+');
	else if (p_data.flag.space && num >= 0)
		update_buffer_c(' ');

	str_num = convert_to_base(num, 10, LOWERCASE);

	if (p_data.field_width > _strlen(str_num))
		write_format_specifer(p_data.field_width - _strlen(str_num), ' ');
	if (p_data.precision > _strlen(str_num))
		write_format_specifer(p_data.precision - _strlen(str_num), '0');

	update_buffer(str_num);

	/* reset flags */
	reset_global_data();
	free(str_num);
}
/**
 * write_unsigned_int - copy argument to printf_buffer
 * @args: va_list argument list
 *
 * Return: nothing
 */
void write_unsigned_int(va_list args)
{
	char *str_num;

	uintmax_t num = (p_data.length_modifier == SHORT)
		? va_arg(args, unsigned int)
		: va_arg(args, unsigned int);

	str_num = convert_unsigned_to_base(num, 10, 0);
	if (p_data.field_width > _strlen(str_num))
		write_format_specifer(p_data.field_width - _strlen(str_num), ' ');
	
	if (p_data.precision > _strlen(str_num))
		write_format_specifer(p_data.precision - _strlen(str_num), '0');

	update_buffer(str_num);
	reset_global_data();
	free(str_num);
}

/**
 * write_string_none_printables - handle non printable characters
 * Non printable characters (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 * @args: va_list argument list
 *
 * Return: number of bytes written to output
 */
void write_string_none_printables(va_list args)
{
	size_t index, ch;
	char *str;
	char *ch_str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		update_buffer("(null)");
		return;
	}

	index = 0;
	while (str[index] != '\0')
	{
		ch = (int)str[index]; /* convert ch to int */
		if ((ch > 0 && ch < 32) || ch >= 127)
		{
			update_buffer(ch < 16 ? "\\x0" : "\\x");
			ch_str = convert_to_base(ch, 16, 0);
			update_buffer(ch_str);
		}
		else
			update_buffer_c(str[index]);

		index++;
	}
}

/**
 * write_str - append string to buffer
 * @args: va_list argument list
 *
 * Return: number of bytes written to stdout
 */
void write_str(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		update_buffer("(null)");
		return;
	}
	if (p_data.field_width > _strlen(str))
		write_format_specifer(p_data.field_width - _strlen(str), ' ');

	if (p_data.precision < _strlen(str))
		str[_strlen(str) - p_data.precision] = '\0';

	update_buffer(str);
	reset_global_data();
}

/**
 * write_rot13 - convert string using rot13 encoding
 * and append to printf buffer
 * @args: va_list argument list
 *
 * Return: nothing
 */
void write_rot13(va_list args)
{
	char *str, *str_roted;

	str = va_arg(args, char *);
	str_roted = convert_to_rot13(str);
	update_buffer(str_roted);
	free(str_roted);
}
