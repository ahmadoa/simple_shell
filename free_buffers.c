#include "main.h"

/**
 * free_buffers - frees memory of buffers
 * @buff: pointer to buffer
 * Return: void
 */
void free_buffers(char **buff)
{
	int i = 0;

	if (!buff || buff == NULL)
		return;
	while (buff[i])
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}
