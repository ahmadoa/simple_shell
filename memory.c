#include "main.h"

/**
 * _realloc - resizes memory block pointed by ptr
 * @old_size: old size of the memory block
 * @ptr: pointer to memory block
 * @new_size: new size to replace the old_size memory block
 * Return: NULL if it fails, memory block if it successeds
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *memory;
	char *copy_pr, *fill;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		memory = malloc(new_size);
		if (memory == NULL)
			return (NULL);

		return (memory);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	copy_pr = ptr;
	memory = malloc(sizeof(*copy_pr) * new_size);
	if (memory == NULL)
	{
		free(ptr);
		return (NULL);
	}

	fill = memory;

	for (i = 0; i < old_size && i < new_size; i++)
		fill[i] = *copy_pr++;

	free(ptr);
	return (memory);
}

/**
 * free_buffers - frees any buffers for no mem leaks
 * @t_argv: pointer to free
 * @line: pointer to char
 * Return: Void
 */

void free_buffers(char **t_argv, char *line)
{
	free(t_argv);
	free(line);
	t_argv = NULL;
	line = NULL;
}

/**
 * _memcpy - Copy Byte From Source To Destination
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @n: Size (How Much You Will Copy)
 * Return: Void Pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_an_array - Fill An Array By Constant Byte
 * @a: Void Pointer
 * @el: Int
 * @len: Length Int
 * Return: Void Pointer
 */

void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _calloc - Allocates Memory For An Array, Using Malloc
 * @size: Size
 * Return: Void Pointer
 */

void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
