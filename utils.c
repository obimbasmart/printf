#include "main.h"

/**
 * update_buffer_c - update the printf buffer
 * @ch: character
 *
 * Return: nothing
 */
void update_buffer_c(char ch)
{
	memcheck(); /* check if memory is enough */
	p_data.buffer[p_data.p_count] = ch;
	p_data.p_count++; /* update index */
}

/**
 * update_buffer - update the printf buffer
 * @str: string
 *
 * Return: nothing
 */
void update_buffer(char *str)
{
	int id = 0;

	while (str[id] != '\0')
	{
		update_buffer_c(str[id]);
		id++;
	}
}

/**
 * _puts - function that writes a string to stdout
 * @str: string to write
 *
 * Return: number of bytes written to stdout
 */
size_t _puts(char *str)
{
	if (str == NULL)
		return (write(STDOUT_FILENO, "(null)", 6));

	return (write(STDOUT_FILENO, str, _strlen(str)));
}

/**
 * _strlen - return the length of a string
 * @str: string
 *
 * Return: integer
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	if (!str)
		return (0);

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * init_printf_data - initialize all printf global variables
 *
 * Return: nothing
 */
void init_printf_data(void)
{

	p_data.BUFFER_SIZE = 1024;
	p_data.buffer = malloc(sizeof(char) * p_data.BUFFER_SIZE);
	if (!p_data.buffer)
		exit(1);

	p_data.p_count = 0;
	p_data.flag.plus = 0;
	p_data.flag.hash = 0;
	p_data.flag.space = 0;
	p_data.length_modifier = p_data.field_width = 0;
	p_data.CASE = 1;
}

