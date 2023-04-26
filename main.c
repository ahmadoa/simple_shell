#include "main.h"

/**
 * intHandler - handles the signal of the shell
 * @sigint: signal number
 * Return: void
 */

void intHandler(int sigint)
{
	(void)sigint;
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_SUCCESS);
}

/**
 * _err - handles errors
 * @argv: tokenized command
 * @c_argv: cmd command
 * @inp_count: counter
 * Return: void
 */

void _err(char **argv, char **c_argv, int inp_count)
{
	write(2, argv[0], _strlen(argv[0]));
	write(2, ": ", 2);
	print_dec(inp_count);
	write(2, ": ", 2);
	write(2, c_argv[0], _strlen(c_argv[0]));
	write(2, ": not found\n", 12);
}

/**
 * handle_input - checks the paths
 * @lineptr: buffer where read line is stored
 * @c_argv: tokenized args
 * @paths: environment paths
 * @av: command line args
 * @inp_count: counter
 * Return: void
 */

void handle_input(__attribute__((unused)) char *lineptr, char **c_argv,
char **paths, char *av[], int inp_count)
{
	char *pathargv = check_path(paths, c_argv[0]);

	if (!pathargv)
	{
		_err(av, c_argv, inp_count);
	}
	else
	{
		execmd(pathargv, c_argv, av, inp_count);
	}
}

/**
 * run_shell - read the input and tokenizes it
 * @av: arugemnts
 * @envp: env variable
 * Return: void
 */

void run_shell(char *av[], __attribute__((unused)) char *envp[])
{
	size_t n = 0;
	ssize_t nchars_read;
	int inp_count = 1;
	char *path = NULL, *lineptr, **c_argv, **paths = NULL;

	if (signal(SIGINT, intHandler) == SIG_ERR)
	{
		perror("Signal Error");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDERR_FILENO, "$ ", 2);
		nchars_read = _getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
			exit(EXIT_FAILURE);
		c_argv = tokenize(lineptr);
		if (c_argv == NULL || *c_argv == NULL || **c_argv == '\0')
			continue;
		if (check_builtin(c_argv, lineptr, av, inp_count))
			continue;
		path = get_path();
		paths = tokenize(path);
		handle_input(lineptr, c_argv, paths, av, inp_count);
		inp_count++;
	}
	free(path);
	free(paths);
	free(c_argv);
	free(lineptr);
}
/**
 * main - simple shell entry point
 * making a loop, reading the input, tokenizing the input
 * and executing the commands
 * @argc: number of passed args
 * @argv: passed arguments
 * @envp: array of pointer to env variables
 * Return: 0 in success, -1 if something fails
 */

int main(int argc, char *argv[], __attribute__((unused)) char *envp[])
{
	if (argc > 1)
	{
		write(2, "Usage: ", 7);
		write(2, argv[0], _strlen(argv[0]));
		write(2, "\n", 1);
		return (EXIT_FAILURE);
	}
	run_shell(argv, envp);
	return (EXIT_SUCCESS);
}
