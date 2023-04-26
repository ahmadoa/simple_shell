#include "main.h"

/**
 * _realloc - resizes memory block pointed by pr
 * @old_size: old size of the memory block
 * @new_size: new size to replace the old size memory block
 * Return: NULL if it fails, memory block if it successeds
 */

void *_realloc(void *pr, unsigned int old_size, unsigned int new_size)
{
	void *memory;
	char *copy_pr, *fill;
	unsigned int i;

	if (new_size == old_size)
		return (pr);
	if (pr == NULL)
	{
		memory = malloc(new_size);
		if (memory == NULL)
			return (NULL);
		return (memory);
	}

	if (new_size == 0 && pr != NULL)
	{
		free(pr);
		return (NULL);
	}

	copy_pr = pr;
	memory = malloc(sizeof(*copy_pr) * new_size);
	if (memory == NULL)
	{
		free(pr);
		return (NULL);
	}
	fill = memory;
	for (i = 0; i < old_size && i < new_size; i++)
		fill[i] = *copy_pr++;
	free(pr);
	return (memory);
}

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
