#include "main.h"

/**
 * _putchar - function that writes a single char to stdout
 * @ch: character to write
 *
 * Return: int, always 1
 */
size_t _putchar(int ch)
{
	return (write(STDOUT_FILENO, &ch, 1));
}


