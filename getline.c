#include "main.h"

/**
 * _getline - read input commands from the STDIN stream
 * Return: read input
 */

char *_getline()
{
	int i, buffSZ = BUFSIZE, read_d;
	char c = 0, *lineptr = malloc(buffSZ);

	if (lineptr == NULL)
	{
		free(lineptr);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		read_d = read(STDIN_FILENO, &c, 1);
		if (read_d == 0)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		lineptr[i] = c;
		if (lineptr[0] == '\n')
		{
			free(lineptr);
			return ("\0");
		}
		if (i >= buffSZ)
		{
			lineptr = _realloc(lineptr, buffSZ, buffSZ + 1);
			if (lineptr == NULL)
				return (NULL);
		}
	}
	lineptr[i] = '\0';
	handle_comments(lineptr);
	return (lineptr);
}
