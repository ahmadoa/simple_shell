#include "main.h"

/**
 * execmd - executes a command in a child process
 * @final: final command to execute
 * @argv: tokens of the command
 * Return: void
 */

void execmd(char *final, char **argv)
{
	int status;
	char **env = environ;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork");
	}

	if (child_pid == 0)
	{
		execve(final, argv, env);
		perror(final);
		free(final);
		free_buffers(argv);
		exit(98);
	}
	else
	{
		wait(&status);
	}
}
