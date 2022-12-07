#include "main.h"

/**
 * get_length_modifier - gets the length modifier of a printf func
 * @ch: length character
 * @length_modifier: the lenght modifier
 *
 * Return: integer. 0 on failure. 1 on success
 */
int get_length_modifier(char ch)
{
	switch (ch)
	{
		case 'h':
			return (SHORT);
		case 'l':
			return (LONG);
		default:
			return (0);
	}
}
