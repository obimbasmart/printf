#include "main.h"

/**
 * convert_unsigned_to_base - converts an unsigned integer to base b
 * @num: unsigned interger
 * @base: the new base
 * @lowercase: 0 or 1 == lowercase or uppercase
 *
 * Return: length of new num in base b
 */
size_t convert_unsigned_to_base(uintmax_t num, size_t base, size_t lowercase)
{
	char *chars;
	size_t nwrite;

	nwrite = 0;
	chars = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";

	if (num < base)
		return (_putchar(chars[num]));


	nwrite += convert_unsigned_to_base(num / base, base, lowercase);
	nwrite += _putchar(chars[num % base]);
	return (nwrite);
}

