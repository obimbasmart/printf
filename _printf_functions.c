#include "main.h"

/**
 * write_string - function that writes a string to stdout
 * @str: string to write
 *
 * Return: int ; always 1
 */
unsigned int write_string(char *str)
{
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	return (write(1, str, strlen(str)));
}

/**
 * write_char - function that writes a single character to stdout
 * @ch: character to write
 *
 * Return: int ; always 1`
 */
unsigned int write_char(char ch)
{

	char *str;

	str = malloc(sizeof(char));
	if (str == NULL)
	{
		return (0);
	}
	str[0] = ch;
	write(1, str, 1);
	free(str);
	return (1);

}

/**
 * write _int - function that writes an integer to stdout
 * @num: the integer to write
 * @counter: the initial bytes writting to stdout
 *
 * Return: int : number of bytes written + counter
 */
unsigned int write_int(long int num, int counter)
{
	if (num < 0)
	{
		counter += write_char('-');
		num *= -1;
	}
	if (num < 10)
	{
		counter += write_char(num + '0');
		return (counter);
	}
	counter = write_int(num / 10, counter);
	counter += write_char((num % 10) + '0');
}
