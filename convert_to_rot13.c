#include "main.h"
/**
 * convert_to_rot13 -  function that encodes a string into rot13.
 * @str : the string
 * Return: number of chars written to stdout
 */
size_t convert_to_rot13(char *str)
{
	size_t idx, idxx, nwrite;
	char ch;
	char original_str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char roted_str[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	idx = nwrite = 0;
	while (str[idx] != '\0')
	{
		ch = str[idx];
		idxx = 0;
		while (idxx < 54)
		{
			if (((ch >= 'A' && ch <= 'Z') ||
				(ch >= 'a' && ch <= 'z')) && ch == original_str[idxx])
			{
				_putchar(roted_str[idxx]);
				break;
			}
			idxx++;
		}
	idx++;
	}
	return (nwrite);
}
