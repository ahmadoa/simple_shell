#include "main.h"

/**
 * c_reader - read typed input
 * Return: the line input
 */

char *c_reader(void)
{
	char *input = NULL;
	size_t buff = 0;
	int nchars_read = _getline(&input, &buff, stdin);

	if (nchars_read == EOF)
	{
		free(input);
		if (isatty(STDIN) != 0)
			write(STDOUT, "\n", 1);
		exit(EXIT_SUCCESS);
	}

	return (input);
}
