#include "main.h"

/**
 * get_length_modifier - gets the length modifier of a printf func
 * @ch: length character
 *
 * Return: integer. 0 on failure. 1 on success
 */
size_t get_length_modifier(char ch)
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
