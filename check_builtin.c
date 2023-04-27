#include "main.h"
/**
 * check_builtin - checks if a command is built in
 * @argv: arguments of the command
 * @line: read input line
 * @ct_output: inp string counter
 * Return: 1 if it fails, function to execute if it successeds
 */
int check_builtin(char **argv, int ct_output, char *line)
{
	char *builtins[2] = {"exit", "env"};

	if (*argv == NULL)
		return (1);

	else if (_strcmp(builtins[0], argv[0]) == 0)
		return (handle_builtin(argv, ct_output, line));

	else if (_strcmp(builtins[1], argv[0]) == 0)
		return (handle_builtin(argv, ct_output, line));

	else
		return (_argscmp(argv, ct_output));
}
