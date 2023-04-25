#include "main.h"

/**
 * handle_builtin - handles builtin commands
 * @argv: arguments of input command
 * @line: read input line
 * Return: 1 if it successeds, 0 if it fails
 */
int handle_builtin(char **argv, char *line)
{
	struct builtin builtin = {"env", "exit"};
	if (_strcmp(*argv, builtin.env) == 0)
	{
		env_function();
		return (1);
	}
	else if (_strcmp(*argv, builtin.exit) == 0)
	{
		exit_function(argv, line);
		return (1);
	}
	return (0);
}
