#include "main.h"

/**
 * write_field_width - update buffer if field width is specified
 * @field_width: length of padding
 *
 * Return: nothing
 */
void write_field_width(size_t field_width)
{
	while (field_width--)
		update_buffer_c(' ');
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
