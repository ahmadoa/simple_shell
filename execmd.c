#include "main.h"

/**
 * execmd - executes a command in a child process
 * @final: final command to execute
 * @argv: tokens of the command
 * Return: void
 */

void execmd(char *final, char **argv, char **ar, int inp_count)
{
	int status, err;
	char **env = environ;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("forking Error:");
		free_buffers(argv);
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		err = execve(final, argv, env);
		if (err == -1)
		{
			write(2, ar[0], _strlen(ar[0]));
			write(2, ": ", 2);
			print_dec(inp_count);
			write(2, ": ", 2);
			write(2, argv[0], _strlen(argv[0]));
			write(2, ": not found\n", 12);
			free(final);
			free_buffers(argv);
			exit(126);
		}
	}
	if (child_pid > 0)
	{
		wait(&status);
	}
}
