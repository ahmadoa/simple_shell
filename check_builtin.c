#include "main.h"
/**
 * check_builtin - checks if a command is built in
 * @argv: arguments of the command
 * @line: read input line
 * @ar: args
 * @inp_count: inp string counter
 * Return: 1 if it succedds, 0 if it doesn't
 */
int check_builtin(char **argv, char *line, char **ar, int inp_count)
{
	if (handle_builtin(argv, line))
		return (1);
	else if (**argv == '/')
	{
		execmd(argv[0], argv, ar, inp_count);
		return (1);
	}
	return (0);
}
