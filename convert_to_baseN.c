#include "main.h"

/**
 * convert_to_base - converts a signed interger to base b
 * @num: signed integer
 * @base: the new base
 * @lowercase: 1 = lowercase or 0 =  uppercase
 *
 * Return: number of characters written to STDOUT
 */
size_t convert_to_base(long int num, int base, size_t lowercase)
{
	char *chars;
	size_t nwrite;

	nwrite = 0;
	if (num < 0 && base == 10)
	{
		num *= -1;
		nwrite += _putchar('-');
	}

	chars = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";

	if (num < base)
	{
		nwrite += _putchar(chars[num]);
		return (nwrite);
	}


	nwrite += convert_to_base(num / base, base, lowercase);
	nwrite += _putchar(chars[num % base]);
	return (nwrite);
}

