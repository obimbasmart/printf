#include "main.h"

/**
 * write_binary - write the binary reps of an unsigned int
 * @args: va_list argument list
 *
 * Return: number of chars written to stdout
 */
void write_binary(va_list args)
{
	char *str_num;

	uint32_t num = va_arg(args, int);

	str_num = convert_unsigned_to_base(num, 2, p_data.CASE);
	if (p_data.field_width > _strlen(str_num))
		write_field_width(p_data.field_width - _strlen(str_num));

	update_buffer(str_num);
	reset_global_data();
	free(str_num);
}

/**
 * write_char - append character to buffer
 * @args: va_list argument list
 *
 * Return: nothing
 */
void write_char(va_list args)
{
	char ch;

	ch = va_arg(args, int);
	if (p_data.field_width > 1)
		write_field_width(p_data.field_width - 1);

	update_buffer_c(ch);
	reset_global_data();
}


/**
 * write_hex - convert a number to hexadecimal and append to printf buffer
 * @args: va_list argument list
 *
 * Return: number of chars printed to stdout
 */
void write_hex(va_list args)
{
	char *str_num;

	uintmax_t num = (p_data.length_modifier == SHORT)
		? va_arg(args, unsigned int)
		: va_arg(args, unsigned int);

	if (p_data.flag.hash && num > 0)
	{
		if (p_data.CASE == LOWERCASE)
			update_buffer("0x");
		else
			update_buffer("0X");
	}

	str_num = convert_unsigned_to_base(num, 16, p_data.CASE);
	if (p_data.field_width > _strlen(str_num))
		write_field_width(p_data.field_width - _strlen(str_num));

	update_buffer(str_num);
	reset_global_data();
	free(str_num);
}

/**
 * write_octal - print an unsigned integer in base 8
 * @args: argument list
 *
 * Return: nothing
 */
void write_octal(va_list args)
{
	char *str_num;

	uintmax_t num = (p_data.length_modifier == SHORT)
		? va_arg(args, unsigned int)
		: va_arg(args, unsigned int);


	if (p_data.flag.hash && num > 0)
		update_buffer_c('0');

	str_num = convert_unsigned_to_base(num, 8, 0);
	if (p_data.field_width > _strlen(str_num))
		write_field_width(p_data.field_width - _strlen(str_num));

	update_buffer(str_num);
	reset_global_data();
	free(str_num);
}

/**
 * write_reversed - write the reverse of the string
 * @args: va_list argument list
 *
 * Return: number of bytes written to stdout
 */
void write_reversed(va_list args)
{
	char *str;
	size_t str_len;

	str = va_arg(args, char *);
	str_len = strlen(str);

	while (str_len--)
		update_buffer_c(str[str_len]);
}
