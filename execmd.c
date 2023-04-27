#include "main.h"

/**
 * execmd - executes a command in a child process
 * @argv: tokens of the command
 * @ct_output: counter
 * Return: ct_output
 */

int execmd(char **argv, int ct_output)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Forking Error");
	}

	else if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Execution error");
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			ct_output = WEXITSTATUS(status);
	}

	return (ct_output);
}
