#include "main.h"
/**
 * check_builtin - checks if a command is built in
 * @argv: arguments of the command
 * @line: read input line
 * Return: 1 if it succedds, 0 if it doesn't
 */
int check_builtin(char **argv, char *line)
{
	if (handle_builtin(argv, line))
		return (1);
	else if (**argv == '/')
	{
		execmd(argv[0], argv);
		return (1);
	}
	return (0);
}
