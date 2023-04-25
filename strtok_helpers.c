#include "main.h"

/**
 * sim - compares a char from a string to the delimiter
 * @delim: seperator
 * @s: string to go through
 * Return: 0 if a similarity is found, 1 if not
 */

unsigned int sim(char delim, const char *s)
{
	unsigned int i = 0;

	while (s[i] != 0)
	{
		if (delim == s[i])
			return (0);
		i++;
	}
	return (1);
}
