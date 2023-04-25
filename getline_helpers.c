#include "main.h"

/**
 * reassign_pr - reassigns pointer with new size
 * @lineptr: read input line
 * @sz: size of input buffer
 * @buff: buffer size
 * @inp: input
 * Return: void
 */

void reassign_pr(char **lineptr, size_t *sz, char *buff, size_t inp)
{
	if (*lineptr == NULL)
	{
		if (inp > 120)
			*sz = inp;
		else
			*sz = 120;
		*lineptr = buff;
	}
	else if (*sz < inp)
	{
		if (inp > 120)
			*sz = inp;
		else
			*sz = 120;
		*lineptr = buff;
	}
	else
	{
		_strcpy(*lineptr, buff);
		free(buff);
	}
}
