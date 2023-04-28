#include "main.h"

/**
 * check_builtin - check builtin commands
 * @argv: read input command
 * Return: 0 in success, -1 if it fails
 */

int check_builtin(char **argv)
{
	int i = 0;
	builtin builtins[] = {
		{"cd", NULL},
		{"echo", NULL},
		{NULL, NULL}
	};

	if (*argv == NULL)
		return (-1);

	while ((builtins + i)->blt_cmd)
	{
		if (_strcmp(argv[0], (builtins + i)->blt_cmd) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * handle_builtin - handle builtin commands
 * @line: tokenized read input
 * @err: state after execution
 * Return: -1 if it fails, 0 otherwise
 */

int handle_builtin(char **line, int err)
{
	int i = 0;
	builtin builtins[] = {
		{"cd", _cd},
		{"env", display_env},
		{"echo", _echo},
		{NULL, NULL}
	};

	while ((builtins + i)->blt_cmd)
	{
		if (_strcmp(line[0], (builtins + i)->blt_cmd) == 0)
		{
			return ((builtins + i)->func(line, err));
		}
		i++;
	}
	return (-1);
}
