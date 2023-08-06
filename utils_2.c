#include "main.h"

/**
 * write_format_specifer - update field_width or precision is specified
 * @len: length of specifier to be written
 * @fmt: format, '0' or ' '
 *
 * Return: nothing
 */
void write_format_specifer(size_t len, char fmt)
{
	while (len--)
		update_buffer_c(fmt);
}

/**
 * write_precision - append more characters if precision is specified
 * @precision: precision length
 *
 * Return: nothing
 */
void write_precision(size_t precision)
{
	while (precision--)
		update_buffer_c('0');
}
/**
 * reset_global_data - reset global variables
 *
 * Return: nothing
 */
void reset_global_data(void)
{
	p_data.flag.plus = p_data.flag.hash = 0;
	p_data.flag.space = p_data.length_modifier = 0;
	p_data.field_width = 0;
	p_data.CASE = LOWERCASE;
}
