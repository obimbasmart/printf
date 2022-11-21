#include "main.h"

/**
 * get_flag - function that gets the flags for a printf format specifier
 * @fg: flag character
 * @flag: the structure representing the flags
 *
 * Return: integer. 0 on failure. 1 on success
 */
int get_flag(char fg, flag_t *flag)
{
	switch (fg)
	{
		case '+':
			flag->plus = 1;
			return (1);
		case '#':
			flag->hash = 1;
			return (1);
		case ' ':
			flag->space = 1;
			return (1);
		default:
			return (0);
	}
}
