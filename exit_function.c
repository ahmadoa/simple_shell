#include "main.h"

/**
 * exit_function - handle the exit command
 * @argv: arguments of input command
 * @line: read input line
 * Return: void
 */
void exit_function(char **argv, char *line)
{
	free(line);
	free_buffers(argv);
	exit(0);
}
