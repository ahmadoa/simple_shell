#include "main.h"

/**
 * handle_comments - handles and removes comments from command
 * @line: input
 * Return: void
 */

void handle_comments(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
	}
}
