#include "main.h"

/**
 * execute - executes the read command
 * @t_argv: tokenized read line
 * @line: vanilla input line
 * @c: exit arg
 * @argv: program name
 * Return: 1 if command is NULL, -1 false, 0 if it executes
 */

int execute(char **t_argv, char *line, int c, char **argv)
{
	int status;
	pid_t child_pid;

	if (*t_argv == NULL)
		return (-1);
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (_strncmp(*t_argv, "./", 2) != 0 && _strncmp(*t_argv, "/", 1) != 0)
			get_path(t_argv);
		if (execve(*t_argv, t_argv, environ) == -1)
		{
			display_err(t_argv[0], c, argv);
			free(line);
			free(t_argv);
			exit(2);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
