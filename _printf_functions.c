#include "main.h"

/**
 * write_string - function that writes a string to stdout
 * @str: string to write
 *
 * Return: int ; always 1
 */
unsigned int write_string(char *str)
{
	return (write(1, str, strlen(str)));
}

/**
 *
 * write_char - function that writes a single character to stdout
 *
 * @ch: character to write
 *
 * Return: int ; always 1`
 */
unsigned int write_char(char ch)
{

	char *str;

	str = malloc(sizeof(char));
	str[0] = ch;

	return (write(1, str, 1));

}


