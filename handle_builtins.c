#include "main.h"
/**
 * handle_builtin - handles builtin commands
 * @argv: arguments of input command
 * @ct_output: output
 * @line: read input line
 * Return: always 0
 */
int handle_builtin(char **argv, __attribute__((unused)) int ct_output,
		char *line)
{
	char *builtins[2] = {"exit", "env"};
	int i = 0, env_sz;
	char *env = NULL;

	if (_strcmp(builtins[0], argv[0]) == 0)
	{
		free(argv);
		free(line);
		exit(ct_output);
	}

	else if (_strcmp(builtins[1], argv[0]) == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			env = environ[i];
			env_sz = _strlen(env);
			write(STDOUT, env, env_sz);
			write(STDOUT, "\n", 1);
		}
	}

	return (0);
}
