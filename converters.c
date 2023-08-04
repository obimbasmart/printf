#include "main.h"

/**
 * convert_to_rot13 -  function that encodes a string into rot13.
 * @str : the string
 * Return: encoded characters, string
 */
char *convert_to_rot13(char *str)
{
	size_t idx, idxx;
	char ch;
	char original_str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char roted_str[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *buffer;

	buffer = malloc(sizeof(char) * BUFFERSIZE);
	if (!buffer)
		return (NULL);

	idx = 0;
	while (str[idx] != '\0')
	{
		ch = str[idx];
		idxx = 0;
		while (idxx < 54)
		{
			if (((ch >= 'A' && ch <= 'Z') ||
						(ch >= 'a' && ch <= 'z')) && ch == original_str[idxx])
			{
				buffer[idx] = roted_str[idxx];
				break;
			}
			idxx++;
		} /* end of inner while */

		if (idxx > 53)
			buffer[idx] = str[idx];

		idx++;
	} /* end of outer while */
	buffer[idx] = '\0';
	return (buffer);
}

/**
 * convert_to_base - converts a signed interger to base b
 * @_num: signed integer
 * @base: the new base
 * @lowercase: 1 = lowercase or 0 =  uppercase
 *
 * Return: number of characters written to STDOUT
 */
char *convert_to_base(long int _num, int base, size_t lowercase)
{
	char *digits;
	size_t num_len; /* length of number */
	int is_negative, index;
	unsigned long int num, num_copy;
	char *buffer;

	num_len = index = is_negative = 0;
	buffer = malloc(sizeof(char) * BUFFERSIZE);
	if (!buffer)
		return (NULL);

	num = _num;
	if (_num < 0 && base == 10)
	{
		num = -_num;
		is_negative = 1;
	}

	num_copy = num;
	/* get the length of the number */
	while (num_copy)
	{
		num_copy /= base;
		num_len++;
	}

	digits = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";

	num_copy = num; /* re-update num_copy */
	for (index = (num_len - 1 + is_negative); index >= is_negative; index--)
	{
		buffer[index] = digits[num_copy % base];
		num_copy /= base;
	}

	if (is_negative)
		buffer[0] = '-';

	buffer[num_len + is_negative] = '\0';
	return (buffer);
}

/**
 * convert_unsigned_to_base - converts an unsigned integer to base b
 * @num: unsigned interger
 * @base: the new base
 * @lowercase: 0 or 1 == lowercase or uppercase
 *
 * Return: length of new num in base b
 */
char *convert_unsigned_to_base(uintmax_t num, size_t base, size_t lowercase)
{
	char *digits;
	size_t num_len;
	uintmax_t num_copy;
	char *buffer;
	int index;

	num_len = index = 0;
	num_copy = num;

	buffer = malloc(sizeof(char) * BUFFERSIZE);
	if (!buffer)
		return (NULL);

	digits = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";

	/* get length of number */
	while (num_copy)
	{
		num_copy /= base;
		num_len++;
	}

	num_copy = num; /* update copy */
	for (index = num_len - 1; index >= 0; index--)
	{
		buffer[index] = digits[num_copy % base];
		num_copy /= base;
	}
	buffer[num_len] = '\0';
	return (buffer);
}



