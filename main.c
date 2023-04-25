#include "main.h"

/**
 * tokenize - parses the rad line in main
 * @line: the read input
 * Return: the tokens of the input, NULL if it fails
 */

char **tokenize(char *line)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " ;:\t\r\n";
	char **tokens = NULL;
	int tokenizer = 1;
	size_t i = 0, flag = 0;

	buf = _strdup(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && flag == 0)
		{
			tokenizer++;
			flag = 1;
		}
		else if (_strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokenizer + 1));
	token = _strtok(buf, delim);

	while (token)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = _strtok(NULL, delim);
		i++;
	}
	tokens[i] = '\0';
	free(buf);
	return (tokens);
}

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
 * main - simple shell entry point
 * making a loop, reading the input, tokenizing the input
 * and executing the commands
 * @argc: number of passed args
 * @av: passed arguments
 * @envp: array of pointer to env variables
 * Return: 0 in success, -1 if something fails
 */

int main(int argc, char *av[], char *envp[])
{
	char *lineptr;
	size_t n = 0;
	ssize_t nchars_read;
	char *path = NULL, **argv, *pathargv = NULL, **paths = NULL;

	(void)envp;
	(void)av;
	if (argc < 1)
		return (-1);

	if (signal(SIGINT, intHandler) == SIG_ERR)
	{
		perror("signal");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDERR_FILENO, "$ ", 2);
		else
			write(STDERR_FILENO, "", 0);
		nchars_read = _getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
			return (-1);
		argv = tokenize(lineptr);
		if (argv == NULL || *argv == NULL || **argv == '\0')
			continue;
		if (check_builtin(argv, lineptr))
			continue;
		path = get_path();
		paths = tokenize(path);
		pathargv = check_path(paths, argv[0]);
		if (!pathargv)
			perror(av[0]);
		else
			execmd(pathargv, argv);
		free(lineptr);
		return (0);
	}
}
