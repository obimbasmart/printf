#include "main.h"
/**
 * convert_to_base - converts a signed interger to base b
 * @_num: signed integer
 * @base: the new base
 * @lowercase: 1 = lowercase or 0 =  uppercase
 *
 * Return: number of characters written to STDOUT
 */
size_t convert_to_base(long int _num, size_t base, size_t lowercase)
{
	char *chars;
	size_t nwrite;
	unsigned long int num;

	nwrite = 0;
	if (_num < 0 && base == 10)
	{
		num = -_num;
		nwrite += _putchar('-');
	}
	else
		num = _num;

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

