#include "main.h"

/**
 * update_buffer_c - update the printf buffer
 * @ch: character
 *
 * Return: nothing
 */
void update_buffer_c(char ch)
{
	*p_buffer = ch;
	p_buffer++;
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
		*p_buffer = str[id];
		id++;
		p_buffer++;
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
	{
		return (write(STDOUT_FILENO, "(null)", 6));
	}
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
