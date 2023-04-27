#include "main.h"

/**
 * _err - handles errors
 * @line: first argument of typed command
 * Return: void
 */

void _err(char *line)
{
	write(2, line, _strlen(line));
	write(2, ": not found\n", 12);
}

/**
 * main - simple shell entry point
 * making a loop, reading the input, tokenizing the input
 * and executing the commands
 * Return: 0 in success
 */

int main(void)
{
	char *line = NULL, **tknz = NULL;
	int exec_res = 0;

	while (1)
	{
		if (isatty(STDIN))
			write(STDOUT, "$ ", 2);

		line = c_reader();
		tknz = tokenize(line);
		exec_res = check_builtin(tknz, exec_res, line);

		free(line);
		free(tknz);
	}

	return (0);
}
