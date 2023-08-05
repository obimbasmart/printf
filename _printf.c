/* Overview of the printf Program Flow: */

/*
 * Global Variables - The program heavily relies on global variables for
 *   managing the output buffer, current position in the buffer, and other
 *   relevant information.
 *   The primary global variable is `p_data`, which is a struct containing
 *   various global variables used in the program. Which includes:
 *
 * - @`buffer`: A string with an initial byte size of 1024. It holds the output
 *   string before it is written to the output stream. Characters are not
 *   mmediately written to the stream but are appended to the buffer.  A single
 *   write operation is made to the stream using the buffer when needed.
 *
 * - @`p_count`: This variable keeps track of the current index (position)
 *   within the buffer.It represents the total number of characters written to
 *   the buffer at any point in time.
 * - Other global variables include `length_modifier`, `field_width`,
 *   `buffersize`, `flags`, etc.
 * - All global variables are initialized at the beginning of the program using
 *   the `init_global_var()` function, and they can be reset as needed during
 *   the program execution using the `reset_global_var()` function.
 *
 * 2. Processing the Format String: The program starts by iterating through the
 * - format string passed to the `printf` function.  For each iteration, it
 *   checks if the current character is a format specifier (indicated by a
 *   '%').  If the character is not a format specifier, it is appended to the
 *   buffer, and the program proceeds to the next character.  If a '%'
 *   character is encountered, it indicates a format specifier, and the program
 *   calls the
 * - `get_options()` function to set any applicable global variables based on
 *   the format specifier.
 *
 * 3. Handling Format Specifiers: Each format specifier has its own
 * corresponding write function to handle it appropriately.  The program uses
 * the `get_func` function to determine the appropriate write function for the
 * encountered format specifier.  The write functions have access to the global
 * variables, which are necessary for implementing functionalities like field
 * width, length modifiers, etc.
 *
 * 4. Writing to the Output Stream: As the program processes the format string
 * and handles format specifiers, the actual output is constructed and stored
 * in the buffer.  Characters are appended to the buffer until the final output
 * is ready to be written to the output stream.  Once the output construction
 * is complete, a single write operation is performed to send the entire buffer
 * content to the output stream.
 */

#include "main.h"

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
			get_options(&format, arg_list);
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

