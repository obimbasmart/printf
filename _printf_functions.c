#include "main.h"

/**
 * write_string - function that writes a string to stdout
 * @str: string to write
 *
 * Return: number of bytes written to stdout
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
 * Return: int, always 1;
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
 * write_int - function that writes an integer to stdout
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
	return (counter);
}

/**
 * convert_num_to_base - convert an unsigned integer to base base
 * @n: unsigned integer num
 * @base: new base
 *
 * Return: number of characters printed to stdout
 */
unsigned int convert_num_to_base(uint32_t n, unsigned int base)
{
	unsigned int len;

	len = 0;

	if (n <= (base - 1))
	{
		return (write_char(n + '0'));
	}

	len += convert_num_to_base(n / base, base);
	len += write_char((n % base) + '0');
	return (len);
}

/**
 * write_hexadecimal - prints hexadecimal reps of unsigned int
 * @n: unsigned interger
 * @flag: flag signifies if small letter or Capital letter to be used.
 * x for small letter. X for capital letter
 *
 * Return: number of chars printed to stdout
 */
unsigned int write_hexadecimal(uintmax_t n, char flag)
{
	unsigned int len, offset;
	char *chars;

	chars = "0123456789ABCDEF";
	n = uint32_t (n);

	offset = len = 0;

	if (flag == 'x')
		offset = 32;

	if (n < 16)
		return (write_char(chars[n] > 47 && chars[n] < 58
				 ? (unsigned int)chars[n]
				 : chars[n] + offset));


	len += write_hexadecimal(n / 16, flag);
	len += write_hexadecimal((n % 16), flag);
	return (len);
}

